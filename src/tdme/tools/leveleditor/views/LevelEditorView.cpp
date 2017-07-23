// Generated from /tdme/src/tdme/tools/leveleditor/views/LevelEditorView.java
#include <tdme/tools/leveleditor/views/LevelEditorView.h>

#include <algorithm>
#include <vector>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Character.h>
#include <java/lang/Comparable.h>
#include <java/lang/Float.h>
#include <java/lang/Iterable.h>
#include <java/lang/Object.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/util/Iterator.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <tdme/engine/Camera.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/Entity.h>
#include <tdme/engine/Light.h>
#include <tdme/engine/Object3D.h>
#include <tdme/engine/PartitionOctTree.h>
#include <tdme/engine/Rotation.h>
#include <tdme/engine/Rotations.h>
#include <tdme/engine/Timing.h>
#include <tdme/engine/Transformations.h>
#include <tdme/engine/fileio/models/DAEReader.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/engine/model/Face.h>
#include <tdme/engine/model/FacesEntity.h>
#include <tdme/engine/model/Group.h>
#include <tdme/engine/model/Material.h>
#include <tdme/engine/model/Model_UpVector.h>
#include <tdme/engine/model/Model.h>
#include <tdme/engine/model/ModelHelper.h>
#include <tdme/engine/model/RotationOrder.h>
#include <tdme/engine/model/TextureCoordinate.h>
#include <tdme/engine/primitives/BoundingBox.h>
#include <tdme/engine/primitives/BoundingVolume.h>
#include <tdme/gui/GUI.h>
#include <tdme/gui/events/GUIKeyboardEvent_Type.h>
#include <tdme/gui/events/GUIKeyboardEvent.h>
#include <tdme/gui/events/GUIMouseEvent.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/math/Quaternion.h>
#include <tdme/math/Vector3.h>
#include <tdme/math/Vector4.h>
#include <tdme/os/_FileSystem.h>
#include <tdme/os/_FileSystemInterface.h>
#include <tdme/tools/leveleditor/TDMELevelEditor.h>
#include <tdme/tools/leveleditor/controller/LevelEditorEntityLibraryScreenController.h>
#include <tdme/tools/leveleditor/controller/LevelEditorScreenController.h>
#include <tdme/tools/leveleditor/logic/Level.h>
#include <tdme/tools/leveleditor/views/LevelEditorView_LevelEditorView_1.h>
#include <tdme/tools/leveleditor/views/LevelEditorView_ObjectColor.h>
#include <tdme/tools/shared/controller/FileDialogPath.h>
#include <tdme/tools/shared/controller/FileDialogScreenController.h>
#include <tdme/tools/shared/controller/InfoDialogScreenController.h>
#include <tdme/tools/shared/files/LevelFileExport.h>
#include <tdme/tools/shared/files/LevelFileImport.h>
#include <tdme/tools/shared/model/LevelEditorEntity_EntityType.h>
#include <tdme/tools/shared/model/LevelEditorEntity.h>
#include <tdme/tools/shared/model/LevelEditorEntityLibrary.h>
#include <tdme/tools/shared/model/LevelEditorLevel.h>
#include <tdme/tools/shared/model/LevelEditorLight.h>
#include <tdme/tools/shared/model/LevelEditorObject.h>
#include <tdme/tools/shared/model/LevelPropertyPresets.h>
#include <tdme/tools/shared/model/PropertyModelClass.h>
#include <tdme/tools/shared/tools/Tools.h>
#include <tdme/tools/shared/views/PopUps.h>
#include <tdme/utils/StringConverter.h>
#include <tdme/utils/_ArrayList.h>
#include <tdme/utils/_Exception.h>
#include <tdme/utils/_Console.h>
#include <Array.h>
#include <SubArray.h>
#include <ObjectArray.h>

using std::find;
using std::remove;
using std::vector;

using tdme::tools::leveleditor::views::LevelEditorView;
using java::io::Serializable;
using java::lang::CharSequence;
using java::lang::Character;
using java::lang::Comparable;
using java::lang::Float;
using java::lang::Iterable;
using java::lang::Object;
using java::lang::String;
using java::lang::StringBuilder;
using java::util::Iterator;
using java::util::Properties;
using java::util::Set;
using tdme::engine::Camera;
using tdme::engine::Engine;
using tdme::engine::Entity;
using tdme::engine::Light;
using tdme::engine::Object3D;
using tdme::engine::PartitionOctTree;
using tdme::engine::Rotation;
using tdme::engine::Rotations;
using tdme::engine::Timing;
using tdme::engine::Transformations;
using tdme::engine::fileio::models::DAEReader;
using tdme::engine::model::Color4;
using tdme::engine::model::Face;
using tdme::engine::model::FacesEntity;
using tdme::engine::model::Group;
using tdme::engine::model::Material;
using tdme::engine::model::Model_UpVector;
using tdme::engine::model::Model;
using tdme::engine::model::ModelHelper;
using tdme::engine::model::RotationOrder;
using tdme::engine::model::TextureCoordinate;
using tdme::engine::primitives::BoundingBox;
using tdme::engine::primitives::BoundingVolume;
using tdme::gui::GUI;
using tdme::gui::events::GUIKeyboardEvent_Type;
using tdme::gui::events::GUIKeyboardEvent;
using tdme::gui::events::GUIMouseEvent;
using tdme::gui::nodes::GUIScreenNode;
using tdme::math::Quaternion;
using tdme::math::Vector3;
using tdme::math::Vector4;
using tdme::os::_FileSystem;
using tdme::os::_FileSystemInterface;
using tdme::tools::leveleditor::TDMELevelEditor;
using tdme::tools::leveleditor::controller::LevelEditorEntityLibraryScreenController;
using tdme::tools::leveleditor::controller::LevelEditorScreenController;
using tdme::tools::leveleditor::logic::Level;
using tdme::tools::leveleditor::views::LevelEditorView_LevelEditorView_1;
using tdme::tools::leveleditor::views::LevelEditorView_ObjectColor;
using tdme::tools::shared::controller::FileDialogPath;
using tdme::tools::shared::controller::FileDialogScreenController;
using tdme::tools::shared::controller::InfoDialogScreenController;
using tdme::tools::shared::files::LevelFileExport;
using tdme::tools::shared::files::LevelFileImport;
using tdme::tools::shared::model::LevelEditorEntity_EntityType;
using tdme::tools::shared::model::LevelEditorEntity;
using tdme::tools::shared::model::LevelEditorEntityLibrary;
using tdme::tools::shared::model::LevelEditorLevel;
using tdme::tools::shared::model::LevelEditorLight;
using tdme::tools::shared::model::LevelEditorObject;
using tdme::tools::shared::model::LevelPropertyPresets;
using tdme::tools::shared::model::PropertyModelClass;
using tdme::tools::shared::tools::Tools;
using tdme::tools::shared::views::PopUps;
using tdme::utils::StringConverter;
using tdme::utils::_ArrayList;
using tdme::utils::_Exception;
using tdme::utils::_Console;

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java {
namespace io {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
}  // namespace io

namespace lang {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
}  // namespace lang
}  // namespace java

