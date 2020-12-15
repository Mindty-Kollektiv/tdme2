#include <tdme/engine/SceneConnector.h>

#if defined(_WIN32) && defined(_MSC_VER)
	#pragma warning(disable:4503)
#endif

#include <vector>
#include <map>
#include <string>

#include <tdme/tdme.h>
#include <tdme/audio/Audio.h>
#include <tdme/audio/Sound.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/Entity.h>
#include <tdme/engine/EntityHierarchy.h>
#include <tdme/engine/EnvironmentMapping.h>
#include <tdme/engine/FogParticleSystem.h>
#include <tdme/engine/Light.h>
#include <tdme/engine/LODObject3D.h>
#include <tdme/engine/Object3D.h>
#include <tdme/engine/Object3DModel.h>
#include <tdme/engine/Object3DRenderGroup.h>
#include <tdme/engine/ObjectParticleSystem.h>
#include <tdme/engine/ParticleSystemEntity.h>
#include <tdme/engine/ParticleSystemGroup.h>
#include <tdme/engine/PointsParticleSystem.h>
#include <tdme/engine/Transformations.h>
#include <tdme/engine/fileio/models/ModelReader.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/engine/model/Color4Base.h>
#include <tdme/engine/model/Model.h>
#include <tdme/utilities/ModelTools.h>
#include <tdme/engine/physics/Body.h>
#include <tdme/engine/physics/World.h>
#include <tdme/engine/primitives/ConvexMesh.h>
#include <tdme/engine/primitives/OrientedBoundingBox.h>
#include <tdme/engine/primitives/PrimitiveModel.h>
#include <tdme/engine/primitives/Sphere.h>
#include <tdme/engine/primitives/TerrainMesh.h>
#include <tdme/engine/subsystems/particlesystem/BoundingBoxParticleEmitter.h>
#include <tdme/engine/subsystems/particlesystem/CircleParticleEmitter.h>
#include <tdme/engine/subsystems/particlesystem/CircleParticleEmitterPlaneVelocity.h>
#include <tdme/engine/subsystems/particlesystem/PointParticleEmitter.h>
#include <tdme/engine/subsystems/particlesystem/SphereParticleEmitter.h>
#include <tdme/math/Math.h>
#include <tdme/math/Vector3.h>
#include <tdme/math/Vector4.h>
#include <tdme/engine/fileio/prototypes/PrototypeReader.h>
#include <tdme/engine/fileio/ProgressCallback.h>
#include <tdme/engine/prototype/Prototype.h>
#include <tdme/engine/prototype/Prototype_EntityType.h>
#include <tdme/engine/prototype/PrototypeAudio.h>
#include <tdme/engine/prototype/PrototypeBoundingVolume.h>
#include <tdme/engine/prototype/PrototypeLODLevel.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_BoundingBoxParticleEmitter.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_CircleParticleEmitter.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_CircleParticleEmitterPlaneVelocity.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_Emitter.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_FogParticleSystem.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_ObjectParticleSystem.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_PointParticleEmitter.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_PointParticleSystem.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_SphereParticleEmitter.h>
#include <tdme/engine/prototype/PrototypeParticleSystem_Type.h>
#include <tdme/engine/prototype/PrototypeParticleSystem.h>
#include <tdme/engine/prototype/PrototypePhysics.h>
#include <tdme/engine/prototype/PrototypePhysics_BodyType.h>
#include <tdme/engine/scene/Scene.h>
#include <tdme/engine/scene/SceneLight.h>
#include <tdme/engine/scene/SceneEntity.h>
#include <tdme/engine/prototype/PrototypeProperties.h>
#include <tdme/engine/prototype/PrototypeProperty.h>
#include <tdme/tools/shared/tools/Tools.h>
#include <tdme/utilities/MutableString.h>
#include <tdme/utilities/StringTools.h>
#include <tdme/utilities/Console.h>

using std::map;
using std::vector;
using std::string;
using std::to_string;

using tdme::engine::SceneConnector;

