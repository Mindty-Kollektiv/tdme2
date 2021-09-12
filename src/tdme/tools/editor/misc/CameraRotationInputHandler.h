#pragma once

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/primitives/BoundingBox.h>
#include <tdme/engine/Transformations.h>
#include <tdme/gui/events/GUIInputEventHandler.h>
#include <tdme/tools/editor/misc/fwd-tdme.h>

using tdme::engine::primitives::BoundingBox;
using tdme::engine::Engine;
using tdme::engine::Transformations;
using tdme::gui::events::GUIInputEventHandler;
using tdme::tools::editor::misc::CameraRotationInputHandlerEventHandler;

/**
 * Camera Rotation Input Handler
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::tools::editor::misc::CameraRotationInputHandler final
	: public GUIInputEventHandler
{
private:
	Engine* engine { nullptr };
	bool mouseDragging;
	bool keyLeft;
	bool keyRight;
	bool keyUp;
	bool keyDown;
	bool keyPeriod;
	bool keyComma;
	bool keyPlus;
	bool keyMinus;
	bool keyR;
	int mouseLastX;
	int mouseLastY;
	float maxAxisDimension;
	Transformations lookFromRotations;
	float scale;
	bool resetRequested;
	BoundingBox boundingBoxTransformed;
	CameraRotationInputHandlerEventHandler* eventHandler { nullptr };

public:
	/**
	 * Public constructor
	 * @param engine engine
	 * @param eventHandler event handler
	 */
	CameraRotationInputHandler(Engine* engine, CameraRotationInputHandlerEventHandler* eventHandler = nullptr);

	/**
	 * Destructor
	 */
	~CameraRotationInputHandler();

	/**
	 * @return max dimension on one of x,y,z axis
	 */
	float getMaxAxisDimension();

	/**
	 * Set max dimension on one of x,y,z axis
	 * @param maxAxisDimension max axis dimension
	 */
	void setMaxAxisDimension(float maxAxisDimension);

	/**
	 * @return look from rotation
	 */
	const Transformations& getLookFromRotations();

	/**
	 * @return scale
	 */
	float getScale();

	/**
	 * Set scale
	 * @param scale scale
	 */
	void setScale(float scale);

	/**
	 * Reset
	 */
	void reset();

	// overriden methods
	void handleInputEvents() override;

};