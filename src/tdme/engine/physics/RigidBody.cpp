
#include <tdme/engine/physics/RigidBody.h>

#include <string>
#include <vector>

#include <ext/reactphysics3d/src/body/Body.h>
#include <ext/reactphysics3d/src/body/CollisionBody.h>
#include <ext/reactphysics3d/src/body/RigidBody.h>
#include <ext/reactphysics3d/src/collision/CollisionCallback.h>
#include <ext/reactphysics3d/src/collision/NarrowPhaseInfo.h>
#include <ext/reactphysics3d/src/collision/ProxyShape.h>
#include <ext/reactphysics3d/src/collision/shapes/CollisionShape.h>
#include <ext/reactphysics3d/src/collision/narrowphase/DefaultCollisionDispatch.h>
#include <ext/reactphysics3d/src/collision/narrowphase/NarrowPhaseAlgorithm.h>
#include <ext/reactphysics3d/src/constraint/ContactPoint.h>
#include <ext/reactphysics3d/src/engine/CollisionWorld.h>
#include <ext/reactphysics3d/src/engine/DynamicsWorld.h>
#include <ext/reactphysics3d/src/mathematics/Transform.h>
#include <ext/reactphysics3d/src/mathematics/Vector3.h>
#include <ext/reactphysics3d/src/memory/MemoryAllocator.h>

#include <tdme/engine/Rotation.h>
#include <tdme/engine/Transformations.h>
#include <tdme/engine/physics/CollisionListener.h>
#include <tdme/engine/physics/World.h>
#include <tdme/engine/primitives/BoundingVolume.h>
#include <tdme/engine/primitives/Capsule.h>
#include <tdme/engine/primitives/TerrainMesh.h>
#include <tdme/engine/primitives/OrientedBoundingBox.h>
#include <tdme/math/Math.h>
#include <tdme/math/Matrix4x4.h>
#include <tdme/math/Quaternion.h>
#include <tdme/math/Vector3.h>
#include <tdme/utils/Console.h>

using std::string;
using std::to_string;
using std::vector;

using tdme::engine::physics::RigidBody;
using tdme::engine::Rotation;
using tdme::engine::Transformations;
using tdme::engine::physics::CollisionListener;
using tdme::engine::physics::World;
using tdme::engine::primitives::BoundingVolume;
using tdme::engine::primitives::Capsule;
using tdme::engine::primitives::OrientedBoundingBox;
using tdme::engine::primitives::TerrainMesh;
using tdme::math::Math;
using tdme::math::Matrix4x4;
using tdme::math::Quaternion;
using tdme::math::Vector3;
using tdme::utils::Console;

constexpr uint16_t RigidBody::TYPEIDS_ALL;
constexpr uint16_t RigidBody::TYPEID_STATIC;
constexpr uint16_t RigidBody::TYPEID_DYNAMIC;