using tdme::audio::Audio;
using tdme::audio::Sound;
using tdme::engine::Engine;
using tdme::engine::Entity;
using tdme::engine::EntityHierarchy;
using tdme::engine::EnvironmentMapping;
using tdme::engine::FogParticleSystem;
using tdme::engine::Light;
using tdme::engine::LODObject3D;
using tdme::engine::Object3D;
using tdme::engine::Object3DModel;
using tdme::engine::Object3DRenderGroup;
using tdme::engine::ObjectParticleSystem;
using tdme::engine::ParticleSystemEntity;
using tdme::engine::ParticleSystemGroup;
using tdme::engine::PointsParticleSystem;
using tdme::engine::Transformations;
using tdme::engine::fileio::models::ModelReader;
using tdme::engine::model::Color4;
using tdme::engine::model::Color4Base;
using tdme::engine::model::Model;
using tdme::utilities::ModelTools;
using tdme::engine::physics::Body;
using tdme::engine::physics::World;
using tdme::engine::primitives::ConvexMesh;
using tdme::engine::primitives::OrientedBoundingBox;
using tdme::engine::primitives::PrimitiveModel;
using tdme::engine::primitives::Sphere;
using tdme::engine::primitives::TerrainMesh;
using tdme::engine::subsystems::particlesystem::BoundingBoxParticleEmitter;
using tdme::engine::subsystems::particlesystem::CircleParticleEmitter;
using tdme::engine::subsystems::particlesystem::CircleParticleEmitterPlaneVelocity;
using tdme::engine::subsystems::particlesystem::PointParticleEmitter;
using tdme::engine::subsystems::particlesystem::SphereParticleEmitter;
using tdme::math::Math;
using tdme::math::Vector3;
using tdme::math::Vector4;
using tdme::engine::fileio::prototypes::PrototypeReader;
using tdme::engine::fileio::ProgressCallback;
using tdme::engine::prototype::Prototype;
using tdme::engine::prototype::Prototype_EntityType;
using tdme::engine::prototype::PrototypeAudio;
using tdme::engine::prototype::PrototypeBoundingVolume;
using tdme::engine::prototype::PrototypeParticleSystem_BoundingBoxParticleEmitter;
using tdme::engine::prototype::PrototypeParticleSystem_CircleParticleEmitter;
using tdme::engine::prototype::PrototypeParticleSystem_CircleParticleEmitterPlaneVelocity;
using tdme::engine::prototype::PrototypeParticleSystem_Emitter;
using tdme::engine::prototype::PrototypeParticleSystem_FogParticleSystem;
using tdme::engine::prototype::PrototypeParticleSystem_ObjectParticleSystem;
using tdme::engine::prototype::PrototypeParticleSystem_PointParticleEmitter;
using tdme::engine::prototype::PrototypeParticleSystem_PointParticleSystem;
using tdme::engine::prototype::PrototypeParticleSystem_SphereParticleEmitter;
using tdme::engine::prototype::PrototypeParticleSystem_Type;
using tdme::engine::prototype::PrototypeParticleSystem;
using tdme::engine::prototype::PrototypePhysics;
using tdme::engine::prototype::PrototypePhysics_BodyType;
using tdme::engine::scene::Scene;
using tdme::engine::scene::SceneLight;
using tdme::engine::scene::SceneEntity;
using tdme::engine::prototype::PrototypeProperties;
using tdme::engine::prototype::PrototypeProperty;
using tdme::tools::shared::tools::Tools;
using tdme::utilities::MutableString;
using tdme::utilities::StringTools;
using tdme::utilities::Console;

Model* SceneConnector::emptyModel = nullptr;
float SceneConnector::renderGroupsPartitionWidth = 64.0f;
float SceneConnector::renderGroupsPartitionHeight = 64.0f;
float SceneConnector::renderGroupsPartitionDepth = 64.0f;
int SceneConnector::renderGroupsReduceBy = 1;
int SceneConnector::renderGroupsLODLevels = 3;
float SceneConnector::renderGroupsLOD2MinDistance = 25.0;
float SceneConnector::renderGroupsLOD3MinDistance = 50.0;
int SceneConnector::renderGroupsLOD2ReduceBy = 4;
int SceneConnector::renderGroupsLOD3ReduceBy = 16;
bool SceneConnector::enableEarlyZRejection = false;

void SceneConnector::setLights(Engine* engine, Scene& level, const Vector3& translation)
{
	for (auto i = 0; i < Engine::LIGHTS_MAX && i < level.getLightCount(); i++) {
		engine->getLightAt(i)->setAmbient(Color4(level.getLightAt(i)->getAmbient()));
		engine->getLightAt(i)->setDiffuse(Color4(level.getLightAt(i)->getDiffuse()));
		engine->getLightAt(i)->setSpecular(Color4(level.getLightAt(i)->getSpecular()));
		engine->getLightAt(i)->setSpotDirection(level.getLightAt(i)->getSpotDirection());
		engine->getLightAt(i)->setSpotExponent(level.getLightAt(i)->getSpotExponent());
		engine->getLightAt(i)->setSpotCutOff(level.getLightAt(i)->getSpotCutOff());
		engine->getLightAt(i)->setConstantAttenuation(level.getLightAt(i)->getConstantAttenuation());
		engine->getLightAt(i)->setLinearAttenuation(level.getLightAt(i)->getLinearAttenuation());
		engine->getLightAt(i)->setQuadraticAttenuation(level.getLightAt(i)->getQuadraticAttenuation());
		engine->getLightAt(i)->setEnabled(level.getLightAt(i)->isEnabled());
		engine->getLightAt(i)->setPosition(
			Vector4(
				level.getLightAt(i)->getPosition().getX() + translation.getX(),
				level.getLightAt(i)->getPosition().getY() + translation.getY(),
				level.getLightAt(i)->getPosition().getZ() + translation.getZ(),
				1.0f
			)
		);
	}
}

