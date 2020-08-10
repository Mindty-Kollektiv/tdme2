#pragma once

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/model/fwd-tdme.h>
#include <tdme/engine/primitives/fwd-tdme.h>
#include <tdme/application/Application.h>
#include <tdme/tests/fwd-tdme.h>
#include <tdme/application/InputEventHandler.h>
#include <tdme/utils/ObjectDeleter.h>

using tdme::application::Application;
using tdme::engine::Engine;
using tdme::engine::model::Model;
using tdme::engine::primitives::BoundingVolume;
using tdme::utils::ObjectDeleter;

/** 
 * LOD test
 * @author andreas.drewke
 * @version $Id$
 */
class tdme::tests::LODTest final
	: public virtual Application, public virtual InputEventHandler
{
private:
	Engine* engine { nullptr };

	bool keyLeft { false };
	bool keyRight { false };
	bool keyUp { false };
	bool keyDown { false };
	bool keyA { false };
	bool keyD { false };
	bool keyW { false };
	bool keyS { false };
	float camRotationY { 0.0f };
	ObjectDeleter<Model> modelDeleter;
	ObjectDeleter<BoundingVolume> bvDeleter;

public:

	/** 
	 * Main
	 * @param argc argument count
	 * @param argv argument values
	 */
	static void main(int argc, char** argv);

	/**
	 * Public constructor
	 */
	LODTest();

	// overriden methods
	void display() override;
	void dispose() override;
	void initialize() override;
	void reshape(int32_t width, int32_t height) override;

	// override methods
	void onChar(unsigned int key, int x, int y) override;
	void onKeyDown (unsigned char key, int x, int y) override;
	void onKeyUp(unsigned char key, int x, int y) override;
	void onSpecialKeyDown (int key, int x, int y) override;
	void onSpecialKeyUp(int key, int x, int y) override;
	void onMouseDragged(int x, int y) override;
	void onMouseMoved(int x, int y) override;
	void onMouseButton(int button, int state, int x, int y) override;
	void onMouseWheel(int button, int direction, int x, int y) override;

};
