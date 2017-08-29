// Generated from /tdme/src/tdme/engine/fileio/models/TMWriter.java
#include <tdme/engine/fileio/models/TMWriter.h>

#include <array>
#include <map>
#include <string>
#include <vector>

#include <java/io/Serializable.h>
#include <java/lang/Cloneable.h>
#include <java/lang/Float.h>
#include <java/lang/String.h>
#include <java/util/Iterator.h>
#include <tdme/engine/model/Animation.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/engine/model/Face.h>
#include <tdme/engine/model/FacesEntity.h>
#include <tdme/engine/model/Group.h>
#include <tdme/engine/model/Joint.h>
#include <tdme/engine/model/JointWeight.h>
#include <tdme/engine/model/Material.h>
#include <tdme/engine/model/Model_UpVector.h>
#include <tdme/engine/model/Model.h>
#include <tdme/engine/model/RotationOrder.h>
#include <tdme/engine/model/Skinning.h>
#include <tdme/engine/model/TextureCoordinate.h>
#include <tdme/engine/primitives/BoundingBox.h>
#include <tdme/math/Matrix4x4.h>
#include <tdme/math/Vector3.h>
#include <tdme/os/_FileSystem.h>
#include <tdme/os/_FileSystemInterface.h>
#include <tdme/utils/_Exception.h>
#include <Array.h>
#include <SubArray.h>
#include <ObjectArray.h>

using std::array;
using std::map;
using std::vector;
using std::wstring;

using tdme::engine::fileio::models::TMWriter;
using java::io::Serializable;
using java::lang::Cloneable;
using java::lang::Float;
using java::lang::String;
using java::util::Iterator;
using tdme::engine::model::Animation;
using tdme::engine::model::Color4;
using tdme::engine::model::Face;
using tdme::engine::model::FacesEntity;
using tdme::engine::model::Group;
using tdme::engine::model::Joint;
using tdme::engine::model::JointWeight;
using tdme::engine::model::Material;
using tdme::engine::model::Model_UpVector;
using tdme::engine::model::Model;
using tdme::engine::model::RotationOrder;
using tdme::engine::model::Skinning;
using tdme::engine::model::TextureCoordinate;
using tdme::engine::primitives::BoundingBox;
using tdme::math::Matrix4x4;
using tdme::math::Vector3;
using tdme::os::_FileSystem;
using tdme::os::_FileSystemInterface;
using tdme::utils::_Exception;

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java {
namespace io {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
}  // namespace io

namespace lang {
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
}  // namespace lang
}  // namespace java

namespace tdme {
namespace engine {
namespace model {
typedef ::SubArray< ::tdme::engine::model::Face, ::java::lang::ObjectArray > FaceArray;
typedef ::SubArray< ::tdme::engine::model::FacesEntity, ::java::lang::ObjectArray > FacesEntityArray;
typedef ::SubArray< ::tdme::engine::model::Joint, ::java::lang::ObjectArray > JointArray;
typedef ::SubArray< ::tdme::engine::model::JointWeight, ::java::lang::ObjectArray > JointWeightArray;
typedef ::SubArray< ::tdme::engine::model::TextureCoordinate, ::java::lang::ObjectArray > TextureCoordinateArray;
}  // namespace model
}  // namespace engine

namespace math {
typedef ::SubArray< ::tdme::math::Matrix4x4, ::java::lang::ObjectArray > Matrix4x4Array;
typedef ::SubArray< ::tdme::math::Vector3, ::java::lang::ObjectArray > Vector3Array;
}  // namespace math

namespace engine {
namespace model {
typedef ::SubArray< ::tdme::engine::model::JointWeightArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > JointWeightArrayArray;
}  // namespace model
}  // namespace engine
}  // namespace tdme

namespace
{
template<typename F>
struct finally_
{
    finally_(F f) : f(f), moved(false) { }
    finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
    ~finally_() { if(!moved) f(); }
private:
    finally_(const finally_&); finally_& operator=(const finally_&);
    F f;
    bool moved;
};

template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
}

void TMWriter::write(Model* model, String* pathName, String* fileName) throw (_FileSystemException, ModelFileIOException)
{
	TMWriterOutputStream* os = nullptr;
	auto finally0 = finally([&] {
		if (os != nullptr) {
			delete os;
		}
	});
	os = new TMWriterOutputStream();
	os->writeString(u"TDME Model"_j);
	os->writeByte(static_cast< int8_t >(1));
	os->writeByte(static_cast< int8_t >(0));
	os->writeByte(static_cast< int8_t >(0));
	os->writeString(model->getName());
	os->writeString(model->getUpVector()->toString());
	os->writeString(model->getRotationOrder()->toString());
	os->writeFloatArray(model->getBoundingBox()->getMin()->getArray());
	os->writeFloatArray(model->getBoundingBox()->getMax()->getArray());
	os->writeFloat(model->getFPS());
	os->writeFloatArray(model->getImportTransformationsMatrix()->getArray());
	os->writeInt(model->getMaterials()->size());
	for (auto it: *model->getMaterials()) {
		Material* material = it.second;
		writeMaterial(os, material);
	}
	_FileSystem::getInstance()->setContent(pathName, fileName, os->getData(), os->getPosition());
	writeSubGroups(os, model->getSubGroups());
}

