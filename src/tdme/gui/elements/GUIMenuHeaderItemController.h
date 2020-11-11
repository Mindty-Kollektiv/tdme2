#pragma once

#include <string>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/gui/elements/fwd-tdme.h>
#include <tdme/gui/events/fwd-tdme.h>
#include <tdme/gui/nodes/fwd-tdme.h>
#include <tdme/gui/nodes/GUIElementController.h>
#include <tdme/utilities/MutableString.h>

using std::vector;
using std::string;

using tdme::gui::nodes::GUINodeController;
using tdme::gui::events::GUIKeyboardEvent;
using tdme::gui::events::GUIMouseEvent;
using tdme::gui::nodes::GUIElementController;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUINode;
using tdme::gui::nodes::GUIParentNode;
using tdme::utilities::MutableString;

/**
 * GUI menu header item controller
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::gui::elements::GUIMenuHeaderItemController final
	: public GUIElementController
{
	friend class GUIMenuHeaderController;
	friend class GUIMenuHeaderItem;
	friend class GUIMenuHeaderItemOptionController;
	friend class GUIMenuItemController;

private:
	static string CONDITION_DISABLED;
	static string CONDITION_ENABLED;
	static string CONDITION_OPENED;
	static string CONDITION_CLOSED;
	static string CONDITION_SELECTED;
	static string CONDITION_UNSELECTED;
	vector<GUINode*> childControllerNodes;
	vector<GUIMenuItemController*> menuItemControllers;
	bool open;
	bool disabled;
	bool selected;
	MutableString value;
	GUINode* itemNode { nullptr };

private:
	/**
	 * Private constructor
	 * @param node node
	 */
	GUIMenuHeaderItemController(GUINode* node);

	/**
	 * Initialize
	 */
	void init();

	/**
	 * @return drop down open state
	 */
	bool isOpen();

	/**
	 * @return is selected
	 */
	bool isSelected();

	/**
	 * Select
	 */
	void select();

	/**
	 * Unselect
	 */
	void unselect();

	/**
	 * Toggle open state
	 */
	void toggleOpenState();

	/**
	 * Determine menu item controllers
	 */
	void determineMenuItemControllers();

	/**
	 * Get selected option idx
	 */
	int32_t getSelectedMenuItemControllerIdx();

	/**
	 * Select next node
	 */
	void selectNext();

	/**
	 * Select previous
	 */
	void selectPrevious();

public:
	// overridden methods
	bool isDisabled() override;
	void setDisabled(bool disabled) override;
	void initialize() override;
	void dispose() override;
	void postLayout() override;
	void handleMouseEvent(GUINode* node, GUIMouseEvent* event) override;
	void handleKeyboardEvent(GUINode* node, GUIKeyboardEvent* event) override;
	void tick() override;
	void onFocusGained() override;
	void onFocusLost() override;
	bool hasValue() override;
	const MutableString& getValue() override;
	void setValue(const MutableString& value) override;

};
