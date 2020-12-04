#include <tdme/tools/leveleditor/controller/EnvironmentMappingScreenController.h>

#include <string>

#include <tdme/gui/GUIParser.h>
#include <tdme/gui/events/Action.h>
#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/events/GUIChangeListener.h>
#include <tdme/gui/nodes/GUIElementNode.h>
#include <tdme/gui/nodes/GUINode.h>
#include <tdme/gui/nodes/GUINodeController.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/gui/nodes/GUITextNode.h>
#include <tdme/tools/leveleditor/controller/LevelEditorEntityLibraryScreenController.h>
#include <tdme/tools/leveleditor/views/EnvironmentMappingView.h>
#include <tdme/tools/shared/controller/EntityBaseSubScreenController.h>
#include <tdme/tools/shared/controller/EntityPhysicsSubScreenController.h>
#include <tdme/tools/shared/controller/FileDialogPath.h>
#include <tdme/tools/shared/controller/InfoDialogScreenController.h>
#include <tdme/tools/shared/tools/Tools.h>
#include <tdme/tools/shared/views/PopUps.h>
#include <tdme/tools/leveleditor/TDMELevelEditor.h>
#include <tdme/utilities/Float.h>
#include <tdme/utilities/MutableString.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>

using std::string;

using tdme::tools::leveleditor::controller::EnvironmentMappingScreenController;
using tdme::gui::GUIParser;
using tdme::gui::events::Action;
using tdme::gui::events::GUIActionListenerType;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUINode;
using tdme::gui::nodes::GUINodeController;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::nodes::GUITextNode;
using tdme::tools::leveleditor::controller::LevelEditorEntityLibraryScreenController;
using tdme::tools::leveleditor::views::EnvironmentMappingView;
using tdme::tools::shared::controller::EntityBaseSubScreenController;
using tdme::tools::shared::controller::EntityPhysicsSubScreenController;
using tdme::tools::shared::controller::FileDialogPath;
using tdme::tools::shared::controller::InfoDialogScreenController;
using tdme::tools::shared::tools::Tools;
using tdme::tools::shared::views::PopUps;
using tdme::tools::leveleditor::TDMELevelEditor;
using tdme::utilities::Float;
using tdme::utilities::MutableString;
using tdme::utilities::Console;
using tdme::utilities::Exception;

MutableString EnvironmentMappingScreenController::TEXT_EMPTY = MutableString("");

EnvironmentMappingScreenController::EnvironmentMappingScreenController(EnvironmentMappingView* view)
{
	class OnSetEntityDataAction: public virtual Action
	{
	public:
		void performAction() override {
			finalView->updateGUIElements();
			TDMELevelEditor::getInstance()->getLevelEditorEntityLibraryScreenController()->setEntityLibrary();
		}

		/**
		 * Public constructor
		 * @param EnvironmentMappingScreenController environment mapping screen controller
		 * @param finalView final view
		 */
		OnSetEntityDataAction(EnvironmentMappingScreenController* environmentMappingScreenController, EnvironmentMappingView* finalView): environmentMappingScreenController(environmentMappingScreenController), finalView(finalView) {
		}


	private:
		EnvironmentMappingScreenController* environmentMappingScreenController;
		EnvironmentMappingView* finalView;

	};

	this->view = view;
	auto const finalView = view;
	this->modelPath = new FileDialogPath(".");
	this->entityBaseSubScreenController = new EntityBaseSubScreenController(view->getPopUpsViews(), new OnSetEntityDataAction(this, finalView));
}

GUIScreenNode* EnvironmentMappingScreenController::getScreenNode()
{
	return screenNode;
}