template<typename T, typename U>
static T java_cast(U* u)
{
    if (!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    return t;
}

LevelEditorView::LevelEditorView(const ::default_init_tag&)
	: super(*static_cast< ::default_init_tag* >(0))
{
	clinit();
}

LevelEditorView::LevelEditorView(PopUps* popUps) 
	: LevelEditorView(*static_cast< ::default_init_tag* >(0))
{
	ctor(popUps);
}

void LevelEditorView::init()
{
	GRID_DIMENSION_X = 20;
	GRID_DIMENSION_Y = 20;
	camLookRotationX = new Rotation(-45.0f, new Vector3(1.0f, 0.0f, 0.0f));
	camLookRotationY = new Rotation(0.0f, new Vector3(0.0f, 1.0f, 0.0f));
	camScaleMax = 3.0f;
	camScaleMin = 0.05f;
	FORWARD_VECTOR = new Vector3(0.0f, 0.0f, 1.0f);
	SIDE_VECTOR = new Vector3(1.0f, 0.0f, 0.0f);
	camForwardVector = new Vector3();
	camSideVector = new Vector3();
	camLookAtToFromVector = new Vector3();
	camLookAt = new Vector3();
	mouseDownLastX = LevelEditorView::MOUSE_DOWN_LAST_POSITION_NONE;
	mouseDownLastY = LevelEditorView::MOUSE_DOWN_LAST_POSITION_NONE;
	mousePanningSide = LevelEditorView::MOUSE_PANNING_NONE;
	mousePanningForward = LevelEditorView::MOUSE_PANNING_NONE;
	mouseRotationX = LevelEditorView::MOUSE_ROTATION_NONE;
	mouseRotationY = LevelEditorView::MOUSE_ROTATION_NONE;
	groundPlateWidth = 1.0f;
	groundPlateDepth = 1.0f;
}

StringArray* LevelEditorView::OBJECTCOLOR_NAMES;

constexpr int32_t LevelEditorView::MOUSE_BUTTON_NONE;

constexpr int32_t LevelEditorView::MOUSE_BUTTON_LEFT;

constexpr int32_t LevelEditorView::MOUSE_BUTTON_MIDDLE;

constexpr int32_t LevelEditorView::MOUSE_BUTTON_RIGHT;

constexpr int32_t LevelEditorView::MOUSE_DOWN_LAST_POSITION_NONE;

constexpr int32_t LevelEditorView::MOUSE_PANNING_NONE;

constexpr int32_t LevelEditorView::MOUSE_ROTATION_NONE;

void LevelEditorView::ctor(PopUps* popUps)
{
	super::ctor();
	init();
	this->popUps = popUps;
	level = TDMELevelEditor::getInstance()->getLevel();
	reloadEntityLibrary = false;
	selectedEntity = nullptr;
	keyLeft = false;
	keyRight = false;
	keyUp = false;
	keyDown = false;
	keyPlus = false;
	keyMinus = false;
	keyR = false;
	keyControl = false;
	keyEscape = false;
	mouseDownLastX = MOUSE_DOWN_LAST_POSITION_NONE;
	mouseDownLastY = MOUSE_DOWN_LAST_POSITION_NONE;
	mouseDragging = false;
	mouseDraggingLastObject = nullptr;
	gridCenter = new Vector3();
	gridCenterLast = nullptr;
	gridEnabled = true;
	gridY = 0.0f;
	objectColors[L"red"] = new LevelEditorView_ObjectColor(this, 1.5f, 0.8f, 0.8f, 0.5f, 0.0f, 0.0f);
	objectColors[L"green"] = new LevelEditorView_ObjectColor(this, 0.8f, 1.5f, 0.8f, 0.0f, 0.5f, 0.0f);
	objectColors[L"blue"] = new LevelEditorView_ObjectColor(this, 0.8f, 0.8f, 1.5f, 0.0f, 0.0f, 0.5f);
	objectColors[L"yellow"] = new LevelEditorView_ObjectColor(this, 1.5f, 1.5f, 0.8f, 0.5f, 0.5f, 0.0f);
	objectColors[L"magenta"] = new LevelEditorView_ObjectColor(this, 1.5f, 0.8f, 1.5f, 0.5f, 0.0f, 0.5f);
	objectColors[L"cyan"] = new LevelEditorView_ObjectColor(this, 0.8f, 1.5f, 1.5f, 0.0f, 0.5f, 0.5f);
	objectColors[L"none"] = new LevelEditorView_ObjectColor(this, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f);
	camScale = 1.0f;
	camLookRotationX->update();
	camLookRotationY->update();
	levelEditorGround = createLevelEditorGroundPlateModel();
	engine = Engine::getInstance();
	entityPickingFilterNoGrid = new LevelEditorView_LevelEditorView_1(this);
	tmpVector3 = new Vector3();
}

PopUps* LevelEditorView::getPopUps()
{
	return popUps;
}

String* LevelEditorView::getFileName()
{
	return _FileSystem::getInstance()->getFileName(level->getFileName());
}

LevelEditorLevel* LevelEditorView::getLevel()
{
	return level;
}

LevelEditorEntity* LevelEditorView::getSelectedEntity()
{
	return selectedEntity;
}

LevelEditorObject* LevelEditorView::getSelectedObject()
{
	if (selectedObjects.size() != 1)
		return nullptr;

	auto selectedObject = selectedObjects.at(0);
	return selectedObject != nullptr && selectedObject->getId()->startsWith(u"leveleditor."_j) == false ? level->getObjectById(selectedObject->getId()) : static_cast< LevelEditorObject* >(nullptr);
}

bool LevelEditorView::isGridEnabled()
{
	return gridEnabled;
}

void LevelEditorView::setGridEnabled(bool gridEnabled)
{
	this->gridEnabled = gridEnabled;
	if (gridEnabled) {
		updateGrid();
	} else {
		removeGrid();
	}
}

float LevelEditorView::getGridY()
{
	return gridY;
}

void LevelEditorView::setGridY(float gridY)
{
	if (gridEnabled)
		removeGrid();

	this->gridY = gridY;
	if (gridEnabled)
		updateGrid();

}

void LevelEditorView::loadEntityFromLibrary(int32_t id)
{
	selectedEntity = TDMELevelEditor::getInstance()->getEntityLibrary()->getEntity(id);
}

void LevelEditorView::handleInputEvents()
{
	auto keyDeleteBefore = keyDelete;
	auto keyControlBefore = keyControl;
	auto keyCBefore = keyC;
	auto keyVBefore = keyV;
	auto keyXBefore = keyX;
	keyControl = false;
	for (auto i = 0; i < engine->getGUI()->getKeyboardEvents()->size(); i++) {
		auto event = java_cast< GUIKeyboardEvent* >(engine->getGUI()->getKeyboardEvents()->get(i));
		if (event->isProcessed() == true)
			continue;

		keyControl = event->isControlDown();

		auto isKeyDown = event->getType() == GUIKeyboardEvent_Type::KEY_PRESSED;

		if (event->getKeyCode() == GUIKeyboardEvent::KEYCODE_ESCAPE)
			keyEscape = isKeyDown;

		if (event->getKeyCode() == GUIKeyboardEvent::KEYCODE_LEFT)
			keyLeft = isKeyDown;

		if (event->getKeyCode() == GUIKeyboardEvent::KEYCODE_RIGHT)
			keyRight = isKeyDown;

		if (event->getKeyCode() == GUIKeyboardEvent::KEYCODE_UP)
			keyUp = isKeyDown;

		if (event->getKeyCode() == GUIKeyboardEvent::KEYCODE_DOWN)
			keyDown = isKeyDown;

		if (event->getKeyCode() == GUIKeyboardEvent::KEYCODE_BACKSPACE)
			keyDelete = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u'x')
			keyX = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u'c')
			keyC = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u'v')
			keyV = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u'a')
			keyA = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u'd')
			keyD = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u'w')
			keyW = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u's')
			keyS = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u'+')
			keyPlus = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u'-')
			keyMinus = isKeyDown;

		if (Character::toLowerCase(event->getKeyChar()) == u'r')
			keyR = isKeyDown;

	}
	if (keyEscape == true && selectedObjects.size() > 0) {
		vector<Entity*> objectsToRemove;
		for (auto selectedObject: selectedObjects) {
			objectsToRemove.push_back(selectedObject);
		}
		for (auto objectToRemove: objectsToRemove) {
			setStandardObjectColorEffect(objectToRemove);
			selectedObjects.erase(remove(selectedObjects.begin(), selectedObjects.end(), objectToRemove), selectedObjects.end());
			auto selectedObjectByIdIt = selectedObjectsById.find(objectToRemove->getId()->getCPPWString());
			if (selectedObjectByIdIt != selectedObjectsById.end()) {
				selectedObjectsById.erase(selectedObjectByIdIt);
			}
		}
		levelEditorScreenController->unselectObjectsInObjectListBox();
	}
	for (auto i = 0; i < engine->getGUI()->getMouseEvents()->size(); i++) {
		auto event = java_cast< GUIMouseEvent* >(engine->getGUI()->getMouseEvents()->get(i));
		if (event->isProcessed() == true)
			continue;

		if (event->getButton() != MOUSE_BUTTON_NONE) {
			if (mouseDragging == false) {
				if (mouseDownLastX != event->getX() || mouseDownLastY != event->getY()) {
					mouseDragging = true;
				}
			}
		} else {
			if (mouseDragging == true) {
				mouseDownLastX = MOUSE_DOWN_LAST_POSITION_NONE;
				mouseDownLastY = MOUSE_DOWN_LAST_POSITION_NONE;
				mouseDragging = false;
				mouseDraggingLastObject = nullptr;
			}
		}
		if (event->getButton() == MOUSE_BUTTON_LEFT) {
			if (mouseDragging == false) {
				if (mouseDownLastX != event->getX() || mouseDownLastY != event->getY()) {
					mouseDragging = true;
				}
			}
			if (keyControl == false) {
				vector<Entity*> objectsToRemove;
				for (auto selectedObject: selectedObjects) {
					if (mouseDragging == true && mouseDraggingLastObject == selectedObject) {
					} else {
						objectsToRemove.push_back(selectedObject);
					}
				}
				for (auto objectToRemove: objectsToRemove) {
					setStandardObjectColorEffect(objectToRemove);
					selectedObjects.erase(remove(selectedObjects.begin(), selectedObjects.end(), objectToRemove), selectedObjects.end());
					auto selectedObjectByIdIt = selectedObjectsById.find(objectToRemove->getId()->getCPPWString());
					if (selectedObjectByIdIt != selectedObjectsById.end()) {
						selectedObjectsById.erase(selectedObjectByIdIt);
					}
					levelEditorScreenController->unselectObjectInObjectListBox(objectToRemove->getId());
				}
			}
			auto selectedObject = engine->getObjectByMousePosition(event->getX(), event->getY(), entityPickingFilterNoGrid);
			if (selectedObject == nullptr) {
				selectedObject = engine->getObjectByMousePosition(event->getX(), event->getY());
			}
			if (selectedObject != nullptr) {
				if (mouseDragging == true && mouseDraggingLastObject == selectedObject) {
				} else {
					if (find(selectedObjects.begin(), selectedObjects.end(), selectedObject) == selectedObjects.end()) {
						setStandardObjectColorEffect(selectedObject);
						setHighlightObjectColorEffect(selectedObject);
						selectedObjects.push_back(selectedObject);
						selectedObjectsById[selectedObject->getId()->getCPPWString()] = selectedObject;
						levelEditorScreenController->selectObjectInObjectListbox(selectedObject->getId());
						auto levelEditorObject = level->getObjectById(selectedObject->getId());
						if (levelEditorObject != nullptr) {
							TDMELevelEditor::getInstance()->getLevelEditorEntityLibraryScreenController()->selectEntity(levelEditorObject->getEntity()->getId());
						}
					} else {
						setStandardObjectColorEffect(selectedObject);
						selectedObjects.erase(remove(selectedObjects.begin(), selectedObjects.end(), selectedObject), selectedObjects.end());
						auto selectedObjectsByIdIt = selectedObjectsById.find(selectedObject->getId()->getCPPWString());
						if (selectedObjectsByIdIt != selectedObjectsById.end()) {
							selectedObjectsById.erase(selectedObjectsByIdIt);
						}
						levelEditorScreenController->unselectObjectInObjectListBox(selectedObject->getId());
					}
				}
			}
			mouseDraggingLastObject = selectedObject;
			updateGUIElements();
		} else if (event->getButton() == MOUSE_BUTTON_RIGHT) {
			if (mouseDownLastX != MOUSE_DOWN_LAST_POSITION_NONE && mouseDownLastY != MOUSE_DOWN_LAST_POSITION_NONE) {
				mousePanningSide = event->getX() - mouseDownLastX;
				mousePanningForward = event->getY() - mouseDownLastY;
			}
		} else if (event->getButton() == MOUSE_BUTTON_MIDDLE) {
			centerObject();
			if (mouseDownLastX != MOUSE_DOWN_LAST_POSITION_NONE && mouseDownLastY != MOUSE_DOWN_LAST_POSITION_NONE) {
				mouseRotationX = event->getX() - mouseDownLastX;
				mouseRotationY = event->getY() - mouseDownLastY;
			}
		}
		if (event->getButton() != MOUSE_BUTTON_NONE) {
			mouseDownLastX = event->getX();
			mouseDownLastY = event->getY();
		}
		auto mouseWheel = event->getWheelY();
		if (mouseWheel != 0) {
			camScale += -mouseWheel * 0.05f;
			if (camScale < camScaleMin)
				camScale = camScaleMin;

			if (camScale > camScaleMax)
				camScale = camScaleMax;

		}
	}
	if (keyDeleteBefore == true && keyDelete == false) {
		removeObject();
	}
	if ((keyControlBefore == true || keyControl == true) && keyXBefore == true && keyX == false) {
		copyObjects();
		removeObject();
	}
	if ((keyControlBefore == true || keyControl == true) && keyCBefore == true && keyC == false) {
		copyObjects();
	}
	if ((keyControlBefore == true || keyControl == true) && keyVBefore == true && keyV == false) {
		pasteObjects();
	}
}

