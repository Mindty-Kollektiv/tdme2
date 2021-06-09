#pragma once

#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/events/GUIChangeListener.h>
#include <tdme/gui/events/GUIContextMenuRequestListener.h>
#include <tdme/gui/events/GUIFocusListener.h>
#include <tdme/gui/nodes/fwd-tdme.h>
#include <tdme/tools/editor/tabcontrollers/fwd-tdme.h>

using tdme::gui::events::GUIActionListener;
using tdme::gui::events::GUIChangeListener;
using tdme::gui::events::GUIContextMenuRequestListener;
using tdme::gui::events::GUIFocusListener;
using tdme::gui::nodes::GUIScreenNode;

/**
 * Tab controller, which connects UI with logic
 * @author Andreas Drewke
 * @version $Id$
 */
struct tdme::tools::editor::tabcontrollers::TabController: public GUIActionListener, public GUIChangeListener, public GUIFocusListener, public GUIContextMenuRequestListener
{
	/**
	 * Destructor
	 */
	virtual ~TabController() {}

	/**
	 * Init
	 */
	virtual void initialize(GUIScreenNode* screenNode) = 0;

	/**
	 * Dispose
	 */
	virtual void dispose() = 0;

	// ???
	virtual GUIScreenNode* getScreenNode() = 0;

};
