#include <tdme/tools/shared/views/SharedTerrainEditorView.h>

#include <map>
#include <string>
#include <unordered_set>

#include <tdme/engine/fileio/prototypes/PrototypeReader.h>
#include <tdme/engine/fileio/prototypes/PrototypeWriter.h>
#include <tdme/engine/model/Model.h>
#include <tdme/engine/model/Material.h>
#include <tdme/engine/model/SpecularMaterialProperties.h>
#include <tdme/engine/primitives/BoundingBox.h>
#include <tdme/engine/prototype/Prototype.h>
#include <tdme/engine/prototype/PrototypeProperty.h>
#include <tdme/engine/prototype/PrototypeTerrain.h>
#include <tdme/engine/Camera.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/Entity.h>
#include <tdme/engine/Object3D.h>
#include <tdme/engine/Object3DRenderGroup.h>
#include <tdme/engine/PartitionOctTree.h>
#include <tdme/engine/EntityHierarchy.h>
#include <tdme/engine/EnvironmentMapping.h>
#include <tdme/engine/SceneConnector.h>
#include <tdme/engine/Timing.h>
#include <tdme/gui/events/GUIKeyboardEvent.h>
#include <tdme/gui/events/GUIMouseEvent.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/gui/GUI.h>
#include <tdme/math/Vector3.h>
#include <tdme/tools/sceneeditor/TDMESceneEditor.h>
#include <tdme/tools/shared/controller/FileDialogScreenController.h>
#include <tdme/tools/shared/controller/InfoDialogScreenController.h>
#include <tdme/tools/shared/controller/TerrainEditorScreenController.h>
#include <tdme/tools/shared/tools/Tools.h>
#include <tdme/tools/shared/views/CameraInputHandler.h>
#include <tdme/tools/shared/views/PopUps.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>
#include <tdme/utilities/Integer.h>
#include <tdme/utilities/StringTools.h>

using std::map;
using std::string;
using std::unordered_set;

using tdme::engine::fileio::prototypes::PrototypeReader;
using tdme::engine::fileio::prototypes::PrototypeWriter;
using tdme::engine::model::Model;
using tdme::engine::model::Material;
using tdme::engine::model::SpecularMaterialProperties;
using tdme::engine::primitives::BoundingBox;
using tdme::engine::prototype::Prototype;
using tdme::engine::prototype::PrototypeProperty;
using tdme::engine::prototype::PrototypeTerrain;
using tdme::engine::Camera;
using tdme::engine::Engine;
using tdme::engine::Entity;
using tdme::engine::EntityHierarchy;
using tdme::engine::EnvironmentMapping;
using tdme::engine::Object3D;
using tdme::engine::Object3DRenderGroup;
using tdme::engine::PartitionOctTree;
using tdme::engine::SceneConnector;
using tdme::engine::Timing;
using tdme::gui::events::GUIKeyboardEvent;
using tdme::gui::events::GUIMouseEvent;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::GUI;
using tdme::math::Vector3;
using tdme::tools::shared::controller::FileDialogScreenController;
using tdme::tools::shared::controller::InfoDialogScreenController;
using tdme::tools::shared::controller::TerrainEditorScreenController;
using tdme::tools::shared::tools::Tools;
using tdme::tools::shared::views::CameraInputHandler;
using tdme::tools::shared::views::PopUps;
using tdme::tools::shared::views::SharedTerrainEditorView;
using tdme::utilities::Console;
using tdme::utilities::Exception;
using tdme::utilities::Integer;
using tdme::utilities::StringTools;

SharedTerrainEditorView::SharedTerrainEditorView(PopUps* popUps)
{
	this->popUps = popUps;
	terrainEditorScreenController = nullptr;
	initModelRequested = false;
	prototype = nullptr;
	engine = Engine::getInstance();
	cameraInputHandler = new CameraInputHandler(engine);
}

SharedTerrainEditorView::~SharedTerrainEditorView() {
	delete terrainEditorScreenController;
	delete cameraInputHandler;
}

PopUps* SharedTerrainEditorView::getPopUps()
{
	return popUps;
}

Prototype* SharedTerrainEditorView::getPrototype()
{
	return prototype;
}

