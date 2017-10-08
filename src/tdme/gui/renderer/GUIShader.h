#pragma once

#include <tdme.h>
#include <tdme/engine/subsystems/renderer/fwd-tdme.h>
#include <tdme/gui/renderer/fwd-tdme.h>

using tdme::engine::subsystems::renderer::GLRenderer;

/** 
 * GUI Shader
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::gui::renderer::GUIShader final
{

private:
	GLRenderer* renderer {  };
	int32_t vertexShaderGlId {  };
	int32_t fragmentShaderGlId {  };
	int32_t programGlId {  };
	int32_t uniformDiffuseTextureUnit {  };
	int32_t uniformDiffuseTextureAvailable {  };
	int32_t uniformEffectColorMul {  };
	int32_t uniformEffectColorAdd {  };
	bool initialized {  };
	bool isRunning {  };

public:

	/** 
	 * @return if initialized and ready to use
	 */
	bool isInitialized();

	/** 
	 * Init shadow mapping
	 */
	void initialize();

	/** 
	 * Use render GUI program
	 */
	void useProgram();

	/** 
	 * Un use render GUI program
	 */
	void unUseProgram();

	/** 
	 * Bind texture
	 * @param renderer
	 * @param texture id
	 */
	void bindTexture(GLRenderer* renderer, int32_t textureId);

	/** 
	 * Update effect to program
	 * @param renderer
	 */
	void updateEffect(GLRenderer* renderer);

	GUIShader(GLRenderer* renderer);
};
