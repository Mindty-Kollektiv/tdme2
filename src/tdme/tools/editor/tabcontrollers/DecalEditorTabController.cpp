#include <tdme/tools/editor/tabcontrollers/DecalEditorTabController.h>

#include <string>

#include <tdme/tdme.h>
#include <tdme/engine/fileio/textures/PNGTextureWriter.h>
#include <tdme/engine/fileio/textures/TextureReader.h>
#include <tdme/engine/fileio/textures/Texture.h>
#include <tdme/engine/prototype/Prototype.h>
#include <tdme/engine/prototype/PrototypeDecal.h>
#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/events/GUIChangeListener.h>
#include <tdme/gui/nodes/GUIElementNode.h>
#include <tdme/gui/nodes/GUIImageNode.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/gui/nodes/GUITextNode.h>
#include <tdme/gui/GUI.h>
#include <tdme/gui/GUIParser.h>
#include <tdme/tools/editor/controllers/EditorScreenController.h>
#include <tdme/tools/editor/controllers/FileDialogScreenController.h>
#include <tdme/tools/editor/controllers/InfoDialogScreenController.h>
#include <tdme/tools/editor/misc/PopUps.h>
#include <tdme/tools/editor/misc/Tools.h>
#include <tdme/tools/editor/tabcontrollers/subcontrollers/BasePropertiesSubController.h>
#include <tdme/tools/editor/tabcontrollers/subcontrollers/PrototypeDisplaySubController.h>
#include <tdme/tools/editor/tabcontrollers/subcontrollers/PrototypePhysicsSubController.h>
#include <tdme/tools/editor/tabcontrollers/TabController.h>
#include <tdme/tools/editor/tabviews/subviews/PrototypePhysicsSubView.h>
#include <tdme/tools/editor/tabviews/DecalEditorTabView.h>
#include <tdme/tools/editor/views/EditorView.h>
#include <tdme/utilities/Action.h>
#include <tdme/utilities/Base64.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>
#include <tdme/utilities/ExceptionBase.h>
#include <tdme/utilities/MutableString.h>

using std::string;

using tdme::tools::editor::tabcontrollers::DecalEditorTabController;

using tdme::engine::fileio::textures::PNGTextureWriter;
using tdme::engine::fileio::textures::TextureReader;
using tdme::engine::fileio::textures::Texture;
using tdme::engine::prototype::Prototype;
using tdme::gui::events::GUIActionListenerType;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUIImageNode;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::nodes::GUITextNode;
using tdme::gui::GUIParser;
using tdme::tools::editor::controllers::EditorScreenController;
using tdme::tools::editor::controllers::FileDialogScreenController;
using tdme::tools::editor::controllers::InfoDialogScreenController;
using tdme::tools::editor::misc::PopUps;
using tdme::tools::editor::misc::Tools;
using tdme::tools::editor::tabcontrollers::subcontrollers::BasePropertiesSubController;
using tdme::tools::editor::tabcontrollers::subcontrollers::PrototypeDisplaySubController;
using tdme::tools::editor::tabcontrollers::subcontrollers::PrototypePhysicsSubController;
using tdme::tools::editor::tabcontrollers::TabController;
using tdme::tools::editor::tabviews::subviews::PrototypePhysicsSubView;
using tdme::tools::editor::tabviews::DecalEditorTabView;
using tdme::tools::editor::views::EditorView;
using tdme::utilities::Action;
using tdme::utilities::Base64;
using tdme::utilities::Console;
using tdme::utilities::Exception;
using tdme::utilities::ExceptionBase;
using tdme::utilities::MutableString;

DecalEditorTabController::DecalEditorTabController(DecalEditorTabView* view)
{
	this->view = view;
	this->popUps = view->getPopUps();
	this->basePropertiesSubController = new BasePropertiesSubController(view->getEditorView(), "prototype");
	this->prototypePhysicsSubController = new PrototypePhysicsSubController(view->getEditorView(), view, false);
	this->prototypeDisplaySubController = new PrototypeDisplaySubController(view->getEditorView(), view, this->prototypePhysicsSubController->getView());
}

DecalEditorTabController::~DecalEditorTabController() {
	delete prototypeDisplaySubController;
	delete prototypePhysicsSubController;
	delete basePropertiesSubController;
}

DecalEditorTabView* DecalEditorTabController::getView() {
	return view;
}

GUIScreenNode* DecalEditorTabController::getScreenNode()
{
	return screenNode;
}

