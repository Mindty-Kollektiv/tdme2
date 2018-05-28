#include <tdme/tools/shared/controller/EntityBoundingVolumeSubScreenController.h>

#include <string>

#include <tdme/engine/fileio/models/ModelReader.h>
#include <tdme/engine/Transformations.h>
#include <tdme/engine/primitives/BoundingBox.h>
#include <tdme/engine/primitives/BoundingVolume.h>
#include <tdme/engine/primitives/Capsule.h>
#include <tdme/engine/primitives/ConvexMesh.h>
#include <tdme/engine/primitives/OrientedBoundingBox.h>
#include <tdme/engine/primitives/Sphere.h>
#include <tdme/gui/GUIParser.h>
#include <tdme/gui/events/GUIActionListener_Type.h>
#include <tdme/gui/nodes/GUIElementNode.h>
#include <tdme/gui/nodes/GUINode.h>
#include <tdme/gui/nodes/GUINodeConditions.h>
#include <tdme/gui/nodes/GUINodeController.h>
#include <tdme/gui/nodes/GUIParentNode.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/math/Matrix4x4.h>
#include <tdme/math/Vector3.h>
#include <tdme/tools/shared/controller/EntityBoundingVolumeSubScreenController_GenerateConvexMeshes.h>
#include <tdme/tools/shared/controller/EntityBoundingVolumeSubScreenController_onBoundingVolumeConvexMeshesFile.h>
#include <tdme/tools/shared/controller/EntityBoundingVolumeSubScreenController_onBoundingVolumeConvexMeshFile_1.h>
#include <tdme/tools/shared/controller/EntityBoundingVolumeSubScreenController_BoundingVolumeType.h>
#include <tdme/tools/shared/controller/FileDialogPath.h>
#include <tdme/tools/shared/controller/FileDialogScreenController.h>
#include <tdme/tools/shared/controller/InfoDialogScreenController.h>
#include <tdme/tools/shared/model/LevelEditorEntity.h>
#include <tdme/tools/shared/model/LevelEditorEntityBoundingVolume.h>
#include <tdme/tools/shared/model/LevelEditorEntityModel.h>
#include <tdme/tools/shared/model/LevelEditorEntityPhysics.h>
#include <tdme/tools/shared/model/LevelEditorEntityPhysics_BodyType.h>
#include <tdme/tools/shared/tools/Tools.h>
#include <tdme/tools/shared/views/EntityBoundingVolumeView.h>
#include <tdme/tools/shared/views/PopUps.h>
#include <tdme/utils/MutableString.h>
#include <tdme/utils/StringUtils.h>
#include <tdme/utils/Console.h>
#include <tdme/utils/Exception.h>

using std::string;
using std::to_string;

using tdme::tools::shared::controller::EntityBoundingVolumeSubScreenController;

using tdme::engine::fileio::models::ModelReader;
using tdme::engine::Transformations;
using tdme::engine::primitives::BoundingBox;
using tdme::engine::primitives::BoundingVolume;
using tdme::engine::primitives::Capsule;
using tdme::engine::primitives::ConvexMesh;
using tdme::engine::primitives::OrientedBoundingBox;
using tdme::engine::primitives::Sphere;
using tdme::gui::GUIParser;
using tdme::gui::events::GUIActionListener_Type;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUINode;
using tdme::gui::nodes::GUINodeConditions;
using tdme::gui::nodes::GUINodeController;
using tdme::gui::nodes::GUIParentNode;
using tdme::gui::nodes::GUIScreenNode;
using tdme::math::Matrix4x4;
using tdme::math::Vector3;
using tdme::tools::shared::controller::EntityBoundingVolumeSubScreenController_GenerateConvexMeshes;
using tdme::tools::shared::controller::EntityBoundingVolumeSubScreenController_onBoundingVolumeConvexMeshesFile;
using tdme::tools::shared::controller::EntityBoundingVolumeSubScreenController_onBoundingVolumeConvexMeshFile_1;
using tdme::tools::shared::controller::EntityBoundingVolumeSubScreenController_BoundingVolumeType;
using tdme::tools::shared::controller::FileDialogPath;
using tdme::tools::shared::controller::FileDialogScreenController;
using tdme::tools::shared::controller::InfoDialogScreenController;
using tdme::tools::shared::model::LevelEditorEntity;
using tdme::tools::shared::model::LevelEditorEntityBoundingVolume;
using tdme::tools::shared::model::LevelEditorEntityPhysics;
using tdme::tools::shared::model::LevelEditorEntityPhysics_BodyType;
using tdme::tools::shared::tools::Tools;
using tdme::tools::shared::views::EntityBoundingVolumeView;
using tdme::tools::shared::views::PopUps;
using tdme::utils::MutableString;
using tdme::utils::StringUtils;
using tdme::utils::Console;
using tdme::utils::Exception;

