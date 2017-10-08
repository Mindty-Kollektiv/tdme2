#pragma once

#include <array>

#include <tdme.h>
#include <tdme/gui/events/fwd-tdme.h>
#include <tdme/gui/nodes/fwd-tdme.h>
#include <tdme/utils/fwd-tdme.h>
#include <tdme/gui/nodes/GUINodeController.h>

using std::array;

using tdme::gui::nodes::GUINodeController;
using tdme::gui::events::GUIKeyboardEvent;
using tdme::gui::events::GUIMouseEvent;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUIInputInternalController_CursorMode;
using tdme::gui::nodes::GUINode;
using tdme::utils::MutableString;

/** 
 * GUI input internal controller
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::gui::nodes::GUIInputInternalController final
	: public GUINodeController
{

private:
	static constexpr int64_t CURSOR_MODE_DURATION { 500LL };
	static constexpr int64_t DRAGGING_CALMDOWN { 50LL };
	GUIElementNode* inputNode {  };
	int64_t cursorModeStarted {  };
	GUIInputInternalController_CursorMode* cursorMode {  };
	int32_t index {  };
	int32_t offset {  };
	bool isDragging {  };
	array<float, 2> dragPosition {  };
	int64_t draggingTickLast {  };

public:
	bool isDisabled() override;
	void setDisabled(bool disabled) override;
	void initialize() override;
	void dispose() override;
	void postLayout() override;

public: /* protected */

	/** 
	 * @return index
	 */
	int32_t getIndex();

	/** 
	 * @return offset
	 */
	int32_t getOffset();

	/** 
	 * Reset cursor mode
	 */
	void resetCursorMode();

	/** 
	 * @return cursor mode
	 */
	GUIInputInternalController_CursorMode* getCursorMode();

public:
	void handleMouseEvent(GUINode* node, GUIMouseEvent* event) override;

private:

	/** 
	 * Check and correct offset
	 */
	void checkOffset();

public:
	void handleKeyboardEvent(GUINode* node, GUIKeyboardEvent* event) override;
	void tick() override;
	void onFocusGained() override;
	void onFocusLost() override;
	bool hasValue() override;
	MutableString* getValue() override;
	void setValue(MutableString* value) override;

public: /* protected */
	GUIInputInternalController(GUINode* node);

private:
	void init();
	friend class GUIInputInternalController_CursorMode;
};
