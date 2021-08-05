#include <tdme/tools/editor/tabcontrollers/SceneEditorTabController.h>

#include <string>

#include <tdme/engine/Engine.h>
#include <tdme/engine/fileio/models/ModelReader.h>
#include <tdme/engine/fileio/prototypes/PrototypeReader.h>
#include <tdme/engine/model/RotationOrder.h>
#include <tdme/engine/prototype/BaseProperty.h>
#include <tdme/engine/prototype/Prototype.h>
#include <tdme/engine/scene/Scene.h>
#include <tdme/engine/scene/SceneEntity.h>
#include <tdme/engine/scene/SceneLibrary.h>
#include <tdme/engine/Transformations.h>
#include <tdme/gui/GUI.h>
#include <tdme/gui/GUIParser.h>
#include <tdme/math/Math.h>
#include <tdme/utilities/Action.h>
#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/events/GUIChangeListener.h>
#include <tdme/gui/nodes/GUIElementNode.h>
#include <tdme/gui/nodes/GUINodeConditions.h>
#include <tdme/gui/nodes/GUINodeController.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/tools/editor/misc/Tools.h>
#include <tdme/tools/editor/controllers/ContextMenuScreenController.h>
#include <tdme/tools/editor/controllers/EditorScreenController.h>
#include <tdme/tools/editor/controllers/FileDialogScreenController.h>
#include <tdme/tools/editor/controllers/InfoDialogScreenController.h>
#include <tdme/tools/editor/tabcontrollers/TabController.h>
#include <tdme/tools/editor/tabcontrollers/subcontrollers/BasePropertiesSubController.h>
#include <tdme/tools/editor/views/EditorView.h>
#include <tdme/tools/editor/tabviews/SceneEditorTabView.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>
#include <tdme/utilities/Float.h>
#include <tdme/utilities/ExceptionBase.h>
#include <tdme/utilities/MutableString.h>
#include <tdme/utilities/StringTools.h>

using std::string;

using tdme::tools::editor::tabcontrollers::SceneEditorTabController;

using tdme::engine::fileio::models::ModelReader;
using tdme::engine::fileio::prototypes::PrototypeReader;
using tdme::engine::Engine;
using tdme::engine::Transformations;
using tdme::engine::model::RotationOrder;
using tdme::engine::prototype::BaseProperty;
using tdme::engine::prototype::Prototype;
using tdme::engine::scene::Scene;
using tdme::engine::scene::SceneEntity;
using tdme::engine::scene::SceneLibrary;
using tdme::utilities::Action;
using tdme::gui::GUIParser;
using tdme::gui::events::GUIActionListenerType;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUINodeConditions;
using tdme::gui::nodes::GUINodeController;
using tdme::gui::nodes::GUIScreenNode;
using tdme::math::Math;
using tdme::tools::editor::misc::Tools;
using tdme::tools::editor::controllers::ContextMenuScreenController;
using tdme::tools::editor::controllers::EditorScreenController;
using tdme::tools::editor::controllers::InfoDialogScreenController;
using tdme::tools::editor::controllers::FileDialogScreenController;
using tdme::tools::editor::misc::PopUps;
using tdme::tools::editor::tabcontrollers::TabController;
using tdme::tools::editor::tabcontrollers::subcontrollers::BasePropertiesSubController;
using tdme::tools::editor::tabviews::SceneEditorTabView;
using tdme::tools::editor::views::EditorView;
using tdme::utilities::Console;
using tdme::utilities::Exception;
using tdme::utilities::ExceptionBase;
using tdme::utilities::Float;
using tdme::utilities::MutableString;
using tdme::utilities::StringTools;

SceneEditorTabController::SceneEditorTabController(SceneEditorTabView* view)
{
	this->view = view;
	this->popUps = view->getPopUps();
	this->basePropertiesSubController = new BasePropertiesSubController(view->getEditorView(), "scene");
}

SceneEditorTabController::~SceneEditorTabController() {
	delete basePropertiesSubController;
}