Entity* SceneConnector::createParticleSystem(PrototypeParticleSystem* particleSystem, const string& id, bool enableDynamicShadows)
{
	ParticleEmitter* engineEmitter = nullptr;
	{
		auto v = particleSystem->getEmitter();
		if (v == PrototypeParticleSystem_Emitter::NONE) {
			return nullptr;
		} else
		if (v == PrototypeParticleSystem_Emitter::POINT_PARTICLE_EMITTER) {
			auto emitter = particleSystem->getPointParticleEmitter();
			engineEmitter = new PointParticleEmitter(emitter->getCount(), emitter->getLifeTime(), emitter->getLifeTimeRnd(), emitter->getMass(), emitter->getMassRnd(), emitter->getPosition(), emitter->getVelocity(), emitter->getVelocityRnd(), emitter->getColorStart(), emitter->getColorEnd());
		} else
		if (v == PrototypeParticleSystem_Emitter::BOUNDINGBOX_PARTICLE_EMITTER) {
			auto emitter = particleSystem->getBoundingBoxParticleEmitters();
			engineEmitter = new BoundingBoxParticleEmitter(emitter->getCount(), emitter->getLifeTime(), emitter->getLifeTimeRnd(), emitter->getMass(), emitter->getMassRnd(), new OrientedBoundingBox(emitter->getObbCenter(), emitter->getObbAxis0(), emitter->getObbAxis1(), emitter->getObbAxis2(), emitter->getObbHalfextension()), emitter->getVelocity(), emitter->getVelocityRnd(), emitter->getColorStart(), emitter->getColorEnd());
		} else
		if (v == PrototypeParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER) {
			auto emitter = particleSystem->getCircleParticleEmitter();
			engineEmitter = new CircleParticleEmitter(emitter->getCount(), emitter->getLifeTime(), emitter->getLifeTimeRnd(), emitter->getAxis0(), emitter->getAxis1(), emitter->getCenter(), emitter->getRadius(), emitter->getMass(), emitter->getMassRnd(), emitter->getVelocity(), emitter->getVelocityRnd(), emitter->getColorStart(), emitter->getColorEnd());
		} else
		if (v == PrototypeParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER_PLANE_VELOCITY) {
			auto emitter = particleSystem->getCircleParticleEmitterPlaneVelocity();
			engineEmitter = new CircleParticleEmitterPlaneVelocity(emitter->getCount(), emitter->getLifeTime(), emitter->getLifeTimeRnd(), emitter->getAxis0(), emitter->getAxis1(), emitter->getCenter(), emitter->getRadius(), emitter->getMass(), emitter->getMassRnd(), emitter->getVelocity(), emitter->getVelocityRnd(), emitter->getColorStart(), emitter->getColorEnd());
		} else
		if (v == PrototypeParticleSystem_Emitter::SPHERE_PARTICLE_EMITTER) {
			auto emitter = particleSystem->getSphereParticleEmitter();
			engineEmitter = new SphereParticleEmitter(emitter->getCount(), emitter->getLifeTime(), emitter->getLifeTimeRnd(), emitter->getMass(), emitter->getMassRnd(), new Sphere(emitter->getCenter(), emitter->getRadius()), emitter->getVelocity(), emitter->getVelocityRnd(), emitter->getColorStart(), emitter->getColorEnd());
		} else {
			Console::println(
				string(
					"SceneConnector::createParticleSystem(): unknown particle system emitter '" +
					particleSystem->getEmitter()->getName() +
					"'"
				)
			);
			return nullptr;
		}
	}

	{
		{
			auto v = particleSystem->getType();
			if (v == PrototypeParticleSystem_Type::NONE) {
				return nullptr;
			} else
			if (v == PrototypeParticleSystem_Type::OBJECT_PARTICLE_SYSTEM) {
				auto objectParticleSystem = particleSystem->getObjectParticleSystem();
				if (objectParticleSystem->getModel() == nullptr) return nullptr;

				return new ObjectParticleSystem(
					id,
					objectParticleSystem->getModel(),
					objectParticleSystem->getScale(),
					objectParticleSystem->isAutoEmit(),
					enableDynamicShadows,
					enableDynamicShadows,
					objectParticleSystem->getMaxCount(),
					engineEmitter
				);
			} else
			if (v == PrototypeParticleSystem_Type::POINT_PARTICLE_SYSTEM) {
				auto pointParticleSystem = particleSystem->getPointParticleSystem();
				return new PointsParticleSystem(
					id,
					engineEmitter,
					pointParticleSystem->getMaxPoints(),
					pointParticleSystem->getPointSize(),
					pointParticleSystem->isAutoEmit(),
					pointParticleSystem->getTexture(),
					pointParticleSystem->getTextureHorizontalSprites(),
					pointParticleSystem->getTextureVerticalSprites(),
					pointParticleSystem->getTextureSpritesFPS()
				);
			} else
			if (v == PrototypeParticleSystem_Type::FOG_PARTICLE_SYSTEM) {
				auto fogParticleSystem = particleSystem->getFogParticleSystem();
				return new FogParticleSystem(
					id,
					engineEmitter,
					fogParticleSystem->getMaxPoints(),
					fogParticleSystem->getPointSize(),
					fogParticleSystem->getTexture(),
					fogParticleSystem->getTextureHorizontalSprites(),
					fogParticleSystem->getTextureVerticalSprites(),
					fogParticleSystem->getTextureSpritesFPS()
				);
			} else {
				Console::println(
					string(
						"SceneConnector::createParticleSystem(): unknown particle system type '" +
						particleSystem->getType()->getName() +
						"'"
					)
				);
				return nullptr;
			}
		}
	}

}