constexpr int32_t EntityBoundingVolumeSubScreenController::MODEL_BOUNDINGVOLUME_COUNT;

vector<string> EntityBoundingVolumeSubScreenController::MODEL_BOUNDINGVOLUME_IDS = {
	"model_bv.0",
	"model_bv.1",
	"model_bv.2",
	"model_bv.3",
	"model_bv.4",
	"model_bv.5",
	"model_bv.6",
	"model_bv.7"
};

EntityBoundingVolumeSubScreenController::EntityBoundingVolumeSubScreenController(PopUps* popUps, FileDialogPath* modelPath, bool isModelBoundingVolumes)
{
	this->modelPath = modelPath;
	this->view = new EntityBoundingVolumeView(this, popUps);
	this->isModelBoundingVolumes = isModelBoundingVolumes;
}

EntityBoundingVolumeSubScreenController::~EntityBoundingVolumeSubScreenController() {
	delete view;
}

EntityBoundingVolumeView* EntityBoundingVolumeSubScreenController::getView()
{
	return view;
}

void EntityBoundingVolumeSubScreenController::initialize(GUIScreenNode* screenNode)
{
	try {
		for (auto i = 0; i < 8; i++) {
			boundingVolumeTypeDropDown[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_type_" + to_string(i)));
			boundingVolumeNoneApply[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("button_boundingvolume_apply_" + to_string(i)));
			boundingVolume[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_" + to_string(i)));
			boundingvolumeSphereCenter[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_sphere_center_" + to_string(i)));
			boundingvolumeSphereRadius[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_sphere_radius_" + to_string(i)));
			boundingvolumeCapsuleA[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_capsule_a_" + to_string(i)));
			boundingvolumeCapsuleB[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_capsule_b_" + to_string(i)));
			boundingvolumeCapsuleRadius[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_capsule_radius_" + to_string(i)));
			boundingvolumeBoundingBoxMin[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_aabb_min_" + to_string(i)));
			boundingvolumeBoundingBoxMax[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_aabb_max_" + to_string(i)));
			boundingvolumeObbCenter[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_obb_center_" + to_string(i)));
			boundingvolumeObbCenter[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_obb_center_" + to_string(i)));
			boundingvolumeObbHalfextension[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_obb_halfextension_" + to_string(i)));
			boundingvolumeObbRotationX[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_obb_rotation_x_" + to_string(i)));
			boundingvolumeObbRotationY[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_obb_rotation_y_" + to_string(i)));
			boundingvolumeObbRotationZ[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_obb_rotation_z_" + to_string(i)));
			boundingvolumeConvexMeshFile[i] = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmesh_file_" + to_string(i)));
		}
		bodyTypeDropdown = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("physics_bodytype_dropdown"));
		bodyTypeDropdownApply = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("physics_bodytype_dropdown_apply"));
		bodyMass = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("physics_body_mass"));
		bodyBounciness = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("physics_body_bounciness"));
		bodyFriction = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("physics_body_friction"));
		bodyApply = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("physics_body_apply"));
		if (isModelBoundingVolumes == true) {
			terrainMesh = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("terrain_mesh"));
			terrainMeshApply = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("button_terrain_mesh_apply"));
			convexMeshesFile = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_file"));
			convexMeshesLoad = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("button_boundingvolume_convexmeshes_file"));
			convexMeshesResolution = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_resolution"));
			convexMeshesDepth = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_depth"));
			convexMeshesConcavity = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_concavity"));
			convexMeshesPlaneDownSampling = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_planedownsampling"));
			convexMeshesConvexHullDownSampling = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_convexhullownsampling"));
			convexMeshesAlpha = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_alpha"));
			convexMeshesBeta = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_beta"));
			convexMeshesMaxVerticesPerConvexHull = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_maxverticesperch"));
			convexMeshesMinVolumePerConvexHull = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_minvolumeperch"));
			convexMeshesPCA = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("boundingvolume_convexmeshes_pca"));
			convexMeshesRemove = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("button_boundingvolume_convexmeshes_remove"));
			convexMeshesGenerate = dynamic_cast< GUIElementNode* >(screenNode->getNodeById("button_boundingvolume_convexmeshes_generate"));
		}
	} catch (Exception& exception) {
		Console::print(string("EntityBoundingVolumeSubScreenController::initialize(): An error occurred: "));
		Console::println(string(exception.what()));
	}
}

void EntityBoundingVolumeSubScreenController::disableBoundingVolume(int32_t idx)
{
	view->selectBoundingVolumeType(idx, 0);
	boundingVolumeTypeDropDown[idx]->getController()->setDisabled(true);
	boundingVolumeNoneApply[idx]->getController()->setDisabled(true);
}

void EntityBoundingVolumeSubScreenController::enableBoundingVolume(int32_t idx)
{
	boundingVolumeTypeDropDown[idx]->getController()->setDisabled(false);
	boundingVolumeNoneApply[idx]->getController()->setDisabled(false);
}

void EntityBoundingVolumeSubScreenController::setupModelBoundingVolumeType(LevelEditorEntity* entity, int32_t idx)
{
	if (entity == nullptr) {
		view->selectBoundingVolumeType(idx, 0);
		return;
	}
	auto entityBoundingVolume = entity->getBoundingVolumeAt(idx);
	if (entityBoundingVolume == nullptr) {
		view->selectBoundingVolumeType(idx, 0);
	} else {
		auto bv = entityBoundingVolume->getBoundingVolume();
		if (bv == nullptr) {
			view->selectBoundingVolumeType(idx, 0);
		} else
		if (dynamic_cast< Sphere* >(bv) != nullptr) {
			view->selectBoundingVolumeType(idx, 1);
		} else
		if (dynamic_cast< Capsule* >(bv) != nullptr) {
			view->selectBoundingVolumeType(idx, 2);
		} else
		if (dynamic_cast< BoundingBox* >(bv) != nullptr) {
			view->selectBoundingVolumeType(idx, 3);
		} else
		if (dynamic_cast< OrientedBoundingBox* >(bv) != nullptr) {
			view->selectBoundingVolumeType(idx, 4);
		} else
		if (dynamic_cast< ConvexMesh* >(bv) != nullptr) {
			view->selectBoundingVolumeType(idx, 5);
		} else {
			Console::println(string("ModelEditorScreenController::onTabSelected(): invalid bounding volume@" + to_string(idx)));
		}
	}
}

void EntityBoundingVolumeSubScreenController::setupBoundingVolumeTypes(int32_t idx, vector<string>* boundingVolumeTypes)
{
	auto boundingVolumeTypeDropDownInnerNode = dynamic_cast< GUIParentNode* >((boundingVolumeTypeDropDown[idx]->getScreenNode()->getNodeById(boundingVolumeTypeDropDown[idx]->getId() + "_inner")));
	auto bvIdx = 0;
	string boundingVolumeTypeDropDownSubNodesXML = "";
	boundingVolumeTypeDropDownSubNodesXML =
		boundingVolumeTypeDropDownSubNodesXML +
		"<scrollarea-vertical width=\"100%\" height=\"80\">";
	for (auto& bvType : *boundingVolumeTypes) {
		boundingVolumeTypeDropDownSubNodesXML =
			boundingVolumeTypeDropDownSubNodesXML +
			"<dropdown-option text=\"" +
			GUIParser::escapeQuotes(bvType) +
			"\" value=\"" +
			to_string(bvIdx++) +
			"\" />\n";
	}
	boundingVolumeTypeDropDownSubNodesXML =
		boundingVolumeTypeDropDownSubNodesXML +
		"</scrollarea-vertical>";
	try {
		boundingVolumeTypeDropDownInnerNode->replaceSubNodes(boundingVolumeTypeDropDownSubNodesXML, true);
	} catch (Exception& exception) {
		Console::print(string("EntityBoundingVolumeSubScreenController::setupBoundingVolumeTypes(): An error occurred: "));
		Console::println(string(exception.what()));
	}
}

void EntityBoundingVolumeSubScreenController::selectBoundingVolume(int32_t idx, EntityBoundingVolumeSubScreenController_BoundingVolumeType* bvType)
{
	boundingVolume[idx]->getActiveConditions().remove("sphere");
	boundingVolume[idx]->getActiveConditions().remove("capsule");
	boundingVolume[idx]->getActiveConditions().remove("aabb");
	boundingVolume[idx]->getActiveConditions().remove("obb");
	boundingVolume[idx]->getActiveConditions().remove("convexmesh");
	{
		auto v = bvType;
		if (v == EntityBoundingVolumeSubScreenController_BoundingVolumeType::NONE) {
			boundingVolumeTypeDropDown[idx]->getController()->setValue(MutableString("0"));
		} else
		if (v == EntityBoundingVolumeSubScreenController_BoundingVolumeType::SPHERE) {
			boundingVolumeTypeDropDown[idx]->getController()->setValue(MutableString("1"));
			boundingVolume[idx]->getActiveConditions().add("sphere");
		} else
		if (v == EntityBoundingVolumeSubScreenController_BoundingVolumeType::CAPSULE) {
			boundingVolumeTypeDropDown[idx]->getController()->setValue(MutableString("2"));
			boundingVolume[idx]->getActiveConditions().add("capsule");
		} else
		if (v == EntityBoundingVolumeSubScreenController_BoundingVolumeType::BOUNDINGBOX) {
			boundingVolumeTypeDropDown[idx]->getController()->setValue(MutableString("3"));
			boundingVolume[idx]->getActiveConditions().add("aabb");
		} else
		if (v == EntityBoundingVolumeSubScreenController_BoundingVolumeType::ORIENTEDBOUNDINGBOX) {
			boundingVolumeTypeDropDown[idx]->getController()->setValue(MutableString("4"));
			boundingVolume[idx]->getActiveConditions().add("obb");
		} else
		if (v == EntityBoundingVolumeSubScreenController_BoundingVolumeType::CONVEXMESH) {
			boundingVolumeTypeDropDown[idx]->getController()->setValue(MutableString("5"));
			boundingVolume[idx]->getActiveConditions().add("convexmesh");
		}
	}

}

void EntityBoundingVolumeSubScreenController::setupSphere(int32_t idx, const Vector3& center, float radius)
{
	selectBoundingVolume(idx, EntityBoundingVolumeSubScreenController_BoundingVolumeType::SPHERE);
	boundingvolumeSphereCenter[idx]->getController()->setValue(MutableString(Tools::formatFloat(center.getX())).append(", ").append(Tools::formatFloat(center.getY())).append(", ").append(Tools::formatFloat(center.getZ())));
	boundingvolumeSphereRadius[idx]->getController()->setValue(MutableString(Tools::formatFloat(radius)));
}

void EntityBoundingVolumeSubScreenController::setupCapsule(int32_t idx, const Vector3& a, const Vector3& b, float radius)
{
	selectBoundingVolume(idx, EntityBoundingVolumeSubScreenController_BoundingVolumeType::CAPSULE);
	boundingvolumeCapsuleA[idx]->getController()->setValue(MutableString(Tools::formatFloat(a.getX())).append(", ").append(Tools::formatFloat(a.getY())).append(", ").append(Tools::formatFloat(a.getZ())));
	boundingvolumeCapsuleB[idx]->getController()->setValue(MutableString(Tools::formatFloat(b.getX())).append(", ").append(Tools::formatFloat(b.getY())).append(", ").append(Tools::formatFloat(b.getZ())));
	boundingvolumeCapsuleRadius[idx]->getController()->setValue(MutableString(Tools::formatFloat(radius)));
}

void EntityBoundingVolumeSubScreenController::setupBoundingBox(int32_t idx, const Vector3& min, const Vector3& max)
{
	selectBoundingVolume(idx, EntityBoundingVolumeSubScreenController_BoundingVolumeType::BOUNDINGBOX);
	boundingvolumeBoundingBoxMin[idx]->getController()->setValue(MutableString(Tools::formatFloat(min.getX())).append(", ").append(Tools::formatFloat(min.getY())).append(", ").append(Tools::formatFloat(min.getZ())));
	boundingvolumeBoundingBoxMax[idx]->getController()->setValue(MutableString(Tools::formatFloat(max.getX())).append(", ").append(Tools::formatFloat(max.getY())).append(", ").append(Tools::formatFloat(max.getZ())));
}

void EntityBoundingVolumeSubScreenController::setupOrientedBoundingBox(int32_t idx, const Vector3& center, const Vector3& axis0, const Vector3& axis1, const Vector3& axis2, const Vector3& halfExtension)
{
	Vector3 rotation;
	Matrix4x4 rotationMatrix;
	rotationMatrix.identity();
	rotationMatrix.setAxes(axis0, axis1, axis2);
	rotationMatrix.computeEulerAngles(rotation);
	selectBoundingVolume(idx, EntityBoundingVolumeSubScreenController_BoundingVolumeType::ORIENTEDBOUNDINGBOX);
	boundingvolumeObbCenter[idx]->getController()->setValue(MutableString(Tools::formatFloat(center.getX())).append(", ").append(Tools::formatFloat(center.getY())).append(", ").append(Tools::formatFloat(center.getZ())));
	boundingvolumeObbHalfextension[idx]->getController()->setValue(MutableString(Tools::formatFloat(halfExtension.getX())).append(", ").append(Tools::formatFloat(halfExtension.getY())).append(", ").append(Tools::formatFloat(halfExtension.getZ())));
	boundingvolumeObbRotationX[idx]->getController()->setValue(MutableString(Tools::formatFloat(rotation.getX())));
	boundingvolumeObbRotationY[idx]->getController()->setValue(MutableString(Tools::formatFloat(rotation.getY())));
	boundingvolumeObbRotationZ[idx]->getController()->setValue(MutableString(Tools::formatFloat(rotation.getZ())));
}

void EntityBoundingVolumeSubScreenController::setupConvexMesh(int32_t idx, const string& file)
{
	selectBoundingVolume(idx, EntityBoundingVolumeSubScreenController_BoundingVolumeType::CONVEXMESH);
	boundingvolumeConvexMeshFile[idx]->getController()->setValue(MutableString(file));
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeTypeApply(LevelEditorEntity* entity, int32_t idx)
{
	auto boundingVolumeTypeId = Tools::convertToIntSilent(boundingVolumeTypeDropDown[idx]->getController()->getValue().getString());
	view->selectBoundingVolumeType(idx, boundingVolumeTypeId);
	switch (boundingVolumeTypeId) {
	case (0):
		onBoundingVolumeNoneApply(entity, idx);
		break;
	case (1):
		onBoundingVolumeSphereApply(entity, idx);
		break;
	case (2):
		onBoundingVolumeCapsuleApply(entity, idx);
		break;
	case (3):
		onBoundingVolumeAabbApply(entity, idx);
		break;
	case (4):
		onBoundingVolumeObbApply(entity, idx);
		break;
	case (5):
		onBoundingVolumeConvexMeshApply(entity, idx);
		break;
	}
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeNoneApply(LevelEditorEntity* entity, int32_t idx)
{
	view->applyBoundingVolumeNone(entity, idx);
	view->resetBoundingVolume(entity, idx);
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeSphereApply(LevelEditorEntity* entity, int32_t idx)
{
	try {
		view->applyBoundingVolumeSphere(
			entity,
			idx,
			Tools::convertToVector3(boundingvolumeSphereCenter[idx]->getController()->getValue().getString()),
			Tools::convertToFloat(boundingvolumeSphereRadius[idx]->getController()->getValue().getString())
		);
	} catch (Exception& exception) {
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeCapsuleApply(LevelEditorEntity* entity, int32_t idx)
{
	try {
		view->applyBoundingVolumeCapsule(
			entity,
			idx,
			Tools::convertToVector3(boundingvolumeCapsuleA[idx]->getController()->getValue().getString()),
			Tools::convertToVector3(boundingvolumeCapsuleB[idx]->getController()->getValue().getString()),
			Tools::convertToFloat(boundingvolumeCapsuleRadius[idx]->getController()->getValue().getString())
		);
	} catch (Exception& exception) {
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeAabbApply(LevelEditorEntity* entity, int32_t idx)
{
	try {
		view->applyBoundingVolumeAabb(
			entity,
			idx,
			Tools::convertToVector3(boundingvolumeBoundingBoxMin[idx]->getController()->getValue().getString()),
			Tools::convertToVector3(boundingvolumeBoundingBoxMax[idx]->getController()->getValue().getString())
		);
	} catch (Exception& exception) {
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeObbApply(LevelEditorEntity* entity, int32_t idx)
{
	try {
		Transformations rotations;
		rotations.addRotation(OrientedBoundingBox::AABB_AXIS_Z, Tools::convertToFloat(boundingvolumeObbRotationZ[idx]->getController()->getValue().getString()));
		rotations.addRotation(OrientedBoundingBox::AABB_AXIS_Y, Tools::convertToFloat(boundingvolumeObbRotationY[idx]->getController()->getValue().getString()));
		rotations.addRotation(OrientedBoundingBox::AABB_AXIS_X, Tools::convertToFloat(boundingvolumeObbRotationX[idx]->getController()->getValue().getString()));
		rotations.update();
		Vector3 xAxis;
		Vector3 yAxis;
		Vector3 zAxis;
		rotations.getTransformationsMatrix().clone().getAxes(xAxis, yAxis, zAxis);
		view->applyBoundingVolumeObb(
			entity,
			idx,
			Tools::convertToVector3(boundingvolumeObbCenter[idx]->getController()->getValue().getString()),
			xAxis,
			yAxis,
			zAxis,
			Tools::convertToVector3(boundingvolumeObbHalfextension[idx]->getController()->getValue().getString())
		);
	} catch (Exception& exception) {
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeConvexMeshApply(LevelEditorEntity* entity, int32_t idx)
{
	view->applyBoundingVolumeConvexMesh(
		entity,
		idx,
		boundingvolumeConvexMeshFile[idx]->getController()->getValue().getString()
	);
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeConvexMeshFile(LevelEditorEntity* entity, int32_t idx)
{
	auto const idxFinal = idx;
	auto const entityFinal = entity;
	vector<string> extensions = ModelReader::getModelExtensions();
	view->getPopUpsViews()->getFileDialogScreenController()->show(
		modelPath->getPath(),
		"Load from: ",
		&extensions,
		entity->getBoundingVolumeAt(idx)->getModelMeshFile().length() > 0 ? entity->getBoundingVolumeAt(idx)->getModelMeshFile() : entity->getFileName(),
		new EntityBoundingVolumeSubScreenController_onBoundingVolumeConvexMeshFile_1(this, idxFinal, entityFinal)
	);
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeConvexMeshesFile(LevelEditorEntity* entity)
{
	auto const entityFinal = entity;
	vector<string> extensions = ModelReader::getModelExtensions();
	view->getPopUpsViews()->getFileDialogScreenController()->show(
		Tools::getPath(convexMeshesFile->getController()->getValue().getString()),
		"Load from: ",
		&extensions,
		Tools::getFileName(convexMeshesFile->getController()->getValue().getString()),
		new EntityBoundingVolumeSubScreenController_onBoundingVolumeConvexMeshesFile(this, entityFinal)
	);
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeConvexMeshesRemove(LevelEditorEntity* entity)
{
	EntityBoundingVolumeSubScreenController_GenerateConvexMeshes::removeConvexMeshes(
		this,
		entity
	);
}

void EntityBoundingVolumeSubScreenController::onBoundingVolumeConvexMeshesGenerate(LevelEditorEntity* entity)
{
	EntityBoundingVolumeSubScreenController_GenerateConvexMeshes::generateConvexMeshes(
		this,
		entity
	);
}

void EntityBoundingVolumeSubScreenController::setTerrainMesh(LevelEditorEntity* entity) {
	terrainMesh->getController()->setValue(MutableString(entity->getModelSettings()->isTerrainMesh() == true?"1":""));
	terrainMesh->getController()->setDisabled(false);
	terrainMeshApply->getController()->setDisabled(false);
}

void EntityBoundingVolumeSubScreenController::onSetTerrainMesh(LevelEditorEntity* entity) {
	entity->getModelSettings()->setTerrainMesh(terrainMesh->getController()->getValue().equals("1"));
}

void EntityBoundingVolumeSubScreenController::unsetTerrainMesh() {
	terrainMesh->getController()->setValue(MutableString(""));
	terrainMesh->getController()->setDisabled(true);
	terrainMeshApply->getController()->setDisabled(true);
}

void EntityBoundingVolumeSubScreenController::unsetConvexMeshes() {
	convexMeshesFile->getController()->setDisabled(true);
	convexMeshesLoad->getController()->setDisabled(true);
	convexMeshesResolution->getController()->setDisabled(true);
	convexMeshesResolution->getController()->setValue(MutableString("1000000"));
	convexMeshesDepth->getController()->setDisabled(true);
	convexMeshesDepth->getController()->setValue(MutableString("20"));
	convexMeshesConcavity->getController()->setDisabled(true);
	convexMeshesConcavity->getController()->setValue(MutableString("0.0025"));
	convexMeshesPlaneDownSampling->getController()->setDisabled(true);
	convexMeshesPlaneDownSampling->getController()->setValue(MutableString("4"));
	convexMeshesConvexHullDownSampling->getController()->setDisabled(true);
	convexMeshesConvexHullDownSampling->getController()->setValue(MutableString("4"));
	convexMeshesAlpha->getController()->setDisabled(true);
	convexMeshesAlpha->getController()->setValue(MutableString("0.05"));
	convexMeshesBeta->getController()->setDisabled(true);
	convexMeshesBeta->getController()->setValue(MutableString("0.05"));
	convexMeshesMaxVerticesPerConvexHull->getController()->setDisabled(true);
	convexMeshesMaxVerticesPerConvexHull->getController()->setValue(MutableString("256"));
	convexMeshesMinVolumePerConvexHull->getController()->setDisabled(true);
	convexMeshesMinVolumePerConvexHull->getController()->setValue(MutableString("0.0001"));
	convexMeshesPCA->getController()->setDisabled(true);
	convexMeshesPCA->getController()->setValue(MutableString("0"));
	convexMeshesRemove->getController()->setDisabled(true);
	convexMeshesGenerate->getController()->setDisabled(true);
}

void EntityBoundingVolumeSubScreenController::setConvexMeshes(LevelEditorEntity* entity) {
	convexMeshesFile->getController()->setValue(MutableString(entity->getFileName()));
	convexMeshesFile->getController()->setDisabled(false);
	convexMeshesLoad->getController()->setDisabled(false);
	convexMeshesResolution->getController()->setDisabled(false);
	convexMeshesResolution->getController()->setValue(MutableString("1000000"));
	convexMeshesDepth->getController()->setDisabled(false);
	convexMeshesDepth->getController()->setValue(MutableString("20"));
	convexMeshesConcavity->getController()->setDisabled(false);
	convexMeshesConcavity->getController()->setValue(MutableString("0.0025"));
	convexMeshesPlaneDownSampling->getController()->setDisabled(false);
	convexMeshesPlaneDownSampling->getController()->setValue(MutableString("4"));
	convexMeshesConvexHullDownSampling->getController()->setDisabled(false);
	convexMeshesConvexHullDownSampling->getController()->setValue(MutableString("4"));
	convexMeshesAlpha->getController()->setDisabled(false);
	convexMeshesAlpha->getController()->setValue(MutableString("0.05f"));
	convexMeshesBeta->getController()->setDisabled(false);
	convexMeshesBeta->getController()->setValue(MutableString("0.05f"));
	convexMeshesMaxVerticesPerConvexHull->getController()->setDisabled(false);
	convexMeshesMaxVerticesPerConvexHull->getController()->setValue(MutableString("256"));
	convexMeshesMinVolumePerConvexHull->getController()->setDisabled(false);
	convexMeshesMinVolumePerConvexHull->getController()->setValue(MutableString("0.0001"));
	convexMeshesPCA->getController()->setDisabled(false);
	convexMeshesPCA->getController()->setValue(MutableString("0"));
	convexMeshesRemove->getController()->setDisabled(false);
	convexMeshesGenerate->getController()->setDisabled(false);
}

void EntityBoundingVolumeSubScreenController::unsetPhysics() {
	bodyTypeDropdown->getController()->setValue(MutableString("none"));
	bodyTypeDropdown->getController()->setDisabled(true);
	bodyTypeDropdownApply->getController()->setDisabled(true);
	bodyMass->getController()->setValue(MutableString());
	bodyMass->getController()->setDisabled(true);
	bodyBounciness->getController()->setValue(MutableString());
	bodyBounciness->getController()->setDisabled(true);
	bodyFriction->getController()->setValue(MutableString());
	bodyFriction->getController()->setDisabled(true);
	bodyApply->getController()->setDisabled(true);
}

void EntityBoundingVolumeSubScreenController::setPhysics(LevelEditorEntity* entity) {
	auto physics = entity->getPhysics();
	if (physics->getType() == LevelEditorEntityPhysics_BodyType::NONE) {
		bodyTypeDropdown->getController()->setValue(MutableString("none"));
	} else
	if (physics->getType() == LevelEditorEntityPhysics_BodyType::COLLISION_BODY) {
		bodyTypeDropdown->getController()->setValue(MutableString("collisionbody"));
	} else
	if (physics->getType() == LevelEditorEntityPhysics_BodyType::DYNAMIC_RIGIDBODY) {
		bodyTypeDropdown->getController()->setValue(MutableString("dynamicrigidbody"));
	} else
	if (physics->getType() == LevelEditorEntityPhysics_BodyType::STATIC_RIGIDBODY) {
		bodyTypeDropdown->getController()->setValue(MutableString("staticrigidbody"));
	}
	bodyTypeDropdown->getController()->setDisabled(false);
	bodyTypeDropdownApply->getController()->setDisabled(false);
	bodyMass->getController()->setValue(
		physics->getType() == LevelEditorEntityPhysics_BodyType::NONE ||
		physics->getType() == LevelEditorEntityPhysics_BodyType::COLLISION_BODY ||
		physics->getType() == LevelEditorEntityPhysics_BodyType::STATIC_RIGIDBODY?
			"":
			Tools::formatFloat(physics->getMass())
	);
	bodyMass->getController()->setDisabled(
		physics->getType() == LevelEditorEntityPhysics_BodyType::NONE ||
		physics->getType() == LevelEditorEntityPhysics_BodyType::COLLISION_BODY ||
		physics->getType() == LevelEditorEntityPhysics_BodyType::STATIC_RIGIDBODY
	);
	bodyBounciness->getController()->setValue(
		physics->getType() == LevelEditorEntityPhysics_BodyType::NONE ||
		physics->getType() == LevelEditorEntityPhysics_BodyType::COLLISION_BODY?
			"":
			Tools::formatFloat(physics->getRestitution())
	);
	bodyBounciness->getController()->setDisabled(
		physics->getType() == LevelEditorEntityPhysics_BodyType::NONE ||
		physics->getType() == LevelEditorEntityPhysics_BodyType::COLLISION_BODY
	);
	bodyFriction->getController()->setValue(
		physics->getType() == LevelEditorEntityPhysics_BodyType::NONE ||
		physics->getType() == LevelEditorEntityPhysics_BodyType::COLLISION_BODY?
			"":
			Tools::formatFloat(physics->getFriction())
	);
	bodyFriction->getController()->setDisabled(
		physics->getType() == LevelEditorEntityPhysics_BodyType::NONE ||
		physics->getType() == LevelEditorEntityPhysics_BodyType::COLLISION_BODY
	);
	bodyApply->getController()->setDisabled(
		physics->getType() == LevelEditorEntityPhysics_BodyType::NONE ||
		physics->getType() == LevelEditorEntityPhysics_BodyType::COLLISION_BODY
	);
}

void EntityBoundingVolumeSubScreenController::onPhysicsBodyTypeApply(LevelEditorEntity* entity) {
	auto physics = entity->getPhysics();
	auto type = bodyTypeDropdown->getController()->getValue().getString();
	if (type == "none") {
		physics->setType(LevelEditorEntityPhysics_BodyType::NONE);
	} else
	if (type == "collisionbody") {
		physics->setType(LevelEditorEntityPhysics_BodyType::COLLISION_BODY);
	} else
	if (type == "dynamicrigidbody") {
		physics->setType(LevelEditorEntityPhysics_BodyType::DYNAMIC_RIGIDBODY);
	} else
	if (type == "staticrigidbody") {
		physics->setType(LevelEditorEntityPhysics_BodyType::STATIC_RIGIDBODY);
	}
	setPhysics(entity);
}

void EntityBoundingVolumeSubScreenController::onPhysicsBodyApply(LevelEditorEntity* entity) {
	auto physics = entity->getPhysics();
	try {
		auto mass = Float::parseFloat(bodyMass->getController()->getValue().getString());
		auto bounciness = Float::parseFloat(bodyBounciness->getController()->getValue().getString());
		auto friction = Float::parseFloat(bodyFriction->getController()->getValue().getString());
		if (mass < 0.0f || mass > 1000000000.0f) throw ExceptionBase("mass must be within 0 .. 1,000,000,000");
		if (bounciness < 0.0f || bounciness > 1.0f) throw ExceptionBase("bounciness must be within 0 .. 1");
		if (friction < 0.0f || friction > 1.0f) throw ExceptionBase("friction must be within 0 .. 1");
		physics->setType(LevelEditorEntityPhysics_BodyType::valueOf(bodyTypeDropdown->getController()->getValue().getString()));
		physics->setMass(mass);
		physics->setRestitution(bounciness);
		physics->setFriction(friction);
	} catch (Exception& exception) {
		showErrorPopUp("Warning", (string(exception.what())));
	}
}

void EntityBoundingVolumeSubScreenController::showErrorPopUp(const string& caption, const string& message)
{
	view->getPopUpsViews()->getInfoDialogScreenController()->show(caption, message);
}

void EntityBoundingVolumeSubScreenController::onActionPerformed(GUIActionListener_Type* type, GUIElementNode* node, LevelEditorEntity* entity)
{
	{
		auto v = type;
		if (v == GUIActionListener_Type::PERFORMED) {
			if (StringUtils::startsWith(node->getId(), "button_boundingvolume_apply_")) {
				onBoundingVolumeTypeApply(entity, Tools::convertToIntSilent(node->getId().substr(StringUtils::lastIndexOf(node->getId(), static_cast< int32_t >(u'_')) + 1)));
			} else if (StringUtils::startsWith(node->getId(), "button_boundingvolume_sphere_apply_")) {
				onBoundingVolumeSphereApply(entity, Tools::convertToIntSilent(node->getId().substr(StringUtils::lastIndexOf(node->getId(), static_cast< int32_t >(u'_')) + 1)));
			} else if (StringUtils::startsWith(node->getId(), "button_boundingvolume_capsule_apply_")) {
				onBoundingVolumeCapsuleApply(entity, Tools::convertToIntSilent(node->getId().substr(StringUtils::lastIndexOf(node->getId(), static_cast< int32_t >(u'_')) + 1)));
			} else if (StringUtils::startsWith(node->getId(), "button_boundingvolume_obb_apply_")) {
				onBoundingVolumeObbApply(entity, Tools::convertToIntSilent(node->getId().substr(StringUtils::lastIndexOf(node->getId(), static_cast< int32_t >(u'_')) + 1)));
			} else if (StringUtils::startsWith(node->getId(), "button_boundingvolume_aabb_apply_")) {
				onBoundingVolumeAabbApply(entity, Tools::convertToIntSilent(node->getId().substr(StringUtils::lastIndexOf(node->getId(), static_cast< int32_t >(u'_')) + 1)));
			} else if (StringUtils::startsWith(node->getId(), "button_boundingvolume_convexmesh_apply_")) {
				onBoundingVolumeConvexMeshApply(entity, Tools::convertToIntSilent(node->getId().substr(StringUtils::lastIndexOf(node->getId(), static_cast< int32_t >(u'_')) + 1)));
			} else
			if (StringUtils::startsWith(node->getId(), "button_boundingvolume_convexmesh_file_")) {
				onBoundingVolumeConvexMeshFile(entity, Tools::convertToIntSilent(node->getId().substr(StringUtils::lastIndexOf(node->getId(), static_cast< int32_t >(u'_')) + 1)));
			} else
			if (node->getId() == "button_terrain_mesh_apply") {
				onSetTerrainMesh(entity);
			} else
			if (node->getId() == "button_boundingvolume_convexmeshes_file") {
				onBoundingVolumeConvexMeshesFile(entity);
			} else
			if (node->getId() == "button_boundingvolume_convexmeshes_remove") {
				onBoundingVolumeConvexMeshesRemove(entity);
			} else
			if (node->getId() == "button_boundingvolume_convexmeshes_generate") {
				onBoundingVolumeConvexMeshesGenerate(entity);
			} else
			if (node->getId() == "physics_bodytype_dropdown_apply") {
				onPhysicsBodyTypeApply(entity);
			} else
			if (node->getId() == "physics_body_apply") {
				onPhysicsBodyApply(entity);
			} else {
				Console::println(
					string(
						"ModelEditorScreenController::onActionPerformed()::unknown, type='" +
						type->getName() +
						"', id = '" +
						node->getId() +
						"'" +
						", name = '" +
						node->getName() +
						"'"
					)
				);
			}
		}
	}

}
