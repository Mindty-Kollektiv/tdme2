#pragma once

#include <string>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/gui/events/fwd-tdme.h>
#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/events/GUIChangeListener.h>
#include <tdme/gui/nodes/fwd-tdme.h>
#include <tdme/tools/editor/misc/fwd-tdme.h>
#include <tdme/tools/editor/tabcontrollers/TabController.h>
#include <tdme/tools/editor/tabviews/fwd-tdme.h>
#include <tdme/utilities/fwd-tdme.h>
#include <tdme/utilities/MiniScript.h>

#include <ext/tinyxml/tinyxml.h>

using std::string;
using std::vector;

using tdme::gui::events::GUIActionListener;
using tdme::gui::events::GUIActionListenerType;
using tdme::gui::events::GUIChangeListener;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUIParentNode;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::nodes::GUITextNode;
using tdme::tools::editor::misc::PopUps;
using tdme::tools::editor::tabcontrollers::TabController;
using tdme::tools::editor::tabviews::TextEditorTabView;
using tdme::utilities::MiniScript;

using tinyxml::TiXmlAttribute;
using tinyxml::TiXmlDocument;
using tinyxml::TiXmlElement;

/**
 * Text editor tab controller
 * @author Andreas Drewke
 */
class tdme::tools::editor::tabcontrollers::TextEditorTabController final
	: public TabController
{
public:
	struct MiniScriptScriptSyntaxTree {
		MiniScript::Script::ScriptType type;
		string condition;
		string name;
		MiniScript::ScriptSyntaxTreeNode conditionSyntaxTree;
		vector<MiniScript::ScriptSyntaxTreeNode> syntaxTree;
	};

private:
	TextEditorTabView* view { nullptr };
	GUIScreenNode* screenNode { nullptr };
	PopUps* popUps { nullptr };
	vector<MiniScriptScriptSyntaxTree> miniScriptSyntaxTrees;

public:
	/**
	 * Public constructor
	 * @param view view
	 */
	TextEditorTabController(TextEditorTabView* view);

	/**
	 * Destructor
	 */
	virtual ~TextEditorTabController();

	/**
	 * Get view
	 */
	TextEditorTabView* getView();

	// overridden method
	GUIScreenNode* getScreenNode() override;

	// overridden methods
	void initialize(GUIScreenNode* screenNode) override;
	void dispose() override;
	void onValueChanged(GUIElementNode* node) override;
	void onActionPerformed(GUIActionListenerType type, GUIElementNode* node) override;
	void onFocus(GUIElementNode* node) override;
	void onUnfocus(GUIElementNode* node) override;
	void onContextMenuRequested(GUIElementNode* node, int mouseX, int mouseY) override;
	void executeCommand(TabControllerCommand command) override;

	/**
	 * Set outliner content
	 */
	void setOutlinerContent();

	/**
	 * Set outliner add drop down content
	 */
	void setOutlinerAddDropDownContent();

	/**
	 * @return miniscript syntax trees
	 */
	inline const vector<MiniScriptScriptSyntaxTree>& getMiniScriptSyntaxTrees() {
		return miniScriptSyntaxTrees;
	}

	/**
	 * Update MiniScript syntax tree
	 * @param miniScriptScriptIdx MiniScript script index
	 */
	void updateMiniScriptSyntaxTree(int miniScriptScriptIdx);

	/**
	 * Shows the error pop up
	 * @param caption caption
	 * @param message message
	 */
	void showErrorPopUp(const string& caption, const string& message);

};
