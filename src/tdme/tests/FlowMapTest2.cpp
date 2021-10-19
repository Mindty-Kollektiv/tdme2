#include <tdme/tests/FlowMapTest2.h>

#include <string>

#include <tdme/utilities/Time.h>

#include <tdme/application/Application.h>
#include <tdme/application/InputEventHandler.h>
#include <tdme/engine/fileio/models/ModelReader.h>
#include <tdme/engine/fileio/prototypes/PrototypeReader.h>
#include <tdme/engine/fileio/scenes/SceneReader.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/engine/model/Material.h>
#include <tdme/engine/model/Model.h>
#include <tdme/engine/physics/Body.h>
#include <tdme/engine/physics/World.h>
#include <tdme/engine/primitives/OrientedBoundingBox.h>
#include <tdme/engine/prototype/BaseProperties.h>
#include <tdme/engine/prototype/BaseProperty.h>
#include <tdme/engine/prototype/Prototype.h>
#include <tdme/engine/prototype/PrototypeBoundingVolume.h>
#include <tdme/engine/scene/Scene.h>
#include <tdme/engine/scene/SceneEntity.h>
#include <tdme/engine/Camera.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/Light.h>
#include <tdme/engine/Object3D.h>
#include <tdme/engine/Rotation.h>
#include <tdme/engine/SceneConnector.h>
#include <tdme/engine/Timing.h>
#include <tdme/math/Math.h>
#include <tdme/math/Quaternion.h>
#include <tdme/math/Vector3.h>
#include <tdme/math/Vector4.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Float.h>
#include <tdme/utilities/FlowMap.h>
#include <tdme/utilities/FlowMapCell.h>
#include <tdme/utilities/Integer.h>
#include <tdme/utilities/PathFinding.h>
#include <tdme/utilities/Primitives.h>

using std::string;
using std::to_string;

using tdme::tests::FlowMapTest2;

using tdme::application::Application;
using tdme::application::InputEventHandler;
using tdme::engine::fileio::models::ModelReader;
using tdme::engine::fileio::prototypes::PrototypeReader;
using tdme::engine::fileio::scenes::SceneReader;
using tdme::engine::model::Color4;
using tdme::engine::model::Material;
using tdme::engine::model::Model;
using tdme::engine::physics::Body;
using tdme::engine::physics::World;
using tdme::engine::primitives::OrientedBoundingBox;
using tdme::engine::prototype::BaseProperties;
using tdme::engine::prototype::BaseProperty;
using tdme::engine::prototype::Prototype;
using tdme::engine::prototype::PrototypeBoundingVolume;
using tdme::engine::scene::Scene;
using tdme::engine::scene::SceneEntity;
using tdme::engine::Camera;
using tdme::engine::Engine;
using tdme::engine::Light;
using tdme::engine::Object3D;
using tdme::engine::Rotation;
using tdme::engine::SceneConnector;
using tdme::engine::Timing;
using tdme::math::Math;
using tdme::math::Quaternion;
using tdme::math::Vector3;
using tdme::math::Vector4;
using tdme::utilities::Console;
using tdme::utilities::Float;
using tdme::utilities::FlowMap;
using tdme::utilities::FlowMapCell;
using tdme::utilities::Integer;
using tdme::utilities::PathFinding;
using tdme::utilities::Primitives;
using tdme::utilities::Time;

FlowMapTest2::FlowMapTest2()
{
	Application::setLimitFPS(true);
	engine = Engine::getInstance();
	world = new World();
	timeLastUpdate = -1;
}

FlowMapTest2::~FlowMapTest2() {
	if (flowMap != nullptr) flowMap->releaseReference();
	delete world;
	delete emptyModel;
	delete playerModelPrototype;
	delete pathFinding;
}

void FlowMapTest2::main(int argc, char** argv)
{
	auto flowMapTest2 = new FlowMapTest2();
	flowMapTest2->run(argc, argv, "FlowMapTest2", flowMapTest2);
}

