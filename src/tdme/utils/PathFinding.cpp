#include <tdme/utils/PathFinding.h>

#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <vector>

#include <tdme/engine/Transformations.h>
#include <tdme/engine/physics/Body.h>
#include <tdme/engine/physics/World.h>
#include <tdme/engine/primitives/BoundingVolume.h>
#include <tdme/engine/primitives/OrientedBoundingBox.h>
#include <tdme/math/Math.h>
#include <tdme/math/Vector3.h>
#include <tdme/utils/Console.h>
#include <tdme/utils/Float.h>
#include <tdme/utils/PathFindingCustomTest.h>
#include <tdme/utils/Time.h>

using std::map;
using std::reverse;
using std::stack;
using std::string;
using std::to_string;
using std::vector;

using tdme::engine::Transformations;
using tdme::engine::physics::World;
using tdme::engine::physics::Body;
using tdme::engine::primitives::BoundingVolume;
using tdme::engine::primitives::OrientedBoundingBox;
using tdme::math::Math;
using tdme::math::Vector3;
using tdme::utils::Console;
using tdme::utils::Float;
using tdme::utils::PathFindingCustomTest;
using tdme::utils::Time;

using tdme::utils::PathFinding;

PathFinding::PathFinding(World* world, bool sloping, int stepsMax, float actorHeight, float stepSize, float stepSizeLast, float actorStepUpMax, uint16_t skipOnCollisionTypeIds, int maxTries) {
	this->world = world;
	this->customTest = nullptr;
	this->sloping = sloping;
	this->actorBoundingVolume = nullptr;
	this->actorBoundingVolumeSlopeTest = nullptr;
	this->stepsMax = stepsMax;
	this->actorHeight = actorHeight;
	this->stepSize = stepSize;
	this->stepSizeLast = stepSizeLast;
	this->actorStepUpMax = actorStepUpMax;
	this->skipOnCollisionTypeIds = skipOnCollisionTypeIds;
	this->maxTries = maxTries;
	this->collisionTypeIds = 0;
}

PathFinding::~PathFinding() {
}

bool PathFinding::isWalkableInternal(float x, float y, float z, float& height, uint16_t collisionTypeIds, bool ignoreStepUpMax) {
	auto cacheId = toId(x, y, z) + ";" + to_string(collisionTypeIds) + ";" + to_string(ignoreStepUpMax);
	auto walkableCacheIt = walkableCache.find(cacheId);
	if (walkableCacheIt != walkableCache.end()) {
		height = walkableCacheIt->second;
		return height > -10000.0f;
	}
	auto walkable = isWalkable(x, y, z, height, collisionTypeIds, ignoreStepUpMax);
	if (walkable == false) return false;
	walkableCache[cacheId] = walkable == false?-10000.0f:height;
	return customTest == nullptr || customTest->isWalkable(this, x, height, z) == true;
}

bool PathFinding::isSlopeWalkableInternal(float x, float y, float z, float successorX, float successorY, float successorZ, uint16_t collisionTypeIds) {
	float slopeAngle = 0.0f;

	// slope angle and center
	auto toVector = Vector3(successorX, y, successorZ);
	auto fromVector = Vector3(x, y, z);
	auto axis = toVector.clone().sub(fromVector);
	auto center = axis.clone().scale(0.5f).add(fromVector).setY(y + 0.1f);
	axis.normalize();
	slopeAngle = Vector3::computeAngle(
		axis,
		Vector3(0.0f, 0.0f, -1.0f),
		Vector3(0.0f, 1.0f, 0.0f)
	);

	auto cacheId = toId(x, y, z) + ";" + to_string(collisionTypeIds) + ";slope;" + to_string(slopeAngle);
	auto walkableCacheIt = walkableCache.find(cacheId);
	if (walkableCacheIt != walkableCache.end()) {
		auto height = walkableCacheIt->second;
		return height > -10000.0f;
	}

	// set up transformations
	Transformations slopeTestTransformations;
	slopeTestTransformations.setTranslation(center);
	slopeTestTransformations.addRotation(Vector3(0.0f, 1.0f, 0.0f), slopeAngle);
	slopeTestTransformations.update();

	// update rigid body
	auto actorSlopeTestCollisionBody = world->getBody("tdme.pathfinding.actor.slopetest");
	actorSlopeTestCollisionBody->fromTransformations(slopeTestTransformations);

	// check if actor collides with world
	vector<Body*> collidedRigidBodies;
	auto walkable = world->doesCollideWith(collisionTypeIds == 0?this->collisionTypeIds:collisionTypeIds, actorSlopeTestCollisionBody, collidedRigidBodies) == false;
	walkableCache[cacheId] = walkable == false?-10000.0f:0.0f;
	return walkable;
}

