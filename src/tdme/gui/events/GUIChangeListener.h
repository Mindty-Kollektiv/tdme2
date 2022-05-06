#pragma once

#include <tdme/tdme.h>
#include <tdme/gui/events/fwd-tdme.h>
#include <tdme/gui/nodes/fwd-tdme.h>

using tdme::gui::nodes::GUIElementNode;

/**
 * GUI change listener interface
 * @author Andreas Drewke
 */
struct tdme::gui::events::GUIChangeListener
{

	/**
	 * Destructor
	 */
	virtual ~GUIChangeListener() {}

	/**
	 * On value changed
	 * @param node node
	 */
	virtual void onValueChanged(GUIElementNode* node) = 0;
};