Entity* SceneConnector::createEmpty(const string& id, const Transformations& transformations) {
	if (emptyModel == nullptr) {
		emptyModel = ModelReader::read("resources/engine/tools/leveleditor/models", "empty.dae");
	}
	auto entity = new Object3D(
		id,
		SceneConnector::emptyModel
	);
	entity->fromTransformations(transformations);
	return entity;
}

Entity* SceneConnector::createEntity(Prototype* prototype, const string& id, const Transformations& transformations, int instances) {
	Entity* entity = nullptr;

	// objects
	if (prototype->getModel() != nullptr) {
		auto lodLevel2 = prototype->getLODLevel2();
		auto lodLevel3 = prototype->getLODLevel3();
		// with LOD
		if (lodLevel2 != nullptr) {
			entity = new LODObject3D(
				id,
				prototype->getModel(),
				lodLevel2->getType(),
				lodLevel2->getMinDistance(),
				lodLevel2->getModel(),
				lodLevel3 != nullptr?lodLevel3->getType():LODObject3D::LODLEVELTYPE_NONE,
				lodLevel3 != nullptr?lodLevel3->getMinDistance():0.0f,
				lodLevel3 != nullptr?lodLevel3->getModel():nullptr
			);
			auto lodObject = dynamic_cast<LODObject3D*>(entity);
			lodObject->setEffectColorAddLOD2(lodLevel2->getColorAdd());
			lodObject->setEffectColorMulLOD2(lodLevel2->getColorMul());
			if (lodLevel3 != nullptr) {
				lodObject->setEffectColorAddLOD3(lodLevel3->getColorAdd());
				lodObject->setEffectColorMulLOD3(lodLevel3->getColorMul());
			}
			if (prototype->getShader() == "water" || prototype->getShader() == "pbr-water") lodObject->setRenderPass(Entity::RENDERPASS_WATER);
			lodObject->setShader(prototype->getShader());
			lodObject->setDistanceShader(prototype->getDistanceShader());
			lodObject->setDistanceShaderDistance(prototype->getDistanceShaderDistance());
		} else {
			// single
			entity = new Object3D(
				id,
				prototype->getModel(),
				instances
			);
			auto object = dynamic_cast<Object3D*>(entity);
			if (prototype->getShader() == "water" || prototype->getShader() == "pbr-water") object->setRenderPass(Entity::RENDERPASS_WATER);
			object->setShader(prototype->getShader());
			object->setDistanceShader(prototype->getDistanceShader());
			object->setDistanceShaderDistance(prototype->getDistanceShaderDistance());
			if (enableEarlyZRejection == true && prototype->isTerrainMesh() == true) {
				object->setEnableEarlyZRejection(true);
			}
		}
	} else
	// particle system
	if (prototype->getType() == Prototype_EntityType::PARTICLESYSTEM) {
		vector<ParticleSystemEntity*> particleSystems;
		for (auto i = 0; i < prototype->getParticleSystemsCount(); i++) {
			auto particleSystem = createParticleSystem(
				prototype->getParticleSystemAt(i),
				id + (i == 0?"":"." + to_string(i)),
				true
			);
			if (particleSystem != nullptr) particleSystems.push_back(dynamic_cast<ParticleSystemEntity*>(particleSystem));
		}
		if (particleSystems.size() == 1) {
			entity = dynamic_cast<Entity*>(particleSystems[0]);
		} else
		if (particleSystems.size() > 1) {
			entity = new ParticleSystemGroup(
				id,
				true,
				true,
				true,
				particleSystems
			);
		}
	} else
	// trigger/environment mapping
	if (prototype->getType() == Prototype_EntityType::TRIGGER ||
		prototype->getType() == Prototype_EntityType::ENVIRONMENTMAPPING) {
		// bounding volumes
		auto entityBoundingVolumesHierarchy = new EntityHierarchy(id);
		for (auto i = 0; i < prototype->getBoundingVolumeCount(); i++) {
			auto entityBoundingVolume = prototype->getBoundingVolume(i);
			if (entityBoundingVolume->getModel() != nullptr) {
				auto bvObject = new Object3D(Prototype::MODEL_BOUNDINGVOLUME_IDS[i], entityBoundingVolume->getModel());
				bvObject->setRenderPass(Entity::RENDERPASS_POST_POSTPROCESSING);
				entityBoundingVolumesHierarchy->addEntity(bvObject);
			}
		}
		if (prototype->getType() == Prototype_EntityType::ENVIRONMENTMAPPING &&
			prototype->getBoundingVolumeCount() == 1 &&
			dynamic_cast<OrientedBoundingBox*>(prototype->getBoundingVolume(0)->getBoundingVolume()) != nullptr) {
			BoundingBox aabb(dynamic_cast<OrientedBoundingBox*>(prototype->getBoundingVolume(0)->getBoundingVolume()));
			auto environmentMapping = new EnvironmentMapping("environmentmapping", Engine::getEnvironmentMappingWidth(), Engine::getEnvironmentMappingHeight(), aabb);
			environmentMapping->setRenderPassMask(prototype->getEnvironmentMapRenderPassMask());
			environmentMapping->setTimeRenderUpdateFrequency(prototype->getEnvironmentMapTimeRenderUpdateFrequency());
			entityBoundingVolumesHierarchy->addEntity(environmentMapping);
		}
		entityBoundingVolumesHierarchy->update();
		if (entityBoundingVolumesHierarchy->getEntities().size() == 0) {
			entityBoundingVolumesHierarchy->dispose();
			delete entityBoundingVolumesHierarchy;
		} else {
			entity = entityBoundingVolumesHierarchy;
		}
	}

	//
	if (entity != nullptr) {
		if (prototype->isTerrainMesh() == true) {
			entity->setRenderPass(Entity::RENDERPASS_TERRAIN);
		}
		entity->setContributesShadows(prototype->isContributesShadows());
		entity->setReceivesShadows(prototype->isReceivesShadows());
		entity->fromTransformations(transformations);
	}

	// done
	return entity;
}