SceneEditorTabView* SceneEditorTabController::getView() {
	return view;
}

GUIScreenNode* SceneEditorTabController::getScreenNode()
{
	return screenNode;
}

FileDialogPath* SceneEditorTabController::getModelPath()
{
	return &modelPath;
}

void SceneEditorTabController::initialize(GUIScreenNode* screenNode)
{
	this->screenNode = screenNode;
	basePropertiesSubController->initialize(screenNode);
	required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById(view->getTabId() + "_tab_viewport"))->getActiveConditions().add("tools");
	required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById(view->getTabId() + "_tab_viewport"))->getActiveConditions().add("snapping");
}

void SceneEditorTabController::dispose()
{
}

void SceneEditorTabController::save()
{
}

void SceneEditorTabController::saveAs()
{
}

void SceneEditorTabController::showErrorPopUp(const string& caption, const string& message)
{
	popUps->getInfoDialogScreenController()->show(caption, message);
}

void SceneEditorTabController::onValueChanged(GUIElementNode* node)
{
	if (node->getId() == "dropdown_outliner_add") {
		auto addOutlinerType = node->getController()->getValue().getString();
		// TODO
	} else
	if (node->getId() == "selectbox_outliner") {
		updateDetails(view->getEditorView()->getScreenController()->getOutlinerSelection());
		vector<string> selectedEntityIds;
		auto outlinerSelection = StringTools::tokenize(view->getEditorView()->getScreenController()->getOutlinerSelection(), "|");
		for (auto& selectedEntityId: outlinerSelection) {
			if (StringTools::startsWith(selectedEntityId, "scene.entities.") == false) continue;
			selectedEntityIds.push_back(StringTools::substring(selectedEntityId, string("scene.entities.").size()));
		}
		view->selectEntities(selectedEntityIds);
	} else
	if (node->getId() == view->getTabId() + "_tab_button_rotate") {
		view->setGizmoType(Gizmo::GIZMOTYPE_ROTATE);
		view->updateGizmo();
	} else
	if (node->getId() == view->getTabId() + "_tab_button_scale") {
		view->setGizmoType(Gizmo::GIZMOTYPE_SCALE);
		view->updateGizmo();
	} else
	if (node->getId() == view->getTabId() + "_tab_button_gizmo") {
		view->setGizmoType(Gizmo::GIZMOTYPE_ALL);
		view->updateGizmo();
	} else
	if (node->getId() == view->getTabId() + "_tab_checkbox_grid") {
		view->setGridEnabled(node->getController()->getValue().equals("1"));
	} else
	if (StringTools::startsWith(node->getId(), view->getTabId() + "_tab_checkbox_snapping") == true) {
		view->setSnapping(
			node->getController()->getValue().equals("1"),
			Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById(view->getTabId() + "_tab_snapping_x"))->getController()->getValue().getString()),
			Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById(view->getTabId() + "_tab_snapping_z"))->getController()->getValue().getString())
		);
	} else {
		for (auto& applyTranslationNode: applyTranslationNodes) {
			if (node->getId() == applyTranslationNode) {
				//
				try {
					view->applyTranslation(
						Vector3(
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_translation_x"))->getController()->getValue().getString()),
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_translation_y"))->getController()->getValue().getString()),
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_translation_z"))->getController()->getValue().getString())
						)
					);
				} catch (Exception& exception) {
					Console::println(string("SceneEditorTabController::onValueChanged(): An error occurred: ") + exception.what());;
					showErrorPopUp("Warning", (string(exception.what())));
				}
				//
				break;
			}
		}
		for (auto& applyRotationNode: applyRotationNodes) {
			if (node->getId() == applyRotationNode) {
				//
				try {
					view->applyRotation(
						Vector3(
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_rotation_x"))->getController()->getValue().getString()),
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_rotation_y"))->getController()->getValue().getString()),
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_rotation_z"))->getController()->getValue().getString())
						)
					);
				} catch (Exception& exception) {
					Console::println(string("SceneEditorTabController::onValueChanged(): An error occurred: ") + exception.what());;
					showErrorPopUp("Warning", (string(exception.what())));
				}
				//
				break;
			}
		}
		for (auto& applyScaleNode: applyScaleNodes) {
			if (node->getId() == applyScaleNode) {
				//
				try {
					view->applyScale(
						Vector3(
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_scale_x"))->getController()->getValue().getString()),
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_scale_y"))->getController()->getValue().getString()),
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_scale_z"))->getController()->getValue().getString())
						)
					);
				} catch (Exception& exception) {
					Console::println(string("SceneEditorTabController::onValueChanged(): An error occurred: ") + exception.what());;
					showErrorPopUp("Warning", (string(exception.what())));
				}
				//
				break;
			}
		}
		for (auto& applySkyNode: applySkyNodes) {
			if (node->getId() == applySkyNode) {
				//
				try {
					auto scene = view->getScene();
					scene->setSkyModelScale(
						Vector3(
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("sky_model_scale"))->getController()->getValue().getString()),
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("sky_model_scale"))->getController()->getValue().getString()),
							Float::parseFloat(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("sky_model_scale"))->getController()->getValue().getString())
						)
					);
					view->updateSky();
				} catch (Exception& exception) {
					Console::println(string("SceneEditorTabController::onValueChanged(): An error occurred: ") + exception.what());;
					showErrorPopUp("Warning", (string(exception.what())));
				}
				//
				break;
			}
		}
		for (auto& applyReflectionEnvironmentMappingNode: applyReflectionEnvironmentMappingNodes) {
			if (node->getId() == applyReflectionEnvironmentMappingNode) {
				//
				try {
					view->applyReflectionEnvironmentMappingId(required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("reflection_environmentmap"))->getController()->getValue().getString());
				} catch (Exception& exception) {
					Console::println(string("SceneEditorTabController::onValueChanged(): An error occurred: ") + exception.what());;
					showErrorPopUp("Warning", (string(exception.what())));
				}
				//
				break;
			}
		}
		basePropertiesSubController->onValueChanged(node, view->getScene());
	}
}

