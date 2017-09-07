// Generated from /tdme/src/tdme/tools/shared/model/LevelEditorEntityParticleSystem.java
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem.h>

#include <java/lang/String.h>
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem_BoundingBoxParticleEmitter.h>
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem_CircleParticleEmitter.h>
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem_CircleParticleEmitterPlaneVelocity.h>
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem_Emitter.h>
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem_ObjectParticleSystem.h>
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem_PointParticleEmitter.h>
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem_PointParticleSystem.h>
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem_SphereParticleEmitter.h>
#include <tdme/tools/shared/model/LevelEditorEntityParticleSystem_Type.h>
#include <tdme/utils/_Console.h>

using tdme::tools::shared::model::LevelEditorEntityParticleSystem;
using java::lang::String;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_BoundingBoxParticleEmitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_CircleParticleEmitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_CircleParticleEmitterPlaneVelocity;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_Emitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_ObjectParticleSystem;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_PointParticleEmitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_PointParticleSystem;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_SphereParticleEmitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_Type;
using tdme::utils::_Console;

LevelEditorEntityParticleSystem::LevelEditorEntityParticleSystem() 
{
	type = LevelEditorEntityParticleSystem_Type::NONE;
	ops = nullptr;
	pps = nullptr;
	emitter = LevelEditorEntityParticleSystem_Emitter::NONE;
	ppe = nullptr;
	bbpe = nullptr;
	cpe = nullptr;
	cpepv = nullptr;
	spe = nullptr;
}

LevelEditorEntityParticleSystem_Type* LevelEditorEntityParticleSystem::getType()
{
	return type;
}

void LevelEditorEntityParticleSystem::setType(LevelEditorEntityParticleSystem_Type* type)
{
	{
		auto v = this->type;
		if ((v == LevelEditorEntityParticleSystem_Type::NONE)) {
			goto end_switch0;;
		}
		if ((v == LevelEditorEntityParticleSystem_Type::OBJECT_PARTICLE_SYSTEM)) {
			ops = nullptr;
			goto end_switch0;;
		}
		if ((v == LevelEditorEntityParticleSystem_Type::POINT_PARTICLE_SYSTEM)) {
			pps = nullptr;
			goto end_switch0;;
		}
		if ((((v != LevelEditorEntityParticleSystem_Type::NONE) && (v != LevelEditorEntityParticleSystem_Type::OBJECT_PARTICLE_SYSTEM) && (v != LevelEditorEntityParticleSystem_Type::POINT_PARTICLE_SYSTEM)))) {
			_Console::println(wstring(L"LevelEditorEntityParticleSystem::setType(): unknown type '" + this->type->toWString() + L"'"));
		}
		end_switch0:;
	}

	this->type = type;
	{
		auto v = this->type;
		if ((v == LevelEditorEntityParticleSystem_Type::NONE)) {
			goto end_switch1;;
		}
		if ((v == LevelEditorEntityParticleSystem_Type::OBJECT_PARTICLE_SYSTEM)) {
			ops = new LevelEditorEntityParticleSystem_ObjectParticleSystem();
			goto end_switch1;;
		}
		if ((v == LevelEditorEntityParticleSystem_Type::POINT_PARTICLE_SYSTEM)) {
			pps = new LevelEditorEntityParticleSystem_PointParticleSystem();
			goto end_switch1;;
		}
		if ((((v != LevelEditorEntityParticleSystem_Type::NONE) && (v != LevelEditorEntityParticleSystem_Type::OBJECT_PARTICLE_SYSTEM) && (v != LevelEditorEntityParticleSystem_Type::POINT_PARTICLE_SYSTEM)))) {
			_Console::println(wstring(L"LevelEditorEntityParticleSystem::setType(): unknown type '" + this->type->toWString() + L"'"));
		}
		end_switch1:;
	}

}

LevelEditorEntityParticleSystem_ObjectParticleSystem* LevelEditorEntityParticleSystem::getObjectParticleSystem()
{
	return ops;
}

LevelEditorEntityParticleSystem_PointParticleSystem* LevelEditorEntityParticleSystem::getPointParticleSystem()
{
	return pps;
}

LevelEditorEntityParticleSystem_Emitter* LevelEditorEntityParticleSystem::getEmitter()
{
	return emitter;
}

