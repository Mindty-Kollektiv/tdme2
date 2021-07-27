#include <cstdlib>
#include <string>

#include <tdme/application/Application.h>
#include <tdme/engine/fileio/models/ModelReader.h>
#include <tdme/engine/fileio/models/TMWriter.h>
#include <tdme/engine/fileio/prototypes/PrototypeReader.h>
#include <tdme/engine/fileio/prototypes/PrototypeWriter.h>
#include <tdme/engine/model/Face.h>
#include <tdme/engine/model/FacesEntity.h>
#include <tdme/engine/model/Material.h>
#include <tdme/engine/model/Model.h>
#include <tdme/engine/model/Node.h>
#include <tdme/engine/model/RotationOrder.h>
#include <tdme/engine/model/SpecularMaterialProperties.h>
#include <tdme/engine/model/UpVector.h>
#include <tdme/engine/primitives/Triangle.h>
#include <tdme/engine/prototype/Prototype.h>
#include <tdme/engine/prototype/Prototype_Type.h>
#include <tdme/engine/prototype/PrototypeBoundingVolume.h>
#include <tdme/engine/Object3DModel.h>
#include <tdme/engine/Version.h>
#include <tdme/os/filesystem/FileSystem.h>
#include <tdme/os/filesystem/FileSystemInterface.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>
#include <tdme/utilities/ModelTools.h>
#include <tdme/utilities/StringTools.h>

using tdme::application::Application;
using tdme::engine::fileio::models::ModelReader;
using tdme::engine::fileio::models::TMWriter;
using tdme::engine::fileio::prototypes::PrototypeReader;
using tdme::engine::fileio::prototypes::PrototypeWriter;
using tdme::engine::model::Face;
using tdme::engine::model::FacesEntity;
using tdme::engine::model::Material;
using tdme::engine::model::Model;
using tdme::engine::model::Node;
using tdme::engine::model::RotationOrder;
using tdme::engine::model::SpecularMaterialProperties;
using tdme::engine::model::UpVector;
using tdme::engine::primitives::Triangle;
using tdme::engine::prototype::Prototype;
using tdme::engine::prototype::Prototype_Type;
using tdme::engine::prototype::PrototypeBoundingVolume;
using tdme::engine::Object3DModel;
using tdme::engine::Version;
using tdme::os::filesystem::FileSystem;
using tdme::os::filesystem::FileSystemInterface;
using tdme::utilities::Console;
using tdme::utilities::Exception;
using tdme::utilities::ModelTools;
using tdme::utilities::StringTools;

static Model* createModel(const string& id, vector<Triangle>& triangles) {
	auto model = new Model(id, id, UpVector::Y_UP, RotationOrder::XYZ, nullptr);
	auto material = new Material("primitive");
	material->setSpecularMaterialProperties(new SpecularMaterialProperties());
	material->getSpecularMaterialProperties()->setAmbientColor(Color4(0.5f, 0.5f, 0.5f, 1.0f));
	material->getSpecularMaterialProperties()->setDiffuseColor(Color4(1.0f, 0.5f, 0.5f, 0.5f));
	material->getSpecularMaterialProperties()->setSpecularColor(Color4(0.0f, 0.0f, 0.0f, 1.0f));
	model->getMaterials()[material->getId()] = material;
	auto node = new Node(model, nullptr, "node", "node");
	vector<Vector3> vertices;
	vector<Vector3> normals;
	vector<Face> faces;
	auto index = 0;
	for (auto& triangle: triangles) {
		for (auto& vertex: triangle.getVertices()) {
			vertices.push_back(vertex);
		}
		{
			array<Vector3, 3> faceVertices = {
				triangle.getVertices()[0],
				triangle.getVertices()[1],
				triangle.getVertices()[2],
			};
			for (auto& normal: ModelTools::computeNormals(faceVertices)) {
				normals.push_back(normal);
			}
		}
		faces.push_back(
			Face(
				node,
				index + 0,
				index + 1,
				index + 2,
				index + 0,
				index + 1,
				index + 2
			)
		);
		index+= 3;
	}
	FacesEntity nodeFacesEntity(node, "faces entity");
	nodeFacesEntity.setMaterial(material);
	nodeFacesEntity.setFaces(faces);
	vector<FacesEntity> nodeFacesEntities;
	nodeFacesEntities.push_back(nodeFacesEntity);
	node->setVertices(vertices);
	node->setNormals(normals);
	node->setFacesEntities(nodeFacesEntities);
	model->getNodes()["node"] = node;
	model->getSubNodes()["node"] = node;
	ModelTools::prepareForIndexedRendering(model);
	return model;
}

