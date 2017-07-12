// Generated from /tdme/src/tdme/engine/Engine.java
#include <tdme/engine/Engine.h>

#include <java/lang/ArrayStoreException.h>
#include <java/lang/Class.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Float.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/Object.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Iterator.h>
#include <tdme/engine/Camera.h>
#include <tdme/engine/Engine_initialize_1.h>
#include <tdme/engine/Engine_initialize_2.h>
#include <tdme/engine/Engine_initialize_3.h>
#include <tdme/engine/Engine_AnimationProcessingTarget.h>
#include <tdme/engine/Entity.h>
#include <tdme/engine/EntityPickingFilter.h>
#include <tdme/engine/FrameBuffer.h>
#include <tdme/engine/Light.h>
#include <tdme/engine/Object3D.h>
#include <tdme/engine/ObjectParticleSystemEntity.h>
#include <tdme/engine/Partition.h>
#include <tdme/engine/PartitionOctTree.h>
#include <tdme/engine/PointsParticleSystemEntity.h>
#include <tdme/engine/Timing.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/engine/physics/CollisionDetection.h>
#include <tdme/engine/primitives/BoundingBox.h>
#include <tdme/engine/primitives/LineSegment.h>
#include <tdme/engine/subsystems/lighting/LightingShader.h>
#include <tdme/engine/subsystems/manager/MeshManager.h>
#include <tdme/engine/subsystems/manager/TextureManager.h>
#include <tdme/engine/subsystems/manager/VBOManager.h>
#include <tdme/engine/subsystems/object/Object3DBase_TransformedFacesIterator.h>
#include <tdme/engine/subsystems/object/Object3DVBORenderer.h>
#include <tdme/engine/subsystems/particlesystem/ParticleSystemEntity.h>
#include <tdme/engine/subsystems/particlesystem/ParticlesShader.h>
#include <tdme/engine/subsystems/renderer/GLRenderer.h>
#include <tdme/engine/subsystems/shadowmapping/ShadowMapping.h>
#include <tdme/engine/subsystems/shadowmapping/ShadowMappingShaderPre.h>
#include <tdme/engine/subsystems/shadowmapping/ShadowMappingShaderRender.h>
#include <tdme/gui/GUI.h>
#include <tdme/gui/renderer/GUIRenderer.h>
#include <tdme/gui/renderer/GUIShader.h>
#include <tdme/math/Matrix4x4.h>
#include <tdme/math/Vector2.h>
#include <tdme/math/Vector3.h>
#include <tdme/math/Vector4.h>
#include <tdme/os/_FileSystem.h>
#include <tdme/os/_FileSystemInterface.h>
#include <tdme/utils/_ArrayList.h>
#include <tdme/utils/_Console.h>
#include <tdme/utils/_HashMap_KeysIterator.h>
#include <tdme/utils/_HashMap_ValuesIterator.h>
#include <tdme/utils/_HashMap.h>
#include <Array.h>
#include <ObjectArray.h>
#include <SubArray.h>

