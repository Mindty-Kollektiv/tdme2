#pragma once

#include <tdme/tdme.h>

#include <string>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/engine/model/fwd-tdme.h>
#include <tdme/engine/primitives/fwd-tdme.h>
#include <tdme/engine/prototype/fwd-tdme.h>
#include <tdme/math/fwd-tdme.h>

using std::string;
using std::vector;

using tdme::engine::model::Model;
using tdme::engine::primitives::BoundingVolume;
using tdme::engine::prototype::Prototype;
using tdme::math::Vector3;

/**
 * Prototype bounding volume definition
 * @author Andreas Drewke
 */
class tdme::engine::prototype::PrototypeBoundingVolume final
{
private:
	int id;
	Prototype* prototype { nullptr };
	string convexMeshFile;
	Model* model { nullptr };
	BoundingVolume* boundingVolume { nullptr };
	bool generated;
	vector<uint8_t> convexMeshData;

public:
	// forbid class copy
	FORBID_CLASS_COPY(PrototypeBoundingVolume)

	/**
	 * Public constructor
	 * @param id id
	 * @param prototype prototype
	 */
	PrototypeBoundingVolume(int id, Prototype* prototype);

	/**
	 * Destructor
	 */
	~PrototypeBoundingVolume();

	/**
	 * @return id
	 */
	inline int getId() {
		return id;
	}

	/**
	 * @return convex mesh file
	 */
	inline const string& getConvexMeshFile() {
		return convexMeshFile;
	}

	/**
	 * @return model
	 */
	inline Model* getModel() {
		return model;
	}

	/**
	 * @return bounding volume
	 */
	inline BoundingVolume* getBoundingVolume() {
		return boundingVolume;
	}

	/**
	 * Setup bounding volume none
	 */
	void setupNone();

	/**
	 * Setup bounding volume sphere
	 * @param center center
	 * @param radius radius
	 */
	void setupSphere(const Vector3& center, float radius);

	/**
	 * Setup bounding volume capsule
	 * @param a a
	 * @param b b
	 * @param radius radius
	 */
	void setupCapsule(const Vector3& a, const Vector3& b, float radius);

	/**
	 * Setup bounding volume oriented bounding box
	 * @param center center
	 * @param axis0 axis 0
	 * @param axis1 axis 1
	 * @param axis2 axis 2
	 * @param halfExtension half extension
	 */
	void setupObb(const Vector3& center, const Vector3& axis0, const Vector3& axis1, const Vector3& axis2, const Vector3& halfExtension);

	/**
	 * Setup bounding volume bounding box
	 * @param min min
	 * @param max max
	 */
	void setupAabb(const Vector3& min, const Vector3& max);

	/**
	 * Clear convex mesh
	 */
	void clearConvexMesh();

	/**
	 * Setup convex mesh
	 * @param pathName path name
	 * @param fileName file name
	 */
	void setupConvexMesh(const string& pathName, const string& fileName);

	/**
	 * Setup convex mesh
	 * @param data TM data vector
	 */
	void setupConvexMesh(const vector<uint8_t>& data);

	/**
	 * @return if this convex mesh was generated by tdme2
	 */
	inline bool isGenerated() {
		return generated;
	}

	/**
	 * Set generated
	 * @param if this convex mesh was generated by tdme2
	 */
	inline void setGenerated(bool generated) {
		this->generated = generated;
	}

	/**
	 * @return has convex mesh data
	 */
	inline bool hasConvexMeshData() {
		return convexMeshData.empty() == false;
	}

	/**
	 * @return convex mesh data
	 */
	inline const vector<uint8_t>& getConvexMeshData() {
		return convexMeshData;
	}

private:

	/**
	 * Update prototype
	 */
	void updatePrototype();

};
