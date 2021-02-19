#include <tdme/tools/shared/controller/TerrainEditorScreenController.h>

#include <map>
#include <string>
#include <vector>

#include <tdme/engine/fileio/textures/Texture.h>
#include <tdme/engine/fileio/textures/TextureReader.h>
#include <tdme/engine/model/Model.h>
#include <tdme/engine/primitives/BoundingBox.h>
#include <tdme/engine/prototype/Prototype.h>
#include <tdme/engine/prototype/PrototypeTerrain.h>
#include <tdme/gui/events/Action.h>
#include <tdme/gui/nodes/GUIElementNode.h>
#include <tdme/gui/nodes/GUINode.h>
#include <tdme/gui/nodes/GUINodeController.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/gui/nodes/GUITextNode.h>
#include <tdme/gui/GUIParser.h>
#include <tdme/tools/shared/controller/FileDialogPath.h>
#include <tdme/tools/shared/controller/FileDialogScreenController.h>
#include <tdme/tools/shared/controller/InfoDialogScreenController.h>
#include <tdme/tools/shared/controller/PrototypeBaseSubScreenController.h>
#include <tdme/tools/shared/tools/Tools.h>
#include <tdme/tools/shared/views/PopUps.h>
#include <tdme/tools/shared/views/SharedTerrainEditorView.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>
#include <tdme/utilities/Float.h>
#include <tdme/utilities/MutableString.h>
#include <tdme/utilities/Terrain.h>

using std::map;
using std::string;
using std::to_string;
using std::vector;

using tdme::engine::fileio::textures::Texture;
using tdme::engine::fileio::textures::TextureReader;
using tdme::engine::model::Model;
using tdme::engine::primitives::BoundingBox;
using tdme::engine::prototype::Prototype;
using tdme::engine::prototype::PrototypeTerrain;
using tdme::gui::events::Action;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUINode;
using tdme::gui::nodes::GUINodeController;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::nodes::GUITextNode;
using tdme::gui::GUIParser;
using tdme::tools::shared::controller::FileDialogPath;
using tdme::tools::shared::controller::FileDialogScreenController;
using tdme::tools::shared::controller::InfoDialogScreenController;
using tdme::tools::shared::controller::PrototypeBaseSubScreenController;
using tdme::tools::shared::controller::TerrainEditorScreenController;
using tdme::tools::shared::tools::Tools;
using tdme::tools::shared::views::PopUps;
using tdme::tools::shared::views::SharedTerrainEditorView;
using tdme::utilities::Console;
using tdme::utilities::Exception;
using tdme::utilities::Float;
using tdme::utilities::MutableString;
using tdme::utilities::Terrain;

TerrainEditorScreenController::TerrainEditorScreenController(SharedTerrainEditorView* view)
{
	class OnSetEntityDataAction: public virtual Action
	{
	public:
		void performAction() override {
			finalView->updateGUIElements();
			finalView->onSetPrototypeData();
		}

		/**
		 * Public constructor
		 * @param terrainEditorScreenController terrain editor screen controller
		 * @param finalView final view
		 */
		OnSetEntityDataAction(TerrainEditorScreenController* terrainEditorScreenController, SharedTerrainEditorView* finalView): terrainEditorScreenController(terrainEditorScreenController), finalView(finalView) {
		}

	private:
		TerrainEditorScreenController* terrainEditorScreenController;
		SharedTerrainEditorView* finalView;
	};

	this->view = view;
	auto const finalView = view;
	this->prototypeBaseSubScreenController = new PrototypeBaseSubScreenController(view->getPopUpsViews(), new OnSetEntityDataAction(this, finalView));
	this->terrainPath = new FileDialogPath(".");
}

GUIScreenNode* TerrainEditorScreenController::getScreenNode()
{
	return screenNode;
}