bool PathFinding::isWalkable(float x, float y, float z, float& height, uint16_t collisionTypeIds, bool ignoreStepUpMax) {
	// determine y height of ground plate of actor bounding volume
	float _z = z - stepSize / 2.0f;
	height = -10000.0f;
	Vector3 actorPosition;
	for (auto i = 0; i < 2; i++) {
		float _x = x - stepSize / 2.0f;
		for (auto j = 0; j < 2; j++) {
			Vector3 actorPositionCandidate;
			auto body = world->determineHeight(
				collisionTypeIds == 0?this->collisionTypeIds:collisionTypeIds,
				ignoreStepUpMax == true?10000.0f:actorStepUpMax,
				actorPositionCandidate.set(_x, y, _z),
				actorPosition
			);
			if (body == nullptr || ((body->getCollisionTypeId() & skipOnCollisionTypeIds) != 0)) {
				return false;
			}
			if (actorPosition.getY() > height) height = actorPosition.getY();
			_x+= stepSize;
		}
		_z+= stepSize;
	}

	// set up transformations
	Transformations actorTransformations;
	actorTransformations.setTranslation(Vector3(x, height + 0.1f, z));
	actorTransformations.update();

	// update rigid body
	auto actorCollisionBody = world->getBody("tdme.pathfinding.actor");
	actorCollisionBody->fromTransformations(actorTransformations);

	// check if actor collides with world
	vector<Body*> collidedRigidBodies;
	return world->doesCollideWith(collisionTypeIds == 0?this->collisionTypeIds:collisionTypeIds, actorCollisionBody, collidedRigidBodies) == false;
}

void PathFinding::start(const Vector3& startPosition, const Vector3& endPosition) {
	// start node
	PathFindingNode start;
	start.position = startPosition;
	start.costsAll = 0.0f;
	start.costsReachPoint = 0.0f;
	start.costsEstimated = 0.0f;
	start.x = getIntegerPositionComponent(start.position.getX());
	start.y = 0;
	start.z = getIntegerPositionComponent(start.position.getZ());
	start.id = toId(
		start.position.getX(),
		start.position.getY(),
		start.position.getZ()
	);

	// end node
	end.position = endPosition;
	end.costsAll = 0.0f;
	end.costsReachPoint = 0.0f;
	end.costsEstimated = 0.0f;
	end.x = getIntegerPositionComponent(end.position.getX());
	end.y = 0;
	end.z = getIntegerPositionComponent(end.position.getZ());
	end.id = toId(
		end.position.getX(),
		end.position.getY(),
		end.position.getZ()
	);

	// end positions
	endPositions = { endPosition };

	// set up start node costs
	start.costsEstimated = computeDistanceToEnd(start);
	start.costsAll = start.costsEstimated;

	// put to open nodes
	openNodes[start.id] = start;
}

