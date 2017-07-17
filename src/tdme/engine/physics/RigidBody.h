// Generated from /tdme/src/tdme/engine/physics/RigidBody.java

#pragma once

#include <vector>
#include <algorithm>

#include <fwd-tdme.h>
#include <java/lang/fwd-tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/physics/fwd-tdme.h>
#include <tdme/engine/primitives/fwd-tdme.h>
#include <tdme/math/fwd-tdme.h>
#include <tdme/utils/fwd-tdme.h>
#include <java/lang/Object.h>
#include <tdme/engine/physics/CollisionListener.h>

using std::vector;
using std::remove;

using java::lang::Object;
using java::lang::String;
using tdme::engine::Transformations;
using tdme::engine::physics::CollisionListener;
using tdme::engine::physics::CollisionResponse;
using tdme::engine::physics::World;
using tdme::engine::primitives::BoundingVolume;
using tdme::math::Matrix4x4;
using tdme::math::Quaternion;
using tdme::math::Vector3;


struct default_init_tag;

/** 
 * Rigid Body class
 * ported from "game physics - a practical introduction/ben kenwright"
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::engine::physics::RigidBody final
	: public Object
{

public:
	typedef Object super;
	static constexpr int32_t TYPEIDS_ALL { 2147483647 };

private:
	static constexpr float VELOCITY_SLEEPTOLERANCE { 1.0f };
	static constexpr int32_t SLEEPING_FRAMES { 300 };

public: /* protected */
	World* world {  };
	int32_t idx {  };
	String* id {  };
	int32_t typeId {  };
	int32_t collisionTypeIds {  };
	bool enabled {  };
	bool isStatic_ {  };
	bool isSleeping_ {  };

private:
	int32_t sleepingFrameCount {  };

public: /* protected */
	Transformations* transformations {  };
	BoundingVolume* obv {  };
	BoundingVolume* cbv {  };
	float friction {  };
	float restitution {  };
	float mass {  };
	float inverseMass {  };
	Vector3* movement {  };
	Vector3* position {  };
	Vector3* linearVelocity {  };
	Vector3* linearVelocityLast {  };
	Vector3* force {  };
	Quaternion* orientation {  };
	Vector3* angularVelocity {  };
	Vector3* angularVelocityLast {  };
	Vector3* torque {  };
	Matrix4x4* inverseInertia {  };

private:
	Matrix4x4* orientationMatrix {  };

public: /* protected */
	Matrix4x4* worldInverseInertia {  };

private:
	Vector3* distance {  };
	vector<CollisionListener*> collisionListener {  };
	Quaternion* tmpQuaternion1 {  };
	Quaternion* tmpQuaternion2 {  };
	Vector3* tmpVector3 {  };

public:

	/** 
	 * No rotation inertia matrix
	 * @param bv
	 * @param mass
	 * @return inertia matrix
	 */
	static Matrix4x4* getNoRotationInertiaMatrix();

	/** 
	 * Computes the inertia matrix
	 * @param bv
	 * @param mass
	 * @return inertia matrix
	 */
	static Matrix4x4* computeInertiaMatrix(BoundingVolume* bv, float mass, float scaleXAxis, float scaleYAxis, float scaleZAxis);
protected:

	/** 
	 * Protected constructor
	 * @param partition
	 * @param idx
	 * @param id
	 * @param enabled
	 * @param type id
	 * @param original bounding volume
	 * @param transformations
	 * @param restitution
	 * @param mass in kg
	 */
	void ctor(World* world, int32_t idx, String* id, bool enabled, int32_t typeId, BoundingVolume* obv, Transformations* transformations, float restitution, float friction, float mass, Matrix4x4* inverseInertia);