int main(int argc, char** argv)
{
	Console::println(string("importtmodel ") + Version::getVersion());
	Console::println(Version::getCopyright());
	Console::println();
	if (argc < 3) {
		Console::println("Usage: importtmodel model.tmodel modelfile.ext [bvs-model.ext]");
		Application::exit(1);
	}
	//
	string tmmFileName = argv[1];
	string modelFileName = argv[2];
	string bvsModelFileName = argc >= 4?argv[3]:"";
	try {
		Prototype* tmm = nullptr;
		// load model
		Console::println("Loading model: " + modelFileName);
		auto model = ModelReader::read(
			FileSystem::getInstance()->getPathName(modelFileName),
			FileSystem::getInstance()->getFileName(modelFileName)
		);
		// load tmm
		if (FileSystem::getInstance()->fileExists(tmmFileName) == false) {
			Console::println("Creating tmodel: " + tmmFileName);
			auto pathName = FileSystem::getInstance()->getPathName(tmmFileName);
			auto fileName = FileSystem::getInstance()->getFileName(tmmFileName);
			auto fileNameWithoutExtension = StringTools::substring(fileName, 0, fileName.rfind('.'));
			tmm = new Prototype(
				-1,
				Prototype_Type::MODEL,
				fileNameWithoutExtension,
				fileNameWithoutExtension,
				pathName + "/" + fileName,
				FileSystem::getInstance()->getPathName(modelFileName) + "/" + FileSystem::getInstance()->getFileName(modelFileName),
				string(),
				model,
				Vector3(0.0f, 0.0f, 0.0f)
			);
		} else {
			Console::println("Loading tmodel: " + tmmFileName);
			tmm = PrototypeReader::read(
				FileSystem::getInstance()->getPathName(tmmFileName),
				FileSystem::getInstance()->getFileName(tmmFileName)
			);
			tmm->setModel(model);
		}
		// remove old bv mesh model files
		for (auto i = 0; i < tmm->getBoundingVolumeCount(); i++) {
			auto bv = tmm->getBoundingVolume(i);
			auto bvModelMesh = bv->getModelMeshFile();
			if (bvModelMesh.empty() == true ||
				FileSystem::getInstance()->fileExists(bvModelMesh) == false ||
				bv->isGenerated() == false) {
				continue;
			}
			try {
				Console::println(
					"Removing old convex mesh model file@" +
					to_string(i) +
					": " + bvModelMesh
				);
				FileSystem::getInstance()->removeFile(
					FileSystem::getInstance()->getPathName(bvModelMesh),
					FileSystem::getInstance()->getFileName(bvModelMesh)
				);
			} catch (Exception& exception) {
				Console::println("An error occurred: " + string(exception.what()));
			}
		}
		// remove references to it
		Console::println("Removing old bounding volumes");
		while (tmm->getBoundingVolumeCount() > 0) tmm->removeBoundingVolume(0);

		// load new convex meshes bv model
		if (bvsModelFileName.empty() == false) {
			Console::println("Loading convex mesh bounding volumes model: " + bvsModelFileName);
			auto bvsModel = ModelReader::read(
				FileSystem::getInstance()->getPathName(bvsModelFileName),
				FileSystem::getInstance()->getFileName(bvsModelFileName)
			);
			// create to a single convex meshes
			vector<string> convexMeshFileNames;
			{
				auto meshFileName = FileSystem::getInstance()->getFileName(bvsModelFileName);
				auto meshPathName = FileSystem::getInstance()->getPathName(bvsModelFileName);
				Object3DModel meshObject3DModel(bvsModel);
				for (auto i = 0; i < meshObject3DModel.getNodeCount(); i++) {
					vector<Triangle> nodeTriangles;
					meshObject3DModel.getTriangles(nodeTriangles, i);
					auto convexMeshFileName = StringTools::substring(meshFileName, 0, meshFileName.rfind('.')) + "_cm" + to_string(i) + ".tm";
					Console::println(
						"Saving convex mesh model file@" +
						to_string(i) +
						": " + convexMeshFileName +
						", triangles = " + to_string(nodeTriangles.size())
					);
					auto convexMeshModel = createModel(
						meshPathName + "/" + convexMeshFileName,
						nodeTriangles
					);
					TMWriter::write(convexMeshModel, meshPathName, convexMeshFileName);
					delete convexMeshModel;
					convexMeshFileNames.push_back(meshPathName + "/" + convexMeshFileName);

				}
			}
			// add to tmm
			for (auto& convexMeshFileName: convexMeshFileNames) {
				Console::println(
					"Adding convex mesh bounding volume@" +
					to_string(tmm->getBoundingVolumeCount()) +
					": " + convexMeshFileName
				);
				tmm->addBoundingVolume(tmm->getBoundingVolumeCount(), new PrototypeBoundingVolume(tmm->getBoundingVolumeCount(), tmm));
				tmm->getBoundingVolume(tmm->getBoundingVolumeCount() - 1)->setupConvexMesh(
					FileSystem::getInstance()->getPathName(convexMeshFileName),
					FileSystem::getInstance()->getFileName(convexMeshFileName)
				);
				tmm->getBoundingVolume(tmm->getBoundingVolumeCount() - 1)->setGenerated(true);
			}
		}
		Console::println("Saving tmodel: " + tmmFileName);
		PrototypeWriter::write(
			FileSystem::getInstance()->getPathName(tmmFileName),
			FileSystem::getInstance()->getFileName(tmmFileName),
			tmm
		);
	} catch (Exception& exception) {
		Console::println("An error occurred: " + string(exception.what()));
	}

}