void SceneEditorTabController::onFocus(GUIElementNode* node) {
	basePropertiesSubController->onFocus(node, view->getScene());
}

void SceneEditorTabController::onUnfocus(GUIElementNode* node) {
	for (auto& applyBaseNode: applyBaseNodes) {
		if (node->getId() == applyBaseNode) {
			//
			try {
				auto name = required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("base_name"))->getController()->getValue().getString();
				if (name.empty() == true) throw ExceptionBase("Please enter a name");
				if (view->applyBase(
						name,
						required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("base_description"))->getController()->getValue().getString()
					) == false) {
					throw ExceptionBase("Could not rename entity");
				}
			} catch (Exception& exception) {
				Console::println(string("SceneEditorTabController::onValueChanged(): An error occurred: ") + exception.what());;
				showErrorPopUp("Warning", (string(exception.what())));
			}
			//
			break;
		}
	}
	basePropertiesSubController->onUnfocus(node, view->getScene());
}

void SceneEditorTabController::onContextMenuRequested(GUIElementNode* node, int mouseX, int mouseY) {
	if (node->getId() == "selectbox_outliner") {
		auto outlinerNode = view->getEditorView()->getScreenController()->getOutlinerSelection();
		if (StringTools::startsWith(outlinerNode, "scene.entities.") == true) {
			// clear
			popUps->getContextMenuScreenController()->clear();
			{
				// center
				class OnCenterAction: public virtual Action
				{
				public:
					void performAction() override {
						sceneEditorTabController->view->centerEntities();
					}
					OnCenterAction(SceneEditorTabController* sceneEditorTabController): sceneEditorTabController(sceneEditorTabController) {
					}
				private:
					SceneEditorTabController* sceneEditorTabController;
				};
				popUps->getContextMenuScreenController()->addMenuItem("Center", "contextmenu_center", new OnCenterAction(this));
			}
			{
				// select same
				class OnSelectSameAction: public virtual Action
				{
				public:
					void performAction() override {
						sceneEditorTabController->view->selectSameEntities();
					}
					OnSelectSameAction(SceneEditorTabController* sceneEditorTabController): sceneEditorTabController(sceneEditorTabController) {
					}
				private:
					SceneEditorTabController* sceneEditorTabController;
				};
				popUps->getContextMenuScreenController()->addMenuItem("Select same", "contextmenu_same", new OnSelectSameAction(this));
			}
			{
				// open prototype
				class OnOpenPrototype: public virtual Action
				{
				public:
					void performAction() override {
						sceneEditorTabController->view->openPrototype();
					}
					OnOpenPrototype(SceneEditorTabController* sceneEditorTabController): sceneEditorTabController(sceneEditorTabController) {
					}
				private:
					SceneEditorTabController* sceneEditorTabController;
				};
				popUps->getContextMenuScreenController()->addMenuItem("Open prototype", "contextmenu_openprototype", new OnOpenPrototype(this));
			}
			{
				// replace prototype
				class OnReplacePrototype: public virtual Action
				{
				public:
					void performAction() override {
						sceneEditorTabController->onReplacePrototype();
					}
					OnReplacePrototype(SceneEditorTabController* sceneEditorTabController): sceneEditorTabController(sceneEditorTabController) {
					}
				private:
					SceneEditorTabController* sceneEditorTabController;
				};
				popUps->getContextMenuScreenController()->addMenuItem("Replace prototype", "contextmenu_replaceprototype", new OnReplacePrototype(this));
			}
			{
				// delete
				class OnDeleteAction: public virtual Action
				{
				public:
					void performAction() override {
						sceneEditorTabController->view->removeEntities();
					}
					OnDeleteAction(SceneEditorTabController* sceneEditorTabController): sceneEditorTabController(sceneEditorTabController) {
					}
				private:
					SceneEditorTabController* sceneEditorTabController;
				};
				popUps->getContextMenuScreenController()->addMenuSeparator();
				popUps->getContextMenuScreenController()->addMenuItem("Delete", "contextmenu_delete", new OnDeleteAction(this));
			}
			//
			popUps->getContextMenuScreenController()->show(mouseX, mouseY);
		}
	} else {
		basePropertiesSubController->onContextMenuRequested(node, mouseX, mouseY, view->getScene());
	}
}