void LevelEditorView::display()
{
	auto cam = engine->getCamera();
	if (reloadEntityLibrary == true) {
		auto entityLibrary = TDMELevelEditor::getInstance()->getEntityLibrary();
		for (auto i = 0; i < entityLibrary->getEntityCount(); i++) {
			selectedEntity = entityLibrary->getEntityAt(i);
			Tools::oseThumbnail(selectedEntity);
		}
		reloadEntityLibrary = false;
		TDMELevelEditor::getInstance()->getLevelEditorEntityLibraryScreenController()->setEntityLibrary();
	}
	if (mouseRotationX != MOUSE_ROTATION_NONE) {
		camLookRotationY->setAngle(camLookRotationY->getAngle() + mouseRotationX);
		camLookRotationY->update();
		mouseRotationX = 0;
	}
	if (mouseRotationY != MOUSE_ROTATION_NONE) {
		camLookRotationX->setAngle(camLookRotationX->getAngle() + mouseRotationY);
		camLookRotationX->update();
		mouseRotationY = 0;
	}
	if (keyA)
		camLookRotationY->setAngle(camLookRotationY->getAngle() + 1.0f);

	if (keyD)
		camLookRotationY->setAngle(camLookRotationY->getAngle() - 1.0f);

	if (keyW)
		camLookRotationX->setAngle(camLookRotationX->getAngle() + 1.0f);

	if (keyS)
		camLookRotationX->setAngle(camLookRotationX->getAngle() - 1.0f);

	if (keyMinus)
		camScale += 0.05f;

	if (keyPlus)
		camScale -= 0.05f;

	if (camScale < camScaleMin)
		camScale = camScaleMin;

	if (camScale > camScaleMax)
		camScale = camScaleMax;

	if (keyR) {
		camLookRotationX->setAngle(-45.0f);
		camLookRotationX->update();
		camLookRotationY->setAngle(0.0f);
		camLookRotationY->update();
		cam->getLookAt()->set(level->computeCenter());
		camScale = 1.0f;
	}
	if (keyA || keyD)
		camLookRotationY->update();

	if (keyW || keyS) {
		if (camLookRotationX->getAngle() > 89.99f)
			camLookRotationX->setAngle(89.99f);

		if (camLookRotationX->getAngle() < -89.99f)
			camLookRotationX->setAngle(-89.99f);

		camLookRotationX->update();
	}
	camLookRotationX->getQuaternion()->multiply(FORWARD_VECTOR, tmpVector3);
	camLookRotationY->getQuaternion()->multiply(tmpVector3, tmpVector3);
	camLookAtToFromVector->set(tmpVector3)->scale(camScale * 10.0f);
	auto timing = engine->getTiming();
	camLookRotationY->getQuaternion()->multiply(FORWARD_VECTOR, camForwardVector)->scale(timing->getDeltaTime() / 1000.0f * 60.0f);
	camLookRotationY->getQuaternion()->multiply(SIDE_VECTOR, camSideVector)->scale(timing->getDeltaTime() / 1000.0f * 60.0f);
	if (keyUp)
		cam->getLookAt()->sub(tmpVector3->set(camForwardVector)->scale(0.1f));

	if (keyDown)
		cam->getLookAt()->add(tmpVector3->set(camForwardVector)->scale(0.1f));

	if (keyLeft)
		cam->getLookAt()->sub(tmpVector3->set(camSideVector)->scale(0.1f));

	if (keyRight)
		cam->getLookAt()->add(tmpVector3->set(camSideVector)->scale(0.1f));

	if (mousePanningForward != MOUSE_PANNING_NONE) {
		cam->getLookAt()->sub(tmpVector3->set(camForwardVector)->scale(mousePanningForward / 30.0f * camScale));
		mousePanningForward = MOUSE_PANNING_NONE;
	}
	if (mousePanningSide != MOUSE_PANNING_NONE) {
		cam->getLookAt()->sub(tmpVector3->set(camSideVector)->scale(mousePanningSide / 30.0f * camScale));
		mousePanningSide = MOUSE_PANNING_NONE;
	}
	cam->getLookFrom()->set(cam->getLookAt())->add(camLookAtToFromVector);
	cam->computeUpVector(cam->getLookFrom(), cam->getLookAt(), cam->getUpVector());
	gridCenter->set(cam->getLookAt());
	updateGrid();
	engine->getGUI()->render();
	engine->getGUI()->handleEvents();
}

void LevelEditorView::selectObjects(vector<String*>& objectIds)
{
	auto objectsToRemove = selectedObjects;
	for (auto objectToRemove: objectsToRemove) {
		setStandardObjectColorEffect(objectToRemove);
		selectedObjects.erase(remove(selectedObjects.begin(), selectedObjects.end(), objectToRemove), selectedObjects.end());
		auto selectedObjectsByIdIt = selectedObjectsById.find(objectToRemove->getId()->getCPPWString());
		if (selectedObjectsByIdIt != selectedObjectsById.end()) {
			selectedObjectsById.erase(selectedObjectsByIdIt);
		}
	}
	for (auto objectId: objectIds) {
		auto selectedObject = engine->getEntity(objectId);
		setStandardObjectColorEffect(selectedObject);
		setHighlightObjectColorEffect(selectedObject);
		selectedObjects.push_back(selectedObject);
		selectedObjectsById[selectedObject->getId()->getCPPWString()] = selectedObject;
	}
	updateGUIElements();
}

void LevelEditorView::unselectObjects()
{
	auto objectsToRemove = selectedObjects;
	for (auto objectToRemove: objectsToRemove) {
		setStandardObjectColorEffect(objectToRemove);
		selectedObjects.erase(remove(selectedObjects.begin(), selectedObjects.end(), objectToRemove), selectedObjects.end());
		auto selectedObjectsByIdIt = selectedObjectsById.find(objectToRemove->getId()->getCPPWString());
		if (selectedObjectsByIdIt != selectedObjectsById.end()) {
			selectedObjectsById.erase(selectedObjectsByIdIt);
		}
	}
	levelEditorScreenController->unselectObjectsInObjectListBox();
	updateGUIElements();
}