void SharedTerrainEditorView::setPrototype(Prototype* prototype)
{
	engine->reset();
	for (auto terrainModel: terrainModels) delete terrainModel;
	terrainBoundingBox = BoundingBox();
	terrainModels.clear();
	unsetWater();
	this->prototype = prototype;
	initModelRequested = true;
}

void SharedTerrainEditorView::removeWater(int waterIdx) {
	auto& water = waters[waterIdx];
	for (auto waterModel: water.waterModels) {
		engine->removeEntity(waterModel->getId());
		delete waterModel;
	}
	waters.erase(waterIdx);
	initModelRequested = true;
	initCameraRequested = false;
}

void SharedTerrainEditorView::setTerrain(BoundingBox& terrainBoundingBox, vector<Model*> terrainModels) {
	engine->reset();
	for (auto terrainModel: this->terrainModels) delete terrainModel;
	this->terrainBoundingBox = terrainBoundingBox;
	this->terrainModels = terrainModels;
	this->partitionFoliageIdx.resize(terrainModels.size());
	initModelRequested = true;
}

void SharedTerrainEditorView::unsetWater() {
	for (auto& it: waters) {
		for (auto waterModel: it.second.waterModels) {
			engine->removeEntity(waterModel->getId());
			delete waterModel;
		}
	}
	this->waters.clear();
}

void SharedTerrainEditorView::addWater(int waterIdx, vector<Model*> waterModels, const Vector3& waterReflectionEnvironmentMappingPosition) {
	auto& water = waters[waterIdx];
	for (auto waterModel: water.waterModels) {
		engine->removeEntity(waterModel->getId());
		delete waterModel;
	}
	water.waterModels = waterModels;
	water.waterReflectionEnvironmentMappingPosition = waterReflectionEnvironmentMappingPosition;
	initModelRequested = true;
	initCameraRequested = false;
}

void SharedTerrainEditorView::addTemporaryFoliage(vector<unordered_map<int, vector<Transformations>>>& newFoliageMaps) {
	if (prototype == nullptr) return;

	//
	auto& foliageMaps = prototype->getTerrain()->getFoliageMaps();

	//
	auto partitionIdx = 0;
	for (auto& foliageMapPartition: newFoliageMaps) {
		auto partitionPrototypeInstanceCount = 0;
		for (auto& foliageMapPartitionIt: foliageMapPartition) {
			partitionPrototypeInstanceCount+= foliageMapPartitionIt.second.size();
		}
		if (partitionPrototypeInstanceCount > 0) {
			//
			temporaryPartitionIdxs.insert(partitionIdx);

			//
			auto foliagePartitionObject3DRenderGroup = engine->getEntity("foliage.object3drendergroup." + to_string(partitionIdx));
			if (foliagePartitionObject3DRenderGroup != nullptr) {
				engine->removeEntity(foliagePartitionObject3DRenderGroup->getId());
				recreateTemporaryFoliage({partitionIdx});
			}
			auto foliagePartitionEntityHierarchy = dynamic_cast<EntityHierarchy*>(engine->getEntity("foliage.entityhierarchy." + to_string(partitionIdx)));
			if (foliagePartitionEntityHierarchy == nullptr) {
				foliagePartitionEntityHierarchy = new EntityHierarchy("foliage.entityhierarchy." + to_string(partitionIdx));
				foliagePartitionEntityHierarchy->setContributesShadows(true);
				foliagePartitionEntityHierarchy->setReceivesShadows(true);
				engine->addEntity(foliagePartitionEntityHierarchy);
			}
			for (auto& foliageMapPartitionIt: foliageMapPartition) {
				auto prototypeIdx = foliageMapPartitionIt.first;
				auto& transformationsVector = foliageMapPartitionIt.second;
				if (transformationsVector.empty() == false) {
					auto foliagePrototype = prototype->getTerrain()->getFoliagePrototype(prototypeIdx);
					auto& foliageIdx = partitionFoliageIdx[partitionIdx];
					for (auto& transformations: transformationsVector) {
						auto foliageEntity = SceneConnector::createEntity(foliagePrototype, foliagePartitionEntityHierarchy->getId() + "." + to_string(prototypeIdx) + "." + to_string(foliageIdx), transformations);
						foliagePartitionEntityHierarchy->addEntity(foliageEntity);
						foliageIdx++;
					}
				}
			}
			foliagePartitionEntityHierarchy->update();
		}
		partitionIdx++;
	}
}