void SceneEditorTabController::onActionPerformed(GUIActionListenerType type, GUIElementNode* node)
{
	if (node->getId() == "sky_model_remove") {
		view->removeSky();
		auto scene = view->getScene();
		scene->setSkyModel(nullptr);
		scene->setSkyModelFileName(string());
		scene->setSkyModelScale(Vector3(1.0f, 1.0f, 1.0f));
	} else
	if (node->getId() == "sky_model_open") {
		class OnLoadSkyModelAction: public virtual Action
		{
		public:
			void performAction() override {
				try {
					sceneEditorTabController->view->removeSky();
					auto scene = sceneEditorTabController->view->getScene();
					scene->setSkyModelFileName(
						sceneEditorTabController->popUps->getFileDialogScreenController()->getPathName() +
						"/" +
						sceneEditorTabController->popUps->getFileDialogScreenController()->getFileName()
					);
					scene->setSkyModelScale(Vector3(1.0f, 1.0f, 1.0f));
					scene->setSkyModel(
						ModelReader::read(
							Tools::getPathName(scene->getSkyModelFileName()),
							Tools::getFileName(scene->getSkyModelFileName()))
					);
					sceneEditorTabController->modelPath.setPath(
						sceneEditorTabController->popUps->getFileDialogScreenController()->getPathName()
					);
					sceneEditorTabController->view->updateSky();
				} catch (Exception& exception) {
					Console::println(string("OnLoadSkyModel::performAction(): An error occurred: ") + exception.what());;
					sceneEditorTabController->showErrorPopUp("Warning", (string(exception.what())));
				}
				sceneEditorTabController->updateDetails("scene");
				sceneEditorTabController->view->getPopUps()->getFileDialogScreenController()->close();
			}

			/**
			 * Public constructor
			 * @param sceneEditorTabController scene editor tab controller
			 */
			OnLoadSkyModelAction(SceneEditorTabController* sceneEditorTabController)
				: sceneEditorTabController(sceneEditorTabController) {
				//
			}

		private:
			SceneEditorTabController* sceneEditorTabController;
		};

		auto extensions = ModelReader::getModelExtensions();
		popUps->getFileDialogScreenController()->show(
			modelPath.getPath(),
			"Load sky model from: ",
			extensions,
			string(),
			true,
			new OnLoadSkyModelAction(this)
		);
	} else {
		basePropertiesSubController->onActionPerformed(type, node, view->getScene());
	}
}

