#pragma once

#include <vector>

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/subsystems/shadowmapping/fwd-tdme.h>
#include <tdme/engine/FrameBuffer.h>
#include <tdme/math/fwd-tdme.h>
#include <tdme/math/Matrix4x4.h>
#include <tdme/math/Vector3.h>
#include <tdme/utilities/fwd-tdme.h>

using std::vector;

using tdme::engine::subsystems::shadowmapping::ShadowMapping;
using tdme::engine::Camera;
using tdme::engine::FrameBuffer;
using tdme::engine::Light;
using tdme::engine::Object;
using tdme::math::Matrix4x4;
using tdme::math::Vector3;

/**
 * Shadow map
 * @author Andreas Drewke
 */
class tdme::engine::subsystems::shadowmapping::ShadowMap final
{
	friend class ShadowMapping;

private:
	vector<Object*> visibleObjects;
	ShadowMapping* shadowMapping { nullptr };
	Camera* lightCamera { nullptr };
	FrameBuffer* frameBuffer { nullptr };
	Matrix4x4 biasMatrix;
	Matrix4x4 depthBiasMVPMatrix;

	/**
	 * Initialize shadow map
	 */
	void initialize();

	/**
	 * Reshape frame buffer
	 * @param width width
	 * @param height height
	 */
	void reshape(int32_t width, int32_t height);

	/**
	 * Disposes this shadow map
	 */
	void dispose();

	/**
	 * Binds frame buffer depth texture
	 * @param contextIdx context index
	 */
	void bindDepthBufferTexture(int contextIdx);

	/**
	 * @return light camera
	 */
	Camera* getCamera();

	/**
	 * Create shadow map
	 * @param light light
	 */
	void createShadowMap(Light* light);

	/**
	 * Computes shadow texture matrix and stores it
	 */
	void computeDepthBiasMVPMatrix();

	/**
	 * Set up shadow texture matrix computed and stored before
	 * @param contextIdx context index
	 */
	void updateDepthBiasMVPMatrix(int contextIdx);

public:
	static constexpr int32_t TEXTUREUNIT { 9 };

	/**
	 * Public constructor
	 * @param shadowMapping shadow mapping
	 * @param width width
	 * @param height height
	 */
	ShadowMap(ShadowMapping* shadowMapping, int32_t width, int32_t height);

	/**
	 * Destructor
	 */
	~ShadowMap();

	/**
	 * @return width
	 */
	inline int32_t getWidth() {
		return frameBuffer->getWidth();
	}

	/**
	 * @return height
	 */
	inline int32_t getHeight() {
		return frameBuffer->getWidth();
	}

	/**
	 * @return frame buffer
	 */
	inline FrameBuffer* getFrameBuffer() {
		return frameBuffer;
	}

};