void SharedTerrainEditorView::recreateTemporaryFoliage(int partitionIdx) {
	if (prototype == nullptr) return;

	//
	temporaryPartitionIdxs.insert(partitionIdx);

	//
	auto& foliageMaps = prototype->getTerrain()->getFoliageMaps();

	//
	auto& foliageMapPartition = foliageMaps[partitionIdx];
	engine->removeEntity("foliage.entityhierarchy." + to_string(partitionIdx));
	auto partitionPrototypeInstanceCount = 0;
	for (auto& foliageMapPartitionIt: foliageMapPartition) {
		partitionPrototypeInstanceCount+= foliageMapPartitionIt.second.size();
	}
	if (partitionPrototypeInstanceCount > 0) {
		auto foliagePartitionEntityHierarchy = new EntityHierarchy("foliage.entityhierarchy." + to_string(partitionIdx));
		foliagePartitionEntityHierarchy->setContributesShadows(true);
		foliagePartitionEntityHierarchy->setReceivesShadows(true);
		engine->addEntity(foliagePartitionEntityHierarchy);
		for (auto& foliageMapPartitionIt: foliageMapPartition) {
			auto prototypeIdx = foliageMapPartitionIt.first;
			auto& transformationsVector = foliageMapPartitionIt.second;
			auto foliagePrototype = prototype->getTerrain()->getFoliagePrototype(prototypeIdx);
			auto& foliageIdx = partitionFoliageIdx[partitionIdx];
			for (auto& transformations: transformationsVector) {
				auto foliageEntity = SceneConnector::createEntity(foliagePrototype, foliagePartitionEntityHierarchy->getId() + "." + to_string(prototypeIdx) + "." + to_string(foliageIdx), transformations);
				foliagePartitionEntityHierarchy->addEntity(foliageEntity);
				foliageIdx++;
			}
		}
		foliagePartitionEntityHierarchy->update();
	}
}

void SharedTerrainEditorView::addFoliage() {
	if (prototype == nullptr) return;

	//
	auto& foliageMaps = prototype->getTerrain()->getFoliageMaps();

	//
	auto partitionIdx = 0;
	for (auto& foliageMapPartition: foliageMaps) {
		engine->removeEntity("foliage.entityhierarchy." + to_string(partitionIdx));
		engine->removeEntity("foliage.object3drendergroup." + to_string(partitionIdx));
		auto partitionPrototypeInstanceCount = 0;
		for (auto& foliageMapPartitionIt: foliageMapPartition) {
			partitionPrototypeInstanceCount+= foliageMapPartitionIt.second.size();
		}
		if (partitionPrototypeInstanceCount > 0) {
			auto foliagePartitionObject3DRenderGroup = new Object3DRenderGroup(
				"foliage.object3drendergroup." + to_string(partitionIdx),
				1,
				25.0f,
				50.0f,
				4,
				16,
				false
			);
			foliagePartitionObject3DRenderGroup->setContributesShadows(true);
			foliagePartitionObject3DRenderGroup->setReceivesShadows(true);
			engine->addEntity(foliagePartitionObject3DRenderGroup);
			for (auto& foliageMapPartitionIt: foliageMapPartition) {
				auto prototypeIdx = foliageMapPartitionIt.first;
				auto& transformationsVector = foliageMapPartitionIt.second;
				auto foliagePrototype = prototype->getTerrain()->getFoliagePrototype(prototypeIdx);
				for (auto& transformations: transformationsVector) {
					foliagePartitionObject3DRenderGroup->addObject(foliagePrototype->getModel(), transformations);
				}
			}
			foliagePartitionObject3DRenderGroup->updateRenderGroup();
		}
		partitionIdx++;
	}
}