void TMWriter::writeMaterial(TMWriterOutputStream* os, Material* m) throw (ModelFileIOException)
{
	os->writeString(m->getId());
	os->writeFloatArray(m->getAmbientColor()->getArray());
	os->writeFloatArray(m->getDiffuseColor()->getArray());
	os->writeFloatArray(m->getSpecularColor()->getArray());
	os->writeFloatArray(m->getEmissionColor()->getArray());
	os->writeFloat(m->getShininess());
	os->writeString(m->getDiffuseTexturePathName());
	os->writeString(m->getDiffuseTextureFileName());
	os->writeString(m->getSpecularTexturePathName());
	os->writeString(m->getSpecularTextureFileName());
	os->writeString(m->getNormalTexturePathName());
	os->writeString(m->getNormalTextureFileName());
	os->writeString(m->getDisplacementTexturePathName());
	os->writeString(m->getDisplacementTextureFileName());
}

void TMWriter::writeVertices(TMWriterOutputStream* os, vector<Vector3>* v) throw (ModelFileIOException)
{
	if (v->size() == 0) {
		os->writeBoolean(false);
	} else {
		os->writeBoolean(true);
		os->writeInt(v->size());
		for (auto i = 0; i < v->size(); i++) {
			os->writeFloatArray((*v)[i].getArray());
		}
	}
}

void TMWriter::writeTextureCoordinates(TMWriterOutputStream* os, vector<TextureCoordinate>* tc) throw (ModelFileIOException)
{
	if (tc == nullptr) {
		os->writeBoolean(false);
	} else {
		os->writeBoolean(true);
		os->writeInt(tc->size());
		for (auto i = 0; i < tc->size(); i++) {
			os->writeFloatArray((*tc)[i].getArray());
		}
	}
}

void TMWriter::writeIndices(TMWriterOutputStream* os, array<int32_t, 3>* indices) throw (ModelFileIOException)
{
	if (indices == nullptr) {
		os->writeBoolean(false);
	} else {
		os->writeBoolean(true);
		os->writeInt(indices->size());
		for (auto i = 0; i < indices->size(); i++) {
			os->writeInt((*indices)[i]);
		}
	}
}

void TMWriter::writeAnimation(TMWriterOutputStream* os, Animation* a) throw (ModelFileIOException)
{
	if (a == nullptr) {
		os->writeBoolean(false);
	} else {
		os->writeBoolean(true);
		os->writeInt(a->getTransformationsMatrices()->size());
		for (auto i = 0; i < a->getTransformationsMatrices()->size(); i++) {
			os->writeFloatArray((*a->getTransformationsMatrices())[i].getArray());
		}
	}
}

void TMWriter::writeFacesEntities(TMWriterOutputStream* os, vector<FacesEntity>* facesEntities) throw (ModelFileIOException)
{
	os->writeInt(facesEntities->size());
	for (auto i = 0; i < facesEntities->size(); i++) {
		auto& fe = (*facesEntities)[i];
		os->writeString(fe.getId());
		if (fe.getMaterial() == nullptr) {
			os->writeBoolean(false);
		} else {
			os->writeBoolean(true);
			os->writeString(fe.getMaterial()->getId());
		}
		os->writeInt(fe.getFaces()->size());
		for (auto j = 0; j < fe.getFaces()->size(); j++) {
			auto& f = (*fe.getFaces())[j];
			writeIndices(os, f.getVertexIndices());
			writeIndices(os, f.getNormalIndices());
			writeIndices(os, f.getTextureCoordinateIndices());
			writeIndices(os, f.getTangentIndices());
			writeIndices(os, f.getBitangentIndices());
		}
	}
}

void TMWriter::writeSkinningJoint(TMWriterOutputStream* os, Joint* joint) throw (ModelFileIOException)
{
	os->writeString(joint->getGroupId());
	os->writeFloatArray(joint->getBindMatrix()->getArray());
}

void TMWriter::writeSkinningJointWeight(TMWriterOutputStream* os, JointWeight* jointWeight) throw (ModelFileIOException)
{
	os->writeInt(jointWeight->getJointIndex());
	os->writeInt(jointWeight->getWeightIndex());
}

void TMWriter::writeSkinning(TMWriterOutputStream* os, Skinning* skinning) throw (ModelFileIOException)
{
	if (skinning == nullptr) {
		os->writeBoolean(false);
	} else {
		os->writeBoolean(true);
		os->writeFloatArray(skinning->getWeights());
		os->writeInt(skinning->getJoints()->size());
		for (auto i = 0; i < skinning->getJoints()->size(); i++) {
			writeSkinningJoint(os, &(*skinning->getJoints())[i]);
		}
		os->writeInt(skinning->getVerticesJointsWeights()->size());
		for (auto i = 0; i < skinning->getVerticesJointsWeights()->size(); i++) {
			os->writeInt((*skinning->getVerticesJointsWeights())[i].size());
			for (auto j = 0; j < (*skinning->getVerticesJointsWeights())[i].size(); j++) {
				writeSkinningJointWeight(os, &(*skinning->getVerticesJointsWeights())[i][j]);
			}
		}
	}
}

void TMWriter::writeSubGroups(TMWriterOutputStream* os, map<wstring, Group*>* subGroups) throw (ModelFileIOException)
{
	os->writeInt(subGroups->size());
	for (auto it: *subGroups) {
		Group* subGroup = it.second;
		writeGroup(os, subGroup);
	}
}

void TMWriter::writeGroup(TMWriterOutputStream* os, Group* g) throw (ModelFileIOException)
{
	os->writeString(g->getId());
	os->writeString(g->getName());
	os->writeBoolean(g->isJoint());
	os->writeFloatArray(g->getTransformationsMatrix()->getArray());
	writeVertices(os, g->getVertices());
	writeVertices(os, g->getNormals());
	writeTextureCoordinates(os, g->getTextureCoordinates());
	writeVertices(os, g->getTangents());
	writeVertices(os, g->getBitangents());
	writeAnimation(os, g->getAnimation());
	writeSkinning(os, g->getSkinning());
	writeFacesEntities(os, g->getFacesEntities());
	writeSubGroups(os, g->getSubGroups());
}