void TerrainEditorScreenController::initialize()
{
	try {
		screenNode = GUIParser::parse("resources/engine/gui", "screen_terraineditor.xml");
		screenNode->addActionListener(this);
		screenNode->addChangeListener(this);
		screenCaption = dynamic_cast< GUITextNode* >(screenNode->getNodeById("screen_caption"));
		viewPort = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("viewport"));
		terrainDimensionWidth = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("terrain_dimension_width"));
		terrainDimensionDepth = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("terrain_dimension_depth"));
		btnTerrainDimensionApply = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("button_terrain_dimension_apply"));
		btnTerrainDimensionLoad = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("button_terrain_dimension_load"));
		btnTerrainDimensionSave = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("button_terrain_dimension_save"));
		terrainBrushScale = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("terrain_brush_scale"));
		terrainBrushStrength = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("terrain_brush_strength"));
		terrainBrushFile = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("terrain_brush_file"));
		terrainBrushFileLoad = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("terrain_brush_file_load"));
		terrainBrushFileClear = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("terrain_brush_file_clear"));
		btnTerrainBrushApply = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("button_terrain_brush_apply"));

		foliageBrushScale = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("foliage_brush_scale"));
		foliageBrushDensity = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("foliage_brush_density"));
		foliageBrushFile = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("foliage_brush_file"));
		foliageBrushFileLoad = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("foliage_brush_file_load"));
		foliageBrushFileClear = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("foliage_brush_file_clear"));
		btnFoliageBrushApply = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("button_foliage_brush_apply"));

		for (auto i = 0; i < 5; i++) {
			foliageBrushModelFileRatio[i] = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("foliage_brush_model_" + to_string(i + 1) + "_ratio"));
			foliageBrushModelFile[i] = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("foliage_brush_model_" + to_string(i + 1)));
			foliageBrushModelFileLoad[i] = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("foliage_brush_model_" + to_string(i + 1) + "_load"));
			foliageBrushModelFileClear[i] = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("foliage_brush_model_" + to_string(i + 1) + "_save"));
		}

	} catch (Exception& exception) {
		Console::print(string("TerrainEditorScreenController::initialize(): An error occurred: "));
		Console::println(string(exception.what()));
	}
	prototypeBaseSubScreenController->initialize(screenNode);
	btnTerrainDimensionSave->getController()->setDisabled(true);
	onApplyTerrainBrush();
}

void TerrainEditorScreenController::dispose()
{
	if (currentBrushTexture != nullptr) currentBrushTexture->releaseReference();
	delete prototypeBaseSubScreenController;
	delete terrainPath;
}

void TerrainEditorScreenController::setScreenCaption(const string& text)
{
	screenCaption->setText(text);
}

void TerrainEditorScreenController::setPrototypeData(const string& name, const string& description)
{
	prototypeBaseSubScreenController->setPrototypeData(name, description);
}

void TerrainEditorScreenController::unsetPrototypeData()
{
	prototypeBaseSubScreenController->unsetPrototypeData();
}

void TerrainEditorScreenController::setPrototypeProperties(const string& presetId, const string& selectedName)
{
	prototypeBaseSubScreenController->setPrototypeProperties(view->getPrototype(), presetId, selectedName);
}

void TerrainEditorScreenController::unsetPrototypeProperties()
{
	prototypeBaseSubScreenController->unsetPrototypeProperties();
}

void TerrainEditorScreenController::showErrorPopUp(const string& caption, const string& message)
{
	view->getPopUpsViews()->getInfoDialogScreenController()->show(caption, message);
}

void TerrainEditorScreenController::onValueChanged(GUIElementNode* node)
{
	prototypeBaseSubScreenController->onValueChanged(node, view->getPrototype());
}

void TerrainEditorScreenController::onActionPerformed(GUIActionListenerType type, GUIElementNode* node)
{
	prototypeBaseSubScreenController->onActionPerformed(type, node, view->getPrototype());
	if (type == GUIActionListenerType::PERFORMED) {
		if (node->getId().compare(btnTerrainDimensionApply->getId()) == 0) {
			onApplyTerrainDimension();
		} else
		if (node->getId().compare(btnTerrainDimensionLoad->getId()) == 0) {
			onTerrainLoad();
		} else
		if (node->getId().compare(btnTerrainDimensionSave->getId()) == 0) {
			onTerrainSave();
		} else
		if (node->getId().compare(btnTerrainBrushApply->getId()) == 0) {
			onApplyTerrainBrush();
		}
	}
}

void TerrainEditorScreenController::setTerrainDimension(float width, float height) {
	terrainDimensionWidth->getController()->setValue(MutableString(width));
	terrainDimensionDepth->getController()->setValue(MutableString(height));
}