using tdme::engine::Engine;
using java::lang::ArrayStoreException;
using java::lang::Class;
using java::lang::ClassCastException;
using java::lang::ClassLoader;
using java::lang::Float;
using java::lang::NullPointerException;
using java::lang::Object;
using java::lang::String;
using java::lang::StringBuilder;
using java::nio::ByteBuffer;
using java::util::Iterator;
using tdme::engine::Camera;
using tdme::engine::Engine_initialize_1;
using tdme::engine::Engine_initialize_2;
using tdme::engine::Engine_initialize_3;
using tdme::engine::Engine_AnimationProcessingTarget;
using tdme::engine::Entity;
using tdme::engine::EntityPickingFilter;
using tdme::engine::FrameBuffer;
using tdme::engine::Light;
using tdme::engine::Object3D;
using tdme::engine::ObjectParticleSystemEntity;
using tdme::engine::Partition;
using tdme::engine::PartitionOctTree;
using tdme::engine::PointsParticleSystemEntity;
using tdme::engine::Timing;
using tdme::engine::model::Color4;
using tdme::engine::physics::CollisionDetection;
using tdme::engine::primitives::BoundingBox;
using tdme::engine::primitives::LineSegment;
using tdme::engine::subsystems::lighting::LightingShader;
using tdme::engine::subsystems::manager::MeshManager;
using tdme::engine::subsystems::manager::TextureManager;
using tdme::engine::subsystems::manager::VBOManager;
using tdme::engine::subsystems::object::Object3DBase_TransformedFacesIterator;
using tdme::engine::subsystems::object::Object3DVBORenderer;
using tdme::engine::subsystems::particlesystem::ParticleSystemEntity;
using tdme::engine::subsystems::particlesystem::ParticlesShader;
using tdme::engine::subsystems::renderer::GLRenderer;
using tdme::engine::subsystems::shadowmapping::ShadowMapping;
using tdme::engine::subsystems::shadowmapping::ShadowMappingShaderPre;
using tdme::engine::subsystems::shadowmapping::ShadowMappingShaderRender;
using tdme::gui::GUI;
using tdme::gui::renderer::GUIRenderer;
using tdme::gui::renderer::GUIShader;
using tdme::math::Matrix4x4;
using tdme::math::Vector2;
using tdme::math::Vector3;
using tdme::math::Vector4;
using tdme::os::_FileSystem;
using tdme::os::_FileSystemInterface;
using tdme::utils::_ArrayList;
using tdme::utils::_Console;
using tdme::utils::_HashMap_KeysIterator;
using tdme::utils::_HashMap_ValuesIterator;
using tdme::utils::_HashMap;

template<typename ComponentType, typename... Bases> struct SubArray;
namespace tdme {
namespace engine {
typedef ::SubArray< ::tdme::engine::Light, ::java::lang::ObjectArray > LightArray;
}  // namespace engine

namespace math {
typedef ::SubArray< ::tdme::math::Vector3, ::java::lang::ObjectArray > Vector3Array;
}  // namespace math
}  // namespace tdme