void SharedTerrainEditorView::recreateFoliage() {
	if (prototype == nullptr) return;

	//
	auto& foliageMaps = prototype->getTerrain()->getFoliageMaps();

	//
	for (auto partitionIdx: temporaryPartitionIdxs) {
		auto& foliageMapPartition = foliageMaps[partitionIdx];
		engine->removeEntity("foliage.object3drendergroup." + to_string(partitionIdx));
		engine->removeEntity("foliage.entityhierarchy." + to_string(partitionIdx));
		auto partitionPrototypeInstanceCount = 0;
		for (auto& foliageMapPartitionIt: foliageMapPartition) {
			partitionPrototypeInstanceCount+= foliageMapPartitionIt.second.size();
		}
		if (partitionPrototypeInstanceCount > 0) {
			auto foliagePartitionObject3DRenderGroup = new Object3DRenderGroup(
				"foliage.object3drendergroup." + to_string(partitionIdx),
				1,
				25.0f,
				50.0f,
				4,
				16,
				false
			);
			foliagePartitionObject3DRenderGroup->setContributesShadows(true);
			foliagePartitionObject3DRenderGroup->setReceivesShadows(true);
			for (auto& foliageMapPartitionIt: foliageMapPartition) {
				auto prototypeIdx = foliageMapPartitionIt.first;
				auto& transformationsVector = foliageMapPartitionIt.second;
				auto foliagePrototype = prototype->getTerrain()->getFoliagePrototype(prototypeIdx);
				auto& foliageIdx = partitionFoliageIdx[partitionIdx];
				for (auto& transformations: transformationsVector) {
					foliagePartitionObject3DRenderGroup->addObject(foliagePrototype->getModel(), transformations);
					foliageIdx++;
				}
			}
			foliagePartitionObject3DRenderGroup->updateRenderGroup();
			engine->addEntity(foliagePartitionObject3DRenderGroup);
		}
	}

	//
	temporaryPartitionIdxs.clear();
}

void SharedTerrainEditorView::resetCamera() {
	initCameraRequested = true;
}

void SharedTerrainEditorView::initModel()
{
	if (prototype == nullptr) return;

	//
	if (terrainModels.empty() == false) {
		auto idx = 0;
		for (auto terrainModel: terrainModels) {
			auto terrainObject3D = new Object3D("terrain." + to_string(idx), terrainModel);
			terrainObject3D->setRenderPass(Entity::RENDERPASS_TERRAIN);
			terrainObject3D->setShader("terrain");
			terrainObject3D->setContributesShadows(true);
			terrainObject3D->setReceivesShadows(true);
			engine->addEntity(terrainObject3D);
			idx++;
		}

		Vector3 sceneCenter = terrainBoundingBox.getCenter();
		sceneCenter.set(Vector3(sceneCenter.getX(), terrainBoundingBox.getMax().getY() + 3.0f, sceneCenter.getZ()));
		cameraInputHandler->setSceneCenter(sceneCenter);
		Tools::oseThumbnail(prototype);
		auto modelBoundingVolume = engine->getEntity("model_bv");
		if (modelBoundingVolume != nullptr) {
			modelBoundingVolume->setEnabled(false);
		}
	}

	//
	if (waters.empty() == false) {
		for (auto& it: waters) {
			auto& water = it.second;
			for (auto waterModel: water.waterModels) {
				auto waterObject3D = new Object3D(waterModel->getId(), waterModel);
				waterObject3D->setRenderPass(Entity::RENDERPASS_WATER);
				waterObject3D->setShader("water");
				waterObject3D->setContributesShadows(false);
				waterObject3D->setReceivesShadows(false);
				waterObject3D->setReflectionEnvironmentMappingId("sky_environment_mapping");
				waterObject3D->setReflectionEnvironmentMappingPosition(water.waterReflectionEnvironmentMappingPosition);
				waterObject3D->setPickable(true);
				engine->addEntity(waterObject3D);
			}
		}
	}

	//
	initSky();

	//
	updateGUIElements();
}