void FlowMapTest2::display()
{
	auto cam = engine->getCamera();
	cam->setLookAt(combatUnits[0].object->getTransformations().getTranslation());
	cam->setLookFrom(cam->getLookAt() + Vector3(0.0f, 40.0f, 0.0f));
	cam->setUpVector(cam->computeUpVector(cam->getLookFrom(), cam->getLookAt()));
	if (mouseClicked == true) {
		mouseClicked = false;
		Vector3 worldClickPosition;
		engine->computeWorldCoordinateByMousePosition(mouseClickPosition[0], mouseClickPosition[1], worldClickPosition);
		Console::println(
			"FlowMapTest2::display(): " +
			to_string(worldClickPosition.getX()) + ", " +
			to_string(worldClickPosition.getY()) + ", " +
			to_string(worldClickPosition.getZ())
		);
		doPathFinding(worldClickPosition);
	}
	if (pause != true) {
		Quaternion formationRotationQuaternion;
		formationRotationQuaternion.identity();
		if (combatUnits[0].pathFindingNodeIdx != -1) {
			formationMovement = combatUnits[0].movementDirection;
			auto currentFormationYRotationAngle = Vector3::computeAngle(Vector3(0.0f, 0.0f, -1.0f), formationMovement.clone().normalize(), Vector3(0.0f, 1.0f, 0.0f));
			if (Float::isNaN(currentFormationYRotationAngle) == false) formationYRotationAngle = currentFormationYRotationAngle;
		}
		formationRotationQuaternion.rotate(Vector3(0.0f, 1.0f, 0.0f), formationYRotationAngle);
		for (auto& combatUnit: combatUnits) {
			combatUnit.object->fromTransformations(combatUnit.rigidBody->getTransformations());
			while (combatUnit.object->getRotationCount() > 1) {
				combatUnit.object->removeRotation(combatUnit.object->getRotationCount() - 1);
			}
			combatUnit.object->setRotationAxis(0, Vector3(0.0f, 1.0f, 0.0f));
			combatUnit.object->setRotationAngle(0, combatUnit.rotationY);
			combatUnit.object->update();
			FlowMapCell* cell = nullptr;
			// find path to end position?
			auto distanceSquared = combatUnit.endPosition.clone().sub(combatUnit.object->getTranslation()).computeLengthSquared();
			if (distanceSquared < Math::square(0.1f)) {
				// done
				if (combatUnit.object->getAnimation() != "still") combatUnit.object->setAnimation("still");
			} else
			if (combatUnit.path.empty() == true &&
				distanceSquared <= Math::square(8.0f)) {
				pathFinding->findPath(
					combatUnit.object->getTransformations().getTranslation(),
					combatUnit.endPosition,
					SceneConnector::RIGIDBODY_TYPEID_STATIC,
					combatUnit.path
				);
				combatUnit.pathIdx = 0;
			}
			// do we have a path?
			if (combatUnit.path.empty() == false) {
				float xDirection = 0.0f;
				float zDirection = 0.0f;
				if (combatUnit.object->getTranslation().equals(combatUnit.endPosition, 0.1f) == true ||
					combatUnit.pathIdx >= combatUnit.path.size()) {
					combatUnit.pathIdx = combatUnit.path.size();
					combatUnit.movementDirection = Vector3();
					combatUnit.path.clear();
					combatUnit.pathIdx = -1;
					if (combatUnit.object->getAnimation() != "still") combatUnit.object->setAnimation("still");
				} else {
					if (Math::abs(combatUnit.object->getTranslation().getX() - combatUnit.path[combatUnit.pathIdx].getX()) < 0.05f)  {
						xDirection = 0.0f;
					} else
					if (combatUnit.object->getTranslation().getX() < combatUnit.path[combatUnit.pathIdx].getX())  {
						xDirection = +1.0f;
					} else
					if (combatUnit.object->getTranslation().getX() > combatUnit.path[combatUnit.pathIdx].getX())  {
						xDirection = -1.0f;
					}
					if (Math::abs(combatUnit.object->getTranslation().getZ() - combatUnit.path[combatUnit.pathIdx].getZ()) < 0.05f)  {
						zDirection = 0.0f;
					} else
					if (combatUnit.object->getTranslation().getZ() < combatUnit.path[combatUnit.pathIdx].getZ())  {
						zDirection = +1.0f;
					} else
					if (combatUnit.object->getTranslation().getZ() > combatUnit.path[combatUnit.pathIdx].getZ())  {
						zDirection = -1.0f;
					}
					auto xDirectionFinished =
						(xDirection > 0.1f && combatUnit.object->getTranslation().getX() >= combatUnit.path[combatUnit.pathIdx].getX()) ||
						(xDirection < -0.1f && combatUnit.object->getTranslation().getX() <= combatUnit.path[combatUnit.pathIdx].getX()) ||
						(Math::abs(combatUnit.object->getTranslation().getX() - combatUnit.path[combatUnit.pathIdx].getX()) < 0.05f);
					auto zDirectionFinished =
						(zDirection > 0.1f && combatUnit.object->getTranslation().getZ() >= combatUnit.path[combatUnit.pathIdx].getZ()) ||
						(zDirection < -0.1f && combatUnit.object->getTranslation().getZ() <= combatUnit.path[combatUnit.pathIdx].getZ()) ||
						(Math::abs(combatUnit.object->getTranslation().getZ() - combatUnit.path[combatUnit.pathIdx].getZ()) < 0.05f);
					combatUnit.movementDirection = Vector3(xDirectionFinished == true?0.0f:xDirection, 0.0f, zDirectionFinished == true?0.0f:zDirection);
					if (xDirectionFinished == true && zDirectionFinished == true) combatUnit.pathIdx++;
				}
			} else
			// ok, try to do flow map
			if ((cell = flowMap != nullptr?flowMap->getCell(combatUnit.object->getTranslation().getX(), combatUnit.object->getTranslation().getZ()):nullptr) != nullptr) {
				auto pathFindingNodeIdx = Math::min(cell->getPathNodeIdx() + 1, flowMap->getPath().size() - 1);
				if (pathFindingNodeIdx > combatUnit.pathFindingNodeIdx) {
					combatUnit.pathFindingNodeIdx = pathFindingNodeIdx;
				}
				if (combatUnit.pathFindingNodeIdx != -1) {
					if (combatUnit.idx == 0) {
						combatUnit.pathFindingNode = flowMap->getPath()[combatUnit.pathFindingNodeIdx];
					} else {
						auto relativeFormationPosition = (combatUnitFormationTransformations[combatUnit.formationIdx].getTranslation() - combatUnitFormationTransformations[combatUnits[0].formationIdx].getTranslation());
						auto formationPosition = formationRotationQuaternion * relativeFormationPosition;
						combatUnit.pathFindingNode = combatUnits[0].object->getTranslation() + formationPosition;
					}
				}
				//combatUnit.cellDirection = flowMapDirection.computeLengthSquared() > Math::square(Math::EPSILON)?flowMapDirection:cell->getDirection();
				auto cellDirection = cell->getDirection();
				auto pcdDotPND = 0.0f;
				Vector3 pathFindingNodeDirection;
				if (cell->hasMissingNeighborCell() == false) {
					pathFindingNodeDirection = combatUnit.pathFindingNode - combatUnit.object->getTranslation();
					if (pathFindingNodeDirection.computeLengthSquared() > Math::square(Math::EPSILON)) {
						pathFindingNodeDirection.normalize();
						pcdDotPND = (Math::clamp(Vector3::computeDotProduct(cellDirection, pathFindingNodeDirection), -0.25f, 1.0f) + 0.25f) / 1.25f;
						if (pcdDotPND > 0.0f) {
							pcdDotPND = 1.0f;
							combatUnit.movementDirection = (cellDirection * ((1.0f - pcdDotPND)) + pathFindingNodeDirection * pcdDotPND).normalize();
							auto nextCellTranslation = combatUnit.object->getTranslation() + combatUnit.movementDirection * flowMap->getStepSize();
							auto nextCell = flowMap->getCell(nextCellTranslation.getX(), nextCellTranslation.getZ());
							if (nextCell == nullptr || nextCell->isWalkable() == false) {
								pcdDotPND = 0.0f;
								combatUnit.movementDirection = (cellDirection * ((1.0f - pcdDotPND)) + pathFindingNodeDirection * pcdDotPND).normalize();
							}
						}
					}
					combatUnit.movementDirection = (cellDirection * ((1.0f - pcdDotPND)) + pathFindingNodeDirection * pcdDotPND).normalize();
				} else {
					auto nextCellPosition = combatUnit.object->getTranslation() + (cell->getDirection() * (flowMap->getStepSize() + 0.1f));
					auto nextCell = flowMap->getCell(nextCellPosition.getX(), nextCellPosition.getZ());
					if (nextCell != nullptr) {
						// TODO: improve me!
						auto cellPositionDirection = (nextCell->getPosition() - combatUnit.object->getTranslation()).setY(0.0f).normalize();
						float cellPositionDirectionScale = Math::max(1.0f, cellPositionDirection.computeLength());
						cellPositionDirection.normalize();
						combatUnit.movementDirection = (cellDirection + (cellPositionDirection * cellPositionDirectionScale)).normalize();
					}
				}

				if (combatUnit.idx == 0)
				{
					auto flowDirectionEntityId = "flowdirectioncurrent" + to_string(combatUnit.idx);
					auto yRotationAngle = Vector3::computeAngle(Vector3(0.0f, 0.0f, 1.0f), pathFindingNodeDirection, Vector3(0.0f, 1.0f, 0.0f));
					auto cellObject = new Object3D(flowDirectionEntityId, emptyModel);
					cellObject->setScale(Vector3(5.0f, 5.0f, 5.0f));
					cellObject->setTranslation(Vector3(-0.0f, 0.5f, 3.0f - (combatUnit.idx * 5.0f)));
					cellObject->addRotation(Vector3(0.0f, 1.0f, 0.0f), yRotationAngle - 90.0f);
					cellObject->setDisableDepthTest(true);
					cellObject->update();
					engine->addEntity(cellObject);
				}
			} else {
				if (combatUnit.object->getAnimation() != "still") combatUnit.object->setAnimation("still");
				combatUnit.movementDirection = Vector3();

				//
				if (flowMap != nullptr) {
					auto combatUnitTranslation = combatUnit.object->getTranslation();
					float minDistance = Float::MAX_VALUE;
					Vector3 flowMapPosition;
					// 1. try: find nearest cell from current position
					auto nearestCell = flowMap->findNearestCell(combatUnit.object->getTranslation().getX(), combatUnit.object->getTranslation().getZ());
					if (nearestCell != nullptr) {
						flowMapPosition = nearestCell->getPosition() + Vector3(flowMap->getStepSize() / 2.0f, 0.0f, flowMap->getStepSize() / 2.0f);
					} else {
						// otherwise find path to closed path finding node of flowmap path
						Vector3 minDistancePathFindingNode;
						for (auto& flowMapPathFindingNode: flowMap->getPath()) {
							auto candidateDistance = combatUnitTranslation.clone().sub(flowMapPathFindingNode).computeLength();
							auto pathCell = flowMap->getCell(flowMapPathFindingNode.getX(), flowMapPathFindingNode.getZ());
							if (candidateDistance < minDistance && pathCell != nullptr) {
								minDistance = candidateDistance;
								minDistancePathFindingNode = pathCell->getPosition() + pathCell->getDirection() * (flowMap->getStepSize() * 0.5f);
							}
						}
					}

					//	line of sight check, then compute direct path
					bool foundPath = false;
					if (combatUnitTranslation.clone().sub(flowMapPosition).computeLengthSquared() < Math::square(0.1f)) {
						for (auto i = 0; i < 3; i++) {
							if (pathFinding->findPath(
								combatUnitTranslation,
								flowMapPosition,
								SceneConnector::RIGIDBODY_TYPEID_STATIC,
								combatUnit.path,
								3,
								static_cast<int>(minDistance * 6.0f)
							) == true) {
								foundPath = true;
								break;
							}
						}
					}

					// try to do direct path
					if (foundPath == false) combatUnit.path = pathFinding->generateDirectPath(combatUnitTranslation, flowMapPosition);
					combatUnit.pathIdx = 0;
				}
			}
			//
			combatUnit.movementDirection.setY(0.0f);
			if (combatUnit.movementDirection.computeLengthSquared() > Math::square(Math::EPSILON)) {
				combatUnit.movementDirection.normalize();
				// movement direction
				if (combatUnit.object->getAnimation() != "walk") combatUnit.object->setAnimation("walk");
				combatUnit.movementDirectionRing[combatUnit.movementDirectionRingIdx] = combatUnit.movementDirection;
				combatUnit.movementDirectionRingLength = Math::min(combatUnit.movementDirectionRingLength + 1, combatUnit.movementDirectionRing.size());
				Vector3 movementDirection;
				for (auto i = 0; i < combatUnit.movementDirectionRingLength; i++) {
					movementDirection.add(combatUnit.movementDirectionRing[(combatUnit.movementDirectionRingIdx - i) % combatUnit.movementDirectionRing.size()]);
				}
				if (movementDirection.computeLengthSquared() > Math::square(Math::EPSILON)) {
					movementDirection.normalize();
					combatUnit.rotationY = Vector3::computeAngle(Vector3(0.0f, 0.0f, 1.0f), movementDirection, Vector3(0.0f, 1.0f, 0.0f));
				} else {
					combatUnit.rotationY = 0.0f;
				}
				combatUnit.object->setRotationAngle(0, combatUnit.rotationY);
				combatUnit.movementDirectionRingIdx = (combatUnit.movementDirectionRingIdx + 1) % combatUnit.movementDirectionRing.size();
				combatUnit.object->update();
				{
					{
						auto pathFindingNodeId = "pathfindingnodecurrent." + to_string(combatUnit.idx);
						auto pathFindingNodeObject = new Object3D(pathFindingNodeId, emptyModel);
						pathFindingNodeObject->setScale(Vector3(2.0f, 2.0f, 2.0f));
						pathFindingNodeObject->setTranslation(combatUnit.pathFindingNode + Vector3(0.0f, 0.0f, 0.0f));
						pathFindingNodeObject->addRotation(Vector3(0.0f, 0.0f, 1.0f), 90.0f);
						pathFindingNodeObject->setDisableDepthTest(true);
						pathFindingNodeObject->setEffectColorMul(Color4(0.0f, 0.0f, 0.0f, 1.0f));
						pathFindingNodeObject->update();
						engine->addEntity(pathFindingNodeObject);
					}
				}
			}
			//
			combatUnit.rigidBody->setLinearVelocity(combatUnit.movementDirection * combatUnit.speed * 2.0f);
		}
	}
	// speed detection
	// TODO: if distance of CU to CU 0 gets bigger over time, also increase speed
	if (flowMap != nullptr) {
		for (auto& combatUnit: combatUnits) {
			if (combatUnit.path.empty() == false) {
				combatUnit.speed = 1.5f;
				continue;
			}
			if (combatUnit.idx == 0) continue;
			auto villagerPathNodeIdx = Math::min(combatUnit.pathFindingNodeIdx + 1, flowMap->getPath().size() - 1);
			auto formationPositionMovement = combatUnit.pathFindingNode - combatUnit.object->getTranslation();
			auto formationPositionDistance = formationPositionMovement.computeLength();
			formationPositionMovement.normalize();
			auto formationPositionMovementDotMovementDirection = Vector3::computeDotProduct(combatUnit.movementDirection, formationPositionMovement);
			if (formationPositionDistance > 0.1f) {
				combatUnit.speed = formationPositionMovementDotMovementDirection > 0.0f?2.0f:0.5f;
			} else {
				combatUnit.speed = 1.0f;
			}
		}
	}
	world->update(1.0f / 60.0f);
	engine->display();
}