template<typename T, typename U>
static T java_cast(U* u)
{
    if (!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if (!t) throw new ::java::lang::ClassCastException();
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
Engine::Engine(const ::default_init_tag&)
	: super(*static_cast< ::default_init_tag* >(0))
{
	clinit();
}

Engine::Engine() 
	: Engine(*static_cast< ::default_init_tag* >(0))
{
	ctor();
}

Engine* Engine::instance;

GLRenderer* Engine::renderer;

TextureManager* Engine::textureManager;

VBOManager* Engine::vboManager;

MeshManager* Engine::meshManager;

GUIRenderer* Engine::guiRenderer;

Engine_AnimationProcessingTarget* Engine::animationProcessingTarget;

ShadowMappingShaderPre* Engine::shadowMappingShaderPre;

ShadowMappingShaderRender* Engine::shadowMappingShaderRender;

LightingShader* Engine::lightingShader;

ParticlesShader* Engine::particlesShader;

GUIShader* Engine::guiShader;

Engine* Engine::getInstance()
{
	clinit();
	if (instance == nullptr) {
		instance = new Engine();
	}
	return instance;
}

Engine* Engine::createOffScreenInstance(int32_t width, int32_t height)
{
	clinit();
	if (instance == nullptr || instance->initialized == false) {
		_Console::println(static_cast< Object* >(u"Engine::createOffScreenInstance(): Engine not created or not initialized."_j));
		return nullptr;
	}
	auto offScreenEngine = new Engine();
	offScreenEngine->initialized = true;
	offScreenEngine->gui = new GUI(offScreenEngine, guiRenderer);
	offScreenEngine->object3DVBORenderer = new Object3DVBORenderer(offScreenEngine, renderer);
	offScreenEngine->object3DVBORenderer->initialize();
	offScreenEngine->frameBuffer = new FrameBuffer(width, height, FrameBuffer::FRAMEBUFFER_DEPTHBUFFER | FrameBuffer::FRAMEBUFFER_COLORBUFFER);
	offScreenEngine->frameBuffer->initialize();
	offScreenEngine->camera = new Camera(renderer);
	offScreenEngine->partition = new PartitionOctTree();
	for (auto i = 0; i < offScreenEngine->lights->length; i++) 
				offScreenEngine->lights->set(i, new Light(renderer, i));

	if (instance->shadowMappingEnabled == true) {
		offScreenEngine->shadowMapping = new ShadowMapping(offScreenEngine, renderer, offScreenEngine->object3DVBORenderer);
	}
	offScreenEngine->reshape(0, 0, width, height);
	return offScreenEngine;
}

void Engine::ctor()
{
	super::ctor();
	width = 0;
	height = 0;
	timing = new Timing();
	camera = nullptr;
	lights = new LightArray(8);
	sceneColor = new Color4(0.0f, 0.0f, 0.0f, 1.0f);
	frameBuffer = nullptr;
	entitiesById = new _HashMap();
	objects = new _ArrayList();
	visibleObjects = new _ArrayList();
	visibleOpses = new _ArrayList();
	ppses = new _ArrayList();
	visiblePpses = new _ArrayList();
	particleSystemEntitiesById = new _HashMap();
	shadowMappingEnabled = false;
	shadowMapping = nullptr;
	renderingInitiated = false;
	renderingComputedTransformations = false;
	modelViewMatrix = new Matrix4x4();
	projectionMatrix = new Matrix4x4();
	tmpMatrix4x4 = new Matrix4x4();
	tmpVector3a = new Vector3();
	tmpVector3b = new Vector3();
	tmpVector3c = new Vector3();
	tmpVector3d = new Vector3();
	tmpVector3e = new Vector3();
	tmpVector3f = new Vector3();
	tmpVector4a = new Vector4();
	tmpVector4b = new Vector4();
	lineSegment = new LineSegment();
	initialized = false;
}

bool Engine::isInitialized()
{
	return initialized;
}

int32_t Engine::getWidth()
{
	return width;
}

int32_t Engine::getHeight()
{
	return height;
}

ShadowMapping* Engine::getShadowMapping()
{
	return shadowMapping;
}

GUI* Engine::getGUI()
{
	return gui;
}

Timing* Engine::getTiming()
{
	return timing;
}

Camera* Engine::getCamera()
{
	return camera;
}

Partition* Engine::getPartition()
{
	return partition;
}

void Engine::setPartition(Partition* partition)
{
	this->partition = partition;
}

LightArray* Engine::getLights()
{
	return lights;
}

FrameBuffer* Engine::getFrameBuffer()
{
	return frameBuffer;
}

Light* Engine::getLightAt(int32_t idx)
{
	/* assert((idx >= 0 && idx < 8)) */ ;
	return (*lights)[idx];
}

TextureManager* Engine::getTextureManager()
{
	return textureManager;
}

VBOManager* Engine::getVBOManager()
{
	return vboManager;
}

MeshManager* Engine::getMeshManager()
{
	return meshManager;
}

ShadowMappingShaderPre* Engine::getShadowMappingShaderPre()
{
	clinit();
	return shadowMappingShaderPre;
}

ShadowMappingShaderRender* Engine::getShadowMappingShaderRender()
{
	clinit();
	return shadowMappingShaderRender;
}

LightingShader* Engine::getLightingShader()
{
	clinit();
	return lightingShader;
}

ParticlesShader* Engine::getParticlesShader()
{
	clinit();
	return particlesShader;
}

GUIShader* Engine::getGUIShader()
{
	clinit();
	return guiShader;
}

Object3DVBORenderer* Engine::getObject3DVBORenderer()
{
	return object3DVBORenderer;
}

Color4* Engine::getSceneColor()
{
	return sceneColor;
}

int32_t Engine::getEntityCount()
{
	return entitiesById->size();
}

Entity* Engine::getEntity(String* id)
{
	return java_cast< Entity* >(entitiesById->get(id));
}

void Engine::addEntity(Entity* entity)
{
	entity->setEngine(this);
	entity->setRenderer(renderer);
	entity->initialize();
	auto oldEntity = java_cast< Entity* >(entitiesById->put(entity->getId(), entity));
	if (oldEntity != nullptr) {
		oldEntity->dispose();
		if (oldEntity->isEnabled() == true)
			partition->removeEntity(oldEntity);

	}
	if (entity->isEnabled() == true)
		partition->addEntity(entity);

}

void Engine::removeEntity(String* id)
{
	auto entity = java_cast< Entity* >(entitiesById->remove(id));
	if (entity != nullptr) {
		if (entity->isEnabled() == true)
			partition->removeEntity(entity);

		entity->dispose();
		entity->setEngine(nullptr);
		entity->setRenderer(nullptr);
	}
}

void Engine::reset()
{
	Iterator* entityKeys = entitiesById->getKeysIterator();
	auto entitiesToRemove = new _ArrayList();
	while (entityKeys->hasNext()) {
		auto entityKey = java_cast< String* >(entityKeys->next());
		entitiesToRemove->add(entityKey);
	}
	for (auto i = 0; i < entitiesToRemove->size(); i++) {
		removeEntity(java_cast< String* >(entitiesToRemove->get(i)));
	}
	partition->reset();
	object3DVBORenderer->reset();
}

void Engine::initialize()
{
	initialize(false);
}

void Engine::initialize(bool debug)
{
	if (initialized == true)
		return;

	if (true == true/*GL3*/) {
		renderer = new Engine_initialize_1(this);
		_Console::println(static_cast< Object* >(u"TDME::Using GL3"_j));
		// _Console::println(static_cast< Object* >(::java::lang::StringBuilder().append(u"TDME::Extensions: "_j)->append(gl->glGetString(GL::GL_EXTENSIONS))->toString()));
		shadowMappingEnabled = true;
		animationProcessingTarget = Engine_AnimationProcessingTarget::CPU;
		ShadowMapping::setShadowMapSize(2048, 2048);
	}/* else if (drawable->getGL()->isGL2()) {
		auto gl = java_cast< GL2* >(drawable->getGL()->getGL2());
		if (debug == true) {
			drawable->setGL(new DebugGL2(gl));
		}
		renderer = new Engine_initialize_2(this);
		renderer->setGL(gl);
		_Console::println(static_cast< Object* >(u"TDME::Using GL2"_j));
		_Console::println(static_cast< Object* >(::java::lang::StringBuilder().append(u"TDME::Extensions: "_j)->append(gl->glGetString(GL::GL_EXTENSIONS))->toString()));
		shadowMappingEnabled = true;
		animationProcessingTarget = Engine_AnimationProcessingTarget::CPU;
		ShadowMapping::setShadowMapSize(2048, 2048);
	} else if (drawable->getGL()->isGLES2()) {
		auto gl = java_cast< GLES2* >(drawable->getGL()->getGLES2());
		if (debug == true) {
			drawable->setGL(new DebugGLES2(gl));
		}
		renderer = new Engine_initialize_3(this);
		renderer->setGL(gl);
		_Console::println(static_cast< Object* >(u"TDME::Using GLES2"_j));
		_Console::println(static_cast< Object* >(::java::lang::StringBuilder().append(u"TDME::Extensions: "_j)->append(gl->glGetString(GL::GL_EXTENSIONS))->toString()));
		if (renderer->isBufferObjectsAvailable() == true && renderer->isDepthTextureAvailable() == true) {
			shadowMappingEnabled = true;
			animationProcessingTarget = Engine_AnimationProcessingTarget::CPU;
			ShadowMapping::setShadowMapSize(512, 512);
		} else {
			shadowMappingEnabled = false;
			animationProcessingTarget = Engine_AnimationProcessingTarget::CPU;
		}
	}*/ else {
		_Console::println(static_cast< Object* >(u"Engine::initialize(): unsupported GL!"_j));
		return;
	}
	initialized = true;
	renderer->initialize();
	renderer->renderingTexturingClientState = false;
	textureManager = new TextureManager(renderer);
	vboManager = new VBOManager(renderer);
	meshManager = new MeshManager();
	object3DVBORenderer = new Object3DVBORenderer(this, renderer);
	object3DVBORenderer->initialize();
	guiRenderer = new GUIRenderer(renderer);
	guiRenderer->initialize();
	gui = new GUI(this, guiRenderer);
	gui->initialize();
	camera = new Camera(renderer);
	partition = new PartitionOctTree();
	for (auto i = 0; i < lights->length; i++) 
		lights->set(i, new Light(renderer, i));

	lightingShader = new LightingShader(renderer);
	lightingShader->initialize();
	particlesShader = new ParticlesShader(this, renderer);
	particlesShader->initialize();
	guiShader = new GUIShader(renderer);
	guiShader->initialize();
	if (renderer->isBufferObjectsAvailable()) {
		_Console::println(static_cast< Object* >(u"TDME::VBOs are available."_j));
	} else {
		_Console::println(static_cast< Object* >(u"TDME::VBOs are not available! Engine will not work!"_j));
		initialized = false;
	}
	if (true == false/*glContext->hasBasicFBOSupport() == false*/) {
		_Console::println(static_cast< Object* >(u"TDME::Basic FBOs are not available!"_j));
		shadowMappingEnabled = false;
	} else {
		_Console::println(static_cast< Object* >(u"TDME::Basic FBOs are available."_j));
	}
	if (shadowMappingEnabled == true) {
		_Console::println(static_cast< Object* >(u"TDME::Using shadow mapping"_j));
		shadowMappingShaderPre = new ShadowMappingShaderPre(renderer);
		shadowMappingShaderPre->initialize();
		shadowMappingShaderRender = new ShadowMappingShaderRender(renderer);
		shadowMappingShaderRender->initialize();
		shadowMapping = new ShadowMapping(this, renderer, object3DVBORenderer);
	} else {
		_Console::println(static_cast< Object* >(u"TDME::Not using shadow mapping"_j));
	}
	_Console::println(static_cast< Object* >(::java::lang::StringBuilder().append(u"TDME: animation processing target: "_j)->append(static_cast< Object* >(animationProcessingTarget))->toString()));
	initialized &= shadowMappingShaderPre == nullptr ? true : shadowMappingShaderPre->isInitialized();
	initialized &= shadowMappingShaderRender == nullptr ? true : shadowMappingShaderRender->isInitialized();
	initialized &= lightingShader->isInitialized();
	initialized &= particlesShader->isInitialized();
	initialized &= guiShader->isInitialized();
	_Console::println(static_cast< Object* >(::java::lang::StringBuilder().append(u"TDME::initialized & ready: "_j)->append(initialized)->toString()));
}

void Engine::reshape(int32_t x, int32_t y, int32_t width, int32_t height)
{
	this->width = width;
	this->height = height;
	if (frameBuffer != nullptr) {
		frameBuffer->reshape(width, height);
	}
	if (shadowMapping != nullptr) {
		shadowMapping->reshape(width, height);
	}
	gui->reshape(width, height);
}

void Engine::initRendering()
{
	timing->updateTiming();
	camera->update(width, height);
	objects->clear();
	ppses->clear();
	visibleObjects->clear();
	visibleOpses->clear();
	visiblePpses->clear();
	renderingInitiated = true;
}

void Engine::computeTransformations()
{
	if (renderingInitiated == false) initRendering();

	for (auto _i = entitiesById->getValuesIterator()->iterator(); _i->hasNext(); ) {
		Entity* entity = java_cast< Entity* >(_i->next());
		{
			if (entity->isEnabled() == false)
				continue;

			if (dynamic_cast< ParticleSystemEntity* >(entity) != nullptr) {
				auto pse = java_cast< ParticleSystemEntity* >(entity);
				if (pse->isAutoEmit() == true) {
					pse->emitParticles();
					pse->updateParticles();
				}
			}
		}
	}
	for (auto _i = partition->getVisibleEntities(camera->getFrustum())->iterator(); _i->hasNext(); ) {
		Entity* entity = java_cast< Entity* >(_i->next());
		{
			if (dynamic_cast< Object3D* >(entity) != nullptr) {
				auto object = java_cast< Object3D* >(entity);
				object->computeTransformations();
				visibleObjects->add(object);
			} else if (dynamic_cast< ObjectParticleSystemEntity* >(entity) != nullptr) {
				auto opse = java_cast< ObjectParticleSystemEntity* >(entity);
				visibleObjects->addAll(opse->getEnabledObjects());
				visibleOpses->add(opse);
			} else if (dynamic_cast< PointsParticleSystemEntity* >(entity) != nullptr) {
				auto ppse = java_cast< PointsParticleSystemEntity* >(entity);
				visiblePpses->add(ppse);
			}
		}
	}
	renderingComputedTransformations = true;
}

void Engine::display()
{
	if (renderingInitiated == false) initRendering();

	if (renderingComputedTransformations == false) computeTransformations();

	Engine::renderer->initializeFrame();
	Engine::renderer->enableClientState(Engine::renderer->CLIENTSTATE_VERTEX_ARRAY);
	Engine::renderer->enableClientState(Engine::renderer->CLIENTSTATE_NORMAL_ARRAY);
	camera->update(width, height);
	if (shadowMapping != nullptr)
		shadowMapping->createShadowMaps(objects);

	if (frameBuffer != nullptr) {
		frameBuffer->enableFrameBuffer();
	} else {
		FrameBuffer::disableFrameBuffer();
	}
	camera->update(width, height);
	Engine::renderer->setClearColor(sceneColor->getRed(), sceneColor->getGreen(), sceneColor->getBlue(), sceneColor->getAlpha());
	renderer->clear(renderer->CLEAR_DEPTH_BUFFER_BIT | renderer->CLEAR_COLOR_BUFFER_BIT);
	renderer->setMaterialEnabled();
	if (lightingShader != nullptr) {
		lightingShader->useProgram();
	}
	for (auto j = 0; j < lights->length; j++) {
		(*lights)[j]->update();
	}
	object3DVBORenderer->render(visibleObjects, true);
	if (lightingShader != nullptr) {
		lightingShader->unUseProgram();
	}
	if (shadowMapping != nullptr)
		shadowMapping->renderShadowMaps(visibleObjects);

	renderer->setMaterialDisabled();
	if (particlesShader != nullptr) {
		particlesShader->useProgram();
	}
	object3DVBORenderer->render(visiblePpses);
	if (particlesShader != nullptr) {
		particlesShader->unUseProgram();
	}
	Engine::renderer->disableClientState(Engine::renderer->CLIENTSTATE_VERTEX_ARRAY);
	Engine::renderer->disableClientState(Engine::renderer->CLIENTSTATE_NORMAL_ARRAY);
	Engine::renderer->disableClientState(Engine::renderer->CLIENTSTATE_TEXTURECOORD_ARRAY);
	renderingInitiated = false;
	renderingComputedTransformations = false;
	renderer->renderingTexturingClientState = false;
	modelViewMatrix->set(renderer->getModelViewMatrix());
	projectionMatrix->set(renderer->getProjectionMatrix());
	if (frameBuffer != nullptr)
		FrameBuffer::disableFrameBuffer();

}

void Engine::computeWorldCoordinateByMousePosition(int32_t mouseX, int32_t mouseY, float z, Vector3* worldCoordinate)
{
	tmpMatrix4x4->set(modelViewMatrix)->multiply(projectionMatrix)->invert();
	tmpMatrix4x4->multiply(tmpVector4a->set((2.0f * mouseX / width) - 1.0f, 1.0f - (2.0f * mouseY / height), 2.0f * z - 1.0f, 1.0f), tmpVector4b);
	tmpVector4b->scale(1.0f / tmpVector4b->getW());
	worldCoordinate->set(tmpVector4b->getArray());
}

void Engine::computeWorldCoordinateByMousePosition(int32_t mouseX, int32_t mouseY, Vector3* worldCoordinate)
{
	if (frameBuffer != nullptr)
		frameBuffer->enableFrameBuffer();

	auto z = renderer->readPixelDepth(mouseX, height - mouseY);
	if (frameBuffer != nullptr)
		FrameBuffer::disableFrameBuffer();

	computeWorldCoordinateByMousePosition(mouseX, mouseY, z, worldCoordinate);
}

Entity* Engine::getObjectByMousePosition(int32_t mouseX, int32_t mouseY)
{
	return getObjectByMousePosition(mouseX, mouseY, nullptr);
}

Entity* Engine::getObjectByMousePosition(int32_t mouseX, int32_t mouseY, EntityPickingFilter* filter)
{
	computeWorldCoordinateByMousePosition(mouseX, mouseY, 0.0f, tmpVector3a);
	computeWorldCoordinateByMousePosition(mouseX, mouseY, 1.0f, tmpVector3b);
	auto selectedEntityDistance = Float::MAX_VALUE;
	Entity* selectedEntity = nullptr;
	for (auto i = 0; i < visibleObjects->size(); i++) {
		auto entity = java_cast< Object3D* >(visibleObjects->get(i));
		if (entity->isPickable() == false)
			continue;

		if (filter != nullptr && filter->filterEntity(entity) == false)
			continue;

		if (lineSegment->doesBoundingBoxCollideWithLineSegment(entity->getBoundingBoxTransformed(), tmpVector3a, tmpVector3b, tmpVector3c, tmpVector3d) == true) {
			for (auto _i = entity->getTransformedFacesIterator()->iterator(); _i->hasNext(); ) {
				Vector3Array* vertices = java_cast< Vector3Array* >(_i->next());
				{
					if (lineSegment->doesLineSegmentCollideWithTriangle((*vertices)[0], (*vertices)[1], (*vertices)[2], tmpVector3a, tmpVector3b, tmpVector3e) == true) {
						auto entityDistance = tmpVector3e->sub(tmpVector3a)->computeLength();
						if (selectedEntity == nullptr || entityDistance < selectedEntityDistance) {
							selectedEntity = entity;
							selectedEntityDistance = entityDistance;
						}
					}
				}
			}
		}
	}
	for (auto i = 0; i < visibleOpses->size(); i++) {
		auto entity = java_cast< ObjectParticleSystemEntity* >(visibleOpses->get(i));
		if (entity->isPickable() == false)
			continue;

		if (filter != nullptr && filter->filterEntity(entity) == false)
			continue;

		if (lineSegment->doesBoundingBoxCollideWithLineSegment(entity->getBoundingBoxTransformed(), tmpVector3a, tmpVector3b, tmpVector3c, tmpVector3d) == true) {
			auto entityDistance = tmpVector3e->set(entity->getBoundingBoxTransformed()->getCenter())->sub(tmpVector3a)->computeLength();
			if (selectedEntity == nullptr || entityDistance < selectedEntityDistance) {
				selectedEntity = entity;
				selectedEntityDistance = entityDistance;
			}
		}
	}
	for (auto i = 0; i < visiblePpses->size(); i++) {
		auto entity = java_cast< PointsParticleSystemEntity* >(visiblePpses->get(i));
		if (entity->isPickable() == false)
			continue;

		if (filter != nullptr && filter->filterEntity(entity) == false)
			continue;

		if (lineSegment->doesBoundingBoxCollideWithLineSegment(entity->getBoundingBoxTransformed(), tmpVector3a, tmpVector3b, tmpVector3c, tmpVector3d) == true) {
			auto entityDistance = tmpVector3e->set(entity->getBoundingBoxTransformed()->getCenter())->sub(tmpVector3a)->computeLength();
			if (selectedEntity == nullptr || entityDistance < selectedEntityDistance) {
				selectedEntity = entity;
				selectedEntityDistance = entityDistance;
			}
		}
	}
	return selectedEntity;
}

void Engine::computeScreenCoordinateByWorldCoordinate(Vector3* worldCoordinate, Vector2* screenCoordinate)
{
	tmpMatrix4x4->set(modelViewMatrix)->multiply(projectionMatrix);
	tmpMatrix4x4->multiply(new Vector4(worldCoordinate, 1.0f), tmpVector4a);
	tmpVector4a->scale(1.0f / tmpVector4a->getW());
	auto screenCoordinateXYZW = tmpVector4a->getArray();
	screenCoordinate->setX(((*screenCoordinateXYZW)[0] + 1.0f) * width / 2.0f);
	screenCoordinate->setY(height - (((*screenCoordinateXYZW)[1] + 1.0f) * height / 2.0f));
}

void Engine::dispose()
{
	Iterator* entityKeys = entitiesById->getKeysIterator();
	auto entitiesToRemove = new _ArrayList();
	while (entityKeys->hasNext()) {
		auto entityKey = java_cast< String* >(entityKeys->next());
		entitiesToRemove->add(entityKey);
	}
	for (auto i = 0; i < entitiesToRemove->size(); i++) {
		removeEntity(java_cast< String* >(entitiesToRemove->get(i)));
	}
	if (shadowMapping != nullptr) {
		shadowMapping->dispose();
		shadowMapping = nullptr;
	}
	if (frameBuffer != nullptr) {
		frameBuffer->dispose();
		frameBuffer = nullptr;
	}
	gui->dispose();
	if (this == Engine::instance) {
		guiRenderer->dispose();
	}
}

void Engine::initGUIMode()
{
	if (frameBuffer != nullptr)
		frameBuffer->enableFrameBuffer();

	renderer->initGuiMode();
}

void Engine::doneGUIMode()
{
	renderer->doneGuiMode();
	if (frameBuffer != nullptr)
		FrameBuffer::disableFrameBuffer();

}

bool Engine::makeScreenshot(String* pathName, String* fileName)
{
	if (frameBuffer != nullptr)
		frameBuffer->enableFrameBuffer();

	auto pixels = renderer->readPixels(0, 0, width, height);
	if (pixels == nullptr)
		return false;

	// TODO: save to PNG

	if (frameBuffer != nullptr)
		FrameBuffer::disableFrameBuffer();

	return true;
}

extern java::lang::Class* class_(const char16_t* c, int n);

java::lang::Class* Engine::class_()
{
    static ::java::lang::Class* c = ::class_(u"tdme.engine.Engine", 18);
    return c;
}

void Engine::clinit()
{
	super::clinit();
	static bool in_cl_init = false;
	struct clinit_ {
		clinit_() {
			in_cl_init = true;
		instance = nullptr;
		textureManager = nullptr;
		vboManager = nullptr;
		meshManager = nullptr;
		guiRenderer = nullptr;
		animationProcessingTarget = Engine_AnimationProcessingTarget::CPU;
		shadowMappingShaderPre = nullptr;
		shadowMappingShaderRender = nullptr;
		lightingShader = nullptr;
		particlesShader = nullptr;
		guiShader = nullptr;
		}
	};

	if (!in_cl_init) {
		static clinit_ clinit_instance;
	}
}

java::lang::Class* Engine::getClass0()
{
	return class_();
}