Entity* SceneConnector::createEntity(SceneEntity* sceneEntity, const Vector3& translation) {
	Transformations transformations;
	transformations.fromTransformations(sceneEntity->getTransformations());
	if (translation.equals(Vector3()) == false) {
		transformations.setTranslation(transformations.getTranslation().clone().add(translation));
		transformations.update();
	}
	return createEntity(sceneEntity->getEntity(), sceneEntity->getId(), transformations);
}

void SceneConnector::addScene(Engine* engine, Scene& scene, bool addEmpties, bool addTrigger, bool addEnvironmentMapping, bool pickable, bool enable, const Vector3& translation, ProgressCallback* progressCallback)
{
	if (progressCallback != nullptr) progressCallback->progress(0.0f);
	map<string, map<string, map<string, vector<Transformations*>>>> renderGroupEntitiesByShaderPartitionModel;
	map<string, Prototype*> renderGroupLevelEditorEntities;
	auto progressStepCurrent = 0;
	for (auto i = 0; i < scene.getEntityCount(); i++) {
		auto object = scene.getEntityAt(i);

		if (progressCallback != nullptr && progressStepCurrent % 1000 == 0) progressCallback->progress(0.0f + static_cast<float>(progressStepCurrent) / static_cast<float>(scene.getEntityCount()) * 0.5f);
		progressStepCurrent++;

		if (addEmpties == false && object->getEntity()->getType() == Prototype_EntityType::EMPTY) continue;
		if (addTrigger == false && object->getEntity()->getType() == Prototype_EntityType::TRIGGER) continue;

		if (object->getEntity()->isRenderGroups() == true) {
			auto minX = object->getTransformations().getTranslation().getX();
			auto minY = object->getTransformations().getTranslation().getY();
			auto minZ = object->getTransformations().getTranslation().getZ();
			auto partitionX = (int)(minX / renderGroupsPartitionWidth);
			auto partitionY = (int)(minY / renderGroupsPartitionHeight);
			auto partitionZ = (int)(minZ / renderGroupsPartitionDepth);
			renderGroupLevelEditorEntities[object->getEntity()->getModel()->getId()] = object->getEntity();
			renderGroupEntitiesByShaderPartitionModel[object->getEntity()->getShader() + "." + object->getEntity()->getDistanceShader() + "." + to_string(static_cast<int>(object->getEntity()->getDistanceShaderDistance() / 10.0f))][to_string(partitionX) + "," + to_string(partitionY) + "," + to_string(partitionZ)][object->getEntity()->getModel()->getId()].push_back(&object->getTransformations());
		} else {
			Entity* entity = createEntity(object);
			if (entity == nullptr) continue;

			entity->setTranslation(entity->getTranslation().clone().add(translation));
			entity->setPickable(pickable);
			entity->setContributesShadows(object->getEntity()->isContributesShadows());
			entity->setReceivesShadows(object->getEntity()->isReceivesShadows());
			if (object->getEntity()->getType() == Prototype_EntityType::EMPTY) {
				entity->setScale(Vector3(Math::sign(entity->getScale().getX()), Math::sign(entity->getScale().getY()), Math::sign(entity->getScale().getZ())));
			}
			if (object->getEntity()->getType()->hasNonEditScaleDownMode() == true) {
				entity->setScale(
					object->getEntity()->getType()->getNonEditScaleDownModeDimension().
					clone().
					scale(
						Vector3(
							1.0f / (object->getTransformations().getScale().getX() * entity->getBoundingBox()->getDimensions().getX()),
							1.0f / (object->getTransformations().getScale().getY() * entity->getBoundingBox()->getDimensions().getY()),
							1.0f / (object->getTransformations().getScale().getZ() * entity->getBoundingBox()->getDimensions().getZ())
						)
					)
				);
			}
			entity->update();
			entity->setEnabled(enable);

			auto object3D = dynamic_cast<Object3D*>(entity);
			if (object3D != nullptr) object3D->setReflectionEnvironmentMappingId(object->getReflectionEnvironmentMappingId());

			engine->addEntity(entity);
		}
	}

	// do render nodes
	auto renderNodeIdx = 0;
	progressStepCurrent = 0;
	auto progressStepMax = 0;
	if (progressCallback != nullptr) {
		for (auto& itShader: renderGroupEntitiesByShaderPartitionModel) {
			for (auto& itPartition: itShader.second) {
				for (auto& itModel: itPartition.second) {
					progressStepMax++;
				}
			}
		}
	}
	for (auto& itShader: renderGroupEntitiesByShaderPartitionModel) {
		Console::println("SceneConnector::addLevel(): adding render group: " + itShader.first);
		for (auto& itPartition: itShader.second) {
			auto object3DRenderNode = new Object3DRenderGroup(
				"tdme.rendernode." + itPartition.first + "." + to_string(renderNodeIdx++),
				renderGroupsLODLevels,
				renderGroupsLOD2MinDistance,
				renderGroupsLOD3MinDistance,
				renderGroupsLOD2ReduceBy,
				renderGroupsLOD3ReduceBy
			);
			for (auto& itModel: itPartition.second) {
				if (progressCallback != nullptr) {
					progressCallback->progress(0.5f + static_cast<float>(progressStepCurrent) / static_cast<float>(progressStepMax) * 0.5f);
				}
				progressStepCurrent++;
				auto levelEditorEntity = renderGroupLevelEditorEntities[itModel.first];
				object3DRenderNode->setShader(levelEditorEntity->getShader());
				object3DRenderNode->setDistanceShader(levelEditorEntity->getDistanceShader());
				object3DRenderNode->setDistanceShaderDistance(levelEditorEntity->getDistanceShaderDistance());
				auto objectIdx = -1;
				for (auto transformation: itModel.second) {
					objectIdx++;
					if (objectIdx % renderGroupsReduceBy != 0) continue;
					object3DRenderNode->addObject(levelEditorEntity->getModel(), *transformation);
				}
			}
			object3DRenderNode->updateRenderGroup();
			engine->addEntity(object3DRenderNode);
		}
	}

	//
	if (progressCallback != nullptr) {
		progressCallback->progress(1.0f);
		delete progressCallback;
	}
}

