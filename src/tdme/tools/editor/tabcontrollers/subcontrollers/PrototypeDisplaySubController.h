#pragma once

#include <array>

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/prototype/fwd-tdme.h>
#include <tdme/gui/events/fwd-tdme.h>
#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/nodes/fwd-tdme.h>
#include <tdme/tools/editor/misc/fwd-tdme.h>
#include <tdme/tools/editor/tabcontrollers/subcontrollers/fwd-tdme.h>
#include <tdme/tools/editor/tabviews/subviews/fwd-tdme.h>
#include <tdme/tools/editor/views/fwd-tdme.h>
#include <tdme/utilities/fwd-tdme.h>
#include <tdme/utilities/MutableString.h>

using std::array;

using tdme::engine::Engine;
using tdme::engine::prototype::Prototype;
using tdme::gui::events::GUIActionListenerType;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUIScreenNode;
using tdme::tools::editor::misc::PopUps;
using tdme::tools::editor::tabviews::subviews::PrototypeDisplaySubView;
using tdme::tools::editor::tabviews::subviews::PrototypePhysicsSubView;
using tdme::tools::editor::views::EditorView;
using tdme::utilities::MutableString;

/**
 * Prototype display sub screen controller
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::tools::editor::tabcontrollers::subcontrollers::PrototypeDisplaySubController final
{
private:
	GUIScreenNode* screenNode { nullptr };
	EditorView* editorView { nullptr };
	PrototypeDisplaySubView* view { nullptr };
	PrototypePhysicsSubView* physicsView { nullptr };
	PopUps* popUps { nullptr };

	bool displayShadowing { true };
	bool displayGround { true };
	bool displayBoundingVolumes { true };

	array<string, 6> applyDisplayNodes = {
		"rendering_shader",
		"rendering_distance_shader",
		"rendering_distanceshader_distance",
		"rendering_contributes_shadows",
		"rendering_receives_shadows",
		"rendering_render_groups"
	};
	array<string, 2> reloadOuterlinerDisplayNodes = {
		"rendering_shader",
		"rendering_distance_shader",
	};

public:
	/**
	 * Public constructor
	 * @param editorView editor view
	 * @param engine engine
	 * @param physicsView physics view
	 */
	PrototypeDisplaySubController(EditorView* editorView, Engine* engine, PrototypePhysicsSubView* physicsView);

	/**
	 * Destructor
	 */
	~PrototypeDisplaySubController();

	/**
	 * @return view
	 */
	PrototypeDisplaySubView* getView();

	/**
	 * Init
	 * @param screenNode screen node
	 */
	void initialize(GUIScreenNode* screenNode);

	/**
	 * @return display shadowing checked
	 */
	bool getDisplayShadowing();

	/**
	 * @return display ground checked
	 */
	bool getDisplayGround();

	/**
	 * @return display bounding volume checked
	 */
	bool getDisplayBoundingVolume();

	/**
	 * Create display properties XML
	 * @param prototype prototype
	 * @param xml xml
	 */
	void createDisplayPropertiesXML(Prototype* prototype, string& xml);

	/**
	 * Set display details
	 * @param prototype prototype
	 */
	void setDisplayDetails(Prototype* prototype);

	/**
	 * Apply display details
	 * @param prototype prototype
	 */
	void applyDisplayDetails(Prototype* prototype);

	/**
	 * On value changed
	 * @param node node
	 * @param prototype prototype
	 */
	void onValueChanged(GUIElementNode* node, Prototype* prototype);

	/**
	 * On action performed
	 * @param type type
	 * @param node node
	 * @param prototype prototype
	 */
	void onActionPerformed(GUIActionListenerType type, GUIElementNode* node, Prototype* prototype);

	/**
	 * Shows the error pop up
	 * @param caption caption
	 * @param message message
	 */
	void showErrorPopUp(const string& caption, const string& message);

};
