#pragma once

#include <map>
#include <string>

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/model/fwd-tdme.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/engine/model/Model.h>
#include <tdme/engine/primitives/fwd-tdme.h>
#include <tdme/engine/subsystems/particlesystem/fwd-tdme.h>
#include <tdme/engine/subsystems/renderer/fwd-tdme.h>
#include <tdme/engine/subsystems/rendering/ObjectAnimation.h>
#include <tdme/engine/subsystems/rendering/ObjectInternal.h>
#include <tdme/engine/subsystems/rendering/ObjectNode.h>
#include <tdme/engine/subsystems/rendering/ObjectNodeRenderer.h>
#include <tdme/engine/subsystems/shadowmapping/fwd-tdme.h>
#include <tdme/engine/Camera.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/Entity.h>
#include <tdme/engine/EntityShaderParameters.h>
#include <tdme/engine/Timing.h>
#include <tdme/engine/Transformations.h>
#include <tdme/math/Matrix4x4.h>
#include <tdme/math/Quaternion.h>
#include <tdme/math/Vector3.h>

using std::map;
using std::string;

using tdme::engine::model::Color4;
using tdme::engine::model::Model;
using tdme::engine::primitives::BoundingBox;
using tdme::engine::subsystems::renderer::Renderer;
using tdme::engine::subsystems::rendering::EntityRenderer;
using tdme::engine::subsystems::rendering::ObjectAnimation;
using tdme::engine::subsystems::rendering::ObjectInternal;
using tdme::engine::subsystems::rendering::ObjectNode;
using tdme::engine::subsystems::rendering::ObjectNodeRenderer;
using tdme::engine::subsystems::shadowmapping::ShadowMap;
using tdme::engine::Camera;
using tdme::engine::Engine;
using tdme::engine::Entity;
using tdme::engine::EntityShaderParameters;
using tdme::engine::Timing;
using tdme::engine::Transformations;
using tdme::math::Matrix4x4;
using tdme::math::Quaternion;
using tdme::math::Vector3;

