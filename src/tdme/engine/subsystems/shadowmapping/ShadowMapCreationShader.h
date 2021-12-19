#pragma once

#include <map>
#include <string>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/subsystems/renderer/fwd-tdme.h>
#include <tdme/engine/subsystems/shadowmapping/fwd-tdme.h>
#include <tdme/math/Matrix4x4.h>

using std::map;
using std::string;
using std::vector;

using tdme::engine::subsystems::renderer::Renderer;
using tdme::engine::subsystems::shadowmapping::ShadowMapCreationShaderImplementation;
using tdme::engine::Engine;
using tdme::math::Matrix4x4;

/**
 * Shadow mapping shader to create a shadow map
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::engine::subsystems::shadowmapping::ShadowMapCreationShader final
{
private:
	struct ShadowMapCreationShaderContext {
		ShadowMapCreationShaderImplementation* implementation { nullptr };
	};
	map<string, ShadowMapCreationShaderImplementation*> shader;
	bool running { false };
	Engine* engine { nullptr };
	Renderer* renderer { nullptr };
	vector<ShadowMapCreationShaderContext> contexts;

public:
	/**
	 * Constructor
	 * @param renderer renderer
	 */
	ShadowMapCreationShader(Renderer* renderer);

	/**
	 * Destructor
	 */
	~ShadowMapCreationShader();

	/**
	 * @return if initialized and ready to use
	 */
	bool isInitialized();

	/**
	 * Init shadow map creation shader program
	 */
	void initialize();

	/**
	 * Use shadow map creation shader program
	 * @param engine engine
	 */
	void useProgram(Engine* engine);

	/**
	 * Unuse shadow map creation shader program
	 */
	void unUseProgram();

	/**
	 * Set up matrices
	 * @param contextIdx context index
	 */
	void updateMatrices(int contextIdx);

	/**
	 * Set up texture matrix
	 * @param contextIdx context index
	 */
	void updateTextureMatrix(int contextIdx);

	/**
	 * Update material
	 * @param contextIdx context index
	 */
	void updateMaterial(int contextIdx);

	/**
	 * Update shader parameters
	 * @param context
	 */
	void updateShaderParameters(int contextIdx);

	/**
	 * Bind texture
	 * @param contextIdx context index
	 * @param textureId texture id
	 */
	void bindTexture(int contextIdx, int32_t textureId);

	/**
	 * Set shader
	 * @param context
	 * @param id shader id
	 */
	void setShader(int contextIdx, const string& id);

};
