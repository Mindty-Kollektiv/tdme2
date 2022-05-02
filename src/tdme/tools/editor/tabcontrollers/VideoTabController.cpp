#include <tdme/tools/editor/tabcontrollers/VideoTabController.h>

#include <string>

#include <tdme/tdme.h>
#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/events/GUIChangeListener.h>
#include <tdme/gui/nodes/GUIParentNode.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/gui/GUI.h>
#include <tdme/gui/GUIParser.h>
#include <tdme/os/filesystem/FileSystem.h>
#include <tdme/os/filesystem/FileSystemInterface.h>
#include <tdme/tools/editor/controllers/InfoDialogScreenController.h>
#include <tdme/tools/editor/misc/PopUps.h>
#include <tdme/tools/editor/misc/Tools.h>
#include <tdme/tools/editor/tabcontrollers/TabController.h>
#include <tdme/tools/editor/tabviews/VideoTabView.h>
#include <tdme/tools/editor/views/EditorView.h>
#include <tdme/utilities/Action.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>
#include <tdme/utilities/ExceptionBase.h>

using tdme::tools::editor::tabcontrollers::VideoTabController;

using std::string;

using tdme::gui::events::GUIActionListenerType;
using tdme::gui::nodes::GUIParentNode;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::GUI;
using tdme::gui::GUIParser;
using tdme::os::filesystem::FileSystem;
using tdme::os::filesystem::FileSystemInterface;
using tdme::tools::editor::controllers::InfoDialogScreenController;
using tdme::tools::editor::misc::PopUps;
using tdme::tools::editor::misc::Tools;
using tdme::tools::editor::tabcontrollers::TabController;
using tdme::tools::editor::tabviews::VideoTabView;
using tdme::tools::editor::views::EditorView;
using tdme::utilities::Action;
using tdme::utilities::Console;
using tdme::utilities::Exception;
using tdme::utilities::ExceptionBase;

VideoTabController::VideoTabController(VideoTabView* view)
{
	this->view = view;
	this->popUps = view->getPopUps();
}

VideoTabController::~VideoTabController() {
}

VideoTabView* VideoTabController::getView() {
	return view;
}

GUIScreenNode* VideoTabController::getScreenNode()
{
	return screenNode;
}

void VideoTabController::initialize(GUIScreenNode* screenNode)
{
	this->screenNode = screenNode;
}

void VideoTabController::dispose()
{
}

void VideoTabController::save()
{
}

void VideoTabController::saveAs()
{
}

void VideoTabController::showErrorPopUp(const string& caption, const string& message)
{
	popUps->getInfoDialogScreenController()->show(caption, message);
}

void VideoTabController::onValueChanged(GUIElementNode* node)
{
}

void VideoTabController::onFocus(GUIElementNode* node) {
}

void VideoTabController::onUnfocus(GUIElementNode* node) {
}

void VideoTabController::onContextMenuRequested(GUIElementNode* node, int mouseX, int mouseY) {
}

void VideoTabController::setOutlinerContent() {
	string xml;
	xml+= "<selectbox-option text=\"Video\" value=\"texture\" />\n";
	view->getEditorView()->setOutlinerContent(xml);
}

void VideoTabController::setOutlinerAddDropDownContent() {
	view->getEditorView()->setOutlinerAddDropDownContent(string());
}

void VideoTabController::onActionPerformed(GUIActionListenerType type, GUIElementNode* node)
{
}