void PathFinding::step(const PathFindingNode& node, const set<string>* nodesToTestPtr, bool zeroHeightInId) {
	auto nodeId = node.id;

	// Find valid successors
	for (auto z = -1; z <= 1; z++)
	for (auto x = -1; x <= 1; x++)
	if ((z != 0 || x != 0) &&
		(sloping == true ||
		(Math::abs(x) == 1 && Math::abs(z) == 1) == false)) {
		auto successorX = static_cast<float>(x) * stepSize + (nodesToTestPtr != nullptr?static_cast<float>(node.x) * stepSize:node.position.getX());
		auto successorZ = static_cast<float>(z) * stepSize + (nodesToTestPtr != nullptr?static_cast<float>(node.z) * stepSize:node.position.getZ());
		if (nodesToTestPtr != nullptr) {
			auto successorNodeId = toIdInt(
				node.x + x,
				0,
				node.z + z
			);
			if (nodesToTestPtr->find(successorNodeId) == nodesToTestPtr->end()) continue;
		}
		auto slopeWalkable = Math::abs(x) == 1 && Math::abs(z) == 1?isSlopeWalkableInternal(node.position.getX(), node.position.getY(), node.position.getZ(), successorX, node.position.getY(), successorZ):true;
		//
		float yHeight;
		// first node or walkable?
		if (slopeWalkable == true && isWalkableInternal(successorX, node.position.getY(), successorZ, yHeight) == true) {
			// check if successor node equals previous node / node
			if (equals(node, successorX, yHeight, successorZ)) {
				continue;
			}
			// Add the node to the available sucessorNodes
			PathFindingNode successorNode;
			successorNode.position = Vector3(successorX, yHeight, successorZ);
			successorNode.costsAll = 0.0f;
			successorNode.costsReachPoint = 0.0f;
			successorNode.costsEstimated = 0.0f;
			successorNode.x = node.x + x;
			successorNode.y = zeroHeightInId == true?0:getIntegerPositionComponent(successorNode.position.getY());
			successorNode.z = node.z + z;
			successorNode.id = toIdInt(
				successorNode.x,
				successorNode.y,
				successorNode.z
			);
			// this should never happen, but still I like to check for it
			//if (successorNode.id == nodeId) {
			//	continue;
			//}
			successorNodes.push(successorNode);
		}
	}

	// Check successor nodes
	while (successorNodes.empty() == false) {
		auto& successorNode = successorNodes.top();

		// Compute successor node's costs by costs to reach nodes point and the computed distance from node to successor node
		float successorCostsReachPoint = node.costsReachPoint + computeDistance(successorNode, node);

		// Find sucessor node in open nodes list
		PathFindingNode* openListNode = nullptr;
		auto openListNodeIt = openNodes.find(successorNode.id);
		if (openListNodeIt != openNodes.end()) {
			openListNode = &openListNodeIt->second;
		}

		// found it in open nodes list
		if (openListNode != nullptr) {
			// is the node from open nodes less expensive, discard successor node
			if (openListNode->costsReachPoint <= successorCostsReachPoint) {
				// remove it from stack
				successorNodes.pop();
				// discard it
				continue;
			}
		}

		// Find successor node in closed nodes list
		PathFindingNode* closedListNode = nullptr;
		auto closedListNodeIt = closedNodes.find(successorNode.id);
		if (closedListNodeIt != closedNodes.end()) {
			closedListNode = &closedListNodeIt->second;
		}

		// found it in closed nodes list
		if (closedListNode != nullptr) {
			// is the node from closed nodes list less expensive, discard successor node
			if (closedListNode->costsReachPoint <= successorCostsReachPoint) {
				// remove it from stack
				successorNodes.pop();
				// discard it
				continue;
			}
		}

		// Sucessor node is the node with least cost to this point
		successorNode.previousNodeId = nodeId;
		successorNode.costsReachPoint = successorCostsReachPoint;
		successorNode.costsEstimated = computeDistanceToEnd(successorNode);
		successorNode.costsAll = successorNode.costsReachPoint + successorNode.costsEstimated;

		// Remove found node from open nodes list, since it was less optimal
		if (openListNode != nullptr) {
			// remove open list node
			openNodes.erase(openListNodeIt);
		}

		// Remove found node from closed nodes list, since it was less optimal
		if (closedListNode != nullptr) {
			closedNodes.erase(closedListNodeIt);
		}

		// Add successor node to open nodes list, as we might want to check its successors to find a path to the end
		openNodes[successorNode.id] = successorNode;

		// remove it from stack
		successorNodes.pop();
	}

	// add node to closed nodes list, as we checked its successors
	closedNodes[nodeId] = node;

	// Remove node from open nodes, as we checked its successors
	openNodes.erase(nodeId);
}

