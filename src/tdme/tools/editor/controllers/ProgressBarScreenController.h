#pragma once

#include <string>

#include <tdme/tdme.h>
#include <tdme/gui/events/fwd-tdme.h>
#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/nodes/fwd-tdme.h>
#include <tdme/tools/editor/controllers/fwd-tdme.h>
#include <tdme/tools/editor/controllers/ScreenController.h>
#include <tdme/utilities/fwd-tdme.h>

using std::string;

using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUIScreenNode;
using tdme::tools::editor::controllers::ScreenController;
using tdme::utilities::MutableString;

/**
 * Progress bar screen controller
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::tools::editor::controllers::ProgressBarScreenController final
	: public ScreenController
{

private:
	GUIScreenNode* screenNode { nullptr };
	GUIElementNode* progressBarNode { nullptr };

public:
	/**
	 * Public constructor
	 */
	ProgressBarScreenController();

	/**
	 * Destructor
	 */
	virtual ~ProgressBarScreenController();

	GUIScreenNode* getScreenNode() override;
	void initialize() override;
	void dispose() override;

	/**
	 * Shows the pop up
	 */
	void show();

	/**
	 * Show progress
	 * @param value value
	 */
	void progress(float value);

	/**
	 * Closes the pop up
	 */
	void close();

};
