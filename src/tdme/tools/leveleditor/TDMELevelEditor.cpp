#include <tdme/tools/leveleditor/TDMELevelEditor.h>

#include <cstdlib>
#include <string>

#include <tdme/utilities/Time.h>

#include <tdme/engine/Engine.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/gui/GUI.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/tools/leveleditor/controller/LevelEditorEntityLibraryScreenController.h>
#include <tdme/tools/leveleditor/views/EmptyView.h>
#include <tdme/tools/leveleditor/views/EnvironmentMappingView.h>
#include <tdme/tools/leveleditor/views/LevelEditorView.h>
#include <tdme/tools/leveleditor/views/ModelEditorView.h>
#include <tdme/tools/leveleditor/views/ParticleSystemView.h>
#include <tdme/tools/leveleditor/views/TriggerView.h>
#include <tdme/engine/scene/SceneLibrary.h>
#include <tdme/engine/scene/Scene.h>
#include <tdme/engine/scene/ScenePropertyPresets.h>
#include <tdme/tools/shared/tools/Tools.h>
#include <tdme/tools/shared/views/PopUps.h>
#include <tdme/tools/shared/views/View.h>
#include <tdme/utilities/Console.h>

using std::string;

using tdme::tools::leveleditor::TDMELevelEditor;
using tdme::utilities::Time;

using tdme::engine::Engine;
using tdme::engine::model::Color4;
using tdme::gui::GUI;
using tdme::gui::nodes::GUIScreenNode;
using tdme::tools::leveleditor::controller::LevelEditorEntityLibraryScreenController;
using tdme::tools::leveleditor::views::EmptyView;
using tdme::tools::leveleditor::views::EnvironmentMappingView;
using tdme::tools::leveleditor::views::LevelEditorView;
using tdme::tools::leveleditor::views::ModelEditorView;
using tdme::tools::leveleditor::views::ParticleSystemView;
using tdme::tools::leveleditor::views::TriggerView;
using tdme::engine::scene::Scene;
using tdme::engine::scene::SceneLibrary;
using tdme::engine::scene::ScenePropertyPresets;
using tdme::tools::shared::tools::Tools;
using tdme::tools::shared::views::PopUps;
using tdme::tools::shared::views::View;
using tdme::utilities::Console;

string TDMELevelEditor::VERSION = "1.9.9";

TDMELevelEditor* TDMELevelEditor::instance = nullptr;

void TDMELevelEditor::main(int argc, char** argv) {
	Console::println(string("TDMELevelEditor " + VERSION));
	Console::println(string("Programmed 2014,...,2018 by Andreas Drewke, drewke.net."));
	Console::println();
	auto tdmeLevelEditor = new TDMELevelEditor();
	tdmeLevelEditor->run(argc, argv, "TDMELevelEditor");
}

TDMELevelEditor::TDMELevelEditor() {
	Tools::loadSettings(this);
	TDMELevelEditor::instance = this;
	engine = Engine::getInstance();
	view = nullptr;
	popUps = new PopUps();
	quitRequested = false;

}

TDMELevelEditor::~TDMELevelEditor() {
	delete levelEditorView;
	delete modelEditorView;
	delete triggerView;
	delete emptyView;
	delete particleSystemView;
	delete popUps;
	delete prototypeLibraryScreenController;
}

TDMELevelEditor* TDMELevelEditor::getInstance() {
	return instance;
}

LevelEditorEntityLibraryScreenController* TDMELevelEditor::getLevelEditorEntityLibraryScreenController() {
	return prototypeLibraryScreenController;
}

SceneLibrary* TDMELevelEditor::getEntityLibrary() {
	return levelEditorView->getLevel()->getLibrary();
}

Scene* TDMELevelEditor::getLevel() {
	return levelEditorView->getLevel();
}

void TDMELevelEditor::setView(View* view) {
	if (this->view != nullptr)
		this->view->deactivate();

	this->view = view;
	if (this->view != nullptr)
		this->view->activate();

}

View* TDMELevelEditor::getView() {
	return view;
}

void TDMELevelEditor::quit() {
	quitRequested = true;
}

void TDMELevelEditor::display() {
	engine->display();
	if (view != nullptr)
		view->display();
	if (quitRequested == true) {
		dispose();
		Application::exit(0);
	}
}

void TDMELevelEditor::dispose() {
	if (view != nullptr)
		view->deactivate();

	levelEditorView->dispose();
	modelEditorView->dispose();
	triggerView->dispose();
	emptyView->dispose();
	particleSystemView->dispose();
	engine->dispose();
	Tools::oseDispose();
}

void TDMELevelEditor::initialize() {
	engine->initialize();
	engine->setSceneColor(Color4(125.0f / 255.0f, 125.0f / 255.0f, 125.0f / 255.0f, 1.0f));
	setInputEventHandler(engine->getGUI());
	Tools::oseInit();
	prototypeLibraryScreenController = new LevelEditorEntityLibraryScreenController(popUps);
	prototypeLibraryScreenController->initialize();
	engine->getGUI()->addScreen(
		prototypeLibraryScreenController->getScreenNode()->getId(),
		prototypeLibraryScreenController->getScreenNode()
	);
	popUps->initialize();
	levelEditorView = new LevelEditorView(popUps);
	levelEditorView->initialize();
	ScenePropertyPresets::getInstance()->setDefaultSceneProperties(levelEditorView->getLevel());
	modelEditorView = new ModelEditorView(popUps);
	modelEditorView->initialize();
	triggerView = new TriggerView(popUps);
	triggerView->initialize();
	environmentMappingView = new EnvironmentMappingView(popUps);
	environmentMappingView->initialize();
	emptyView = new EmptyView(popUps);
	emptyView->initialize();
	particleSystemView = new ParticleSystemView(popUps);
	particleSystemView->initialize();
	setView(levelEditorView);
}

void TDMELevelEditor::reshape(int width, int height) {
	engine->reshape(width, height);
}

void TDMELevelEditor::switchToLevelEditor() {
	setView(levelEditorView);
}

void TDMELevelEditor::switchToModelEditor() {
	setView(modelEditorView);
}

void TDMELevelEditor::switchToTriggerView() {
	setView(triggerView);
}

void TDMELevelEditor::switchToEnvironmentMappingView() {
	setView(environmentMappingView);
}

void TDMELevelEditor::switchToEmptyView() {
	setView(emptyView);
}

void TDMELevelEditor::switchToParticleSystemView() {
	setView(particleSystemView);
}