Body* SceneConnector::createBody(World* world, Prototype* prototype, const string& id, const Transformations& transformations, uint16_t collisionTypeId, int index, PrototypePhysics_BodyType* overrideType) {
	if (prototype->getType() == Prototype_EntityType::EMPTY) return nullptr;

	auto physicsType = overrideType != nullptr?overrideType:prototype->getPhysics()->getType();
	if (prototype->getType() == Prototype_EntityType::TRIGGER) {
		vector<BoundingVolume*> boundingVolumes;
		for (auto j = 0; j < prototype->getBoundingVolumeCount(); j++) {
			auto entityBv = prototype->getBoundingVolume(j);
			if (index == -1 || index == j) boundingVolumes.push_back(entityBv->getBoundingVolume());
		}
		if (boundingVolumes.size() == 0) return nullptr;
		return world->addCollisionBody(
			id,
			true,
			collisionTypeId == 0?RIGIDBODY_TYPEID_TRIGGER:collisionTypeId,
			transformations,
			boundingVolumes
		);
	} else
	if (prototype->getType() == Prototype_EntityType::MODEL &&
		prototype->isTerrainMesh() == true) {
		Object3DModel terrainModel(prototype->getModel());
		auto terrainMesh = new TerrainMesh(&terrainModel, transformations);
		if (physicsType == PrototypePhysics_BodyType::COLLISION_BODY) {
			return world->addCollisionBody(
				id,
				true,
				collisionTypeId == 0?RIGIDBODY_TYPEID_COLLISION:collisionTypeId,
				Transformations(),
				{terrainMesh}
			);
		} else
		if (physicsType == PrototypePhysics_BodyType::STATIC_RIGIDBODY) {
			return world->addStaticRigidBody(
				id,
				true,
				collisionTypeId == 0?RIGIDBODY_TYPEID_STATIC:collisionTypeId,
				Transformations(),
				prototype->getPhysics()->getFriction(),
				{terrainMesh}
			);
		} else
		if (physicsType == PrototypePhysics_BodyType::DYNAMIC_RIGIDBODY) {
			return world->addRigidBody(
				id,
				true,
				collisionTypeId == 0?RIGIDBODY_TYPEID_DYNAMIC:collisionTypeId,
				Transformations(),
				prototype->getPhysics()->getRestitution(),
				prototype->getPhysics()->getFriction(),
				prototype->getPhysics()->getMass(),
				prototype->getPhysics()->getInertiaTensor(),
				{terrainMesh}
			);
		}
	} else {
		vector<BoundingVolume*> boundingVolumes;
		for (auto j = 0; j < prototype->getBoundingVolumeCount(); j++) {
			auto entityBv = prototype->getBoundingVolume(j);
			if (index == -1 || index == j) boundingVolumes.push_back(entityBv->getBoundingVolume());
		}
		if (boundingVolumes.size() == 0) return nullptr;
		if (physicsType == PrototypePhysics_BodyType::COLLISION_BODY) {
			return world->addCollisionBody(
				id,
				true,
				collisionTypeId == 0?RIGIDBODY_TYPEID_COLLISION:collisionTypeId,
				transformations,
				boundingVolumes
			);
		} else
		if (physicsType == PrototypePhysics_BodyType::STATIC_RIGIDBODY) {
			return world->addStaticRigidBody(
				id,
				true,
				collisionTypeId == 0?RIGIDBODY_TYPEID_STATIC:collisionTypeId,
				transformations,
				prototype->getPhysics()->getFriction(),
				boundingVolumes
			);
		} else
		if (physicsType == PrototypePhysics_BodyType::DYNAMIC_RIGIDBODY) {
			return world->addRigidBody(
				id,
				true,
				collisionTypeId == 0?RIGIDBODY_TYPEID_DYNAMIC:collisionTypeId,
				transformations,
				prototype->getPhysics()->getRestitution(),
				prototype->getPhysics()->getFriction(),
				prototype->getPhysics()->getMass(),
				prototype->getPhysics()->getInertiaTensor(),
				boundingVolumes
			);
		}
	}
	return nullptr;
}

