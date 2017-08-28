// Generated from /tdme/src/tdme/engine/fileio/models/TMReader.java
#include <tdme/engine/fileio/models/TMReader.h>

#include <array>
#include <map>
#include <string>
#include <vector>

#include <Array.h>

#include <java/io/Serializable.h>
#include <java/lang/Cloneable.h>
#include <java/lang/Float.h>
#include <java/lang/Object.h>
#include <java/lang/String.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/StringBuilder.h>
#include <tdme/engine/fileio/models/ModelFileIOException.h>
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
#include <tdme/engine/model/ModelHelper.h>
#include <tdme/engine/model/RotationOrder.h>
#include <tdme/engine/model/Skinning.h>
#include <tdme/engine/model/TextureCoordinate.h>
#include <tdme/engine/primitives/BoundingBox.h>
#include <tdme/math/Matrix4x4.h>
#include <tdme/math/Vector3.h>
#include <tdme/os/_FileSystem.h>
#include <tdme/os/_FileSystemInterface.h>
#include <tdme/utils/StringConverter.h>
#include <Array.h>
#include <SubArray.h>
#include <ObjectArray.h>

using std::array;
using std::map;
using std::vector;
using std::wstring;
using std::to_string;

using tdme::engine::fileio::models::TMReader;
using tdme::engine::fileio::models::TMReaderInputStream;
using java::io::Serializable;
using java::lang::Cloneable;
using java::lang::Float;
using java::lang::Object;
using java::lang::String;
using java::lang::StringBuffer;
using java::lang::StringBuilder;
using tdme::engine::fileio::models::ModelFileIOException;
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
using tdme::engine::model::ModelHelper;
using tdme::engine::model::RotationOrder;
using tdme::engine::model::Skinning;
using tdme::engine::model::TextureCoordinate;
using tdme::engine::primitives::BoundingBox;
using tdme::math::Matrix4x4;
using tdme::math::Vector3;
using tdme::os::_FileSystem;
using tdme::os::_FileSystemInterface;
using tdme::utils::StringConverter;