void LevelEditorEntityParticleSystem::setEmitter(LevelEditorEntityParticleSystem_Emitter* emitter)
{
	{
		auto v = this->emitter;
		if ((v == LevelEditorEntityParticleSystem_Emitter::NONE)) {
			goto end_switch2;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::POINT_PARTICLE_EMITTER)) {
			ppe = nullptr;
			goto end_switch2;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::BOUNDINGBOX_PARTICLE_EMITTER)) {
			bbpe = nullptr;
			goto end_switch2;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER)) {
			cpe = nullptr;
			goto end_switch2;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER_PLANE_VELOCITY)) {
			cpepv = nullptr;
			goto end_switch2;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::SPHERE_PARTICLE_EMITTER)) {
			spe = nullptr;
			goto end_switch2;;
		}
		if ((((v != LevelEditorEntityParticleSystem_Emitter::NONE) && (v != LevelEditorEntityParticleSystem_Emitter::POINT_PARTICLE_EMITTER) && (v != LevelEditorEntityParticleSystem_Emitter::BOUNDINGBOX_PARTICLE_EMITTER) && (v != LevelEditorEntityParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER) && (v != LevelEditorEntityParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER_PLANE_VELOCITY) && (v != LevelEditorEntityParticleSystem_Emitter::SPHERE_PARTICLE_EMITTER)))) {
			_Console::println(wstring(L"LevelEditorEntityParticleSystem::setEmitter(): unknown emitter '" + this->emitter->toWString() + L"'"));
		}
		end_switch2:;
	}

	this->emitter = emitter;
	{
		auto v = this->emitter;
		if ((v == LevelEditorEntityParticleSystem_Emitter::NONE)) {
			goto end_switch3;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::POINT_PARTICLE_EMITTER)) {
			ppe = new LevelEditorEntityParticleSystem_PointParticleEmitter();
			goto end_switch3;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::BOUNDINGBOX_PARTICLE_EMITTER)) {
			bbpe = new LevelEditorEntityParticleSystem_BoundingBoxParticleEmitter();
			goto end_switch3;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER)) {
			cpe = new LevelEditorEntityParticleSystem_CircleParticleEmitter();
			goto end_switch3;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER_PLANE_VELOCITY)) {
			cpepv = new LevelEditorEntityParticleSystem_CircleParticleEmitterPlaneVelocity();
			goto end_switch3;;
		}
		if ((v == LevelEditorEntityParticleSystem_Emitter::SPHERE_PARTICLE_EMITTER)) {
			spe = new LevelEditorEntityParticleSystem_SphereParticleEmitter();
			goto end_switch3;;
		}
		if ((((v != LevelEditorEntityParticleSystem_Emitter::NONE) && (v != LevelEditorEntityParticleSystem_Emitter::POINT_PARTICLE_EMITTER) && (v != LevelEditorEntityParticleSystem_Emitter::BOUNDINGBOX_PARTICLE_EMITTER) && (v != LevelEditorEntityParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER) && (v != LevelEditorEntityParticleSystem_Emitter::CIRCLE_PARTICLE_EMITTER_PLANE_VELOCITY) && (v != LevelEditorEntityParticleSystem_Emitter::SPHERE_PARTICLE_EMITTER)))) {
			_Console::println(wstring(L"LevelEditorEntityParticleSystem::setEmitter(): unknown emitter '" + this->emitter->toWString() + L"'"));
		}
		end_switch3:;
	}

}

LevelEditorEntityParticleSystem_PointParticleEmitter* LevelEditorEntityParticleSystem::getPointParticleEmitter()
{
	return ppe;
}

LevelEditorEntityParticleSystem_BoundingBoxParticleEmitter* LevelEditorEntityParticleSystem::getBoundingBoxParticleEmitters()
{
	return bbpe;
}

LevelEditorEntityParticleSystem_CircleParticleEmitter* LevelEditorEntityParticleSystem::getCircleParticleEmitter()
{
	return cpe;
}

LevelEditorEntityParticleSystem_CircleParticleEmitterPlaneVelocity* LevelEditorEntityParticleSystem::getCircleParticleEmitterPlaneVelocity()
{
	return cpepv;
}

LevelEditorEntityParticleSystem_SphereParticleEmitter* LevelEditorEntityParticleSystem::getSphereParticleEmitter()
{
	return spe;
}