RigidBody::RigidBody(World* world, const string& id, int type, bool enabled, uint16_t collisionTypeId, BoundingVolume* boundingVolume, const Transformations& transformations, float restitution, float friction, float mass, const Matrix4x4& inverseInertiaMatrix)
{
	this->world = world;
	this->id = id;
	this->rootId = id;
	this->inverseInertiaMatrix.set(inverseInertiaMatrix);
	this->boundingVolume = dynamic_cast<TerrainMesh*>(boundingVolume) != nullptr?boundingVolume:boundingVolume->clone();
	this->type = type;
	this->mass = mass;
	this->collideTypeIds = ~0;
	this->collisionTypeId = collisionTypeId;
	this->proxyShape = nullptr;
	switch (type) {
		case TYPE_STATIC:
			this->rigidBody = this->world->world.createRigidBody(reactphysics3d::Transform());
			this->rigidBody->setType(reactphysics3d::BodyType::STATIC);
			this->collisionBody = rigidBody;
			break;
		case TYPE_DYNAMIC:
			this->rigidBody = this->world->world.createRigidBody(reactphysics3d::Transform());
			this->rigidBody->setType(reactphysics3d::BodyType::DYNAMIC);
			this->collisionBody = rigidBody;
			break;
		case TYPE_KINEMATIC:
			this->rigidBody = this->world->world.createRigidBody(reactphysics3d::Transform());
			this->rigidBody->setType(reactphysics3d::BodyType::KINEMATIC);
			this->collisionBody = rigidBody;
			break;
		case TYPE_COLLISION:
			this->rigidBody = nullptr;
			this->collisionBody = this->world->world.createCollisionBody(reactphysics3d::Transform());
			break;
		default:
			this->rigidBody = nullptr;
			this->collisionBody = nullptr;
			Console::println("RigidBody::RigidBody(): unsupported type: " + to_string(type));
			break;
	}
	if (rigidBody != nullptr) {
		auto& inverseInertiaMatrixArray = inverseInertiaMatrix.getArray();
		rigidBody->setInverseInertiaTensorLocal(
			reactphysics3d::Matrix3x3(
				inverseInertiaMatrixArray[0],
				inverseInertiaMatrixArray[1],
				inverseInertiaMatrixArray[2],
				inverseInertiaMatrixArray[4],
				inverseInertiaMatrixArray[5],
				inverseInertiaMatrixArray[6],
				inverseInertiaMatrixArray[8],
				inverseInertiaMatrixArray[9],
				inverseInertiaMatrixArray[10]
			)
		);
		rigidBody->getMaterial().setFrictionCoefficient(friction);
		rigidBody->getMaterial().setBounciness(restitution);
		rigidBody->setMass(mass);
	}
	collisionBody->setUserData(this);
	fromTransformations(transformations);
	setEnabled(enabled);
}

RigidBody::~RigidBody() {
	if (dynamic_cast<TerrainMesh*>(boundingVolume) != nullptr && cloned == true) {
		return;
	}
	delete boundingVolume;
}