void LevelEditorView::updateGUIElements()
{
	levelEditorScreenController->setScreenCaption(::java::lang::StringBuilder().append(u"Level Editor - "_j)->append(level->getFileName())->toString());
	levelEditorScreenController->setLevelSize(level->getDimension()->getX(), level->getDimension()->getZ(), level->getDimension()->getY());
	if (selectedObjects.size() == 1) {
		auto selectedObject = selectedObjects.at(0);
		if (selectedObject != nullptr && selectedObject->getId()->startsWith(u"leveleditor."_j) == false) {
			auto levelEditorObject = level->getObjectById(selectedObject->getId());
			auto preset = levelEditorObject->getProperty(u"preset"_j);
			levelEditorScreenController->setObjectProperties(preset != nullptr ? preset->getValue() : u""_j, levelEditorObject, nullptr);
			levelEditorScreenController->setObject(selectedObject->getTranslation(), selectedObject->getScale(), selectedObject->getRotations()->get(level->getRotationOrder()->getAxisXIndex())->getAngle(), selectedObject->getRotations()->get(level->getRotationOrder()->getAxisYIndex())->getAngle(), selectedObject->getRotations()->get(level->getRotationOrder()->getAxisZIndex())->getAngle());
			Vector3* objectCenter = nullptr;
			if (levelEditorObject->getEntity()->getModel() != nullptr) {
				auto bv = levelEditorObject->getEntity()->getModel()->getBoundingBox()->clone();
				bv->fromBoundingVolumeWithTransformations(bv, levelEditorObject->getTransformations());
				objectCenter = bv->getCenter();
			} else {
				objectCenter = levelEditorObject->getTransformations()->getTranslation();
			}
			levelEditorScreenController->setObjectData(levelEditorObject->getId(), levelEditorObject->getDescription(), levelEditorObject->getEntity()->getName(), objectCenter);
		} else {
			levelEditorScreenController->unsetObjectData();
			levelEditorScreenController->unsetObject();
			levelEditorScreenController->unsetObjectProperties();
		}
	} else
	if (selectedObjects.size() > 1) {
		levelEditorScreenController->unsetObjectData();
		levelEditorScreenController->setObject(new Vector3(0.0f, 0.0f, 0.0f), new Vector3(1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 0.0f);
		levelEditorScreenController->unsetObjectProperties();
	} else
	if (selectedObjects.size() == 0) {
		levelEditorScreenController->unsetObjectData();
		levelEditorScreenController->unsetObject();
		levelEditorScreenController->unsetObjectProperties();
	}
	for (auto i = 0; i < 4; i++) {
		levelEditorScreenController->setLight(i, level->getLightAt(i)->getAmbient(), level->getLightAt(i)->getDiffuse(), level->getLightAt(i)->getSpecular(), level->getLightAt(i)->getPosition(), level->getLightAt(i)->getConstantAttenuation(), level->getLightAt(i)->getLinearAttenuation(), level->getLightAt(i)->getQuadraticAttenuation(), level->getLightAt(i)->getSpotTo(), level->getLightAt(i)->getSpotDirection(), level->getLightAt(i)->getSpotExponent(), level->getLightAt(i)->getSpotCutOff(), level->getLightAt(i)->isEnabled());
	}
}

void LevelEditorView::setObjectsListBox()
{
	levelEditorScreenController->setObjectListbox(level);
}

void LevelEditorView::unselectLightPresets()
{
	levelEditorScreenController->unselectLightPresets();
}

void LevelEditorView::loadSettings()
{
	try {
		Object* tmp;
		auto settings = new Properties();
		settings->load(_FileSystem::getInstance()->getContentAsStringArray(u"settings"_j, u"leveleditor.properties"_j));
		gridEnabled = (tmp = java_cast< Object* >(settings->get(u"grid.enabled"_j))) != nullptr ? tmp->equals(u"true"_j) == true : true;
		gridY = (tmp = java_cast< Object* >(settings->get(u"grid.y"_j))) != nullptr ? Float::parseFloat(tmp->toString()) : 0.0f;
		levelEditorScreenController->getMapPath()->setPath((tmp = java_cast< Object* >(settings->get(u"map.path"_j))) != nullptr ? tmp->toString() : u"."_j);
		TDMELevelEditor::getInstance()->getLevelEditorEntityLibraryScreenController()->setModelPath((tmp = java_cast< Object* >(settings->get(u"model.path"_j))) != nullptr ? tmp->toString() : u"."_j);
	} catch (_Exception& exception) {
		_Console::print(string("LevelEditorView::loadSettings(): An error occurred: "));
		_Console::println(string(exception.what()));
	}
}

void LevelEditorView::initialize()
{
	engine->reset();
	engine->setPartition(new PartitionOctTree());
	try {
		levelEditorScreenController = new LevelEditorScreenController(this);
		levelEditorScreenController->initialize();
		levelEditorScreenController->getScreenNode()->setInputEventHandler(this);
		engine->getGUI()->addScreen(levelEditorScreenController->getScreenNode()->getId(), levelEditorScreenController->getScreenNode());
	} catch (_Exception& exception) {
		_Console::print(string("LevelEditorView::initialize(): An error occurred: "));
		_Console::println(string(exception.what()));
	}
	loadSettings();
	levelEditorScreenController->setGrid(gridEnabled, gridY);
	levelEditorScreenController->setMapProperties(level, nullptr);
	levelEditorScreenController->setObjectPresetIds(LevelPropertyPresets::getInstance()->getObjectPropertiesPresets());
	levelEditorScreenController->setLightPresetsIds(LevelPropertyPresets::getInstance()->getLightPresets());
	updateGUIElements();
	auto light0 = engine->getLightAt(0);
	light0->getAmbient()->set(1.0f, 1.0f, 1.0f, 1.0f);
	light0->getDiffuse()->set(1.0f, 1.0f, 1.0f, 1.0f);
	light0->getPosition()->set(0.0f, 20.0f, 0.0f, 1.0f);
	light0->setEnabled(true);
	auto cam = engine->getCamera();
	cam->setZNear(1.0f);
	cam->setZFar(1000.0f);
	cam->getLookAt()->set(level->computeCenter());
	gridCenter->set(cam->getLookAt());
	camLookAt->set(engine->getCamera()->getLookAt());
}

void LevelEditorView::activate()
{
	engine->getGUI()->resetRenderScreens();
	engine->getGUI()->addRenderScreen(levelEditorScreenController->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(TDMELevelEditor::getInstance()->getLevelEditorEntityLibraryScreenController()->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(popUps->getFileDialogScreenController()->getScreenNode()->getId());
	engine->getGUI()->addRenderScreen(popUps->getInfoDialogScreenController()->getScreenNode()->getId());
	TDMELevelEditor::getInstance()->getLevelEditorEntityLibraryScreenController()->setEntityLibrary();
	loadLevel();
	engine->getCamera()->getLookAt()->set(camLookAt);
}

void LevelEditorView::deactivate()
{
	camLookAt->set(engine->getCamera()->getLookAt());
}

void LevelEditorView::storeSettings()
{
	try {
		auto settings = new Properties();
		settings->put(u"grid.enabled"_j, gridEnabled == true ? u"true"_j : u"false"_j);
		settings->put(u"grid.y"_j, String::valueOf(gridY));
		settings->put(u"map.path"_j, levelEditorScreenController->getMapPath()->getPath());
		settings->put(u"model.path"_j, TDMELevelEditor::getInstance()->getLevelEditorEntityLibraryScreenController()->getModelPath());
		StringArray* settingsStringArray = settings->storeToStringArray();
		_FileSystem::getInstance()->setContentFromStringArray(u"settings"_j, u"leveleditor.properties"_j, settingsStringArray);
	} catch (_Exception& exception) {
		_Console::print(string("LevelEditorView::storeSettings(): An error occurred: "));
		_Console::println(string(exception.what()));
	}
}

void LevelEditorView::dispose()
{
	Engine::getInstance()->reset();
	storeSettings();
}

void LevelEditorView::setHighlightObjectColorEffect(Entity* object)
{
	auto red = objectColors[L"red"];
	object->getEffectColorAdd()->set(red->colorAddR, red->colorAddG, red->colorAddB, 0.0f);
	object->getEffectColorMul()->set(red->colorMulR, red->colorMulG, red->colorMulB, 1.0f);
}

void LevelEditorView::setStandardObjectColorEffect(Entity* object)
{
	auto color = objectColors[L"none"];
	object->getEffectColorAdd()->set(color->colorAddR, color->colorAddG, color->colorAddB, 0.0f);
	object->getEffectColorMul()->set(color->colorMulR, color->colorMulG, color->colorMulB, 1.0f);
	auto levelEditorObject = level->getObjectById(object->getId());
	if (levelEditorObject == nullptr)
		return;

	auto colorProperty = levelEditorObject->getProperty(u"object.color"_j);
	if (colorProperty == nullptr)
		colorProperty = levelEditorObject->getEntity()->getProperty(u"object.color"_j);

	if (colorProperty != nullptr) {
		auto objectColorIt = objectColors.find(colorProperty->getValue()->getCPPWString());
		auto objectColor = objectColorIt != objectColors.end() ? objectColorIt->second : nullptr;
		if (objectColor != nullptr) {
			object->getEffectColorAdd()->set(object->getEffectColorAdd()->getRed() + objectColor->colorAddR, object->getEffectColorAdd()->getGreen() + objectColor->colorAddG, object->getEffectColorAdd()->getBlue() + objectColor->colorAddB, 0.0f);
			object->getEffectColorMul()->set(object->getEffectColorMul()->getRed() * objectColor->colorMulR, object->getEffectColorMul()->getGreen() * objectColor->colorMulG, object->getEffectColorMul()->getBlue() * objectColor->colorMulB, 1.0f);
		}
	}
}

void LevelEditorView::loadLevel()
{
	removeGrid();
	engine->reset();
	selectedObjects.clear();
	selectedObjectsById.clear();
	Level::setLight(engine, level, nullptr);
	Level::addLevel(engine, level, true, true, false, true, nullptr);
	setObjectsListBox();
	unselectLightPresets();
	updateGrid();
}

void LevelEditorView::updateGrid()
{
	if (gridEnabled == false)
		return;

	auto centerX = static_cast< int32_t >(gridCenter->getX());
	auto centerZ = static_cast< int32_t >(gridCenter->getZ());
	auto centerLastX = gridCenterLast == nullptr ? centerX : static_cast< int32_t >(gridCenterLast->getX());
	auto centerLastZ = gridCenterLast == nullptr ? centerZ : static_cast< int32_t >(gridCenterLast->getZ());
	if (gridCenterLast != nullptr && (centerLastX != centerX || centerLastZ != centerZ) == false) {
		return;
	}
	auto gridDimensionLeft = GRID_DIMENSION_X + (centerLastX < centerX ? centerX - centerLastX : 0);
	auto gridDimensionRight = GRID_DIMENSION_X + (centerLastX > centerX ? centerLastX - centerX : 0);
	auto gridDimensionNear = GRID_DIMENSION_Y + (centerLastZ < centerZ ? centerZ - centerLastZ : 0);
	auto gridDimensionFar = GRID_DIMENSION_Y + (centerLastZ > centerZ ? centerLastZ - centerZ : 0);
	auto addedCells = 0;
	auto removedCells = 0;
	auto reAddedCells = 0;
	for (auto gridZ = -gridDimensionNear; gridZ < gridDimensionFar; gridZ++) 
	for (auto gridX = -gridDimensionLeft; gridX < gridDimensionRight; gridX++) {
		auto objectId =
			::java::lang::StringBuilder().
			 append(u"leveleditor.ground@"_j)->
			 append((centerX + gridX))->
			 append(u","_j)->
			 append((centerZ + gridZ))->
			 toString();
		auto _object = engine->getEntity(objectId);
		if (gridX < -GRID_DIMENSION_X || gridX >= GRID_DIMENSION_X || gridZ < -GRID_DIMENSION_Y || gridZ >= GRID_DIMENSION_Y) {
			if (_object != nullptr) {
				engine->removeEntity(objectId);
				removedCells++;
			}
		} else
		if (_object == nullptr) {
			auto _objectIt = selectedObjectsById.find(objectId->getCPPWString());
			if (_objectIt != selectedObjectsById.end()) {
				_object = _objectIt->second;
			}
			if (_object != nullptr) {
				engine->addEntity(_object);
				reAddedCells++;
			} else {
				_object = new Object3D(objectId, levelEditorGround);
				_object->getRotations()->add(new Rotation(0.0f, level->getRotationOrder()->getAxis0()));
				_object->getRotations()->add(new Rotation(0.0f, level->getRotationOrder()->getAxis1()));
				_object->getRotations()->add(new Rotation(0.0f, level->getRotationOrder()->getAxis2()));
				_object->getTranslation()->set(centerX + static_cast< float >(gridX) * groundPlateWidth, gridY - 0.05f, centerZ + static_cast< float >(gridZ) * groundPlateDepth);
				_object->setEnabled(true);
				_object->setPickable(true);
				_object->update();
				setStandardObjectColorEffect(_object);
				engine->addEntity(_object);
				addedCells++;
			}
		}
	}

	if (gridCenterLast == nullptr)
		gridCenterLast = new Vector3();

	gridCenterLast->set(gridCenter);
}

void LevelEditorView::removeGrid()
{
	if (gridCenterLast == nullptr)
		return;

	auto removedCells = 0;
	auto centerX = static_cast< int32_t >(gridCenterLast->getX());
	auto centerZ = static_cast< int32_t >(gridCenterLast->getZ());
	for (auto gridZ = -GRID_DIMENSION_Y; gridZ < GRID_DIMENSION_Y; gridZ++) 
				for (auto gridX = -GRID_DIMENSION_X; gridX < GRID_DIMENSION_X; gridX++) {
			auto objectId = ::java::lang::StringBuilder().append(u"leveleditor.ground@"_j)->append((centerX + gridX))
				->append(u","_j)
				->append((centerZ + gridZ))->toString();
			auto _object = engine->getEntity(objectId);
			if (_object != nullptr) {
				removedCells++;
				engine->removeEntity(objectId);
			}
		}

	gridCenterLast = nullptr;
}

Model* LevelEditorView::createLevelEditorGroundPlateModel()
{
	auto groundPlate = new Model(u"leveleditor.ground"_j, u"leveleditor.ground"_j, Model_UpVector::Y_UP, RotationOrder::XYZ, java_cast< BoundingBox* >(BoundingBox::createBoundingVolume(new Vector3(0.0f, -0.01f, 0.0f), new Vector3(1.0f, +0.01f, 1.0f))));
	auto groundPlateMaterial = new Material(u"ground"_j);
	groundPlateMaterial->getDiffuseColor()->setAlpha(0.75f);
	groundPlateMaterial->setDiffuseTexture(u"resources/tools/leveleditor/textures"_j, u"groundplate.png"_j);
	groundPlateMaterial->getSpecularColor()->set(0.0f, 0.0f, 0.0f, 1.0f);
	(*groundPlate->getMaterials())[L"ground"] = groundPlateMaterial;
	auto groundGroup = new Group(groundPlate, nullptr, L"ground", L"ground");
	auto groupFacesEntityGround = new FacesEntity(groundGroup, L"leveleditor.ground.facesentity");
	groupFacesEntityGround->setMaterial(groundPlateMaterial);
	vector<FacesEntity*> groupFacesEntities;
	groupFacesEntities.push_back(groupFacesEntityGround);
	vector<Vector3*> groundVertices;
	groundVertices.push_back(new Vector3(0.0f, 0.0f, 0.0f));
	groundVertices.push_back(new Vector3(0.0f, 0.0f, +groundPlateDepth));
	groundVertices.push_back(new Vector3(+groundPlateWidth, 0.0f, +groundPlateDepth));
	groundVertices.push_back(new Vector3(+groundPlateWidth, 0.0f, 0.0f));
	vector<Vector3*> groundNormals;
	groundNormals.push_back(new Vector3(0.0f, 1.0f, 0.0f));
	vector<TextureCoordinate*> groundTextureCoordinates;
	groundTextureCoordinates.push_back(new TextureCoordinate(0.0f, 1.0f));
	groundTextureCoordinates.push_back(new TextureCoordinate(0.0f, 0.0f));
	groundTextureCoordinates.push_back(new TextureCoordinate(1.0f, 0.0f));
	groundTextureCoordinates.push_back(new TextureCoordinate(1.0f, 1.0f));
	vector<Face*> groundFacesGround;
	groundFacesGround.push_back(new Face(groundGroup, 0, 1, 2, 0, 0, 0, 0, 1, 2));
	groundFacesGround.push_back(new Face(groundGroup, 2, 3, 0, 0, 0, 0, 2, 3, 0));
	groupFacesEntityGround->setFaces(groundFacesGround);
	groundGroup->setVertices(groundVertices);
	groundGroup->setNormals(groundNormals);
	groundGroup->setTextureCoordinates(groundTextureCoordinates);
	groundGroup->setFacesEntities(groupFacesEntities);
	(*groundPlate->getGroups())[groundGroup->getId()] = groundGroup;
	(*groundPlate->getSubGroups())[groundGroup->getId()] = groundGroup;
	ModelHelper::prepareForIndexedRendering(groundPlate);
	return groundPlate;
}

bool LevelEditorView::objectDataApply(String* name, String* description)
{
	if (selectedObjects.size() != 1)
		return false;

	auto selectedObject = selectedObjects.at(0);
	if (selectedObject->getId()->startsWith(u"leveleditor."_j))
		return false;

	auto levelEditorObject = level->getObjectById(selectedObject->getId());
	if (levelEditorObject == nullptr)
		return false;

	levelEditorObject->setDescription(description);
	if (levelEditorObject->getId()->equals(name) == false) {
		if (engine->getEntity(name) != nullptr) {
			return false;
		}
		auto oldId = levelEditorObject->getId();
		level->removeObject(levelEditorObject->getId());
		engine->removeEntity(levelEditorObject->getId());
		selectedObjectsById.clear();
		selectedObjects.clear();
		levelEditorObject->setId(name);
		level->addObject(levelEditorObject);
		auto object = new Object3D(levelEditorObject->getId(), levelEditorObject->getEntity()->getModel());
		object->fromTransformations(levelEditorObject->getTransformations());
		object->setPickable(true);
		setStandardObjectColorEffect(object);
		setHighlightObjectColorEffect(object);
		engine->addEntity(object);
		selectedObjects.push_back(object);
		selectedObjectsById[object->getId()->getCPPWString()] = object;
		levelEditorScreenController->setObjectListbox(level);
	}
	levelEditorObject->setDescription(description);
	return true;
}

void LevelEditorView::placeObject()
{
	for (auto selectedObject: selectedObjects) {
		placeObject(selectedObject);
	}
	level->computeDimension();
	updateGUIElements();
}

void LevelEditorView::placeObject(Entity* selectedObject)
{
	if (selectedEntity != nullptr && selectedObject != nullptr) {
		auto selectedLevelEditorObject = level->getObjectById(selectedObject->getId());
		auto levelEditorObjectTransformations = new Transformations();
		levelEditorObjectTransformations->getTranslation()->set(selectedObject->getTranslation());
		auto centerSelectedObject = selectedObject->getBoundingBox()->getMin()->clone()->add(selectedObject->getBoundingBox()->getMax())->scale(0.5f);
		auto centerNewObject = selectedEntity->getModel() != nullptr ? selectedEntity->getModel()->getBoundingBox()->getCenter()->clone() : new Vector3(0.0f, 0.0f, 0.0f);
		levelEditorObjectTransformations->getTranslation()->add(centerNewObject->clone()->add(centerSelectedObject));
		if (selectedLevelEditorObject == nullptr || selectedLevelEditorObject->getEntity()->getType() == LevelEditorEntity_EntityType::PARTICLESYSTEM || selectedEntity->getType() == LevelEditorEntity_EntityType::PARTICLESYSTEM) {
			levelEditorObjectTransformations->getTranslation()->setY(gridY + (selectedEntity->getModel() != nullptr ? -selectedEntity->getModel()->getBoundingBox()->getMin()->getY() : 0.0f));
		} else {
			auto bv = selectedLevelEditorObject->getEntity()->getModel()->getBoundingBox()->clone();
			bv->fromBoundingVolumeWithTransformations(selectedLevelEditorObject->getEntity()->getModel()->getBoundingBox(), selectedLevelEditorObject->getTransformations());
			levelEditorObjectTransformations->getTranslation()->setY(bv->computeDimensionOnAxis(new Vector3(0.0f, 1.0f, 0.0f)) / 2 + bv->getCenter()->getY() + -selectedEntity->getModel()->getBoundingBox()->getMin()->getY());
		}
		levelEditorObjectTransformations->getScale()->set(new Vector3(1.0f, 1.0f, 1.0f));
		levelEditorObjectTransformations->getPivot()->set(selectedEntity->getPivot());
		levelEditorObjectTransformations->getRotations()->add(new Rotation(0.0f, level->getRotationOrder()->getAxis0()));
		levelEditorObjectTransformations->getRotations()->add(new Rotation(0.0f, level->getRotationOrder()->getAxis1()));
		levelEditorObjectTransformations->getRotations()->add(new Rotation(0.0f, level->getRotationOrder()->getAxis2()));
		levelEditorObjectTransformations->update();
		for (auto i = 0; i < level->getObjectCount(); i++) {
			auto levelEditorObject = level->getObjectAt(i);
			if (levelEditorObject->getEntity() == selectedEntity && levelEditorObject->getTransformations()->getTranslation()->equals(levelEditorObjectTransformations->getTranslation())) {
				return;
			}
		}
		auto levelEditorObject = new LevelEditorObject(::java::lang::StringBuilder().append(selectedEntity->getName())->append(u"_"_j)
			->append(level->allocateObjectId())->toString(), u""_j, levelEditorObjectTransformations, selectedEntity);
		level->addObject(levelEditorObject);
		if (levelEditorObject->getEntity()->getModel() != nullptr) {
			auto object = new Object3D(levelEditorObject->getId(), levelEditorObject->getEntity()->getModel());
			object->fromTransformations(levelEditorObjectTransformations);
			object->setPickable(true);
			engine->addEntity(object);
		}
		if (levelEditorObject->getEntity()->getType() == LevelEditorEntity_EntityType::PARTICLESYSTEM) {
			auto object = Level::createParticleSystem(levelEditorObject->getEntity()->getParticleSystem(), levelEditorObject->getId(), false);
			object->fromTransformations(levelEditorObjectTransformations);
			object->setPickable(true);
			engine->addEntity(object);
		}
		levelEditorScreenController->setObjectListbox(level);
	}
}

void LevelEditorView::removeObject()
{
	vector<Entity*> objectsToRemove;
	for (auto selectedObject: selectedObjects) {
		if (selectedObject != nullptr && selectedObject->getId()->startsWith(u"leveleditor."_j) == false) {
			level->removeObject(selectedObject->getId());
			engine->removeEntity(selectedObject->getId());
			objectsToRemove.push_back(selectedObject);
		}
	}
	for (auto objectToRemove: objectsToRemove) {
		selectedObjects.erase(remove(selectedObjects.begin(), selectedObjects.end(), objectToRemove), selectedObjects.end());
	}
	level->computeDimension();
	levelEditorScreenController->setObjectListbox(level);
	updateGUIElements();
}

void LevelEditorView::colorObject()
{
	if (selectedObjects.size() == 0)
		return;

	for (auto selectedObject: selectedObjects) {
		auto levelEditorObject = level->getObjectById(selectedObject->getId());
		if (levelEditorObject == nullptr)
			continue;

		auto color = (*OBJECTCOLOR_NAMES)[0];
		auto colorProperty = levelEditorObject->getProperty(u"object.color"_j);
		if (colorProperty == nullptr) {
			levelEditorObject->addProperty(u"object.color"_j, color);
		} else {
			color = colorProperty->getValue();
			for (auto i = 0; i < OBJECTCOLOR_NAMES->length; i++) {
				if (color->equalsIgnoreCase((*OBJECTCOLOR_NAMES)[i])) {
					color = (*OBJECTCOLOR_NAMES)[(i + 1) % OBJECTCOLOR_NAMES->length];
					break;
				}
			}
			if (color->equals(u"none"_j)) {
				levelEditorObject->removeProperty(u"object.color"_j);
			} else {
				levelEditorObject->updateProperty(colorProperty->getName(), u"object.color"_j, color);
			}
		}
		setStandardObjectColorEffect(selectedObject);
		setHighlightObjectColorEffect(selectedObject);
	}

	if (selectedObjects.size() == 1) {
		auto selectedObject = selectedObjects.at(0);
		if (selectedObject != nullptr && selectedObject->getId()->startsWith(u"leveleditor."_j) == false) {
			auto levelEditorObject = level->getObjectById(selectedObject->getId());
			auto preset = levelEditorObject->getProperty(u"preset"_j);
			levelEditorScreenController->setObjectProperties(preset != nullptr ? preset->getValue() : u""_j, levelEditorObject, nullptr);
		} else {
			levelEditorScreenController->unsetObjectProperties();
		}
	} else if (selectedObjects.size() > 1) {
		levelEditorScreenController->unsetObjectProperties();
	}
}

void LevelEditorView::centerObject()
{
	if (selectedObjects.size() == 0) {
		return;
	}
	auto center = new Vector3();
	for (auto selectedObject: selectedObjects) {
		center->add(selectedObject->getBoundingBoxTransformed()->getMin()->clone()->add(selectedObject->getBoundingBoxTransformed()->getMax())->scale(0.5f));
	}
	engine->getCamera()->getLookAt()->set(center->scale(1.0f / selectedObjects.size()));
}

void LevelEditorView::objectTranslationApply(float x, float y, float z)
{
	if (selectedObjects.size() == 0)
		return;

	if (selectedObjects.size() == 1) {
		auto selectedObject = selectedObjects.at(0);
		auto currentEntity = level->getObjectById(selectedObject->getId());
		if (currentEntity == nullptr)
			return;

		currentEntity->getTransformations()->getTranslation()->set(x, y, z);
		currentEntity->getTransformations()->update();
		selectedObject->fromTransformations(currentEntity->getTransformations());
	} else
	if (selectedObjects.size() > 1) {
		for (auto selectedObject: selectedObjects) {
			auto currentEntity = level->getObjectById(selectedObject->getId());
			if (currentEntity == nullptr)
				continue;

			currentEntity->getTransformations()->getTranslation()->add(new Vector3(x, y, z));
			currentEntity->getTransformations()->update();
			selectedObject->fromTransformations(currentEntity->getTransformations());
		}
		levelEditorScreenController->setObject(new Vector3(0.0f, 0.0f, 0.0f), new Vector3(1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 0.0f);
	}
	level->computeDimension();
	updateGUIElements();
}

void LevelEditorView::objectScaleApply(float x, float y, float z)
{
	if (selectedObjects.size() == 0)
		return;

	if (selectedObjects.size() == 1) {
		auto selectedObject = selectedObjects.at(0);
		auto currentEntity = level->getObjectById(selectedObject->getId());
		if (currentEntity == nullptr)
			return;

		currentEntity->getTransformations()->getScale()->set(x, y, z);
		currentEntity->getTransformations()->update();
		selectedObject->fromTransformations(currentEntity->getTransformations());
	} else
	if (selectedObjects.size() > 1) {
		for (auto selectedObject: selectedObjects) {
			auto currentEntity = level->getObjectById(selectedObject->getId());
			if (currentEntity == nullptr)
				continue;

			currentEntity->getTransformations()->getScale()->scale(new Vector3(x, y, z));
			currentEntity->getTransformations()->update();
			selectedObject->fromTransformations(currentEntity->getTransformations());
		}
		levelEditorScreenController->setObject(new Vector3(0.0f, 0.0f, 0.0f), new Vector3(1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 0.0f);
	}
	level->computeDimension();
	updateGUIElements();
}

void LevelEditorView::objectRotationsApply(float x, float y, float z)
{
	if (selectedObjects.size() == 0)
		return;

	if (selectedObjects.size() == 1) {
		auto selectedObject = selectedObjects.at(0);
		auto currentEntity = level->getObjectById(selectedObject->getId());
		if (currentEntity == nullptr)
			return;

		currentEntity->getTransformations()->getRotations()->get(level->getRotationOrder()->getAxisXIndex())->setAngle(x);
		currentEntity->getTransformations()->getRotations()->get(level->getRotationOrder()->getAxisYIndex())->setAngle(y);
		currentEntity->getTransformations()->getRotations()->get(level->getRotationOrder()->getAxisZIndex())->setAngle(z);
		currentEntity->getTransformations()->update();
		selectedObject->fromTransformations(currentEntity->getTransformations());
	} else
	if (selectedObjects.size() > 1) {
		for (auto selectedObject: selectedObjects) {
			auto currentEntity = level->getObjectById(selectedObject->getId());
			if (currentEntity == nullptr)
				continue;

			currentEntity->getTransformations()->getRotations()->get(level->getRotationOrder()->getAxisXIndex())->setAngle(currentEntity->getTransformations()->getRotations()->get(level->getRotationOrder()->getAxisXIndex())->getAngle() + x);
			currentEntity->getTransformations()->getRotations()->get(level->getRotationOrder()->getAxisYIndex())->setAngle(currentEntity->getTransformations()->getRotations()->get(level->getRotationOrder()->getAxisYIndex())->getAngle() + y);
			currentEntity->getTransformations()->getRotations()->get(level->getRotationOrder()->getAxisZIndex())->setAngle(currentEntity->getTransformations()->getRotations()->get(level->getRotationOrder()->getAxisZIndex())->getAngle() + z);
			currentEntity->getTransformations()->update();
			selectedObject->fromTransformations(currentEntity->getTransformations());
		}
		levelEditorScreenController->setObject(new Vector3(0.0f, 0.0f, 0.0f), new Vector3(1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 0.0f);
	}
	level->computeDimension();
	updateGUIElements();
}

bool LevelEditorView::mapPropertySave(String* oldName, String* name, String* value)
{
	if (level->updateProperty(oldName, name, value) == true) {
		levelEditorScreenController->setMapProperties(level, name);
		return true;
	}
	return false;
}

bool LevelEditorView::mapPropertyAdd()
{
	if (level->addProperty(u"new.property"_j, u"new.value"_j)) {
		levelEditorScreenController->setMapProperties(level, u"new.property"_j);
		return true;
	}
	return false;
}

bool LevelEditorView::mapPropertyRemove(String* name)
{
	auto idx = level->getPropertyIndex(name);
	if (idx != -1 && level->removeProperty(name) == true) {
		auto property = level->getPropertyByIndex(idx);
		if (property == nullptr) {
			property = level->getPropertyByIndex(idx - 1);
		}
		levelEditorScreenController->setMapProperties(level, property == nullptr ? static_cast< String* >(nullptr) : property->getName());
		return true;
	}
	return false;
}

bool LevelEditorView::objectPropertyRemove(String* name)
{
	if (selectedObjects.size() != 1)
		return false;

	auto selectedObject = selectedObjects.at(0);
	auto levelEditorObject = level->getObjectById(selectedObject->getId());
	if (levelEditorObject == nullptr)
		return false;

	auto idx = levelEditorObject->getPropertyIndex(name);
	if (idx != -1 && levelEditorObject->removeProperty(name) == true) {
		auto property = levelEditorObject->getPropertyByIndex(idx);
		if (property == nullptr) {
			property = levelEditorObject->getPropertyByIndex(idx - 1);
		}
		levelEditorScreenController->setObjectProperties(nullptr, levelEditorObject, property == nullptr ? static_cast< String* >(nullptr) : property->getName());
		return true;
	}
	return false;
}

void LevelEditorView::objectPropertiesPreset(String* presetId)
{
	if (selectedObjects.size() != 1)
		return;

	auto selectedObject = selectedObjects.at(0);
	auto levelEditorObject = level->getObjectById(selectedObject->getId());
	if (levelEditorObject == nullptr)
		return;

	levelEditorObject->clearProperties();
	auto objectPropertiesPresets = LevelPropertyPresets::getInstance()->getObjectPropertiesPresets();
	const vector<PropertyModelClass*>* objectPropertyPresetVector = nullptr;
	auto objectPropertyPresetVectorIt = objectPropertiesPresets->find(presetId->getCPPWString());
	if (objectPropertyPresetVectorIt != objectPropertiesPresets->end()) {
		objectPropertyPresetVector = &objectPropertyPresetVectorIt->second;
	}
	if (objectPropertyPresetVector != nullptr) {
		for (auto objectPropertyPreset: *objectPropertyPresetVector) {
			levelEditorObject->addProperty(objectPropertyPreset->getName(), objectPropertyPreset->getValue());
		}
	}
	levelEditorScreenController->setObjectProperties(presetId, levelEditorObject, nullptr);
}

bool LevelEditorView::objectPropertySave(String* oldName, String* name, String* value)
{
	if (selectedObjects.size() != 1)
		return false;

	auto selectedObject = selectedObjects.at(0);
	auto levelEditorObject = level->getObjectById(selectedObject->getId());
	if (levelEditorObject == nullptr)
		return false;

	if (levelEditorObject->updateProperty(oldName, name, value) == true) {
		levelEditorScreenController->setObjectProperties(nullptr, levelEditorObject, name);
		return true;
	}
	return false;
}

bool LevelEditorView::objectPropertyAdd()
{
	if (selectedObjects.size() != 1)
		return false;

	auto selectedObject = selectedObjects.at(0);
	auto levelEditorObject = level->getObjectById(selectedObject->getId());
	if (levelEditorObject == nullptr)
		return false;

	if (levelEditorObject->addProperty(u"new.property"_j, u"new.value"_j)) {
		levelEditorScreenController->setObjectProperties(nullptr, levelEditorObject, u"new.property"_j);
		return true;
	}
	return false;
}

void LevelEditorView::loadMap(String* path, String* file)
{
	selectedEntity = nullptr;
	try {
		if (file->toLowerCase()->endsWith(u".dae"_j) == true) {
			auto daeLevel = DAEReader::readLevel(path, file);
			file = ::java::lang::StringBuilder(file).append(u".tl"_j)->toString();
		}
		LevelFileImport::doImport(path, file, level);
		for (auto i = 0; i < level->getEntityLibrary()->getEntityCount(); i++) {
			level->getEntityLibrary()->getEntityAt(i)->setDefaultBoundingVolumes();
		}
		levelEditorScreenController->setMapProperties(level, nullptr);
		levelEditorScreenController->unsetObjectProperties();
		levelEditorScreenController->unsetObject();
		loadLevel();
		engine->getCamera()->getLookAt()->set(level->computeCenter());
		camLookRotationX->setAngle(-45.0f);
		camLookRotationX->update();
		camLookRotationY->setAngle(0.0f);
		camLookRotationY->update();
		camScale = 1.0f;
		gridCenter->set(engine->getCamera()->getLookAt());
		reloadEntityLibrary = true;
		updateGUIElements();
	} catch (_Exception& exception) {
		levelEditorScreenController->showErrorPopUp(
			u"Warning: Could not load level file"_j,
			new String(StringConverter::toWideString(string(exception.what())))
		);
	}
}

void LevelEditorView::saveMap(String* pathName, String* fileName)
{
	try {
		LevelFileExport::export_(pathName, fileName, level);
	} catch (_Exception& exception) {
		levelEditorScreenController->showErrorPopUp(
			u"Warning: Could not save level file"_j,
			new String(StringConverter::toWideString(string(exception.what())))
		);
	}
	updateGUIElements();
}

void LevelEditorView::copyObjects()
{
	pasteObjects_.clear();
	for (auto selectedObject: selectedObjects) {
		if (selectedObject != nullptr && selectedObject->getId()->startsWith(u"leveleditor."_j) == false) {
			auto levelEditorObject = level->getObjectById(selectedObject->getId());
			if (levelEditorObject == nullptr)
				continue;

			pasteObjects_.push_back(levelEditorObject);
		}
	}
}

void LevelEditorView::pasteObjects()
{
	auto pasteObjectsMinX = Float::MAX_VALUE;
	auto pasteObjectsMinZ = Float::MAX_VALUE;
	auto pasteObjectsMinY = Float::MIN_VALUE;
	for (auto object: pasteObjects_) {
		BoundingVolume* obv = object->getEntity()->getModel()->getBoundingBox();
		auto cbv = obv->clone();
		cbv->fromBoundingVolumeWithTransformations(obv, object->getTransformations());
		auto objectBBMinXYZ = (java_cast< BoundingBox* >(cbv))->getMin()->getArray();
		if ((*objectBBMinXYZ)[0] < pasteObjectsMinX)
			pasteObjectsMinX = (*objectBBMinXYZ)[0];

		if ((*objectBBMinXYZ)[1] < pasteObjectsMinY)
			pasteObjectsMinY = (*objectBBMinXYZ)[1];

		if ((*objectBBMinXYZ)[2] < pasteObjectsMinZ)
			pasteObjectsMinZ = (*objectBBMinXYZ)[2];
	}
	auto selectedObjectsMinX = Float::MAX_VALUE;
	auto selectedObjectsMinZ = Float::MAX_VALUE;
	auto selectedObjectsMaxY = Float::MIN_VALUE;
	for (auto object: selectedObjects) {
		auto levelEditorObject = level->getObjectById(object->getId());
		if (levelEditorObject == nullptr)
			continue;

		BoundingVolume* obv = levelEditorObject->getEntity()->getModel()->getBoundingBox();
		auto cbv = obv->clone();
		cbv->fromBoundingVolumeWithTransformations(obv, levelEditorObject->getTransformations());
		auto objectBBMinXYZ = (java_cast< BoundingBox* >(cbv))->getMin()->getArray();
		auto objectBBMaxXYZ = (java_cast< BoundingBox* >(cbv))->getMax()->getArray();
		if ((*objectBBMinXYZ)[0] < selectedObjectsMinX)
			selectedObjectsMinX = (*objectBBMinXYZ)[0];

		if ((*objectBBMaxXYZ)[1] > selectedObjectsMaxY)
			selectedObjectsMaxY = (*objectBBMaxXYZ)[1];

		if ((*objectBBMinXYZ)[2] < selectedObjectsMinZ)
			selectedObjectsMinZ = (*objectBBMinXYZ)[2];
	}
	for (auto pasteObject: pasteObjects_) {
		auto pasteModel = pasteObject->getEntity();
		auto levelEditorObjectTransformations = new Transformations();
		levelEditorObjectTransformations->fromTransformations(pasteObject->getTransformations());
		auto objectDiffX = pasteObject->getTransformations()->getTranslation()->getX() - pasteObjectsMinX;
		auto objectDiffY = pasteObject->getTransformations()->getTranslation()->getY() - pasteObjectsMinY;
		auto objectDiffZ = pasteObject->getTransformations()->getTranslation()->getZ() - pasteObjectsMinZ;
		levelEditorObjectTransformations->getTranslation()->setX(selectedObjectsMinX + objectDiffX);
		levelEditorObjectTransformations->getTranslation()->setY(selectedObjectsMaxY + objectDiffY);
		levelEditorObjectTransformations->getTranslation()->setZ(selectedObjectsMinZ + objectDiffZ);
		levelEditorObjectTransformations->update();
		for (auto i = 0; i < level->getObjectCount(); i++) {
			auto levelEditorObject = level->getObjectAt(i);
			if (levelEditorObject->getEntity() == pasteModel && levelEditorObject->getTransformations()->getTranslation()->equals(levelEditorObjectTransformations->getTranslation())) {
				return;
			}
		}
		auto levelEditorObject = new LevelEditorObject(::java::lang::StringBuilder().append(pasteModel->getName())->append(u"_"_j)
			->append(level->allocateObjectId())->toString(), u""_j, levelEditorObjectTransformations, pasteModel);
		ModelProperties* properties = pasteObject;
		for (int i = 0; i < properties->getPropertyCount(); i++) {
			PropertyModelClass* property = properties->getPropertyByIndex(i);
			levelEditorObject->addProperty(property->getName(), property->getValue());
		}
		level->addObject(levelEditorObject);
		auto object = new Object3D(levelEditorObject->getId(), levelEditorObject->getEntity()->getModel());
		object->fromTransformations(levelEditorObjectTransformations);
		object->setPickable(true);
		engine->addEntity(object);
	}
	levelEditorScreenController->setObjectListbox(level);
}

void LevelEditorView::computeSpotDirection(int32_t i, Vector4* position, Vector3* spotTo)
{
	auto _from = new Vector3(position->getArray());
	auto spotDirection = spotTo->clone()->sub(_from);
	level->getLightAt(i)->getPosition()->set(position->getX(), position->getY(), position->getZ(), position->getW());
	level->getLightAt(i)->getSpotTo()->set(spotTo->getX(), spotTo->getY(), spotTo->getZ());
	level->getLightAt(i)->getSpotDirection()->set(spotDirection->getX(), spotDirection->getY(), spotDirection->getZ());
	engine->getLightAt(i)->getPosition()->set(position->getX(), position->getY(), position->getZ(), position->getW());
	engine->getLightAt(i)->getSpotDirection()->set(spotDirection->getX(), spotDirection->getY(), spotDirection->getZ());
	levelEditorScreenController->setLight(i, level->getLightAt(i)->getAmbient(), level->getLightAt(i)->getDiffuse(), level->getLightAt(i)->getSpecular(), level->getLightAt(i)->getPosition(), level->getLightAt(i)->getConstantAttenuation(), level->getLightAt(i)->getLinearAttenuation(), level->getLightAt(i)->getQuadraticAttenuation(), level->getLightAt(i)->getSpotTo(), level->getLightAt(i)->getSpotDirection(), level->getLightAt(i)->getSpotExponent(), level->getLightAt(i)->getSpotCutOff(), level->getLightAt(i)->isEnabled());
}

void LevelEditorView::applyLight(int32_t i, Color4* ambient, Color4* diffuse, Color4* specular, Vector4* position, float constantAttenuation, float linearAttenuation, float quadraticAttenuation, Vector3* spotTo, Vector3* spotDirection, float spotExponent, float spotCutoff, bool enabled)
{
	level->getLightAt(i)->getAmbient()->set(ambient->getRed(), ambient->getGreen(), ambient->getBlue(), ambient->getAlpha());
	level->getLightAt(i)->getDiffuse()->set(diffuse->getRed(), diffuse->getGreen(), diffuse->getBlue(), diffuse->getAlpha());
	level->getLightAt(i)->getSpecular()->set(specular->getRed(), specular->getGreen(), specular->getBlue(), specular->getAlpha());
	level->getLightAt(i)->getPosition()->set(position->getX(), position->getY(), position->getZ(), position->getW());
	level->getLightAt(i)->setConstantAttenuation(constantAttenuation);
	level->getLightAt(i)->setLinearAttenuation(linearAttenuation);
	level->getLightAt(i)->setQuadraticAttenuation(quadraticAttenuation);
	level->getLightAt(i)->getSpotTo()->set(spotTo->getX(), spotTo->getY(), spotTo->getZ());
	level->getLightAt(i)->getSpotDirection()->set(spotDirection->getX(), spotDirection->getY(), spotDirection->getZ());
	level->getLightAt(i)->setSpotExponent(spotExponent);
	level->getLightAt(i)->setSpotCutOff(spotCutoff);
	level->getLightAt(i)->setEnabled(enabled);
	engine->getLightAt(i)->getAmbient()->set(ambient->getRed(), ambient->getGreen(), ambient->getBlue(), ambient->getAlpha());
	engine->getLightAt(i)->getDiffuse()->set(diffuse->getRed(), diffuse->getGreen(), diffuse->getBlue(), diffuse->getAlpha());
	engine->getLightAt(i)->getSpecular()->set(specular->getRed(), specular->getGreen(), specular->getBlue(), specular->getAlpha());
	engine->getLightAt(i)->getPosition()->set(position->getX(), position->getY(), position->getZ(), position->getW());
	engine->getLightAt(i)->setConstantAttenuation(constantAttenuation);
	engine->getLightAt(i)->setLinearAttenuation(linearAttenuation);
	engine->getLightAt(i)->setQuadraticAttenuation(quadraticAttenuation);
	engine->getLightAt(i)->getSpotDirection()->set(spotDirection->getX(), spotDirection->getY(), spotDirection->getZ());
	engine->getLightAt(i)->setSpotExponent(spotExponent);
	engine->getLightAt(i)->setSpotCutOff(spotCutoff);
	engine->getLightAt(i)->setEnabled(enabled);
	levelEditorScreenController->setLight(i, level->getLightAt(i)->getAmbient(), level->getLightAt(i)->getDiffuse(), level->getLightAt(i)->getSpecular(), level->getLightAt(i)->getPosition(), level->getLightAt(i)->getConstantAttenuation(), level->getLightAt(i)->getLinearAttenuation(), level->getLightAt(i)->getQuadraticAttenuation(), level->getLightAt(i)->getSpotTo(), level->getLightAt(i)->getSpotDirection(), level->getLightAt(i)->getSpotExponent(), level->getLightAt(i)->getSpotCutOff(), level->getLightAt(i)->isEnabled());
}

extern java::lang::Class* class_(const char16_t* c, int n);

java::lang::Class* LevelEditorView::class_()
{
    static ::java::lang::Class* c = ::class_(u"tdme.tools.leveleditor.views.LevelEditorView", 44);
    return c;
}

void LevelEditorView::clinit()
{
	super::clinit();
	static bool in_cl_init = false;
	struct clinit_ {
		clinit_() {
			in_cl_init = true;
		OBJECTCOLOR_NAMES = (new StringArray({
			u"blue"_j,
			u"yellow"_j,
			u"magenta"_j,
			u"cyan"_j,
			u"none"_j
		}));
		}
	};

	if (!in_cl_init) {
		static clinit_ clinit_instance;
	}
}

java::lang::Class* LevelEditorView::getClass0()
{
	return class_();
}