template<typename T, typename U>
static T java_cast(U* u)
{
    if (!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    return t;
}

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
TMReader::TMReader(const ::default_init_tag&)
	: super(*static_cast< ::default_init_tag* >(0))
{
	clinit();
}

TMReader::TMReader()
	: TMReader(*static_cast< ::default_init_tag* >(0))
{
	ctor();
}

Model* TMReader::read(String* pathName, String* fileName) throw (_FileSystemException, ModelFileIOException)
{
	clinit();
	TMReaderInputStream* is = nullptr;
	auto finally0 = finally([&] {
		if (is != nullptr) {
			delete is;
		}
	});
	is = new TMReaderInputStream(_FileSystem::getInstance()->getContent(pathName, fileName));
	auto fileId = is->readString();
	if (fileId == nullptr || fileId->equals(u"TDME Model"_j) == false) {
		throw ModelFileIOException(
			"File is not a TDME model file, file id = '" +
			StringConverter::toString(fileId->getCPPWString()) +
			"'"
		);
	}
	auto version = new int8_tArray(3);
	(*version)[0] = is->readByte();
	(*version)[1] = is->readByte();
	(*version)[2] = is->readByte();
	if ((*version)[0] != 1 || (*version)[1] != 0 || (*version)[2] != 0) {
		throw ModelFileIOException(
			"Version mismatch, should be 1.0.0, but is " +
			to_string((*version)[0]) +
			"." +
			to_string((*version)[1]) +
			"." +
			to_string((*version)[2])
		);
	}
	auto name = is->readString();
	auto upVector = Model_UpVector::valueOf(is->readWString());
	auto rotationOrder = RotationOrder::valueOf(is->readWString());
	array<float, 3> boundingBoxMinXYZ;
	is->readFloatArray(&boundingBoxMinXYZ);
	array<float, 3> boundingBoxMaxXYZ;
	is->readFloatArray(&boundingBoxMaxXYZ);
	auto boundingBox = new BoundingBox(new Vector3(&boundingBoxMinXYZ), new Vector3(&boundingBoxMaxXYZ));
	auto model = new Model(
		::java::lang::StringBuilder().
		 append(pathName)->
		 append(L'/')->
		 append(fileName)->
		 toString()->
		 getCPPWString(),
		fileName->getCPPWString(),
		upVector,
		rotationOrder,
		boundingBox
	);
	model->setFPS(is->readFloat());
	array<float, 16> importTransformationsMatrixArray;
	is->readFloatArray(&importTransformationsMatrixArray);
	model->getImportTransformationsMatrix()->set(&importTransformationsMatrixArray);
	auto materialCount = is->readInt();
	for (auto i = 0; i < materialCount; i++) {
		auto material = readMaterial(is);
		(*model->getMaterials())[material->getId()] = material;
	}
	readSubGroups(is, model, nullptr, model->getSubGroups());
	return model;
}

Material* TMReader::readMaterial(TMReaderInputStream* is) throw (ModelFileIOException)
{
	clinit();
	auto id = is->readWString();
	auto m = new Material(id);
	array<float, 4> colorRGBAArray;
	is->readFloatArray(&colorRGBAArray);
	m->getAmbientColor()->set(&colorRGBAArray);
	is->readFloatArray(&colorRGBAArray);
	m->getDiffuseColor()->set(&colorRGBAArray);
	is->readFloatArray(&colorRGBAArray);
	m->getSpecularColor()->set(&colorRGBAArray);
	is->readFloatArray(&colorRGBAArray);
	m->getEmissionColor()->set(&colorRGBAArray);
	m->setShininess(is->readFloat());
	auto diffuseTexturePathName = is->readWString();
	auto diffuseTextureFileName = is->readWString();
	if (diffuseTextureFileName.size() != 0) {
		m->setDiffuseTexture(diffuseTexturePathName, diffuseTextureFileName);
	}
	auto specularTexturePathName = is->readWString();
	auto specularTextureFileName = is->readWString();
	if (specularTextureFileName.size() != 0) {
		m->setSpecularTexture(specularTexturePathName, specularTextureFileName);
	}
	auto normalTexturePathName = is->readWString();
	auto normalTextureFileName = is->readWString();
	if (normalTextureFileName.size() != 0) {
		m->setNormalTexture(normalTexturePathName, normalTextureFileName);
	}
	auto displacementTexturePathName = is->readWString();
	auto displacementTextureFileName = is->readWString();
	if (displacementTextureFileName.size() != 0) {
		m->setDisplacementTexture(displacementTexturePathName, displacementTextureFileName);
	}
	return m;
}

const vector<Vector3> TMReader::readVertices(TMReaderInputStream* is) throw (ModelFileIOException)
{
	clinit();
	vector<Vector3> v;
	array<float, 3> vXYZ;
	if (is->readBoolean() == true) {
		v.resize(is->readInt());
		for (auto i = 0; i < v.size(); i++) {
			is->readFloatArray(&vXYZ);
			v[i].set(&vXYZ);
		}
	}
	return v;
}

const vector<TextureCoordinate> TMReader::readTextureCoordinates(TMReaderInputStream* is) throw (ModelFileIOException)
{
	clinit();
	array<float, 2> tcUV;
	vector<TextureCoordinate> tc;
	if (is->readBoolean() == true) {
		tc.resize(is->readInt());
		for (auto i = 0; i < tc.size(); i++) {
			is->readFloatArray(&tcUV);
			tc[i] = TextureCoordinate(&tcUV);
		}
	}
	return tc;
}

int32_tArray* TMReader::readIndices(TMReaderInputStream* is) throw (ModelFileIOException)
{
	clinit();
	if (is->readBoolean() == false) {
		return nullptr;
	} else {
		auto indices = new int32_tArray(is->readInt());
		for (auto i = 0; i < indices->length; i++) {
			(*indices)[i] = is->readInt();
		}
		return indices;
	}
}

Animation* TMReader::readAnimation(TMReaderInputStream* is, Group* g) throw (ModelFileIOException)
{
	clinit();
	if (is->readBoolean() == false) {
		return nullptr;
	} else {
		array<float, 16> matrixArray;
		g->createAnimation(is->readInt());
		for (auto i = 0; i < g->getAnimation()->getTransformationsMatrices()->size(); i++) {
			is->readFloatArray(&matrixArray);
			(*g->getAnimation()->getTransformationsMatrices())[i].set(&matrixArray);
		}
		ModelHelper::createDefaultAnimation(g->getModel(), g->getAnimation()->getTransformationsMatrices()->size());
		return g->getAnimation();
	}
}

void TMReader::readFacesEntities(TMReaderInputStream* is, Group* g) throw (ModelFileIOException)
{
	clinit();
	vector<FacesEntity> facesEntities;
	facesEntities.resize(is->readInt());
	for (auto i = 0; i < facesEntities.size(); i++) {
		facesEntities[i] = FacesEntity(g, is->readString()->getCPPWString());
		if (is->readBoolean() == true) {
			Material* material = nullptr;
			auto materialIt = g->getModel()->getMaterials()->find(is->readString()->getCPPWString());
			if (materialIt != g->getModel()->getMaterials()->end()) {
				material = materialIt->second;
			}
			facesEntities[i].setMaterial(material);
		}
		vector<Face> faces;
		faces.resize(is->readInt());
		for (auto j = 0; j < faces.size(); j++) {
			auto vertexIndices = readIndices(is);
			auto normalIndices = readIndices(is);
			faces[j] = Face(g, (*vertexIndices)[0], (*vertexIndices)[1], (*vertexIndices)[2], (*normalIndices)[0], (*normalIndices)[1], (*normalIndices)[2]);
			auto textureCoordinateIndices = readIndices(is);
			if (textureCoordinateIndices != nullptr && textureCoordinateIndices->length > 0) {
				faces[j].setTextureCoordinateIndices((*textureCoordinateIndices)[0], (*textureCoordinateIndices)[1], (*textureCoordinateIndices)[2]);
			}
			auto tangentIndices = readIndices(is);
			auto bitangentIndices = readIndices(is);
			if (tangentIndices != nullptr && tangentIndices->length > 0 && bitangentIndices != nullptr && bitangentIndices->length > 0) {
				faces[j].setTangentIndices((*tangentIndices)[0], (*tangentIndices)[1], (*tangentIndices)[2]);
				faces[j].setBitangentIndices((*bitangentIndices)[0], (*bitangentIndices)[1], (*bitangentIndices)[2]);
			}
		}
		facesEntities[i].setFaces(&faces);
	}
	g->setFacesEntities(&facesEntities);
}

Joint TMReader::readSkinningJoint(TMReaderInputStream* is) throw (ModelFileIOException)
{
	clinit();
	array<float, 16> matrixArray;
	Joint joint(is->readWString());
	is->readFloatArray(&matrixArray);
	joint.getBindMatrix()->set(&matrixArray);
	return joint;
}

JointWeight TMReader::readSkinningJointWeight(TMReaderInputStream* is) throw (ModelFileIOException)
{
	clinit();
	return JointWeight(is->readInt(), is->readInt());
}

void TMReader::readSkinning(TMReaderInputStream* is, Group* g) throw (ModelFileIOException)
{
	clinit();
	if (is->readBoolean() == true) {
		auto skinning = g->createSkinning();
		skinning->setWeights(is->readFloatVector());
		vector<Joint> joints;
		joints.resize(is->readInt());
		for (auto i = 0; i < joints.size(); i++) {
			joints[i] = readSkinningJoint(is);
		}
		skinning->setJoints(&joints);
		vector<vector<JointWeight>> verticesJointsWeight;
		verticesJointsWeight.resize(is->readInt());
		for (auto i = 0; i < verticesJointsWeight.size(); i++) {
			verticesJointsWeight[i].resize(is->readInt());
			for (auto j = 0; j < verticesJointsWeight[i].size(); j++) {
				verticesJointsWeight[i][j] = readSkinningJointWeight(is);
			}
		}
		skinning->setVerticesJointsWeights(&verticesJointsWeight);
	}
}

void TMReader::readSubGroups(TMReaderInputStream* is, Model* model, Group* parentGroup, map<wstring, Group*>* subGroups) throw (ModelFileIOException)
{
	clinit();
	auto subGroupCount = is->readInt();
	for (auto i = 0; i < subGroupCount; i++) {
		auto subGroup = readGroup(is, model, parentGroup);
		(*subGroups)[subGroup->getId()] = subGroup;
		(*model->getGroups())[subGroup->getId()] = subGroup;
	}
}

Group* TMReader::readGroup(TMReaderInputStream* is, Model* model, Group* parentGroup) throw (ModelFileIOException)
{
	clinit();
	auto group = new Group(model, parentGroup, is->readWString(), is->readWString());
	group->setJoint(is->readBoolean());
	array<float, 16> matrixArray;
	is->readFloatArray(&matrixArray);
	group->getTransformationsMatrix()->set(&matrixArray);
	vector<Vector3> vertices = readVertices(is);
	group->setVertices(&vertices);
	vector<Vector3> normals = readVertices(is);
	group->setNormals(&normals);
	vector<TextureCoordinate> textureCoordinates = readTextureCoordinates(is);
	group->setTextureCoordinates(&textureCoordinates);
	vector<Vector3> tangents = readVertices(is);
	group->setTangents(&tangents);
	vector<Vector3> bitangents = readVertices(is);
	group->setBitangents(&bitangents);
	readAnimation(is, group);
	readSkinning(is, group);
	readFacesEntities(is, group);
	group->determineFeatures();
	readSubGroups(is, model, parentGroup, group->getSubGroups());
	return group;
}

extern java::lang::Class* class_(const char16_t* c, int n);

java::lang::Class* TMReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"tdme.engine.fileio.models.TMReader", 34);
    return c;
}

java::lang::Class* TMReader::getClass0()
{
	return class_();
}