bool PathFinding::findPath(const Vector3& startPosition, const Vector3& endPosition, const uint16_t collisionTypeIds, vector<Vector3>& path, int alternativeEndSteps, PathFindingCustomTest* customTest) {
	// clear path
	path.clear();

	// equal start and end position?
	if (startPosition.equals(endPosition, 0.1f) == true) {
		if (VERBOSE == true) Console::println("PathFinding::findPath(): start position == end position! Exiting!");
		path.push_back(endPosition);
		return true;
	}

	//
	auto now = Time::getCurrentMillis();

	// set up custom test
	this->customTest = customTest;

	// initialize custom test
	if (this->customTest != nullptr) this->customTest->initialize();

	//
	this->collisionTypeIds = collisionTypeIds;

	// init bounding volume, transformations, collision body
	actorBoundingVolume = new OrientedBoundingBox(
		Vector3(0.0f, actorHeight / 2.0f, 0.0f),
		OrientedBoundingBox::AABB_AXIS_X,
		OrientedBoundingBox::AABB_AXIS_Y,
		OrientedBoundingBox::AABB_AXIS_Z,
		Vector3(stepSize, actorHeight / 2.0f, stepSize)
	);
	// set up transformations
	Transformations actorTransformations;
	actorTransformations.setTranslation(startPosition);
	actorTransformations.update();
	world->addCollisionBody("tdme.pathfinding.actor", true, 32768, actorTransformations, {actorBoundingVolume});

	// init bounding volume for slope testcollision body
	actorBoundingVolumeSlopeTest =	new OrientedBoundingBox(
		Vector3(0.0f, actorHeight / 2.0f, 0.0f),
		OrientedBoundingBox::AABB_AXIS_X,
		OrientedBoundingBox::AABB_AXIS_Y,
		OrientedBoundingBox::AABB_AXIS_Z,
		Vector3(stepSize * 1.5f, actorHeight / 2.0f, stepSize * 1.5f)
	);
	world->addCollisionBody("tdme.pathfinding.actor.slopetest", true, 32768, actorTransformations, {actorBoundingVolumeSlopeTest});

	// positions
	Vector3 startPositionComputed;
	startPositionComputed.set(startPosition);

	// compute possible end positions
	vector<Vector3> endPositionCandidates;
	{
		Vector3 forwardVector;
		Vector3 sideVector;
		forwardVector.set(endPosition).sub(startPositionComputed).setY(0.0f).normalize();
		Vector3::computeCrossProduct(forwardVector, Vector3(0.0f, 1.0f, 0.0f), sideVector).normalize();
		if (Float::isNaN(sideVector.getX()) ||
			Float::isNaN(sideVector.getY()) ||
			Float::isNaN(sideVector.getZ())) {
			endPositionCandidates.push_back(endPosition);
		} else {
			auto sideDistance = stepSize;
			auto forwardDistance = 0.0f;
			auto endYHeight = 0.0;
			auto i = 0;
			while (true == true) {
				endPositionCandidates.push_back(Vector3().set(sideVector).scale(0.0f).add(forwardVector.clone().scale(-forwardDistance)).add(endPosition));
				i++; if (i >= alternativeEndSteps) break;
				endPositionCandidates.push_back(Vector3().set(sideVector).scale(-sideDistance).add(forwardVector.clone().scale(-forwardDistance)).add(endPosition));
				i++; if (i >= alternativeEndSteps) break;
				endPositionCandidates.push_back(Vector3().set(sideVector).scale(+sideDistance).add(forwardVector.clone().scale(-forwardDistance)).add(endPosition));
				i++; if (i >= alternativeEndSteps) break;
				forwardDistance+= stepSize;
			}
		}
	}

	auto tries = 0;
	bool success = false;
	for (auto& endPositionCandidate: endPositionCandidates) {
		Vector3 endPositionComputed = endPositionCandidate;
		float endYHeight = endPositionComputed.getY();
		if (isWalkableInternal(
				endPositionComputed.getX(),
				endPositionComputed.getY(),
				endPositionComputed.getZ(),
				endYHeight,
				0,
				true
			) == false) {
			if (VERBOSE == true) {
				Console::println(
					"Not walkable: " +
					to_string(endPositionComputed.getX()) + ", " +
					to_string(endPositionComputed.getY()) + ", " +
					to_string(endPositionComputed.getZ()) + " / " +
					to_string(endYHeight)
				);
			}
			//
			continue;
		} else {
			endPositionComputed.setY(endYHeight);
		}

		if (VERBOSE == true) {
			Console::println(
				"Finding path: " +
				to_string(startPositionComputed.getX()) + ", " +
				to_string(startPositionComputed.getY()) + ", " +
				to_string(startPositionComputed.getZ()) + " --> " +
				to_string(endPositionComputed.getX()) + ", " +
				to_string(endPositionComputed.getY()) + ", " +
				to_string(endPositionComputed.getZ())
			);
		}

		// otherwise start path finding
		start(startPositionComputed, endPositionComputed);

		// do the steps
		bool done = false;
		for (auto stepIdx = 0; done == false && stepIdx < stepsMax; stepIdx++) {
			// check if there are still open nodes available
			if (openNodes.size() == 0) {
				done = true;
				break;
			}

			// Choose node from open nodes thats least expensive to check its successors
			PathFindingNode* nodePtr = nullptr;
			for (auto nodeIt = openNodes.begin(); nodeIt != openNodes.end(); ++nodeIt) {
				if (nodePtr == nullptr || nodeIt->second.costsAll < nodePtr->costsAll) nodePtr = &nodeIt->second;
			}

			//
			if (nodePtr == nullptr) {
				done = true;
				break;
			}
			const auto& node = *nodePtr;

			//
			if (equalsLastNode(node, end)) {
				end.previousNodeId = node.previousNodeId;
				// Console::println("PathFinding::findPath(): path found with steps: " + to_string(stepIdx));
				int nodesCount = 0;
				map<string, PathFindingNode>::iterator nodeIt;
				for (auto nodePtr = &end; nodePtr != nullptr; nodePtr = (nodeIt = closedNodes.find(nodePtr->previousNodeId)) != closedNodes.end()?&nodeIt->second:nullptr) {
					nodesCount++;
					// if (nodesCount > 0 && nodesCount % 100 == 0) {
					//	 Console::println("PathFinding::findPath(): compute path: steps: " + to_string(nodesCount) + " / " + to_string(path.size()) + ": " + to_string((uint64_t)node));
					// }
					if (Float::isNaN(nodePtr->position.getX()) ||
						Float::isNaN(nodePtr->position.getY()) ||
						Float::isNaN(nodePtr->position.getZ())) {
						Console::println("PathFinding::findPath(): compute path: step: NaN");
						done = true;
						break;
					}
					path.push_back(nodePtr->position);
				}
				reverse(path.begin(), path.end());
				if (path.size() > 1) path.erase(path.begin());
				if (path.size() == 0) {
					// Console::println("PathFinding::findPath(): path with 0 steps: Fixing!");
					path.push_back(endPositionComputed);
				}
				done = true;
				success = true;
				break;
			} else {
				// do a step
				step(node, nullptr, false);
			}
		}

		// reset
		openNodes.clear();
		closedNodes.clear();

		//
		tries++;

		//
		if (success == true || tries == maxTries) break;
	}

	//
	if (tries == 0) {
		if (VERBOSE == true) Console::println("PathFinding::findPath(): end position were not walkable!");
	}

	//
	/*
	if (stepIdx == stepsMax) {
		Console::println("PathFinding::findPath(): steps == stepsMax: " + to_string(stepIdx));
	}
	*/

	// unset actor bounding volume and remove rigid body
	this->actorBoundingVolume = nullptr;
	this->actorBoundingVolumeSlopeTest = nullptr;
	world->removeBody("tdme.pathfinding.actor");
	world->removeBody("tdme.pathfinding.actor.slopetest");

	//
	if (VERBOSE == true && tries > 1) Console::println("PathFinding::findPath(): time: " + to_string(Time::getCurrentMillis() - now) + "ms / " + to_string(tries) + " tries");

	// dispose custom test
	if (this->customTest != nullptr) {
		this->customTest->dispose();
		this->customTest = nullptr;
	}

	// return success
	return success;
}