void SharedTerrainEditorView::initSky() {
	// sky sphere
	auto skySphere = new Object3D("sky_sphere", skySpherePrototype->getModel());
	skySphere->setRenderPass(Entity::RENDERPASS_NOFRUSTUMCULLING);
	skySphere->setShader("sky");
	skySphere->setFrustumCulling(false);
	skySphere->setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	skySphere->setScale(Vector3(300.0f/200.0f, 300.0f/200.0f, 300.0f/200.0f));
	skySphere->update();
	skySphere->setContributesShadows(false);
	skySphere->setReceivesShadows(false);
	skySphere->setExcludeEffectPass(Engine::EFFECTPASS_LIGHTSCATTERING);
	engine->addEntity(skySphere);

	// sky dome
	auto skyDome = new Object3D("sky_dome", skyDomePrototype->getModel());
	skyDome->setRenderPass(Entity::RENDERPASS_NOFRUSTUMCULLING);
	skyDome->setShader("sky");
	skyDome->setFrustumCulling(false);
	skyDome->setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	skyDome->setScale(Vector3(295.0f/190.0f, 295.0f/190.0f, 295.0f/190.0f));
	skyDome->getModel()->getMaterials().begin()->second->getSpecularMaterialProperties()->setDiffuseTextureMaskedTransparency(true);
	skyDome->update();
	skyDome->setContributesShadows(false);
	skyDome->setReceivesShadows(false);
	skyDome->setEffectColorMul(Color4(1.0f, 1.0f, 1.0f, 0.7f));
	skyDome->setExcludeEffectPass(Engine::EFFECTPASS_LIGHTSCATTERING);
	engine->addEntity(skyDome);

	// sky panorama
	auto skyPanorama = new Object3D("sky_panorama", skyPanoramaPrototype->getModel());
	skyPanorama->setRenderPass(Entity::RENDERPASS_NOFRUSTUMCULLING);
	skyPanorama->setShader("sky");
	skyPanorama->setFrustumCulling(false);
	skyPanorama->setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	skyPanorama->setScale(Vector3(280.0f/190.0f, 280.0f/180.0f, 280.0f/180.0f));
	skyPanorama->addRotation(Vector3(0.0f, 1.0f, 0.0f), 0.0f);
	skyPanorama->update();
	skyPanorama->setContributesShadows(false);
	skyPanorama->setReceivesShadows(false);
	skyPanorama->setExcludeEffectPass(Engine::EFFECTPASS_LIGHTSCATTERING);
	engine->addEntity(skyPanorama);

	auto environmentMapping = new EnvironmentMapping("sky_environment_mapping", Engine::getEnvironmentMappingWidth(), Engine::getEnvironmentMappingHeight(), BoundingBox(Vector3(-30.0f, 0.0f, -30.0f), Vector3(30.0f, 60.0f, -30.0f)));
	environmentMapping->setFrustumCulling(false);
	environmentMapping->setRenderPassMask(Entity::RENDERPASS_NOFRUSTUMCULLING);
	environmentMapping->setTimeRenderUpdateFrequency(33LL);
	environmentMapping->update();
	engine->addEntity(environmentMapping);
}

void SharedTerrainEditorView::updateSky() {
	auto skySphere = engine->getEntity("sky_sphere");
	skySphere->setTranslation(engine->getCamera()->getLookFrom());
	skySphere->update();

	auto skyDome = static_cast<Object3D*>(engine->getEntity("sky_dome"));
	skyDome->setTranslation(engine->getCamera()->getLookFrom());
	skyDome->setTextureMatrix((Matrix2D3x3()).identity().translate(Vector2(0.0f, skyDomeTranslation * 0.01f)));
	skyDome->update();

	auto skyPanorama = engine->getEntity("sky_panorama");
	skyPanorama->setTranslation(engine->getCamera()->getLookFrom());
	skyPanorama->setRotationAngle(0, skyDomeTranslation * 1.0f * 0.1f);
	skyPanorama->update();

	auto environmentMapping = engine->getEntity("sky_environment_mapping");
	environmentMapping->setTranslation(engine->getCamera()->getLookFrom());
	environmentMapping->update();

	skyDomeTranslation+= 1.0f / 60.0;
}