public:

	/** 
	 * Set up index in rigid body array list
	 * @param idx
	 */
	void setIdx(int32_t idx);

	/** 
	 * @return index in rigid body array list
	 */
	int32_t getIdx();

	/** 
	 * @return id
	 */
	String* getId();

	/** 
	 * @return type id
	 */
	int32_t getTypeId();

	/** 
	 * @return collision type ids bitmask
	 */
	int32_t getCollisionTypeIds();

	/** 
	 * Set up collision type ids
	 * @param collisionTypeIds
	 */
	void setCollisionTypeIds(int32_t collisionTypeIds);

	/** 
	 * @return if enabled
	 */
	bool isEnabled();

	/** 
	 * Set up if rigid body is enabled
	 * @param enabled
	 */
	void setEnabled(bool enabled);

	/** 
	 * @return object is static
	 */
	bool isStatic();

	/** 
	 * @return if sleeping
	 */
	bool isSleeping();

	/** 
	 * @return transformations
	 */
	Transformations* getTransformations();

	/** 
	 * @return original bounding volume
	 */
	BoundingVolume* getBoudingVolume();

	/** 
	 * Set up bounding volume
	 * @param obv
	 */
	void setBoundingVolume(BoundingVolume* obv);

	/** 
	 * @return transformed bounding volume
	 */
	BoundingVolume* getBoundingVolumeTransformed();

	/** 
	 * @return position
	 */
	Vector3* getPosition();

	/** 
	 * @return last frame movement
	 */
	Vector3* getMovement();

	/** 
	 * @return friction
	 */
	float getFriction();

	/** 
	 * Set up friction
	 * @param friction
	 */
	void setFriction(float friction);

	/** 
	 * @return restitution / bouncyness
	 */
	float getRestitution();

	/** 
	 * Set up restitution
	 * @param restitution
	 */
	void setRestitution(float restitution);

	/** 
	 * @return mass
	 */
	float getMass();

	/** 
	 * Set up mass
	 * @param mass
	 */
	void setMass(float mass);

	/** 
	 * @return linear velocity
	 */
	Vector3* getLinearVelocity();

	/** 
	 * @return angular velocity
	 */
	Vector3* getAngularVelocity();

	/** 
	 * @return force
	 */
	Vector3* getForce();

public: /* protected */

	/** 
	 * Wake up
	 */
	void awake(bool resetFrameCount);

public:

	/** 
	 * Put rigid body to sleep
	 */
	void sleep();

private:

	/** 
	 * Compute world inverse inertia
	 */
	void computeWorldInverseInertiaMatrix();

public:

	/** 
	 * Synchronizes this rigid body with transformations
	 * @param transformations
	 */
	void synch(Transformations* transformations);

	/** 
	 * Add force
	 * @param position of world force
	 * @param direction magnitude
	 */
	void addForce(Vector3* forceOrigin, Vector3* force);

public: /* protected */

	/** 
	 * Updates this rigid body / integrates it
	 * @param delta time
	 */
	void update(float deltaTime);

	/** 
	 * @return if velocity has been changed
	 */
	bool checkVelocityChange();

public:

	/** 
	 * Add a collision listener to this rigid body
	 * @param listener
	 */
	void addCollisionListener(CollisionListener* listener);

	/** 
	 * Remove a collision listener to this rigid body
	 * @param listener
	 */
	void removeCollisionListener(CollisionListener* listener);

public: /* protected */

	/** 
	 * Fire on collision 
	 * @param other
	 * @param collision response
	 */
	void fireOnCollision(RigidBody* other, CollisionResponse* collisionResponse);

	/** 
	 * Fire on collision begin
	 * @param other
	 * @param collision response
	 */
	void fireOnCollisionBegin(RigidBody* other, CollisionResponse* collisionResponse);

	/** 
	 * Fire on collision end
	 * @param other
	 * @param collision response
	 */
	void fireOnCollisionEnd(RigidBody* other);

public:
	String* toString() override;

	// Generated

public: /* protected */
	RigidBody(World* world, int32_t idx, String* id, bool enabled, int32_t typeId, BoundingVolume* obv, Transformations* transformations, float restitution, float friction, float mass, Matrix4x4* inverseInertia);
protected:
	RigidBody(const ::default_init_tag&);


public:
	static ::java::lang::Class *class_();

private:
	void init();
	virtual ::java::lang::Class* getClass0();
};