void SceneEditorTabController::setSkyDetails() {
	Console::println("SceneEditorTabController::setSkyDetails(): ");

	auto scene = view->getScene();

	view->getEditorView()->setDetailsContent(
		string("<template id=\"details_sky\" src=\"resources/engine/gui/template_details_sky.xml\" />")
	);

	//
	try {
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("details_sky"))->getActiveConditions().add("open");
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("sky_model_scale"))->getController()->setValue(
			Math::max(scene->getSkyModelScale().getX(), Math::max(scene->getSkyModelScale().getY(), scene->getSkyModelScale().getZ()))
		);
	} catch (Exception& exception) {
		Console::println(string("ModelEditorTabController::setEntityDetails(): An error occurred: ") + exception.what());;
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void SceneEditorTabController::updateReflectionEnvironmentMappingDetailsDropDown(const string& selectedReflectionEnvironmentMappingId) {
	auto scene = view->getScene();
	if (scene == nullptr) return;

	string reflectionEnvironmentMappingIdsXML =
		string() + "<dropdown-option text=\"<None>\" value=\"\" " + (selectedReflectionEnvironmentMappingId.empty() == true?"selected=\"true\" ":"") + " />\n";
	for (auto& environmentMappingId: scene->getEnvironmentMappingIds()) {
		reflectionEnvironmentMappingIdsXML+=
			"<dropdown-option text=\"" +
			GUIParser::escapeQuotes(environmentMappingId) +
			"\" value=\"" +
			GUIParser::escapeQuotes(environmentMappingId) +
			"\" " +
			(selectedReflectionEnvironmentMappingId == environmentMappingId?"selected=\"true\" ":"") +
			" />\n";
	}

	try {
		required_dynamic_cast<GUIParentNode*>(screenNode->getInnerNodeById("reflection_environmentmap"))->replaceSubNodes(reflectionEnvironmentMappingIdsXML, true);
	} catch (Exception& exception) {
		Console::print(string("SceneEditorTabController::updateReflectionEnvironmentMappingDetailsDropDown(): An error occurred: "));
		Console::println(string(exception.what()));
	}
}

void SceneEditorTabController::setEntityDetails(const string& entityId) {
	Console::println("SceneEditorTabController::setEntityDetails(): " + entityId);

	auto scene = view->getScene();
	auto entity = scene->getEntity(entityId);
	if (entity == nullptr) return;

	view->getEditorView()->setDetailsContent(
		string("<template id=\"details_base\" src=\"resources/engine/gui/template_details_base.xml\" />") +
		string("<template id=\"details_transformations\" src=\"resources/engine/gui/template_details_transformation.xml\" />") +
		string("<template id=\"details_reflections\" src=\"resources/engine/gui/template_details_reflection.xml\" />")
	);

	//
	try {
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("details_base"))->getActiveConditions().add("open");
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("details_transformations"))->getActiveConditions().add("open");
		if ((entity->getPrototype()->getType()->getGizmoTypeMask() & Gizmo::GIZMOTYPE_ROTATE) == Gizmo::GIZMOTYPE_ROTATE) {
			required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("details_transformations"))->getActiveConditions().add("rotation");
		}
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("details_reflections"))->getActiveConditions().add("open");

		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("base_name"))->getController()->setValue(entity->getId());
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("base_description"))->getController()->setValue(entity->getDescription());
	} catch (Exception& exception) {
		Console::println(string("ModelEditorTabController::setEntityDetails(): An error occurred: ") + exception.what());;
		showErrorPopUp("Warning", (string(exception.what())));
	}

	//
	updateReflectionEnvironmentMappingDetailsDropDown(entity->getReflectionEnvironmentMappingId());
	updateEntityDetails(entity->getTransformations());
}

