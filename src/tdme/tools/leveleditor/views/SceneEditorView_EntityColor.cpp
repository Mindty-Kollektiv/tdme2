#include <tdme/tools/leveleditor/views/SceneEditorView_EntityColor.h>

#include <tdme/tools/leveleditor/views/SceneEditorView.h>

using tdme::tools::leveleditor::views::SceneEditorView_EntityColor;
using tdme::tools::leveleditor::views::SceneEditorView;

SceneEditorView_EntityColor::SceneEditorView_EntityColor(SceneEditorView* sceneEditorView, float colorMulR, float colorMulG, float colorMulB, float colorAddR, float colorAddG, float colorAddB)
{
	this->sceneEditorView = sceneEditorView;
	this->colorMulR = colorMulR;
	this->colorMulG = colorMulG;
	this->colorMulB = colorMulB;
	this->colorAddR = colorAddR;
	this->colorAddG = colorAddG;
	this->colorAddB = colorAddB;
}
