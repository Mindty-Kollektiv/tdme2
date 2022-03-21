#include <tdme/tools/editor/tabviews/TextEditorTabView.h>

#include <cctype>
#include <string>

#include <tdme/tdme.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/gui/nodes/GUIStyledTextNode.h>
#include <tdme/gui/nodes/GUIStyledTextNodeController.h>
#include <tdme/gui/GUI.h>
#include <tdme/tools/editor/controllers/EditorScreenController.h>
#include <tdme/tools/editor/misc/CodeFormatter.h>
#include <tdme/tools/editor/tabcontrollers/TextEditorTabController.h>
#include <tdme/tools/editor/tabviews/TabView.h>
#include <tdme/tools/editor/views/EditorView.h>

using std::string;

using tdme::tools::editor::tabviews::TextEditorTabView;

using tdme::engine::Engine;
using tdme::engine::model::Color4;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::nodes::GUIStyledTextNode;
using tdme::gui::GUI;
using tdme::tools::editor::controllers::EditorScreenController;
using tdme::tools::editor::misc::CodeFormatter;
using tdme::tools::editor::tabcontrollers::TextEditorTabController;
using tdme::tools::editor::views::EditorView;

TextEditorTabView::TextEditorTabView(EditorView* editorView, const string& tabId, GUIScreenNode* screenNode, const string& extension)
{
	this->editorView = editorView;
	this->tabId = tabId;
	this->popUps = editorView->getPopUps();
	this->tabScreenNode = screenNode;
	this->extension = extension;
	this->textNode = required_dynamic_cast<GUIStyledTextNode*>(screenNode->getInnerNodeById("text"));
	engine = Engine::createOffScreenInstance(512, 512, false, false, false);
	engine->setSceneColor(Color4(125.0f / 255.0f, 125.0f / 255.0f, 125.0f / 255.0f, 1.0f));
	engine->getGUI()->addScreen(screenNode->getId(), screenNode);
	engine->getGUI()->addRenderScreen(screenNode->getId());

	// initial text format
	CodeFormatter::getInstance()->format(extension, textNode);
	//

	// add text node change listener
	class TextChangeListener: public GUIStyledTextNodeController::ChangeListener {
	public:
		TextChangeListener(TextEditorTabView* textEditorTabView): textEditorTabView(textEditorTabView) {
		}

		virtual ~TextChangeListener() {
		}

		virtual void onRemoveText(int idx, int count) override {
			CodeFormatter::getInstance()->format(textEditorTabView->extension, textEditorTabView->textNode);
		}
		virtual void onInsertText(int idx, int count) override {
			CodeFormatter::getInstance()->format(textEditorTabView->extension, textEditorTabView->textNode);
		}
	private:
		TextEditorTabView* textEditorTabView;
	};
	required_dynamic_cast<GUIStyledTextNodeController*>(textNode->getController())->addChangeListener(textNodeChangeListener = new TextChangeListener(this));
}

TextEditorTabView::~TextEditorTabView() {
	delete textEditorTabController;
	delete engine;
	delete textNodeChangeListener;
}

void TextEditorTabView::handleInputEvents()
{
	engine->getGUI()->handleEvents();
}

void TextEditorTabView::display()
{
	engine->display();
	engine->getGUI()->render();
}

void TextEditorTabView::initialize()
{
	try {
		textEditorTabController = new TextEditorTabController(this);
		textEditorTabController->initialize(editorView->getScreenController()->getScreenNode());
	} catch (Exception& exception) {
		Console::print(string("TextEditorTabView::initialize(): An error occurred: "));
		Console::println(string(exception.what()));
	}
	// TODO: load settings
}

void TextEditorTabView::dispose()
{
	required_dynamic_cast<GUIStyledTextNodeController*>(textNode->getController())->removeChangeListener(textNodeChangeListener);
	engine->dispose();
}

void TextEditorTabView::updateRendering() {
}

Engine* TextEditorTabView::getEngine() {
	return engine;
}

void TextEditorTabView::activate() {
	textEditorTabController->setOutlinerAddDropDownContent();
	textEditorTabController->setOutlinerContent();
	editorView->getScreenController()->restoreOutlinerState(outlinerState);
	editorView->getScreenController()->setDetailsContent(string());
}

void TextEditorTabView::deactivate() {
	editorView->getScreenController()->storeOutlinerState(outlinerState);
}

void TextEditorTabView::reloadOutliner() {
	textEditorTabController->setOutlinerContent();
	editorView->getScreenController()->setDetailsContent(string());
}

