#include <tdme/engine/DecalObject.h>

#include <string>

#include <tdme/tdme.h>
#include <tdme/engine/model/fwd-tdme.h>
#include <tdme/engine/subsystems/renderer/fwd-tdme.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/Partition.h>
#include <tdme/engine/Transformations.h>
#include <tdme/math/Matrix4x4.h>
#include <tdme/math/Quaternion.h>
#include <tdme/math/Vector3.h>

using std::string;

using tdme::engine::DecalObject;
using tdme::engine::Engine;
using tdme::engine::Partition;
using tdme::engine::Transformations;
using tdme::math::Matrix4x4;
using tdme::math::Quaternion;
using tdme::math::Vector3;

DecalObject::DecalObject(const string& id, Texture* texture):
	DecalObjectInternal(id, texture)
{
}

void DecalObject::setEngine(Engine* engine) {
	if (this->engine != nullptr) this->engine->deregisterEntity(this);
	this->engine = engine;
	if (engine != nullptr) engine->registerEntity(this);
	DecalObjectInternal::setEngine(engine);
}

void DecalObject::fromTransformations(const Transformations& transformations)
{
	DecalObjectInternal::fromTransformations(transformations);
	if (parentEntity == nullptr && frustumCulling == true && engine != nullptr && enabled == true) engine->partition->updateEntity(this);
}

void DecalObject::update()
{
	DecalObjectInternal::update();
	if (parentEntity == nullptr && frustumCulling == true && engine != nullptr && enabled == true) engine->partition->updateEntity(this);
}

void DecalObject::setEnabled(bool enabled)
{
	// return if enable state has not changed
	if (this->enabled == enabled) return;

	// frustum if root entity
	if (parentEntity == nullptr) {
		// frustum culling enabled?
		if (frustumCulling == true) {
			// yeo, add or remove from partition
			if (enabled == true) {
				if (engine != nullptr) engine->partition->addEntity(this);
			} else {
				if (engine != nullptr) engine->partition->removeEntity(this);
			}
		}
	}
	// call parent class::setEnabled()
	DecalObjectInternal::setEnabled(enabled);
}

void DecalObject::setFrustumCulling(bool frustumCulling) {
	// check if enabled and engine attached
	if (enabled == true && engine != nullptr) {
		// had frustum culling
		if (this->frustumCulling == true) {
			// yep, remove if set to false now
			if (frustumCulling == false) engine->partition->removeEntity(this);
		} else {
			// yep, add if set to true now
			if (frustumCulling == true) engine->partition->addEntity(this);
		}
	}
	this->frustumCulling = frustumCulling;
	// delegate change to engine
	if (engine != nullptr) engine->registerEntity(this);
}