void SharedTerrainEditorView::handleInputEvents()
{
	for (auto i = 0; i < engine->getGUI()->getMouseEvents().size(); i++) {
		auto& event = engine->getGUI()->getMouseEvents()[i];
		if (event.isProcessed() == true) continue;

		if (event.getButton() == MOUSE_BUTTON_LEFT) {
			if (event.getType() == GUIMouseEvent::MOUSEEVENT_RELEASED) {
				if (terrainEditorScreenController->getTerrainBrushOperation() == Terrain::BRUSHOPERATION_DELETE) {
					auto selectedEntity = engine->getEntityByMousePosition(event.getXUnscaled(), event.getYUnscaled());
					if (selectedEntity != nullptr && StringTools::startsWith(selectedEntity->getId(), "water.") == true) {
						auto waterPositionMapIdx = Integer::parseInt(StringTools::substring(selectedEntity->getId(), 6, selectedEntity->getId().rfind('.')));
						terrainEditorScreenController->deleteWater(waterPositionMapIdx);
					}
					event.setProcessed(true);
				} else {
					recreateFoliage();
					brushingEnabled = false;
					terrainEditorScreenController->unsetCurrentBrushFlattenHeight();
					event.setProcessed(true);
				}
			} else
			if (event.getType() == GUIMouseEvent::MOUSEEVENT_PRESSED ||
				event.getType() == GUIMouseEvent::MOUSEEVENT_DRAGGED) {
				engine->computeWorldCoordinateByMousePosition(event.getXUnscaled(), event.getYUnscaled(), brushCenterPosition);
				if (terrainEditorScreenController->getTerrainBrushOperation() == Terrain::BRUSHOPERATION_WATER) {
					if (terrainEditorScreenController->determineCurrentBrushHeight(terrainBoundingBox, terrainModels, brushCenterPosition) == true) {
						vector<Model*> waterModels;
						Vector3 waterReflectionEnvironmentMappingPosition;
						terrainEditorScreenController->createWater(terrainBoundingBox, brushCenterPosition, waterModels, waterReflectionEnvironmentMappingPosition);
						brushingEnabled = false;
						terrainEditorScreenController->unsetCurrentBrushFlattenHeight();
						//
						for (auto waterModel: waterModels) {
							auto waterObject3D = new Object3D(waterModel->getId(), waterModel); // TODO: make this persistent
							waterObject3D->setRenderPass(Entity::RENDERPASS_WATER);
							waterObject3D->setShader("water");
							waterObject3D->setContributesShadows(false);
							waterObject3D->setReceivesShadows(false);
							waterObject3D->setReflectionEnvironmentMappingId("sky_environment_mapping");
							waterObject3D->setReflectionEnvironmentMappingPosition(waterReflectionEnvironmentMappingPosition);
							waterObject3D->setPickable(true);
							engine->addEntity(waterObject3D);
						}
					}
				} else {
					brushingEnabled = true;
				}
				event.setProcessed(true);
			}
		}
	}
	cameraInputHandler->handleInputEvents();
}

void SharedTerrainEditorView::display()
{
	// commands
	if (initModelRequested == true) {
		initModel();
		if (initCameraRequested == true) cameraInputHandler->reset();
		initModelRequested = false;
		initCameraRequested = true;
	}

	// actually do the brushing
	if (brushingEnabled == true && terrainEditorScreenController->determineCurrentBrushHeight(terrainBoundingBox, terrainModels, brushCenterPosition) == true) {
		if (terrainEditorScreenController->getTerrainBrushOperation() != Terrain::BRUSHOPERATION_NONE) {
			terrainEditorScreenController->applyTerrainBrush(terrainBoundingBox, terrainModels, brushCenterPosition, engine->getTiming()->getDeltaTime());
		} else
		if (terrainEditorScreenController->getFoliageBrushOperation() != Terrain::BRUSHOPERATION_NONE) {
			terrainEditorScreenController->applyFoliageBrush(terrainBoundingBox, brushCenterPosition, engine->getTiming()->getDeltaTime());
		}

	}

	// viewport
	auto xScale = (float)engine->getWidth() / (float)terrainEditorScreenController->getScreenNode()->getScreenWidth();
	auto yScale = (float)engine->getHeight() / (float)terrainEditorScreenController->getScreenNode()->getScreenHeight();
	auto viewPortLeft = 0;
	auto viewPortTop = 0;
	auto viewPortWidth = 0;
	auto viewPortHeight = 0;
	terrainEditorScreenController->getViewPort(viewPortLeft, viewPortTop, viewPortWidth, viewPortHeight);
	viewPortLeft = (int)((float)viewPortLeft * xScale);
	viewPortTop = (int)((float)viewPortTop * yScale);
	viewPortWidth = (int)((float)viewPortWidth * xScale);
	viewPortHeight = (int)((float)viewPortHeight * yScale);
	engine->getCamera()->enableViewPort(viewPortLeft, viewPortTop, viewPortWidth, viewPortHeight);

	//
	updateSky();
}

