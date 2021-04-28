#pragma once

#include <string>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/engine/prototype/fwd-tdme.h>
#include <tdme/tools/editor/misc/fwd-tdme.h>
#include <tdme/tools/editor/tabcontrollers/subcontrollers/fwd-tdme.h>
#include <tdme/tools/editor/tabviews/subviews/fwd-tdme.h>

using std::string;
using std::vector;

using tdme::engine::prototype::Prototype;
using tdme::tools::editor::misc::PopUps;
using tdme::tools::editor::tabcontrollers::subcontrollers::PrototypeSoundsSubController;

/**
 * Prototype sounds view
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::tools::editor::tabviews::subviews::PrototypeSoundsSubView final
{
private:
	PrototypeSoundsSubController* prototypeSoundsSubController { nullptr };
	PopUps* popUps { nullptr };

public:
	/**
	 * Public constructor
	 * @param prototypeSoundsSubController entity sounds sub screen controller
	 * @param popUps pop ups
	 */
	PrototypeSoundsSubView(PrototypeSoundsSubController* prototypeSoundsSubController, PopUps* popUps);

	/**
	 * @return pop ups
	 */
	PopUps* getPopUps();

	/**
	 * Unset sounds
	 */
	void unsetSounds();

	/**
	 * Set sounds
	 * @param prototype prototype
	 */
	void setSounds(Prototype* prototype);

};