FlowMap* PathFinding::createFlowMap(const vector<Vector3>& endPositions, const Vector3& center, float depth, float width, const uint16_t collisionTypeIds, const vector<Vector3>& path, PathFindingCustomTest* customTest) {
	this->endPositions = endPositions;

	// set up custom test
	this->customTest = customTest;

	// initialize custom test
	if (this->customTest != nullptr) this->customTest->initialize();

	//
	this->collisionTypeIds = collisionTypeIds;

	// init bounding volume, transformations, collision body
	actorBoundingVolume = new OrientedBoundingBox(
		Vector3(0.0f, actorHeight / 2.0f, 0.0f),
		OrientedBoundingBox::AABB_AXIS_X,
		OrientedBoundingBox::AABB_AXIS_Y,
		OrientedBoundingBox::AABB_AXIS_Z,
		Vector3(stepSize, actorHeight / 2.0f, stepSize)
	);
	// set up transformations
	Transformations actorTransformations;
	actorTransformations.setTranslation(endPositions[0]);
	actorTransformations.update();
	world->addCollisionBody("tdme.pathfinding.actor", true, 32768, actorTransformations, {actorBoundingVolume});

	// init bounding volume for slope testcollision body
	actorBoundingVolumeSlopeTest =	new OrientedBoundingBox(
		Vector3(0.0f, actorHeight / 2.0f, 0.0f),
		OrientedBoundingBox::AABB_AXIS_X,
		OrientedBoundingBox::AABB_AXIS_Y,
		OrientedBoundingBox::AABB_AXIS_Z,
		Vector3(stepSize * 1.5f, actorHeight / 2.0f, stepSize * 1.5f)
	);
	world->addCollisionBody("tdme.pathfinding.actor.slopetest", true, 32768, actorTransformations, {actorBoundingVolumeSlopeTest});

	//
	auto zMin = static_cast<int>(Math::ceil(-depth / 2.0f / stepSize));
	auto zMax = static_cast<int>(Math::ceil(depth / 2.0f / stepSize));
	auto xMin = static_cast<int>(Math::ceil(-width / 2.0f / stepSize));
	auto xMax = static_cast<int>(Math::ceil(width / 2.0f / stepSize));
	const vector<Vector3> emptyPath = { center };
	const vector<Vector3>& pathToUse = path.empty() == false?path:emptyPath;
	auto stepSize2 = stepSize + 0.01f;

	// based on path finding and
	//	see: https://howtorts.github.io/2014/01/04/basic-flow-fields.html
	// generate cost map via dijkstra

	// set up end position in costs map
	if (endPositions.size() == 0) {
		Console::println("PathFinding::createFlowMap(): no end positions given");
	}

	// add to open nodes
	auto startNodePosition = Vector3(
		alignPositionComponent(pathToUse[0].getX()),
		pathToUse[0].getY(),
		alignPositionComponent(pathToUse[0].getZ())
	);
	float nodeYHeight;
	isWalkableInternal(startNodePosition.getX(), startNodePosition.getY(), startNodePosition.getZ(), nodeYHeight);
	PathFindingNode node;
	node.position.set(startNodePosition).setY(nodeYHeight);
	node.costsAll = 0.0f;
	node.costsReachPoint = 0.0f;
	node.costsEstimated = 0.0f;
	node.x = getIntegerPositionComponent(startNodePosition.getX());
	node.y = 0;
	node.z = getIntegerPositionComponent(startNodePosition.getZ());
	node.id = toIdInt(node.x, node.y, node.z);

	// not in use in this case, this does not make sense, I still like it lol
	end = PathFindingNode();

	// set up start node costs
	node.costsEstimated = computeDistanceToEnd(node);
	node.costsAll = node.costsEstimated;

	// put to open nodes
	openNodes[node.id] = node;

	// nodes to test
	for (auto& _centerPathNode: pathToUse) {
		auto centerPathNode = Vector3(
			FlowMap::alignPositionComponent(_centerPathNode.getX(), stepSize),
			_centerPathNode.getY(),
			FlowMap::alignPositionComponent(_centerPathNode.getZ(), stepSize)
		);
		auto centerPathNodeX = FlowMap::getIntegerPositionComponent(centerPathNode.getX(), stepSize);
		auto centerPathNodeZ = FlowMap::getIntegerPositionComponent(centerPathNode.getZ(), stepSize);
		for (auto z = zMin; z <= zMax; z++) {
			for (auto x = xMin; x <= xMax; x++) {
				auto nodeId = toIdInt(
					centerPathNodeX + x,
					0,
					centerPathNodeZ + z
				);
				nodesToTest.insert(nodeId);
			}
		}
	}

	// Do A* on open nodes
	while (openNodes.size() > 0) {
		// Choose node from open nodes thats least expensive to check its successors
		PathFindingNode* nodePtr = nullptr;
		for (auto nodeIt = openNodes.begin(); nodeIt != openNodes.end(); ++nodeIt) {
			if (nodePtr == nullptr || nodeIt->second.costsAll < nodePtr->costsAll) nodePtr = &nodeIt->second;
		}
		if (nodePtr == nullptr) break;
		const auto& node = *nodePtr;

		// do a step
		step(node, &nodesToTest, true);
	}

	// clear nodes to test
	nodesToTest.clear();

	// generate flow map
	auto flowMap = new FlowMap(stepSize);
	for (auto& _centerPathNode: pathToUse) {
		auto centerPathNode = Vector3(
			FlowMap::alignPositionComponent(_centerPathNode.getX(), stepSize),
			_centerPathNode.getY(),
			FlowMap::alignPositionComponent(_centerPathNode.getZ(), stepSize)
		);
		auto centerPathNodeX = FlowMap::getIntegerPositionComponent(centerPathNode.getX(), stepSize);
		auto centerPathNodeZ = FlowMap::getIntegerPositionComponent(centerPathNode.getZ(), stepSize);
		for (auto z = zMin; z <= zMax; z++) {
			for (auto x = xMin; x <= xMax; x++) {
				auto cellPosition = Vector3(
					static_cast<float>(centerPathNodeX) * stepSize + static_cast<float>(x) * stepSize,
					0.0f,
					static_cast<float>(centerPathNodeZ) * stepSize + static_cast<float>(z) * stepSize
				);
				auto cellId = FlowMap::toIdInt(
					centerPathNodeX + x,
					centerPathNodeZ + z
				);
				auto nodeId = toIdInt(
					centerPathNodeX + x,
					0,
					centerPathNodeZ + z
				);

				// do we already have this cell?
				if (flowMap->hasCell(cellId) == true) continue;

				// walkable?
				auto nodeIt = closedNodes.find(nodeId);
				if (nodeIt == closedNodes.end()) {
					continue;
				}
				auto& node = nodeIt->second;
				// set y
				cellPosition.setY(node.position.getY());

				// check neighbours around our current cell
				PathFindingNode* minCostsNode = nullptr;
				auto minCosts = Float::MAX_VALUE;
				for (auto _z = -1; _z <= 1; _z++)
				for (auto _x = -1; _x <= 1; _x++)
				if (_z != 0 || _x != 0) {
					//
					auto neighbourNodeId = toIdInt(
						centerPathNodeX + x + _x,
						0,
						centerPathNodeZ + z + _z
					);
					// same node?
					if (neighbourNodeId == nodeId) continue;
					// do we have this cell?
					auto neighbourNodeIt = closedNodes.find(neighbourNodeId);
					if (neighbourNodeIt == closedNodes.end()) {
						// nope
						continue;
					} else {
						// yes && walkable
						auto& neighbourNode = neighbourNodeIt->second;
						if (minCostsNode == nullptr || neighbourNode.costsAll < minCosts) {
							minCostsNode = &neighbourNode;
							minCosts = neighbourNode.costsAll;
						}
					}
				}
				if (minCostsNode != nullptr) {
					auto direction = minCostsNode->position.clone().sub(node.position).setY(0.0f).normalize();
					if (Float::isNaN(direction.getX()) || Float::isNaN(direction.getY()) || Float::isNaN(direction.getZ())) {
						Console::println(
							minCostsNode->id + "; " +
							to_string(minCostsNode->position.getX()) + ", " +
							to_string(minCostsNode->position.getY()) + ", " +
							to_string(minCostsNode->position.getZ()) + " -> " +
							node.id + "; " +
							to_string(node.position.getX()) + ", " +
							to_string(node.position.getY()) + ", " +
							to_string(node.position.getZ()) + ": " +
							to_string(minCostsNode == &node) + "; " +
							to_string(cellPosition.getX()) + ", " +
							to_string(cellPosition.getY()) + ", " +
							to_string(cellPosition.getZ()) + "; " +
							cellId
						);
					}
					flowMap->addCell(
						cellId,
						cellPosition,
						true,
						direction
					);
				}
			}
		}
	}

	// reset
	openNodes.clear();
	closedNodes.clear();

	// do some post adjustments
	for (auto& _centerPathNode: pathToUse) {
		auto centerPathNode = Vector3(
			FlowMap::alignPositionComponent(_centerPathNode.getX(), stepSize),
			_centerPathNode.getY(),
			FlowMap::alignPositionComponent(_centerPathNode.getZ(), stepSize)
		);
		auto centerPathNodeX = FlowMap::getIntegerPositionComponent(centerPathNode.getX(), stepSize);
		auto centerPathNodeZ = FlowMap::getIntegerPositionComponent(centerPathNode.getZ(), stepSize);
		for (auto z = zMin; z <= zMax; z++) {
			for (auto x = xMin; x <= xMax; x++) {
				auto cellPosition = Vector3(
					static_cast<float>(centerPathNodeX) * stepSize + static_cast<float>(x) * stepSize,
					0.0f,
					static_cast<float>(centerPathNodeZ) * stepSize + static_cast<float>(z) * stepSize
				);
				auto cellId = FlowMap::toIdInt(
					centerPathNodeX + x,
					centerPathNodeZ + z
				);
				auto cell = flowMap->getCell(cellId);
				if (cell == nullptr) continue;
				auto topCell = flowMap->getCell(FlowMap::toIdInt(centerPathNodeX + x, centerPathNodeZ + z - 1));
				if (topCell == nullptr && Math::abs(cell->getDirection().getX()) > 0.0f && cell->getDirection().getZ() < 0.0f){
					cell->setDirection(cell->getDirection().clone().setZ(0.0f).normalize());
				}
				auto bottomCell = flowMap->getCell(FlowMap::toIdInt(centerPathNodeX + x, centerPathNodeZ + z + 1));
				if (bottomCell == nullptr && Math::abs(cell->getDirection().getX()) > 0.0f && cell->getDirection().getZ() > 0.0f){
					cell->setDirection(cell->getDirection().clone().setZ(0.0f).normalize());
				}
				auto leftCell = flowMap->getCell(FlowMap::toIdInt(centerPathNodeX + x - 1, centerPathNodeZ + z));
				if (leftCell == nullptr && cell->getDirection().getX() < 0.0f && Math::abs(cell->getDirection().getZ()) > 0.0f){
					cell->setDirection(cell->getDirection().clone().setX(0.0f).normalize());
				}
				auto rightCell = flowMap->getCell(FlowMap::toIdInt(centerPathNodeX + x + 1, centerPathNodeZ + z));
				if (rightCell == nullptr && cell->getDirection().getX() > 0.0f && Math::abs(cell->getDirection().getZ()) > 0.0f){
					cell->setDirection(cell->getDirection().clone().setX(0.0f).normalize());
				}
			}
		}
	}

	// unset actor bounding volume and remove rigid body
	this->actorBoundingVolume = nullptr;
	this->actorBoundingVolumeSlopeTest = nullptr;
	world->removeBody("tdme.pathfinding.actor");
	world->removeBody("tdme.pathfinding.actor.slopetest");

	// dispose custom test
	if (this->customTest != nullptr) {
		this->customTest->dispose();
		this->customTest = nullptr;
	}

	//
	return flowMap;
}