void FlowMapTest2::dispose()
{
	engine->dispose();
	delete scene;
}

void FlowMapTest2::initialize()
{
	engine->initialize();
	scene = SceneReader::read("../MedievalSurvivors/resources/project/maps", "Map_TEST_SquadMovement.tscene");
	SceneConnector::setLights(engine, scene);
	SceneConnector::addScene(engine, scene, false, false, false, false);
	SceneConnector::addScene(world, scene);
	auto cam = engine->getCamera();
	cam->setZNear(0.1f);
	cam->setZFar(15.0f);
	cam->setLookFrom(scene->getCenter() + Vector3(0.0f, 20.0f, 0.0f));
	cam->setLookAt(scene->getCenter());
	cam->setUpVector(cam->computeUpVector(cam->getLookFrom(), cam->getLookAt()));
	emptyModel = ModelReader::read("resources/engine/models", "empty.tm");
	formationLinePrototype = ModelReader::read("resources/tests/levels/pathfinding", "Formation_Line.tm");
	playerModelPrototype = PrototypeReader::read("resources/tests/models/mementoman", "mementoman.tmodel");
	playerModelPrototype->getModel()->addAnimationSetup("walk", 0, 23, true);
	playerModelPrototype->getModel()->addAnimationSetup("still", 24, 99, true);
	playerModelPrototype->getModel()->addAnimationSetup("death", 109, 169, false);
	//
	startPosition = Vector3(0.0f, 0.25f, 4.5f);
	endPosition = Vector3(0.0f, 0.25f, 4.5f);
	for (auto i = 0; i < scene->getEntityCount(); i++) {
		auto entity = scene->getEntityAt(i);
		auto properties = entity->getTotalProperties();
		{
			auto spawnPointProperty = properties.getProperty("spawnpoint");
			if (spawnPointProperty != nullptr && spawnPointProperty->getValue() == "true") {
				auto playerGroupIdx = -1;
				{
					auto spawnPointPlayerGroupIdxProperty = properties.getProperty("spawnpoint.playergroup");
					if (spawnPointPlayerGroupIdxProperty != nullptr) playerGroupIdx = Integer::parseInt(spawnPointPlayerGroupIdxProperty->getValue());
				}
				startPosition = entity->getTransformations().getTranslation();
				endPosition = startPosition;
			}
		}
	}
	// first line
	{
		CombatUnit combatUnit;
		combatUnit.idx = 0;
		combatUnit.formationIdx = 3; // check for other formation size
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	{
		CombatUnit combatUnit;
		combatUnit.idx = 1;
		combatUnit.formationIdx = 0;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	{
		CombatUnit combatUnit;
		combatUnit.idx = 2;
		combatUnit.formationIdx = 1;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	{
		CombatUnit combatUnit;
		combatUnit.idx = 3;
		combatUnit.formationIdx = 2;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	{
		CombatUnit combatUnit;
		combatUnit.idx = 4;
		combatUnit.formationIdx = 4;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	{
		CombatUnit combatUnit;
		combatUnit.idx = 5;
		combatUnit.formationIdx = 5;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	// second line
	{
		CombatUnit combatUnit;
		combatUnit.idx = 6;
		combatUnit.formationIdx = 6;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	{
		CombatUnit combatUnit;
		combatUnit.idx = 7;
		combatUnit.formationIdx = 7;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	{
		CombatUnit combatUnit;
		combatUnit.idx = 8;
		combatUnit.formationIdx = 8;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	{
		CombatUnit combatUnit;
		combatUnit.idx = 9;
		combatUnit.formationIdx = 9;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	{
		CombatUnit combatUnit;
		combatUnit.idx = 10;
		combatUnit.formationIdx = 10;
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.pathIdx = 0;
		combatUnit.rotationY = 0.0f;
		combatUnit.object = new Object3D("combatunit." + to_string(combatUnit.idx), playerModelPrototype->getModel());
		combatUnit.object->addRotation(Vector3(0.0f, 1.0f, 0.0f), 90.0f);
		combatUnit.object->setTranslation(startPosition);
		combatUnit.object->update();
		combatUnit.object->setAnimation("still");
		combatUnit.object->setContributesShadows(playerModelPrototype->isContributesShadows());
		combatUnit.object->setReceivesShadows(playerModelPrototype->isReceivesShadows());
		combatUnit.rigidBody = SceneConnector::createBody(world, playerModelPrototype, "combatunit." + to_string(combatUnit.idx), combatUnit.object->getTransformations(), Body::TYPEID_DYNAMIC);
		combatUnit.rigidBody->setCollisionTypeIds(Body::TYPEID_STATIC);
		engine->addEntity(combatUnit.object);
		combatUnits.push_back(combatUnit);
	}
	pathFinding = new PathFinding(world, true, 2000, 1.8f, 0.4f, 0.81f, 1.0f, Body::TYPEID_DYNAMIC);

	//
	for (auto i = 0; i < combatUnitFormationTransformations.size(); i++) {
		auto emptyName = "Waypoint_" + to_string(i);
		Matrix4x4 transformationsMatrix;
		if (formationLinePrototype->computeTransformationsMatrix(
			emptyName,
			formationLinePrototype->getImportTransformationsMatrix(),
			transformationsMatrix) == false) {
			Console::println("FlowMapTest2::initialize(): Missing '" + emptyName + "'");
		}
		combatUnitFormationTransformations[i].fromMatrix(transformationsMatrix, RotationOrder::ZYX);
	}

	//
	Quaternion formationRotationQuaternion;
	formationRotationQuaternion.identity();
	formationMovement = Vector3(0.0f, 0.0f, -1.0f);
	formationYRotationAngle = Vector3::computeAngle(Vector3(0.0f, 0.0f, -1.0f), formationMovement.clone().normalize(), Vector3(0.0f, 1.0f, 0.0f));
	formationRotationQuaternion.rotate(Vector3(0.0f, 1.0f, 0.0f), formationYRotationAngle);
	for (auto& combatUnit: combatUnits) {
		auto relativeFormationPosition = (combatUnitFormationTransformations[combatUnit.formationIdx].getTranslation() - combatUnitFormationTransformations[combatUnits[0].formationIdx].getTranslation());
		auto formationPosition = formationRotationQuaternion * relativeFormationPosition;
		combatUnit.endPosition = combatUnits[0].object->getTranslation() + formationPosition;
		combatUnit.rotationY = Vector3::computeAngle(Vector3(0.0f, 0.0f, 1.0f), combatUnit.movementDirection, Vector3(0.0f, 1.0f, 0.0f));
		combatUnit.object->setTranslation(combatUnit.endPosition);
		combatUnit.object->setRotationAngle(0, combatUnit.rotationY);
		combatUnit.object->update();
		combatUnit.rigidBody->fromTransformations(combatUnit.object->getTransformations());
	}
}

void FlowMapTest2::reshape(int32_t width, int32_t height)
{
	engine->reshape(width, height);
}

void FlowMapTest2::doPathFinding(const Vector3& newEndPosition) {
	if (flowMap != nullptr) {
		flowMap->releaseReference();
		flowMap = nullptr;
	}

	//
	startPosition = combatUnits[0].object->getTranslation();
	endPosition = newEndPosition;
	for (auto& combatUnit: combatUnits) {
		combatUnit.pathFindingNodeIdx = -1;
		combatUnit.speed = 1.0f;
		combatUnit.movementDirectionRing.fill(Vector3());
		combatUnit.movementDirectionRingLength = 0;
		combatUnit.movementDirectionRingIdx = 0;
		combatUnit.path.clear();
	}

	//
	pathFinding->findPath(
		combatUnits[0].object->getTransformations().getTranslation(),
		endPosition,
		SceneConnector::RIGIDBODY_TYPEID_STATIC,
		path
	);
	Console::println("Found a path: steps: " + to_string(path.size()));
	auto center = scene->getBoundingBox()->getCenter();
	auto depth = Math::ceil(scene->getBoundingBox()->getDimensions().getZ());
	auto width = Math::ceil(scene->getBoundingBox()->getDimensions().getX());

	if (path.size() > 12) {
		vector<Vector3> pathA;
		vector<Vector3> pathB;
		for (auto i = 0; i < path.size(); i++) {
			if (i < (path.size() / 2)) {
				pathA.push_back(path[i]);
			} else {
				if (pathB.empty() == true) {
					pathB.push_back(pathA[pathA.size() - 8]);
					pathB.push_back(pathA[pathA.size() - 7]);
					pathB.push_back(pathA[pathA.size() - 6]);
					pathB.push_back(pathA[pathA.size() - 5]);
					pathB.push_back(pathA[pathA.size() - 4]);
					pathB.push_back(pathA[pathA.size() - 3]);
					pathB.push_back(pathA[pathA.size() - 2]);
					pathB.push_back(pathA[pathA.size() - 1]);
				}
				pathB.push_back(path[i]);
			}
		}
		flowMap = pathFinding->createFlowMap(
			{
				pathA[pathA.size() - 1]
			},
			center,
			12.0f,
			12.0f,
			SceneConnector::RIGIDBODY_TYPEID_STATIC,
			pathA,
			false
		);
		auto flowMap2 = pathFinding->createFlowMap(
			{
				path[path.size() - 1]
			},
			center,
			12.0f,
			12.0f,
			SceneConnector::RIGIDBODY_TYPEID_STATIC,
			pathB,
			true
		);
		flowMap->merge(flowMap2);
		flowMap2->releaseReference();
	} else {
		flowMap = pathFinding->createFlowMap(
			{
				path[path.size() - 1]
			},
			center,
			12.0f,
			12.0f,
			SceneConnector::RIGIDBODY_TYPEID_STATIC,
			path,
			true
		);
	}
	{
		auto i = 0;
		while(true == true) {
			auto flowDirectionEntityId = "flowdirection." + to_string(i);
			if (engine->getEntity(flowDirectionEntityId) == nullptr) break;
			engine->removeEntity(flowDirectionEntityId);
			i++;
		}
	}
	{
		auto i = 0;
		while(true == true) {
			auto flowDirectionEntityId = "pathfindingnode." + to_string(i);
			if (engine->getEntity(flowDirectionEntityId) == nullptr) break;
			engine->removeEntity(flowDirectionEntityId);
			i++;
		}
	}
	if (flowMap == nullptr) return;

	// formation end
	{
		Quaternion formationRotationQuaternion;
		formationMovement = path.size() >= 2?path[path.size() - 1] - path[path.size() - 2]:Vector3(1.0f, 0.0f, 0.0f);
		if (formationMovement.computeLengthSquared() < Math::square(Math::EPSILON)) formationMovement = Vector3(1.0f, 0.0f, 0.0f);
		auto currentFormationYRotationAngle = Vector3::computeAngle(Vector3(0.0f, 0.0f, -1.0f), formationMovement.clone().normalize(), Vector3(0.0f, 1.0f, 0.0f));
		if (Float::isNaN(currentFormationYRotationAngle) == false) formationYRotationAngle = currentFormationYRotationAngle;
		formationRotationQuaternion.rotate(Vector3(0.0f, 1.0f, 0.0f), formationYRotationAngle);
		for (auto& combatUnit: combatUnits) {
			auto relativeFormationPosition = (combatUnitFormationTransformations[combatUnit.formationIdx].getTranslation() - combatUnitFormationTransformations[combatUnits[0].formationIdx].getTranslation());
			auto formationPosition = formationRotationQuaternion * relativeFormationPosition;
			combatUnit.endPosition = endPosition + formationPosition;
			combatUnit.pathIdx = 0;
		}
	}

	// draw flow map
	{
		auto i = 0;
		auto j = 0;
		for (auto z = -depth / 2; z <= depth / 2; z+= flowMap->getStepSize())
		for (auto x = -width / 2; x <= width / 2; x+= flowMap->getStepSize()) {
			auto cellPosition = Vector3(
				x + center.getX(),
				0.0f,
				z + center.getZ()
			);
			auto cell = flowMap->getCell(cellPosition.getX(), cellPosition.getZ());
			if (cell == nullptr) continue;
			{
				auto flowDirectionEntityId = "flowdirection." + to_string(i);
				auto yRotationAngle = Vector3::computeAngle(Vector3(0.0f, 0.0f, 1.0f), cell->getDirection(), Vector3(0.0f, 1.0f, 0.0f));
				auto cellObject = new Object3D(flowDirectionEntityId, emptyModel);
				cellObject->setScale(Vector3(0.5f, 0.5f, 0.5f));
				cellObject->setTranslation(cellPosition + Vector3(0.0f, 0.25f, 0.0f));
				cellObject->addRotation(Vector3(0.0f, 1.0f, 0.0f), yRotationAngle - 90.0f);
				cellObject->setDisableDepthTest(true);
				cellObject->setEffectColorMul(Color4(0.25f, 0.25f, 0.25f, 1.0f));
				cellObject->update();
				if (cell->hasMissingNeighborCell() == true) {
					cellObject->setEffectColorAdd(Color4(1.0f, 0.0f, 0.0f, 0.0f));
				}
				engine->addEntity(cellObject);
				i++;
			}
			/*
			{
				auto pathFindingNodeId = "pathfindingnode." + to_string(j);
				auto pathFindingNodeObject = new Object3D(pathFindingNodeId, emptyModel);
				pathFindingNodeObject->setScale(Vector3(2.0f, 2.0f, 2.0f));
				pathFindingNodeObject->setTranslation(flowMap->getPath()[cell->getPathIdx()] + Vector3(0.0f, 0.4f, 0.0f));
				pathFindingNodeObject->addRotation(Vector3(0.0f, 0.0f, 1.0f), 90.0f);
				pathFindingNodeObject->setDisableDepthTest(true);
				pathFindingNodeObject->setEffectColorMul(Color4(0.0f, 0.0f, 0.0f, 1.0f));
				pathFindingNodeObject->update();
				engine->addEntity(pathFindingNodeObject);
				j++;
			}
			*/
		}
	}
}

void FlowMapTest2::onChar(unsigned int key, int x, int y) {
	if (key == ' ') pause = pause == true?false:true;
}

void FlowMapTest2::onKeyDown (unsigned char key, int x, int y) {
}

void FlowMapTest2::onKeyUp(unsigned char key, int x, int y) {
}

void FlowMapTest2::onSpecialKeyDown (int key, int x, int y) {
}

void FlowMapTest2::onSpecialKeyUp(int key, int x, int y) {
}

void FlowMapTest2::onMouseDragged(int x, int y) {
}

void FlowMapTest2::onMouseMoved(int x, int y) {
}

void FlowMapTest2::onMouseButton(int button, int state, int x, int y) {
	if (state == MOUSE_BUTTON_UP) {
		mouseClicked = true;
		mouseClickPosition = { x, y };
	}
}

void FlowMapTest2::onMouseWheel(int button, int direction, int x, int y) {
}