Matrix4x4 RigidBody::getNoRotationInertiaMatrix()
{
	return Matrix4x4(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 RigidBody::computeInertiaMatrix(BoundingVolume* bv, float mass, float scaleXAxis, float scaleYAxis, float scaleZAxis)
{
	auto width = bv->getBoundingBoxTransformed().getDimensions().getX();
	auto height = bv->getBoundingBoxTransformed().getDimensions().getY();
	auto depth = bv->getBoundingBoxTransformed().getDimensions().getZ();
	return
		(Matrix4x4(
			scaleXAxis * 1.0f / 12.0f * mass * (height * height + depth * depth), 0.0f, 0.0f, 0.0f,
			0.0f, scaleYAxis * 1.0f / 12.0f * mass * (width * width + depth * depth), 0.0f, 0.0f,
			0.0f, 0.0f, scaleZAxis * 1.0f / 12.0f * mass * (width * width + height * height), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		)).invert();
}

bool RigidBody::isCloned() {
	return cloned;
}

void RigidBody::setCloned(bool cloned) {
	this->cloned = cloned;
}

const string& RigidBody::getId()
{
	return id;
}

const string& RigidBody::getRootId()
{
	return rootId;
}

void RigidBody::setRootId(const string& rootId) {
	this->rootId = rootId;
}

int32_t RigidBody::getType() {
	return type;
}

uint16_t RigidBody::getCollisionTypeId()
{
	return collisionTypeId;
}

void RigidBody::setCollisionTypeId(uint16_t typeId)
{
	this->collisionTypeId = typeId;
	this->proxyShape->setCollisionCategoryBits(typeId);
}

uint16_t RigidBody::getCollisionTypeIds()
{
	return collideTypeIds;
}

void RigidBody::setCollisionTypeIds(uint16_t collisionTypeIds)
{
	this->collideTypeIds = collisionTypeIds;
	this->proxyShape->setCollideWithMaskBits(collisionTypeIds);
}

bool RigidBody::isEnabled()
{
	return enabled;
}

void RigidBody::setEnabled(bool enabled)
{
	// return if enable state has not changed
	if (this->enabled == enabled)
		return;

	//
	collisionBody->setIsActive(enabled);

	//
	this->enabled = enabled;
}

bool RigidBody::isSleeping()
{
	return collisionBody->isSleeping();
}

BoundingVolume* RigidBody::getBoundingVolume()
{
	return boundingVolume;
}

BoundingBox RigidBody::computeBoundingBoxTransformed() {
	auto aabb = proxyShape->getWorldAABB();
	return BoundingBox(
		Vector3(
			aabb.getMin().x,
			aabb.getMin().y,
			aabb.getMin().z
		),
		Vector3(
			aabb.getMax().x,
			aabb.getMax().y,
			aabb.getMax().z
		)
	);
}

const Vector3& RigidBody::getPosition() const
{
	return transformations.getTranslation();
}

float RigidBody::getFriction()
{
	if (rigidBody == nullptr) {
		Console::println("RigidBody::getFriction(): no rigid body attached");
		return 0.0f;
	}
	return rigidBody->getMaterial().getFrictionCoefficient();
}

void RigidBody::setFriction(float friction)
{
	if (rigidBody == nullptr) {
		Console::println("RigidBody::setFriction(): no rigid body attached");
		return;
	}
	rigidBody->getMaterial().setFrictionCoefficient(friction);
}

float RigidBody::getRestitution()
{
	if (rigidBody == nullptr) {
		Console::println("RigidBody::getRestitution(): no rigid body attached");
		return 0.0f;
	}
	return rigidBody->getMaterial().getBounciness();
}

void RigidBody::setRestitution(float restitution)
{
	if (rigidBody == nullptr) {
		Console::println("RigidBody::setRestitution(): no rigid body attached");
		return;
	}
	rigidBody->getMaterial().setBounciness(restitution);
}

float RigidBody::getMass()
{
	return mass;
}

void RigidBody::setMass(float mass)
{
	this->mass = mass;
	if (rigidBody == nullptr) {
		Console::println("RigidBody::setMass(): no rigid body attached");
		return;
	}
	rigidBody->setMass(mass);
}

Vector3& RigidBody::getLinearVelocity()
{
	if (rigidBody == nullptr) {
		Console::println("RigidBody::getLinearVelocity(): no rigid body attached");
	}
	return linearVelocity;
}

Vector3& RigidBody::getAngularVelocity()
{
	if (rigidBody == nullptr) {
		Console::println("RigidBody::getAngularVelocity(): no rigid body attached");
	}
	return angularVelocity;
}

const Transformations& RigidBody::getTransformations() {
	return transformations;
}

void RigidBody::fromTransformations(const Transformations& transformations)
{
	if (dynamic_cast<TerrainMesh*>(boundingVolume) != nullptr) {
		if (rigidBody != nullptr) {
			proxyShape = rigidBody->addCollisionShape(boundingVolume->collisionShape, boundingVolume->collisionShapeLocalTransform, mass);
		} else {
			proxyShape = collisionBody->addCollisionShape(boundingVolume->collisionShape, boundingVolume->collisionShapeLocalTransform);
		}
		proxyShape->setCollideWithMaskBits(collideTypeIds);
		proxyShape->setCollisionCategoryBits(collisionTypeId);
		return;
	}

	// store engine transformations
	this->transformations.fromTransformations(transformations);

	// "scale vector transformed" which takes transformations scale and orientation into account
	auto scaleVectorTransformed =
		boundingVolume->collisionShapeLocalTransform.getOrientation() *
		reactphysics3d::Vector3(
			transformations.getScale().getX(),
			transformations.getScale().getY(),
			transformations.getScale().getZ()
		);
	if (scaleVectorTransformed.x < 0.0f) scaleVectorTransformed.x*= -1.0f;
	if (scaleVectorTransformed.y < 0.0f) scaleVectorTransformed.y*= -1.0f;
	if (scaleVectorTransformed.z < 0.0f) scaleVectorTransformed.z*= -1.0f;

	// scale bounding volume and recreate it if nessessary
	if (proxyShape == nullptr || boundingVolume->getScale().equals(Vector3(scaleVectorTransformed.x, scaleVectorTransformed.y, scaleVectorTransformed.z)) == false) {
		if (proxyShape != nullptr) collisionBody->removeCollisionShape(proxyShape);
		boundingVolume->setScale(Vector3(scaleVectorTransformed.x, scaleVectorTransformed.y, scaleVectorTransformed.z));
		if (rigidBody != nullptr) {
			proxyShape = rigidBody->addCollisionShape(boundingVolume->collisionShape, boundingVolume->collisionShapeLocalTransform, mass);
		} else {
			proxyShape = collisionBody->addCollisionShape(boundingVolume->collisionShape, boundingVolume->collisionShapeLocalTransform);
		}
		proxyShape->setCollideWithMaskBits(collideTypeIds);
		proxyShape->setCollisionCategoryBits(collisionTypeId);
	}

	// rigig body transform
	auto& transformationsMatrix = this->transformations.getTransformationsMatrix();
	reactphysics3d::Transform transform;
	// take from transformations matrix
	transform.setFromOpenGL(transformationsMatrix.getArray().data());
	// normalize orientation to remove scale
	auto transformOrientation = transform.getOrientation();
	transformOrientation.normalize();
	transform.setOrientation(transformOrientation);

	/*
	// TODO: center of mass ~ pivot
	// set center of mass which is basically center of bv for now
	rigidBody->setCenterOfMassLocal(boundingVolume->collisionShapeLocalTransform.getPosition());
	// find final position, not sure yet if its working 100%, but still works with some tests
	auto centerOfMassWorld = transform * boundingVolume->collisionShapeLocalTransform.getPosition();
	transform.setPosition(
		transform.getPosition() +
		transform.getPosition() -
		centerOfMassWorld +
		(
			reactphysics3d::Vector3(
				boundingVolume->collisionShapeLocalTranslation.getX(),
				boundingVolume->collisionShapeLocalTranslation.getY(),
				boundingVolume->collisionShapeLocalTranslation.getZ()
			) * scaleVectorTransformed
		)
	);
	*/

	// set transform
	collisionBody->setTransform(transform);
}

void RigidBody::addForce(const Vector3& forceOrigin, const Vector3& force)
{
	if (rigidBody == nullptr) {
		Console::println("RigidBody::addForce(): no rigid body attached");
		return;
	}
	rigidBody->applyForce(
		reactphysics3d::Vector3(force.getX(), force.getY(), force.getZ()),
		reactphysics3d::Vector3(forceOrigin.getX(), forceOrigin.getY(), forceOrigin.getZ())
	);
}

void RigidBody::addForce(const Vector3& force)
{
	if (rigidBody == nullptr) {
		Console::println("RigidBody::addForce(): no rigid body attached");
		return;
	}
	rigidBody->applyForceToCenterOfMass(
		reactphysics3d::Vector3(force.getX(), force.getY(), force.getZ())
	);
}

void RigidBody::addTorque(const Vector3& torque)
{
	if (rigidBody == nullptr) {
		Console::println("RigidBody::addTorque(): no rigid body attached");
		return;
	}
	rigidBody->applyForceToCenterOfMass(
		reactphysics3d::Vector3(torque.getX(), torque.getY(), torque.getZ())
	);
}

void RigidBody::addCollisionListener(CollisionListener* listener)
{
	collisionListener.push_back(listener);
}

void RigidBody::removeCollisionListener(CollisionListener* listener)
{
	collisionListener.erase(remove(collisionListener.begin(), collisionListener.end(), listener), collisionListener.end());
}

void RigidBody::fireOnCollision(RigidBody* other, CollisionResponse* collisionResponse)
{
	for (auto listener: collisionListener) {
		listener->onCollision(this, other, collisionResponse);
	}
}

void RigidBody::fireOnCollisionBegin(RigidBody* other, CollisionResponse* collisionResponse)
{
	for (auto listener: collisionListener) {
		listener->onCollisionBegin(this, other, collisionResponse);
	}
}

void RigidBody::fireOnCollisionEnd(RigidBody* other)
{
	for (auto listener: collisionListener) {
		listener->onCollisionEnd(this, other);
	}
}