void SharedTerrainEditorView::updateGUIElements()
{
	if (prototype != nullptr) {
		terrainEditorScreenController->setScreenCaption("Terrain Editor - " + prototype->getName());
		auto preset = prototype->getProperty("preset");
		terrainEditorScreenController->setPrototypeProperties(preset != nullptr ? preset->getValue() : "", "");
		terrainEditorScreenController->setPrototypeData(prototype->getName(), prototype->getDescription());
		if (terrainModels.empty() == false) {
			terrainEditorScreenController->setTerrainDimension(
				terrainBoundingBox.getDimensions().getX(),
				terrainBoundingBox.getDimensions().getZ()
			);
		} else {
			terrainEditorScreenController->setTerrainDimension(64.0f, 64.0f);
		}
	} else {
		terrainEditorScreenController->setScreenCaption("Terrain Editor - no terrain loaded");
		terrainEditorScreenController->unsetPrototypeProperties();
		terrainEditorScreenController->unsetPrototypeData();
		terrainEditorScreenController->setTerrainDimension(64.0f, 64.0f);
	}
}

void SharedTerrainEditorView::initialize()
{
	try {
		terrainEditorScreenController = new TerrainEditorScreenController(this);
		terrainEditorScreenController->initialize();
		engine->getGUI()->addScreen(terrainEditorScreenController->getScreenNode()->getId(), terrainEditorScreenController->getScreenNode());
		terrainEditorScreenController->getScreenNode()->setInputEventHandler(this);

		//
		// load sky
		skySpherePrototype = PrototypeReader::read("resources/engine/models", "sky_sphere.tmm");
		skyDomePrototype = PrototypeReader::read("resources/engine/models", "sky_dome.tmm");
		skyPanoramaPrototype = PrototypeReader::read("resources/engine/models", "sky_panorama.tmm");
		spherePrototype = PrototypeReader::read("resources/engine/models", "sphere.tmm");

	} catch (Exception& exception) {
		Console::print(string("SharedTerrainEditorView::initialize(): An error occurred: "));
		Console::println(string(exception.what()));
	}
	updateGUIElements();
}

void SharedTerrainEditorView::activate()
{
	engine->reset();
	engine->setPartition(new PartitionOctTree());
	engine->setShadowMapLightEyeDistanceScale(0.1f);
	engine->getGUI()->resetRenderScreens();
	engine->getGUI()->addRenderScreen(terrainEditorScreenController->getScreenNode()->getId());
	onInitAdditionalScreens();
	engine->getGUI()->addRenderScreen(popUps->getFileDialogScreenController()->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(popUps->getInfoDialogScreenController()->getScreenNode()->getId());

	// lights
	for (auto i = 1; i < engine->getLightCount(); i++) engine->getLightAt(i)->setEnabled(false);
	{
		auto light0 = engine->getLightAt(0);
		light0->setAmbient(Color4(0.7f, 0.7f, 0.7f, 1.0f));
		light0->setDiffuse(Color4(0.3f, 0.3f, 0.3f, 1.0f));
		light0->setSpecular(Color4(1.0f, 1.0f, 1.0f, 1.0f));
		light0->setPosition(Vector4(0.0f, 20000.0f, 0.0f, 1.0f));
		light0->setSpotDirection(Vector3(0.0f, 0.0f, 0.0f).sub(Vector3(light0->getPosition().getX(), light0->getPosition().getY(), light0->getPosition().getZ())).normalize());
		light0->setConstantAttenuation(0.5f);
		light0->setLinearAttenuation(0.0f);
		light0->setQuadraticAttenuation(0.0f);
		light0->setSpotExponent(0.0f);
		light0->setSpotCutOff(180.0f);
		light0->setEnabled(true);
	}

	//
	initSky();
}

void SharedTerrainEditorView::deactivate()
{
}

void SharedTerrainEditorView::dispose()
{
	Engine::getInstance()->reset();
}

void SharedTerrainEditorView::onSetPrototypeData() {
}

void SharedTerrainEditorView::onInitAdditionalScreens() {
}

void SharedTerrainEditorView::loadFile(const string& pathName, const string& fileName) {
	// TODO: a.drewke; delete prototype, also check other tools
	auto prototype = PrototypeReader::read(pathName, fileName);
	setPrototype(prototype);
	partitionFoliageIdx.clear();
	temporaryPartitionIdxs.clear();
	terrainEditorScreenController->onLoadTerrain();
}

void SharedTerrainEditorView::saveFile(const string& pathName, const string& fileName) {
	PrototypeWriter::write(pathName, fileName, prototype);
}