void TerrainEditorScreenController::onLoadTerrain() {
	auto prototype = view->getPrototype();
	if (prototype == nullptr) return;

	//
	try {
		auto width = prototype->getTerrain()->getWidth();
		auto depth = prototype->getTerrain()->getDepth();
		BoundingBox terrainBoundingBox;
		vector<Model*> terrainModels;
		Terrain::createTerrainModels(width, depth, 0.0f, prototype->getTerrain()->getHeightVector(), terrainBoundingBox, terrainModels);
		view->unsetWater();
		view->setTerrain(terrainBoundingBox, terrainModels);
		auto waterPositionMapsIndices = prototype->getTerrain()->getWaterPositionMapsIndices();
		for (auto waterPositionMapIdx: waterPositionMapsIndices) {
			vector<Model*> waterModels;
			Terrain::createWaterModels(
				terrainBoundingBox,
				prototype->getTerrain()->getWaterPositionMap(waterPositionMapIdx),
				prototype->getTerrain()->getWaterPositionMapHeight(waterPositionMapIdx),
				waterPositionMapIdx,
				waterModels
			);
			view->addWater(
				waterPositionMapIdx,
				waterModels,
				Terrain::computeWaterReflectionEnvironmentMappingPosition(
					prototype->getTerrain()->getWaterPositionMap(waterPositionMapIdx),
					prototype->getTerrain()->getWaterPositionMapHeight(waterPositionMapIdx)
				)
			);
		}
		prototype->getTerrain()->setWidth(terrainBoundingBox.getDimensions().getX());
		prototype->getTerrain()->setDepth(terrainBoundingBox.getDimensions().getZ());
		btnTerrainDimensionSave->getController()->setDisabled(false);
		view->resetCamera();
	} catch (Exception& exception) {
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void TerrainEditorScreenController::onApplyTerrainDimension() {
	auto prototype = view->getPrototype();
	if (prototype == nullptr) return;

	//
	try {
		auto width = Float::parseFloat(terrainDimensionWidth->getController()->getValue().getString());
		auto depth = Float::parseFloat(terrainDimensionDepth->getController()->getValue().getString());
		if (width < 1.0f || width > 4000.0f) throw ExceptionBase("Width must be within 1 .. 4000");
		if (depth < 1.0f || depth > 4000.0f) throw ExceptionBase("Depth must be within 1 .. 4000");
		prototype->getTerrain()->getHeightVector().clear();
		for (auto idx: prototype->getTerrain()->getWaterPositionMapsIndices()) prototype->getTerrain()->removeWaterPositionMap(idx);
		BoundingBox terrainBoundingBox;
		vector<Model*> terrainModels;
		Terrain::createTerrainModels(width, depth, 0.0f, prototype->getTerrain()->getHeightVector(), terrainBoundingBox, terrainModels);
		view->setTerrain(terrainBoundingBox, terrainModels);
		view->unsetWater();
		prototype->getTerrain()->setWidth(terrainBoundingBox.getDimensions().getX());
		prototype->getTerrain()->setDepth(terrainBoundingBox.getDimensions().getZ());
		btnTerrainDimensionSave->getController()->setDisabled(false);
	} catch (Exception& exception) {
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void TerrainEditorScreenController::onTerrainLoad()
{
	class OnTerrainLoadAction: public virtual Action
	{
	public:
		void performAction() override {
			terrainEditorScreenController->view->loadFile(terrainEditorScreenController->view->getPopUpsViews()->getFileDialogScreenController()->getPathName(), terrainEditorScreenController->view->getPopUpsViews()->getFileDialogScreenController()->getFileName());
			terrainEditorScreenController->terrainPath->setPath(terrainEditorScreenController->view->getPopUpsViews()->getFileDialogScreenController()->getPathName());
			terrainEditorScreenController->view->getPopUpsViews()->getFileDialogScreenController()->close();
		}

		/**
		 * Public constructor
		 * @param terrainEditorScreenController terrain editor screen controller
		 */
		OnTerrainLoadAction(TerrainEditorScreenController* terrainEditorScreenController): terrainEditorScreenController(terrainEditorScreenController) {
		}

	private:
		TerrainEditorScreenController* terrainEditorScreenController;
	};

	vector<string> extensions;
	extensions.push_back("tte");
	auto fileName = view->getPrototype() != nullptr?view->getPrototype()->getFileName():"";
	view->getPopUpsViews()->getFileDialogScreenController()->show(
		terrainPath->getPath(),
		"Load from: ",
		extensions,
		fileName,
		true,
		new OnTerrainLoadAction(this)
	);
}

void TerrainEditorScreenController::onTerrainSave()
{
	class OnTerrainSave: public virtual Action
	{
	public:
		void performAction() override {
			try {
				terrainEditorScreenController->view->saveFile(
					terrainEditorScreenController->view->getPopUpsViews()->getFileDialogScreenController()->getPathName(),
					terrainEditorScreenController->view->getPopUpsViews()->getFileDialogScreenController()->getFileName()
				);
				terrainEditorScreenController->terrainPath->setPath(
						terrainEditorScreenController->view->getPopUpsViews()->getFileDialogScreenController()->getPathName()
				);
				terrainEditorScreenController->view->getPopUpsViews()->getFileDialogScreenController()->close();
			} catch (Exception& exception) {
				terrainEditorScreenController->showErrorPopUp("Warning", (string(exception.what())));
			}
		}

		/**
		 * Public constructor
		 * @param modelEditorScreenController model editor screen controller
		 */
		OnTerrainSave(TerrainEditorScreenController* terrainEditorScreenController): terrainEditorScreenController(terrainEditorScreenController) {
		}

	private:
		TerrainEditorScreenController* terrainEditorScreenController;
	};

	auto fileName = view->getPrototype() != nullptr?view->getPrototype()->getFileName():"";
	vector<string> extensions = {
		"tte"
	};
	fileName = Tools::getFileName(fileName);
	view->getPopUpsViews()->getFileDialogScreenController()->show(
		terrainPath->getPath(),
		"Save to: ",
		extensions,
		fileName,
		false,
		new OnTerrainSave(this)
	);
}

void TerrainEditorScreenController::onApplyTerrainBrush() {
	try {
		// texture
		if (currentBrushTexture != nullptr) currentBrushTexture->releaseReference();
		currentBrushTexture = nullptr;

		// operation
		map<string, MutableString> values;
		screenNode->getValues(values);
		auto brushOperationName = values["terrain_brush_operation"].getString();
		currentBrushOperation = Terrain::BRUSHOPERATION_ADD;
		if (brushOperationName == "add") {
			currentBrushOperation = Terrain::BRUSHOPERATION_ADD;
		} else
		if (brushOperationName == "subtract") {
			currentBrushOperation = Terrain::BRUSHOPERATION_SUBTRACT;
		} else
		if (brushOperationName == "flatten") {
			currentBrushOperation = Terrain::BRUSHOPERATION_FLATTEN;
		} else
		if (brushOperationName == "delete") {
			currentBrushOperation = Terrain::BRUSHOPERATION_DELETE;
		} else
		if (brushOperationName == "smooth") {
			currentBrushOperation = Terrain::BRUSHOPERATION_SMOOTH;
		} else
		if (brushOperationName == "water") {
			currentBrushOperation = Terrain::BRUSHOPERATION_WATER;
		}

		// scale, strength
		currentBrushScale = Float::parseFloat(terrainBrushScale->getController()->getValue().getString());
		currentBrushStrength = Float::parseFloat(terrainBrushStrength->getController()->getValue().getString());

		if (currentBrushScale < 0.1f || currentBrushScale > 100.0f) throw ExceptionBase("Brush scale must be within 0.1 .. 100");
		if (currentBrushStrength <= 0.0f || currentBrushStrength > 10.0f) throw ExceptionBase("Brush strength must be within 0 .. 10");

		// texture
		auto brushTextureFileName = terrainBrushFile->getController()->getValue().getString();
		currentBrushTexture = TextureReader::read(Tools::getPathName(brushTextureFileName), Tools::getFileName(brushTextureFileName), false, false);
	} catch (Exception& exception) {
		Console::println(string("Terrain::onApplyBrush(): An error occurred: ") + exception.what());
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

Terrain::BrushOperation TerrainEditorScreenController::getTerrainBrushOperation() {
	return currentBrushOperation;
}

void TerrainEditorScreenController::applyTerrainBrush(BoundingBox& terrainBoundingBox, vector<Model*>& terrainModels, const Vector3& brushCenterPosition, int64_t deltaTime) {
	auto prototype = view->getPrototype();
	if (prototype == nullptr) return;
	if (terrainModels.empty() == true) return;
	auto terrainModel = terrainModels[0];
	if (terrainModel == nullptr) return;
	Terrain::applyBrushToTerrainModels(
		terrainBoundingBox,
		terrainModels,
		prototype->getTerrain()->getHeightVector(),
		brushCenterPosition,
		currentBrushTexture,
		currentBrushScale,
		currentBrushStrength * static_cast<float>(deltaTime) / 200.0f, // if strength = 1.0f it will e.g. add to level 5 meters/second
		currentBrushOperation,
		currentBrushHeight
	);
}

void TerrainEditorScreenController::createWater(BoundingBox& terrainBoundingBox, const Vector3& brushCenterPosition, vector<Model*>& waterModels, Vector3& waterReflectionEnvironmentMappingPosition) {
	auto prototype = view->getPrototype();
	if (prototype == nullptr) return;
	auto waterPositionMapIdx = prototype->getTerrain()->allocateWaterPositionMapIdx();
	prototype->getTerrain()->setWaterPositionMapHeight(waterPositionMapIdx, currentBrushHeight);
	if (Terrain::computeWaterPositionMap(
		terrainBoundingBox,
		prototype->getTerrain()->getHeightVector(),
		brushCenterPosition,
		prototype->getTerrain()->getWaterPositionMapHeight(waterPositionMapIdx),
		prototype->getTerrain()->getWaterPositionMap(waterPositionMapIdx)) == true) {
		//
		Terrain::createWaterModels(
			terrainBoundingBox,
			prototype->getTerrain()->getWaterPositionMap(waterPositionMapIdx),
			prototype->getTerrain()->getWaterPositionMapHeight(waterPositionMapIdx),
			waterPositionMapIdx,
			waterModels
		);
		waterReflectionEnvironmentMappingPosition = Terrain::computeWaterReflectionEnvironmentMappingPosition(
			prototype->getTerrain()->getWaterPositionMap(waterPositionMapIdx),
			prototype->getTerrain()->getWaterPositionMapHeight(waterPositionMapIdx)
		);
		view->addWater(
			waterPositionMapIdx,
			waterModels,
			waterReflectionEnvironmentMappingPosition
		);
	}
}

void TerrainEditorScreenController::deleteWater(int waterPositionMapIdx) {
	auto prototype = view->getPrototype();
	if (prototype == nullptr) return;
	prototype->getTerrain()->removeWaterPositionMap(waterPositionMapIdx);
	view->removeWater(waterPositionMapIdx);
}

bool TerrainEditorScreenController::determineCurrentBrushHeight(BoundingBox& terrainBoundingBox, vector<Model*> terrainModels, const Vector3& brushCenterPosition) {
	auto prototype = view->getPrototype();
	if (prototype == nullptr) return false;
	if (currentBrushOperation != Terrain::BRUSHOPERATION_FLATTEN && currentBrushOperation != Terrain::BRUSHOPERATION_WATER) return true;
	if (haveCurrentBrushHeight == true) return true;
	if (terrainModels.empty() == true) return false;
	auto terrainModel = terrainModels[0];
	if (terrainModel == nullptr) return false;
	haveCurrentBrushHeight = Terrain::getTerrainModelsHeight(
		terrainBoundingBox,
		terrainModels,
		prototype->getTerrain()->getHeightVector(),
		brushCenterPosition,
		currentBrushHeight
	);
	return haveCurrentBrushHeight;
}

void TerrainEditorScreenController::unsetCurrentBrushFlattenHeight() {
	haveCurrentBrushHeight = false;
}


void TerrainEditorScreenController::getViewPort(int& left, int& top, int& width, int& height) {
	auto& constraints = viewPort->getComputedConstraints();
	left = constraints.left + constraints.alignmentLeft + constraints.contentAlignmentLeft;
	top = constraints.top + constraints.alignmentTop + constraints.contentAlignmentTop;
	width = constraints.width;
	height = constraints.height;
}
