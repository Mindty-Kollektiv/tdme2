#pragma once

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/subsystems/renderer/GLES2Renderer.h>

using tdme::engine::subsystems::renderer::GLES2Renderer;
using tdme::engine::Engine;

/**
 * Engine connector of GLES2 renderer to other engine functionality
 * @author Andreas Drewke
 */
class tdme::engine::EngineGLES2Renderer: public GLES2Renderer
{

public:
	// overriden methods
	void onUpdateProjectionMatrix() override;
	void onUpdateCameraMatrix() override;
	void onUpdateModelViewMatrix() override;
	void onBindTexture(void* context, int32_t textureId) override;
	void onUpdateTextureMatrix(void* context) override;
	void onUpdateEffect(void* context) override;
	void onUpdateLight(void* context, int32_t lightId) override;
	void onUpdateMaterial(void* context) override;
	void onUpdateShader() override;

	/**
	 * Public constructor
	 * @param engine engine
	 */
	EngineGLES2Renderer(Engine* engine);
private:
	Engine* engine;
};
