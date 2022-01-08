#pragma once

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/subsystems/renderer/VKRenderer.h>

using tdme::engine::subsystems::renderer::VKRenderer;
using tdme::engine::Engine;

/**
 * Engine connector of VK renderer to other engine functionality
 * @author Andreas Drewke
 */

class tdme::engine::EngineVKRenderer: public VKRenderer
{
public:
	/**
	 * Public constructor
	 */
	EngineVKRenderer();

	// overridden methods
	bool initializeWindowSystemRendererContext(int tryIdx) override;
	void onUpdateProjectionMatrix(int contextIdx) override;
	void onUpdateCameraMatrix(int contextIdx) override;
	void onUpdateModelViewMatrix(int contextIdx) override;
	void onBindTexture(int contextIdx, int32_t textureId) override;
	void onUpdateTextureMatrix(int contextIdx) override;
	void onUpdateEffect(int contextIdx) override;
	void onUpdateLight(int contextIdx, int32_t lightId) override;
	void onUpdateMaterial(int contextIdx) override;
	void onUpdateShader(int contextIdx) override;
	void onUpdateShaderParameters(int contextIdx) override;

private:
	Engine* engine { nullptr };
};
