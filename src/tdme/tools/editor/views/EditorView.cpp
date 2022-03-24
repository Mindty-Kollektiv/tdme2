#include <tdme/tools/editor/views/EditorView.h>

#include <string>

#include <tdme/tdme.h>
#include <tdme/audio/Audio.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/FrameBuffer.h>
#include <tdme/engine/SimplePartition.h>
#include <tdme/gui/nodes/GUIElementNode.h>
#include <tdme/gui/nodes/GUIFrameBufferNode.h>
#include <tdme/gui/nodes/GUINode.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/gui/GUI.h>
#include <tdme/math/Vector3.h>
#include <tdme/tools/editor/controllers/AboutDialogScreenController.h>
#include <tdme/tools/editor/controllers/ColorPickerScreenController.h>
#include <tdme/tools/editor/controllers/ContextMenuScreenController.h>
#include <tdme/tools/editor/controllers/EditorScreenController.h>
#include <tdme/tools/editor/controllers/FileDialogScreenController.h>
#include <tdme/tools/editor/controllers/InfoDialogScreenController.h>
#include <tdme/tools/editor/controllers/ProgressBarScreenController.h>
#include <tdme/tools/editor/misc/PopUps.h>
#include <tdme/tools/editor/misc/Tools.h>
#include <tdme/tools/editor/tabviews/TabView.h>
#include <tdme/tools/editor/TDMEEditor.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>

using std::string;

using tdme::audio::Audio;
using tdme::engine::Engine;
using tdme::engine::FrameBuffer;
using tdme::engine::SimplePartition;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUIFrameBufferNode;
using tdme::gui::nodes::GUINode;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::GUI;
using tdme::math::Vector3;
using tdme::tools::editor::controllers::AboutDialogScreenController;
using tdme::tools::editor::controllers::ColorPickerScreenController;
using tdme::tools::editor::controllers::ContextMenuScreenController;
using tdme::tools::editor::controllers::EditorScreenController;
using tdme::tools::editor::controllers::FileDialogScreenController;
using tdme::tools::editor::controllers::InfoDialogScreenController;
using tdme::tools::editor::controllers::ProgressBarScreenController;
using tdme::tools::editor::misc::CameraRotationInputHandler;
using tdme::tools::editor::misc::PopUps;
using tdme::tools::editor::misc::Tools;
using tdme::tools::editor::tabviews::TabView;
using tdme::tools::editor::views::EditorView;
using tdme::tools::editor::TDMEEditor;
using tdme::utilities::Console;
using tdme::utilities::Exception;

EditorView::EditorView(PopUps* popUps)
{
	this->popUps = popUps;
	editorScreenController = nullptr;
	engine = Engine::getInstance();
}

EditorView::~EditorView() {
	delete editorScreenController;
}

PopUps* EditorView::getPopUps()
{
	return popUps;
}

void EditorView::handleInputEvents()
{
	for (auto& event: Engine::getInstance()->getGUI()->getKeyboardEvents()) {
		// skip if already processed
		if (event.isProcessed() == true) return;

		//
		switch (event.getKeyCode()) {
			case (GUIKeyboardEvent::KEYCODE_F11):
				{
					if (event.getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
						editorScreenController->setFullScreen(editorScreenController->isFullScreen() == false?true:false);
					}
					event.setProcessed(true);
					break;
				}
			default:
				{
					break;
				}
		}
	}

	//
	auto tabView = editorScreenController->getSelectedTab();
	if (tabView != nullptr) {
		auto xScale = static_cast<float>(engine->getWidth()) / static_cast<float>(editorScreenController->getScreenNode()->getScreenWidth());
		auto yScale = static_cast<float>(engine->getHeight()) / static_cast<float>(editorScreenController->getScreenNode()->getScreenHeight());
		int left, top, width, height;
		getViewPort(tabView->getFrameBufferNode(), left, top, width, height);
		auto offsetX = tabView->getFrameBufferNode()->computeParentChildrenRenderOffsetXTotal();
		auto offsetY = tabView->getFrameBufferNode()->computeParentChildrenRenderOffsetYTotal();
		if (tabView->getId() != lastSelectedTabId) {
			auto lastTabView = lastSelectedTabId.empty() == true?nullptr:editorScreenController->getTab(lastSelectedTabId);
			if (lastTabView != nullptr) lastTabView->getTabView()->deactivate();
			tabView->getTabView()->activate();
			editorScreenController->getScreenNode()->invalidateLayout(editorScreenController->getScreenNode()->getNodeById(tabView->getFrameBufferNode()->getId()));
		}
		for (auto event: Engine::getInstance()->getGUI()->getMouseEvents()) {
			auto eventX = (event.getXUnscaled() - left + offsetX) / xScale;
			auto eventY = (event.getYUnscaled() - top + offsetY) / yScale;
			if ((eventX < 0 || eventX >= width || eventY < 0 || eventY >= height) &&
				event.getType() != GUIMouseEvent::MOUSEEVENT_RELEASED) continue;
			event.setX(eventX);
			event.setY(eventY);
			event.setXUnscaled(eventX);
			event.setYUnscaled(eventY);
			tabView->getTabView()->getEngine()->getGUI()->getMouseEvents().push_back(event);
		}
		for (auto& event: Engine::getInstance()->getGUI()->getKeyboardEvents()) {
			tabView->getTabView()->getEngine()->getGUI()->getKeyboardEvents().push_back(event);
		}
		tabView->getTabView()->handleInputEvents();
		for (auto i = 0; i < Engine::getInstance()->getGUI()->getKeyboardEvents().size(); i++) {
			auto& srcEvent = Engine::getInstance()->getGUI()->getKeyboardEvents()[i];
			auto& dstEvent = tabView->getTabView()->getEngine()->getGUI()->getKeyboardEvents()[i];
			if (dstEvent.isProcessed() == true) srcEvent.setProcessed(true);
		}
		tabView->getTabView()->getEngine()->getGUI()->getMouseEvents().clear();
		tabView->getTabView()->getEngine()->getGUI()->getKeyboardEvents().clear();
		lastSelectedTabId = tabView->getId();
	} else {
		auto lastTabView = editorScreenController->getTab(lastSelectedTabId);
		if (lastTabView != nullptr) lastTabView->getTabView()->deactivate();
		lastSelectedTabId.clear();
	}
}