void SceneEditorTabController::setEntityDetailsMultiple(const Vector3& pivot, const string& selectedReflectionEnvironmentMappingId) {
	Console::println("SceneEditorTabController::setEntityDetailsMultiple(): ");

	auto scene = view->getScene();

	view->getEditorView()->setDetailsContent(
		string("<template id=\"details_transformations\" src=\"resources/engine/gui/template_details_transformation.xml\" />") +
		string("<template id=\"details_reflections\" src=\"resources/engine/gui/template_details_reflection.xml\" />")
	);

	//
	try {
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("details_transformations"))->getActiveConditions().add("open");
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("details_transformations"))->getActiveConditions().add("rotation");
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("details_reflections"))->getActiveConditions().add("open");
	} catch (Exception& exception) {
		Console::println(string("ModelEditorTabController::setEntityDetails(): An error occurred: ") + exception.what());;
		showErrorPopUp("Warning", (string(exception.what())));
	}

	//
	updateReflectionEnvironmentMappingDetailsDropDown(selectedReflectionEnvironmentMappingId);
	updateEntityDetails(
		pivot,
		Vector3(),
		Vector3(1.0f, 1.0f, 1.0f)
	);
}

void SceneEditorTabController::updateEntityDetails(const Transformations& transformations) {
	auto scene = view->getScene();
	updateEntityDetails(
		transformations.getTranslation(),
		Vector3(
			transformations.getRotationAngle(scene->getRotationOrder()->getAxisXIndex()),
			transformations.getRotationAngle(scene->getRotationOrder()->getAxisYIndex()),
			transformations.getRotationAngle(scene->getRotationOrder()->getAxisZIndex())
		),
		transformations.getScale()
	);

}