/**
 * Object to be used with engine class
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::engine::Object final
	: public ObjectInternal
	, public Entity
{
private:
	friend class Engine;
	friend class ImposterObject;
	friend class LODObject;
	friend class LODObjectImposter;
	friend class ObjectRenderGroup;
	friend class ObjectParticleSystem;
	friend class SkinnedObjectRenderGroup;
	friend class tdme::engine::subsystems::rendering::EntityRenderer;
	friend class tdme::engine::subsystems::shadowmapping::ShadowMap;

	Engine* engine { nullptr };
	Entity* parentEntity { nullptr };
	bool frustumCulling { true };
	RenderPass renderPass { RENDERPASS_STANDARD };
	string shaderId;
	uint8_t uniqueShaderId { 0 };
	string distanceShaderId;
	uint8_t uniqueDistanceShaderId { 0 };
	float distanceShaderDistance { 50.0f };
	string reflectionEnvironmentMappingId;
	bool reflectionEnvironmentMappingPositionSet { false };
	Vector3 reflectionEnvironmentMappingPosition;
	Engine::EffectPass excludeFromEffectPass { Engine::EFFECTPASS_NONE };
	bool enableEarlyZRejection { false };
	bool disableDepthTest { false };
	int64_t frameTransformationsLast { -1LL };
	int64_t timeTransformationsLast { -1LL };
	EntityShaderParameters shaderParameters;
	EntityShaderParameters distanceShaderParameters;
	bool needsPreRender { false };
	bool needsForwardShading { false };
	bool enableTransformationsComputingLOD { false };

	/**
	 * @return if this object instance needs a computeTransformations() call each frame
	 */
	inline bool isNeedsComputeTransformations() {
		return model->hasSkinning() == true || model->hasAnimations() == true;
	}

	/**
	 * Compute animations
	 * @param contextIdx context index
	 */
	inline void computeTransformations(int contextIdx) {
		auto timing = engine->getTiming();
		auto currentFrameAtTime = timing->getCurrentFrameAtTime();
		auto currentFrame = timing->getFrame();
		auto distanceFromCamera = (engine->getCamera()->getLookFrom() - getBoundingBoxTransformed()->computeClosestPointInBoundingBox(engine->getCamera()->getLookFrom())).computeLengthSquared();
		if (enableTransformationsComputingLOD == true) {
			if (distanceFromCamera > Math::square(Engine::getTransformationsComputingReduction2Distance())) {
				if (frameTransformationsLast != -1LL && currentFrame - frameTransformationsLast < 4) return;
			} else
			if (distanceFromCamera > Math::square(Math::square(Engine::getTransformationsComputingReduction1Distance()))) {
				if (frameTransformationsLast != -1LL && currentFrame - frameTransformationsLast < 2) return;
			}
		}
		computeTransformations(contextIdx, timeTransformationsLast, currentFrameAtTime);
		frameTransformationsLast = timing->getFrame();
		timeTransformationsLast = currentFrameAtTime;
	}

	/**
	 * Compute transformations
	 * @param contextIdx context index
	 * @param lastFrameAtTime time of last animation computation
	 * @param currentFrameAtTime time of current animation computation
	 */
	inline void computeTransformations(int contextIdx, int64_t lastFrameAtTime, int64_t currentFrameAtTime) override {
		ObjectInternal::computeTransformations(contextIdx, lastFrameAtTime, currentFrameAtTime);
	}

	/**
	 * @return if this object instance needs a preRender() call each frame
	 */
	inline bool isNeedsPreRender() {
		return
			needsPreRender == true ||
			(Engine::animationProcessingTarget != Engine::GPU && model->hasSkinning() == true);
	}

	/**
	 * Pre render step like uploading VBOs and such
	 * @param contextIdx context index
	 */
	inline void preRender(int contextIdx) {
		if (model->hasBoundingBoxUpdate() == true) updateBoundingBox();
		for (auto objectNode: objectNodes) {
			if (objectNode->renderer->needsPreRender() == true) {
				objectNode->renderer->preRender(contextIdx);
			}
		}
	}

	/**
	 * @return if this object needs forward shading
	 */
	inline bool isNeedsForwardShading() {
		return needsForwardShading == true || reflectionEnvironmentMappingId.empty() == false;
	}

	// overridden methods
	inline void setParentEntity(Entity* entity) override {
		this->parentEntity = entity;
	}
	inline Entity* getParentEntity() override {
		return parentEntity;
	}
	inline void applyParentTransformations(const Transformations& parentTransformations) override {
		for (auto& transformations: instanceTransformations) transformations.applyParentTransformations(parentTransformations);
		updateBoundingBox();
	}