Body* SceneConnector::createBody(World* world, SceneEntity* sceneEntity, const Vector3& translation, uint16_t collisionTypeId, int index, PrototypePhysics_BodyType* overrideType) {
	Transformations transformations;
	transformations.fromTransformations(sceneEntity->getTransformations());
	if (translation.equals(Vector3()) == false) {
		transformations.setTranslation(transformations.getTranslation().clone().add(translation));
		transformations.update();
	}
	return createBody(world, sceneEntity->getEntity(), sceneEntity->getId(), transformations, collisionTypeId, index, overrideType);
}

void SceneConnector::addScene(World* world, Scene& scene, bool enable, const Vector3& translation, ProgressCallback* progressCallback)
{
	if (progressCallback != nullptr) progressCallback->progress(0.0f);
	auto progressStepCurrent = 0;

	//
	for (auto i = 0; i < scene.getEntityCount(); i++) {
		auto levelEditorObject = scene.getEntityAt(i);

		//
		if (progressCallback != nullptr && progressStepCurrent % 1000 == 0) progressCallback->progress(0.0f + static_cast<float>(progressStepCurrent) / static_cast<float>(scene.getEntityCount()) * 1.0f);
		progressStepCurrent++;

		//
		auto rigidBody = createBody(world, levelEditorObject);
		if (rigidBody == nullptr) continue;
		if (translation.equals(Vector3()) == false) {
			auto transformations = levelEditorObject->getTransformations();
			transformations.setTranslation(transformations.getTranslation().clone().add(translation));
			transformations.update();
			rigidBody->fromTransformations(transformations);
		}
		rigidBody->setEnabled(enable);
	}

	//
	if (progressCallback != nullptr) {
		progressCallback->progress(1.0f);
		delete progressCallback;
	}
}