void EnvironmentMappingScreenController::initialize()
{
	try {
		screenNode = GUIParser::parse("resources/engine/tools/leveleditor/gui", "screen_environmentmapping.xml");
		screenNode->addActionListener(this);
		screenNode->addChangeListener(this);
		screenCaption = dynamic_cast<GUITextNode*>(screenNode->getNodeById("screen_caption"));
		viewPort = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("viewport"));
		dimensionWidth = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("dimension_width"));
		dimensionHeight = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("dimension_height"));
		dimensionDepth = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("dimension_depth"));
		dimensionApply = dynamic_cast<GUIElementNode*>(screenNode->getNodeById("button_dimension_apply"));
	} catch (Exception& exception) {
		Console::print(string("EnvironmentMappingScreenController::initialize(): An error occurred: "));
		Console::println(string(exception.what()));
	}
	entityBaseSubScreenController->initialize(screenNode);
}

void EnvironmentMappingScreenController::dispose()
{
}

void EnvironmentMappingScreenController::setScreenCaption(const string& text)
{
	screenCaption->setText(text);
}

void EnvironmentMappingScreenController::setEntityData(const string& name, const string& description)
{
	entityBaseSubScreenController->setEntityData(name, description);
}

void EnvironmentMappingScreenController::unsetEntityData()
{
	entityBaseSubScreenController->unsetEntityData();
}

void EnvironmentMappingScreenController::setEntityProperties(const string& presetId, const string& selectedName)
{
	entityBaseSubScreenController->setEntityProperties(view->getEntity(), presetId, selectedName);
}

void EnvironmentMappingScreenController::unsetEntityProperties()
{
	entityBaseSubScreenController->unsetEntityProperties();
}

void EnvironmentMappingScreenController::setDimension(float width, float height, float depth)
{
	dimensionWidth->getController()->setDisabled(false);
	dimensionWidth->getController()->setValue(Tools::formatFloat(width));
	dimensionHeight->getController()->setDisabled(false);
	dimensionHeight->getController()->setValue(Tools::formatFloat(height));
	dimensionDepth->getController()->setDisabled(false);
	dimensionDepth->getController()->setValue(Tools::formatFloat(depth));
	dimensionApply->getController()->setDisabled(false);
}

void EnvironmentMappingScreenController::unsetDimension()
{
	dimensionWidth->getController()->setDisabled(true);
	dimensionWidth->getController()->setValue(TEXT_EMPTY);
	dimensionHeight->getController()->setDisabled(true);
	dimensionHeight->getController()->setValue(TEXT_EMPTY);
	dimensionDepth->getController()->setDisabled(true);
	dimensionDepth->getController()->setValue(TEXT_EMPTY);
	dimensionApply->getController()->setDisabled(true);
}

void EnvironmentMappingScreenController::onDimensionApply()
{
	try {
		auto width = Float::parseFloat(dimensionWidth->getController()->getValue().getString());
		auto height = Float::parseFloat(dimensionHeight->getController()->getValue().getString());
		auto depth = Float::parseFloat(dimensionDepth->getController()->getValue().getString());
		view->setDimension(width, height, depth);
	} catch (Exception& exception) {
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void EnvironmentMappingScreenController::onQuit()
{
	TDMELevelEditor::getInstance()->quit();
}

void EnvironmentMappingScreenController::showErrorPopUp(const string& caption, const string& message)
{
	view->getPopUpsViews()->getInfoDialogScreenController()->show(caption, message);
}

void EnvironmentMappingScreenController::onValueChanged(GUIElementNode* node)
{
	entityBaseSubScreenController->onValueChanged(node, view->getEntity());
}

void EnvironmentMappingScreenController::onActionPerformed(GUIActionListenerType type, GUIElementNode* node)
{
	entityBaseSubScreenController->onActionPerformed(type, node, view->getEntity());
	auto v = type;
	if (type == GUIActionListenerType::PERFORMED) {
		if (node->getId().compare("button_dimension_apply") == 0) {
			onDimensionApply();
		}
	}
}

void EnvironmentMappingScreenController::getViewPort(int& left, int& top, int& width, int& height) {
	auto& constraints = viewPort->getComputedConstraints();
	left = constraints.left + constraints.alignmentLeft + constraints.contentAlignmentLeft;
	top = constraints.top + constraints.alignmentTop + constraints.contentAlignmentTop;
	width = constraints.width;
	height = constraints.height;
}