void DecalEditorTabController::initialize(GUIScreenNode* screenNode)
{
	this->screenNode = screenNode;
	basePropertiesSubController->initialize(screenNode);
	prototypeDisplaySubController->initialize(screenNode);
	prototypePhysicsSubController->initialize(screenNode);
}

void DecalEditorTabController::dispose()
{
}

void DecalEditorTabController::save()
{
	auto fileName = view->getPrototype() != nullptr?view->getPrototype()->getFileName():"";
	try {
		if (fileName.empty() == true) throw ExceptionBase("Could not save file. No filename known");
		view->saveFile(
			Tools::getPathName(fileName),
			Tools::getFileName(fileName)
		);
	} catch (Exception& exception) {
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void DecalEditorTabController::saveAs()
{
	class OnDecalSave: public virtual Action
	{
	public:
		void performAction() override {
			try {
				decalEditorTabController->view->saveFile(
					decalEditorTabController->popUps->getFileDialogScreenController()->getPathName(),
					decalEditorTabController->popUps->getFileDialogScreenController()->getFileName()
				);
			} catch (Exception& exception) {
				decalEditorTabController->showErrorPopUp("Warning", (string(exception.what())));
			}
			decalEditorTabController->popUps->getFileDialogScreenController()->close();
		}
		OnDecalSave(DecalEditorTabController* decalEditorTabController): decalEditorTabController(decalEditorTabController) {
		}
	private:
		DecalEditorTabController* decalEditorTabController;
	};

	auto fileName = view->getPrototype() != nullptr?view->getPrototype()->getFileName():"";
	vector<string> extensions = {
		"tdecal"
	};
	popUps->getFileDialogScreenController()->show(
		fileName.empty() == false?Tools::getPathName(fileName):string(),
		"Save to: ",
		extensions,
		Tools::getFileName(fileName),
		false,
		new OnDecalSave(this)
	);
}

void DecalEditorTabController::onValueChanged(GUIElementNode* node)
{
	if (node->getId() == "selectbox_outliner") {
		auto outlinerNode = view->getEditorView()->getScreenController()->getOutlinerSelection();
		updateDetails(outlinerNode);
	}
	basePropertiesSubController->onValueChanged(node, view->getPrototype());
	prototypeDisplaySubController->onValueChanged(node, view->getPrototype());
	prototypePhysicsSubController->onValueChanged(node, view->getPrototype());
}

void DecalEditorTabController::onFocus(GUIElementNode* node) {
	basePropertiesSubController->onFocus(node, view->getPrototype());
}

void DecalEditorTabController::onUnfocus(GUIElementNode* node) {
	basePropertiesSubController->onUnfocus(node, view->getPrototype());
}

void DecalEditorTabController::onContextMenuRequested(GUIElementNode* node, int mouseX, int mouseY) {
	basePropertiesSubController->onContextMenuRequested(node, mouseX, mouseY, view->getPrototype());
	prototypePhysicsSubController->onContextMenuRequested(node, mouseX, mouseY, view->getPrototype());
}

void DecalEditorTabController::onActionPerformed(GUIActionListenerType type, GUIElementNode* node)
{
	if (type == GUIActionListenerType::PERFORMED) {
		if (node->getId() == "decal_texture_open") {
			//
			class OnDecalTextureFileOpenAction: public virtual Action
			{
			public:
				void performAction() override {
					auto prototype = decalEditorTabController->view->getPrototype();
					auto decal = prototype != nullptr?prototype->getDecal():nullptr;
					if (prototype != nullptr && decal != nullptr) {
						try {
							decal->setTextureFileName(
								decalEditorTabController->view->getPopUps()->getFileDialogScreenController()->getPathName() +
								"/" +
								decalEditorTabController->view->getPopUps()->getFileDialogScreenController()->getFileName()
							);
							if (decal->getTexture() != nullptr) {
								auto decalTextureThumbnail = TextureReader::scale(decal->getTexture(), 128, 128);
								vector<uint8_t> pngData;
								string base64PNGData;
								PNGTextureWriter::write(decalTextureThumbnail, pngData, false, false);
								Base64::encode(pngData, base64PNGData);
								prototype->setThumbnail(base64PNGData);
								decalTextureThumbnail->releaseReference();
							}
						} catch (Exception& exception) {
							Console::println(string() + "OnDecalTextureFileOpenAction::performAction(): An error occurred: " + exception.what());
							decalEditorTabController->showErrorPopUp("Warning", (string(exception.what())));
						}
						required_dynamic_cast<GUIImageNode*>(decalEditorTabController->screenNode->getNodeById("decal_texture"))->setSource(decal->getTextureFileName());
					}
					decalEditorTabController->view->getPopUps()->getFileDialogScreenController()->close();
				}

				/**
				 * Public constructor
				 * @param decalEditorTabController decal editor tab controller
				 */
				OnDecalTextureFileOpenAction(DecalEditorTabController* decalEditorTabController): decalEditorTabController(decalEditorTabController) {
				}

			private:
				DecalEditorTabController* decalEditorTabController;
			};

			auto prototype = view->getPrototype();
			if (prototype == nullptr) return;
			auto decal = prototype->getDecal();
			if (decal == nullptr) return;
			vector<string> extensions = TextureReader::getTextureExtensions();
			view->getPopUps()->getFileDialogScreenController()->show(
				decal->getTextureFileName().empty() == false?Tools::getPathName(decal->getTextureFileName()):string(),
				"Load decal texture from: ",
				extensions,
				Tools::getFileName(decal->getTextureFileName()),
				true,
				new OnDecalTextureFileOpenAction(this)
			);
		} else
		if (node->getId() == "decal_texture_remove") {
			auto prototype = view->getPrototype();
			if (prototype == nullptr) return;
			auto decal = prototype->getDecal();
			if (decal == nullptr) return;
			decal->setTextureFileName(string());
			prototype->setThumbnail(string());
			required_dynamic_cast<GUIImageNode*>(screenNode->getNodeById("decal_texture"))->setSource(prototype->getDecal()->getTextureFileName());
		} else
		if (node->getId() == "decal_texture_browseto") {

		}
	}
	basePropertiesSubController->onActionPerformed(type, node, view->getPrototype());
	prototypePhysicsSubController->onActionPerformed(type, node, view->getPrototype());
}

void DecalEditorTabController::setOutlinerContent() {
	string xml;
	xml+= "<selectbox-parent-option image=\"resources/engine/images/folder.png\" text=\"" + GUIParser::escapeQuotes("Prototype") + "\" value=\"" + GUIParser::escapeQuotes("prototype") + "\">\n";
	auto prototype = view->getPrototype();
	if (prototype != nullptr) {
		xml+= "<selectbox-option text=\"" + GUIParser::escapeQuotes("Decal") + "\" value=\"" + GUIParser::escapeQuotes("decal") + "\" />\n";
		basePropertiesSubController->createBasePropertiesXML(prototype, xml);
		prototypePhysicsSubController->createOutlinerPhysicsXML(prototype, xml);
	}
	xml+= "</selectbox-parent-option>\n";
	view->getEditorView()->setOutlinerContent(xml);
}

void DecalEditorTabController::setOutlinerAddDropDownContent() {
	view->getEditorView()->setOutlinerAddDropDownContent(
		string("<dropdown-option text=\"Property\" value=\"property\" />\n") +
		string("<dropdown-option text=\"BV\" value=\"boundingvolume\" />\n")
	);
}

void DecalEditorTabController::setDecalDetails() {
	view->getEditorView()->setDetailsContent(
		"<template id=\"details_decal\" src=\"resources/engine/gui/template_details_decal.xml\" />\n"
	);

	auto prototype = view->getPrototype();
	if (prototype == nullptr) return;
	auto decal = prototype->getDecal();
	if (decal == nullptr) return;

	//
	try {
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("details_decal"))->getActiveConditions().add("open");
		required_dynamic_cast<GUIImageNode*>(screenNode->getNodeById("decal_texture"))->setSource(decal->getTextureFileName());
	} catch (Exception& exception) {
		Console::println(string("DecalEditorTabController::setDecalDetails(): An error occurred: ") + exception.what());;
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void DecalEditorTabController::updateDetails(const string& outlinerNode) {
	if (outlinerNode == "decal") {
		setDecalDetails();
	} else {
		view->getEditorView()->setDetailsContent(string());
		basePropertiesSubController->updateDetails(view->getPrototype(), outlinerNode);
		prototypeDisplaySubController->updateDetails(view->getPrototype(), outlinerNode);
		prototypePhysicsSubController->updateDetails(view->getPrototype(), outlinerNode);
		prototypePhysicsSubController->getView()->setDisplayBoundingVolume(true);
	}
}

void DecalEditorTabController::updateInfoText(const MutableString& text) {
	required_dynamic_cast<GUITextNode*>(screenNode->getNodeById(view->getTabId() + "_tab_text_info"))->setText(text);
}

void DecalEditorTabController::showErrorPopUp(const string& caption, const string& message)
{
	popUps->getInfoDialogScreenController()->show(caption, message);
}