void SceneConnector::disableScene(Engine* engine, Scene& scene)
{
	for (auto i = 0; i < scene.getEntityCount(); i++) {
		auto object = scene.getEntityAt(i);
		auto entity = engine->getEntity(object->getId());
		if (entity == nullptr)
			continue;

		entity->setEnabled(false);
	}
}

void SceneConnector::disableScene(World* world, Scene& scene)
{
	Transformations transformations;
	for (auto i = 0; i < scene.getEntityCount(); i++) {
		auto object = scene.getEntityAt(i);
		auto rigidBody = world->getBody(object->getId());
		if (rigidBody == nullptr) continue;
		rigidBody->setEnabled(false);
	}
}

void SceneConnector::enableScene(Engine* engine, Scene& scene, const Vector3& translation)
{
	// TODO: a.drewke, Object3DRenderGroups
	for (auto i = 0; i < scene.getEntityCount(); i++) {
		auto object = scene.getEntityAt(i);
		auto entity = engine->getEntity(object->getId());
		if (entity == nullptr)
			continue;

		entity->fromTransformations(object->getTransformations());
		entity->setTranslation(entity->getTranslation().clone().add(translation));
		if (object->getEntity()->getType() == Prototype_EntityType::EMPTY) {
			entity->setScale(Vector3(Math::sign(entity->getScale().getX()), Math::sign(entity->getScale().getY()), Math::sign(entity->getScale().getZ())));
		}
		entity->update();
		entity->setEnabled(true);
	}
}

void SceneConnector::enableScene(World* world, Scene& scene, const Vector3& translation)
{
	Transformations transformations;
	for (auto i = 0; i < scene.getEntityCount(); i++) {
		auto object = scene.getEntityAt(i);
		auto rigidBody = world->getBody(object->getId());
		if (rigidBody == nullptr) continue;
		transformations.fromTransformations(object->getTransformations());
		transformations.setTranslation(transformations.getTranslation().clone().add(translation));
		transformations.update();
		rigidBody->fromTransformations(transformations);
		rigidBody->setEnabled(true);
	}
}

void SceneConnector::addSounds(Audio* audio, Prototype* prototype, const string& id, const int poolSize) {
	for (auto soundDefinition: prototype->getSounds()) {
		if (soundDefinition->getFileName().length() > 0) {
			for (auto poolIdx = 0; poolIdx < poolSize; poolIdx++) {
				string pathName = PrototypeReader::getResourcePathName(
					Tools::getPath(prototype->getEntityFileName()),
					soundDefinition->getFileName()
				);
				string fileName = Tools::getFileName(soundDefinition->getFileName());
				auto sound = new Sound(
					id + "." + soundDefinition->getId() + (poolSize > 1?"." + to_string(poolIdx):""),
					pathName,
					fileName
				);
				sound->setGain(soundDefinition->getGain());
				sound->setPitch(soundDefinition->getPitch());
				sound->setLooping(soundDefinition->isLooping());
				sound->setFixed(soundDefinition->isFixed());
				audio->addEntity(sound);
			}
		}
	}
}