public:
	/**
	 * Public constructor
	 * @param id id
	 * @param model model
	 * @param instances instances to compute and render by duplication, which only is intended to be used with skinned meshes
	 */
	Object(const string& id, Model* model, int instances);

	/**
	 * Public constructor
	 * @param id id
	 * @param model model
	 */
	Object(const string& id, Model* model);

	/**
	 * Set up if this object instance needs a preRender() call each frame
	 */
	inline void setNeedsPreRender(bool needsPreRender) {
		this->needsPreRender = needsPreRender;
	}

	// overridden methods
	inline EntityType getEntityType() override {
		return ENTITYTYPE_OBJECT;
	}

	void setEngine(Engine* engine) override;
	void setRenderer(Renderer* renderer) override;
	void initialize() override;
	void dispose() override;

	inline bool isEnabled() override {
		return ObjectInternal::isEnabled();
	}

	void setEnabled(bool enabled) override;
	bool isFrustumCulling() override;
	void setFrustumCulling(bool frustumCulling) override;
	void fromTransformations(const Transformations& transformations) override;
	void update() override;

	inline BoundingBox* getBoundingBox() override {
		return ObjectInternal::getBoundingBox();
	}

	inline BoundingBox* getBoundingBoxTransformed() override {
		return ObjectInternal::getBoundingBoxTransformed();
	}

	inline const Color4& getEffectColorAdd() const override {
		return ObjectInternal::getEffectColorAdd();
	}

	inline void setEffectColorAdd(const Color4& effectColorAdd) override {
		return ObjectInternal::setEffectColorAdd(effectColorAdd);
	}

	inline const Color4& getEffectColorMul() const override {
		return ObjectInternal::getEffectColorMul();
	}

	inline void setEffectColorMul(const Color4& effectColorMul) override {
		return ObjectInternal::setEffectColorMul(effectColorMul);
	}

	inline const string& getId() override {
		return ObjectInternal::getId();
	}

	inline bool isContributesShadows() override {
		return ObjectInternal::isContributesShadows();
	}

	inline void setContributesShadows(bool contributesShadows) override {
		ObjectInternal::setContributesShadows(contributesShadows);
	}

	inline bool isReceivesShadows() override {
		return ObjectInternal::isReceivesShadows();
	}

	inline void setReceivesShadows(bool receivesShadows) override {
		ObjectInternal::setReceivesShadows(receivesShadows);
	}

	inline bool isPickable() override {
		return ObjectInternal::isPickable();
	}

	inline void setPickable(bool pickable) override {
		ObjectInternal::setPickable(pickable);
	}

	inline const Vector3& getTranslation() const override {
		return instanceTransformations[currentInstance].getTranslation();
	}

	inline void setTranslation(const Vector3& translation) override {
		instanceTransformations[currentInstance].setTranslation(translation);
	}

	inline const Vector3& getScale() const override {
		return instanceTransformations[currentInstance].getScale();
	}

	inline void setScale(const Vector3& scale) override {
		instanceTransformations[currentInstance].setScale(scale);
	}

	inline const Vector3& getPivot() const override {
		return instanceTransformations[currentInstance].getPivot();
	}

	inline void setPivot(const Vector3& pivot) override {
		instanceTransformations[currentInstance].setPivot(pivot);
	}

	inline const int getRotationCount() const override {
		return instanceTransformations[currentInstance].getRotationCount();
	}

	inline Rotation& getRotation(const int idx) override {
		return instanceTransformations[currentInstance].getRotation(idx);
	}

	inline void addRotation(const Vector3& axis, const float angle) override {
		instanceTransformations[currentInstance].addRotation(axis, angle);
	}

	inline void removeRotation(const int idx) override {
		instanceTransformations[currentInstance].removeRotation(idx);
	}

	inline const Vector3& getRotationAxis(const int idx) const override {
		return instanceTransformations[currentInstance].getRotationAxis(idx);
	}

	inline void setRotationAxis(const int idx, const Vector3& axis) override {
		instanceTransformations[currentInstance].setRotationAxis(idx, axis);
	}

	inline const float getRotationAngle(const int idx) const override {
		return instanceTransformations[currentInstance].getRotationAngle(idx);
	}

	inline void setRotationAngle(const int idx, const float angle) override {
		instanceTransformations[currentInstance].setRotationAngle(idx, angle);
	}

	inline const Quaternion& getRotationsQuaternion() const override {
		return instanceTransformations[currentInstance].getRotationsQuaternion();
	}

	inline const Matrix4x4& getTransformationsMatrix() const override {
		return instanceTransformations[currentInstance].getTransformationsMatrix();
	}

	inline const Transformations& getTransformations() const override {
		return instanceTransformations[currentInstance];
	}

	inline RenderPass getRenderPass() const override {
		return renderPass;
	}

	inline void setRenderPass(RenderPass renderPass) override {
		this->renderPass = renderPass;
	}

	/**
	 * @return shader id
	 */
	inline const string& getShader() {
		return shaderId;
	}

	/**
	 * Set shader
	 * @param id shader id
	 */
	void setShader(const string& id);

	/**
	 * @return unique shader id
	 */
	inline uint8_t getUniqueShaderId() {
		return uniqueShaderId;
	}

	/**
	 * @return distance shader id
	 */
	inline const string& getDistanceShader() {
		return distanceShaderId;
	}

	/**
	 * @return unique distance shader id
	 */
	inline uint8_t getUniqueDistanceShaderId() {
		return uniqueDistanceShaderId;
	}

	/**
	 * Set distance shader
	 * @param id shader id
	 */
	void setDistanceShader(const string& id);

	/**
	 * @return distance shader distance
	 */
	inline float getDistanceShaderDistance() {
		return distanceShaderDistance;
	}

	/**
	 * Set distance shader distance
	 * @param distanceShaderDistance shader
	 */
	inline void setDistanceShaderDistance(float distanceShaderDistance) {
		this->distanceShaderDistance = distanceShaderDistance;
	}

	/**
	 * @return reflection environment mapping id
	 */
	inline const string& getReflectionEnvironmentMappingId() {
		return reflectionEnvironmentMappingId;
	}

	/**
	 * @return reflection environment mapping id
	 */
	inline void setReflectionEnvironmentMappingId(const string& reflectionEnvironmentMappingId) {
		this->reflectionEnvironmentMappingId = reflectionEnvironmentMappingId;
	}

	/**
	 * @return if object has a reflection environment mapping position
	 */
	inline bool hasReflectionEnvironmentMappingPosition() {
		return reflectionEnvironmentMappingPositionSet;
	}

	/**
	 * @return reflection environment mapping position
	 */
	inline const Vector3& getReflectionEnvironmentMappingPosition() {
		return reflectionEnvironmentMappingPosition;
	}

	/**
	 * Set reflection environment mapping position
	 * @param reflectionEnvironmentMappingPosition reflection environment mapping position
	 */
	inline void setReflectionEnvironmentMappingPosition(const Vector3& reflectionEnvironmentMappingPosition) {
		this->reflectionEnvironmentMappingPositionSet = true;
		this->reflectionEnvironmentMappingPosition = reflectionEnvironmentMappingPosition;
	}

	/**
	 * Unset reflection environment mapping position
	 */
	inline void unsetReflectionEnvironmentMappingPosition() {
		this->reflectionEnvironmentMappingPositionSet = false;
		this->reflectionEnvironmentMappingPosition.set(0.0f, 0.0f, 0.0f);
	}

	/**
	 * @return if to exclude from a certain effect pass
	 */
	inline Engine::EffectPass getExcludeFromEffectPass() const {
		return excludeFromEffectPass;
	}

	/**
	 * Set exclude from effect pass
	 * @param effectPass effect pass
	 */
	inline void setExcludeEffectPass(Engine::EffectPass effectPass) {
		this->excludeFromEffectPass = effectPass;
	}

	/**
	 * @return If early z rejection is enabled
	 */
	inline bool isEnableEarlyZRejection() const {
		return enableEarlyZRejection;
	}

	/**
	 * Enable/disable early z rejection
	 * @param enableEarlyZRejection enable early z rejection
	 */
	inline void setEnableEarlyZRejection(bool enableEarlyZRejection) {
		this->enableEarlyZRejection = enableEarlyZRejection;
	}

	/**
	 * @return if depth test is disabled
	 */
	inline bool isDisableDepthTest() const {
		return disableDepthTest;
	}

	/**
	 * Set disable depth test
	 * @param disableDepthTest disable depth test
	 */
	inline void setDisableDepthTest(bool disableDepthTest) {
		this->disableDepthTest = disableDepthTest;
	}

	/**
	 * Returns shader parameter for given parameter name, if the value does not exist, the default will be returned
	 * @param shaderId shader id
	 * @param parameterName parameter name
	 * @return shader parameter
	 */
	inline const ShaderParameter getShaderParameter(const string& parameterName) {
		return shaderParameters.getShaderParameter(parameterName);
	}

	/**
	 * Set shader parameter for given parameter name
	 * @param shaderId shader id
	 * @param parameterName parameter name
	 * @param paraemterValue parameter value
	 */
	inline void setShaderParameter(const string& parameterName, const ShaderParameter& parameterValue) {
		shaderParameters.setShaderParameter(parameterName, parameterValue);
	}

	/**
	 * Returns distance shader parameter for given parameter name, if the value does not exist, the default will be returned
	 * @param shaderId shader id
	 * @param parameterName parameter name
	 * @return shader parameter
	 */
	inline const ShaderParameter getDistanceShaderParameter(const string& parameterName) {
		return distanceShaderParameters.getShaderParameter(parameterName);
	}

	/**
	 * Set distance shader parameter for given parameter name
	 * @param shaderId shader id
	 * @param parameterName parameter name
	 * @param paraemterValue parameter value
	 */
	inline void setDistanceShaderParameter(const string& parameterName, const ShaderParameter& parameterValue) {
		distanceShaderParameters.setShaderParameter(parameterName, parameterValue);
	}

	/**
	 * @return if transformations computing LOD is enabled
	 */
	inline bool isEnableTransformationsComputingLOD() const {
		return enableTransformationsComputingLOD;
	}

	/**
	 * Set transformations computing LOD enabled
	 * @param enableTransformationsComputingLOD enable transformations computing LOD
	 */
	inline void setEnableTransformationsComputingLOD(bool enableTransformationsComputingLOD) {
		this->enableTransformationsComputingLOD = disableDepthTest;
	}

};