void EditorView::display()
{
	auto tabView = editorScreenController->getSelectedTab();
	if (tabView != nullptr) {
		auto xScale = static_cast<float>(engine->getWidth()) / static_cast<float>(editorScreenController->getScreenNode()->getScreenWidth());
		auto yScale = static_cast<float>(engine->getHeight()) / static_cast<float>(editorScreenController->getScreenNode()->getScreenHeight());
		int left, top, width, height;
		getViewPort(tabView->getFrameBufferNode()->getParentNode(), left, top, width, height);
		width/= xScale;
		height/= yScale;
		auto reshaped = false;
		if (tabView->getTabView()->hasFixedSize() == false &&
			(tabView->getTabView()->getEngine()->getWidth() != width || tabView->getTabView()->getEngine()->getHeight() != height)) {
			tabView->getTabView()->getEngine()->reshape(width, height);
			reshaped = true;
		}
		tabView->getFrameBufferNode()->setFrameBuffer(tabView->getTabView()->getEngine()->getFrameBuffer());
		tabView->getTabView()->display();
		if (reshaped == true) {
			editorScreenController->getScreenNode()->invalidateLayout(editorScreenController->getScreenNode()->getNodeById(tabView->getFrameBufferNode()->getId()));
		}
	}
	//
	Audio::getInstance()->update();
}

void EditorView::updateGUIElements()
{
}

void EditorView::initialize()
{
	try {
		editorScreenController = new EditorScreenController(this);
		editorScreenController->initialize();
		engine->getGUI()->addScreen(editorScreenController->getScreenNode()->getId(), editorScreenController->getScreenNode());
		editorScreenController->getScreenNode()->setInputEventHandler(this);
	} catch (Exception& exception) {
		Console::print(string("EditorView::initialize(): An error occurred: "));
		Console::println(string(exception.what()));
	}
	updateGUIElements();
}

void EditorView::activate()
{
	engine->reset();
	engine->setPartition(new SimplePartition());
	engine->getGUI()->resetRenderScreens();
	engine->getGUI()->addRenderScreen(editorScreenController->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(popUps->getColorPickerScreenController()->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(popUps->getFileDialogScreenController()->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(popUps->getAboutDialogScreenController()->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(popUps->getProgressBarScreenController()->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(popUps->getInfoDialogScreenController()->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(popUps->getContextMenuScreenController()->getScreenNode()->getId());
}

void EditorView::deactivate()
{
}

void EditorView::dispose()
{
	editorScreenController->dispose();
	Engine::getInstance()->reset();
}

void EditorView::tick()
{
	//
	editorScreenController->tick();
}

void EditorView::setOutlinerContent(const string& xml) {
	editorScreenController->setOutlinerContent(xml);
}

void EditorView::setOutlinerAddDropDownContent(const string& xml) {
	editorScreenController->setOutlinerAddDropDownContent(xml);
}

void EditorView::setDetailsContent(const string& xml) {
	editorScreenController->setDetailsContent(xml);
}

void EditorView::reloadTabOutliner(const string& newSelectionValue) {
	auto selectedTabId = editorScreenController->getSelectedTabId();
	auto& tabViews = editorScreenController->getTabViews();
	auto tabViewIt = tabViews.find(selectedTabId);
	if (tabViewIt != tabViews.end()){
		auto& tab = tabViewIt->second;
		TabView::OutlinerState outlinerState;
		editorScreenController->storeOutlinerState(outlinerState);
		tab.getTabView()->reloadOutliner();
		if (newSelectionValue.empty() == false) outlinerState.value = newSelectionValue;
		editorScreenController->restoreOutlinerState(outlinerState);
	}
	editorScreenController->getScreenNode()->delegateValueChanged(required_dynamic_cast<GUIElementNode*>(editorScreenController->getScreenNode()->getNodeById("selectbox_outliner")));
}

void EditorView::getViewPort(GUINode* viewPortNode, int& left, int& top, int& width, int& height) {
	auto xScale = static_cast<float>(engine->getWidth()) / static_cast<float>(editorScreenController->getScreenNode()->getScreenWidth());
	auto yScale = static_cast<float>(engine->getHeight()) / static_cast<float>(editorScreenController->getScreenNode()->getScreenHeight());
	editorScreenController->getViewPort(viewPortNode, left, top, width, height);
	left = static_cast<int>(static_cast<float>(left) * xScale);
	top = static_cast<int>(static_cast<float>(top) * yScale);
	width = static_cast<int>(static_cast<float>(width) * xScale);
	height = static_cast<int>(static_cast<float>(height) * yScale);
}