void SceneEditorTabController::updateEntityDetails(const Vector3& translation, const Vector3& rotation, const Vector3& scale) {
	//
	try {
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_translation_x"))->getController()->setValue(translation.getX());
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_translation_y"))->getController()->setValue(translation.getY());
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_translation_z"))->getController()->setValue(translation.getZ());

		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_rotation_x"))->getController()->setValue(rotation.getX());
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_rotation_y"))->getController()->setValue(rotation.getY());
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_rotation_z"))->getController()->setValue(rotation.getZ());

		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_scale_x"))->getController()->setValue(scale.getX());
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_scale_y"))->getController()->setValue(scale.getY());
		required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("transformation_scale_z"))->getController()->setValue(scale.getZ());
	} catch (Exception& exception) {
		Console::println(string("ModelEditorTabController::updateEntityDetails(): An error occurred: ") + exception.what());;
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void SceneEditorTabController::setOutlinerContent() {

	string xml;
	xml+= "<selectbox-parent-option image=\"resources/engine/images/folder.png\" text=\"" + GUIParser::escapeQuotes("Scene") + "\" value=\"" + GUIParser::escapeQuotes("scene") + "\">\n";
	auto scene = view->getScene();
	if (scene != nullptr) {
		basePropertiesSubController->createBasePropertiesXML(scene, xml);
		{
			auto sceneLibrary = scene->getLibrary();
			xml+= "<selectbox-parent-option image=\"resources/engine/images/folder.png\" text=\"" + GUIParser::escapeQuotes("Prototypes") + "\" value=\"" + GUIParser::escapeQuotes("scene.prototypes") + "\">\n";
			for (auto i = 0; i < sceneLibrary->getPrototypeCount(); i++) {
				auto prototype = sceneLibrary->getPrototypeAt(i);
				auto icon = getPrototypeIcon(prototype->getType());
				auto prototypeName = prototype->getName();
				xml+= "	<selectbox-option image=\"resources/engine/images/" + icon +"\" text=\"" + GUIParser::escapeQuotes(prototypeName) + "\" value=\"" + GUIParser::escapeQuotes("scene.prototypes." + prototypeName) + "\" />\n";
			}
			xml+= "</selectbox-parent-option>\n";
		}
		{
			xml+= "<selectbox-parent-option image=\"resources/engine/images/folder.png\" text=\"" + GUIParser::escapeQuotes("Entities") + "\" value=\"" + GUIParser::escapeQuotes("scene.entities") + "\">\n";
			for (auto i = 0; i < scene->getEntityCount(); i++) {
				auto entity = scene->getEntityAt(i);
				auto entityName = entity->getName();
				auto prototype = entity->getPrototype();
				auto icon = getPrototypeIcon(prototype->getType());
				if (prototype->isRenderGroups() == true) continue;
				xml+= "	<selectbox-option image=\"resources/engine/images/" + icon + "\" text=\"" + GUIParser::escapeQuotes(entityName) + "\" value=\"" + GUIParser::escapeQuotes("scene.entities." + entityName) + "\" />\n";
			}
			xml+= "</selectbox-parent-option>\n";
		}
	}
	xml+= "</selectbox-parent-option>\n";
	view->getEditorView()->setOutlinerContent(xml);
}

void SceneEditorTabController::setOutlinerAddDropDownContent() {
	view->getEditorView()->setOutlinerAddDropDownContent(
		string("<dropdown-option text=\"Property\" value=\"property\" />\n")
	);
}

void SceneEditorTabController::setDetailsContent() {
	view->getEditorView()->setDetailsContent(string());
}

void SceneEditorTabController::updateDetails(const string& outlinerNode) {
	view->getEditorView()->setDetailsContent(string());
	if (outlinerNode == "scene") {
		setSkyDetails();
	} else
	if (StringTools::startsWith(outlinerNode, "scene.entities.") == true) {
		auto entityId = StringTools::substring(outlinerNode, string("scene.entities.").size());
		setEntityDetails(entityId);
	} else {
		basePropertiesSubController->updateDetails(view->getScene(), outlinerNode);
	}
}

void SceneEditorTabController::unselectEntities() {
	view->getEditorView()->getScreenController()->setOutlinerSelection("scene.entities");
	updateDetails("scene.entities");
}

void SceneEditorTabController::unselectEntity(const string& entityId) {
	auto outlinerSelection = StringTools::tokenize(view->getEditorView()->getScreenController()->getOutlinerSelection(), "|");
	vector<string> selectedEntityIds;
	auto entityIdToRemove = "scene.entities." + entityId;
	for (auto& selectedEntityId: outlinerSelection) {
		if (StringTools::startsWith(selectedEntityId, "scene.entities.") == false) continue;
		if (selectedEntityId == entityIdToRemove) continue;
		selectedEntityIds.push_back(selectedEntityId);
	}
	selectEntities(selectedEntityIds);
}

void SceneEditorTabController::selectEntity(const string& entityId) {
	auto outlinerSelection = StringTools::tokenize(view->getEditorView()->getScreenController()->getOutlinerSelection(), "|");
	vector<string> selectedEntityIds;
	auto entityIdToAdd = "scene.entities." + entityId;
	for (auto& selectedEntityId: outlinerSelection) {
		if (StringTools::startsWith(selectedEntityId, "scene.entities.") == false) continue;
		if (selectedEntityId == entityIdToAdd) continue;
		selectedEntityIds.push_back(selectedEntityId);
	}
	selectedEntityIds.push_back(entityIdToAdd);
	selectEntities(selectedEntityIds);
}

void SceneEditorTabController::selectEntities(const vector<string>& selectedOutlinerEntityIds) {
	if (selectedOutlinerEntityIds.empty() == true) {
		auto newOutlinerSelection = string("scene.entities");
		view->getEditorView()->getScreenController()->setOutlinerSelection(newOutlinerSelection);
		updateDetails(newOutlinerSelection);
	} else
	if (selectedOutlinerEntityIds.size() == 1) {
		auto newOutlinerSelection = string(selectedOutlinerEntityIds[0]);
		view->getEditorView()->getScreenController()->setOutlinerSelection(newOutlinerSelection);
		updateDetails(StringTools::substring(newOutlinerSelection, string("scene.entities.").size()));
	} else {
		auto newOutlinerSelection = string("|");
		for (auto& entityId: selectedOutlinerEntityIds) {
			newOutlinerSelection+= entityId + "|";
		}
		view->getEditorView()->getScreenController()->setOutlinerSelection(newOutlinerSelection);
		updateDetails("scene.entities");
	}
}

void SceneEditorTabController::onReplacePrototype() {
	class OnReplacePrototypeAction: public virtual Action
	{
	public:
		void performAction() override {
			try {
				auto outlinerSelection = StringTools::tokenize(sceneEditorTabController->view->getEditorView()->getScreenController()->getOutlinerSelection(), "|");
				if (outlinerSelection.size() != 1) return;
				string selectedEntityId;
				if (StringTools::startsWith(outlinerSelection[0], "scene.entities.") == false) return;
				selectedEntityId = StringTools::substring(outlinerSelection[0], string("scene.entities.").size());
				auto scene = sceneEditorTabController->view->getScene();
				auto sceneLibrary = scene->getLibrary();
				auto selectedSceneEntity = scene->getEntity(selectedEntityId);
				auto prototype = selectedSceneEntity != nullptr?selectedSceneEntity->getPrototype():nullptr;
				if (prototype == nullptr) return;
				auto newPrototype = PrototypeReader::read(
					sceneLibrary->allocatePrototypeId(),
					sceneEditorTabController->popUps->getFileDialogScreenController()->getPathName(),
					sceneEditorTabController->popUps->getFileDialogScreenController()->getFileName()
				);
				sceneLibrary->addPrototype(newPrototype);
				sceneEditorTabController->view->clearScene();
				scene->replacePrototypeByIds(prototype->getId(), newPrototype->getId());
				sceneEditorTabController->view->reloadScene();

				sceneEditorTabController->modelPath.setPath(sceneEditorTabController->popUps->getFileDialogScreenController()->getPathName());

				//
				class ReloadTabOutlinerAction: public Action {
				private:
					EditorView* editorView;
					string outlinerNode;
				public:
					ReloadTabOutlinerAction(EditorView* editorView, const string& outlinerNode): editorView(editorView), outlinerNode(outlinerNode) {}
					virtual void performAction() {
						editorView->reloadTabOutliner(outlinerNode);
						editorView->getScreenController()->getScreenNode()->delegateValueChanged(required_dynamic_cast<GUIElementNode*>(editorView->getScreenController()->getScreenNode()->getNodeById("selectbox_outliner")));
					}
				};
				Engine::getInstance()->enqueueAction(new ReloadTabOutlinerAction(sceneEditorTabController->view->getEditorView(), "scene.entities"));
			} catch (Exception& exception) {
				Console::println(string("OnReplacePrototypeAction::performAction(): An error occurred: ") + exception.what());;
				sceneEditorTabController->showErrorPopUp("Warning", (string(exception.what())));
			}
			sceneEditorTabController->view->getPopUps()->getFileDialogScreenController()->close();
		}

		/**
		 * Public constructor
		 * @param sceneEditorTabController scene editor tab controller
		 */
		OnReplacePrototypeAction(SceneEditorTabController* sceneEditorTabController)
			: sceneEditorTabController(sceneEditorTabController) {
			//
		}

	private:
		SceneEditorTabController* sceneEditorTabController;
	};

	auto extensions = PrototypeReader::getPrototypeExtensions();
	popUps->getFileDialogScreenController()->show(
		modelPath.getPath(),
		"Replace prototype with: ",
		extensions,
		string(),
		true,
		new OnReplacePrototypeAction(this)
	);
}
