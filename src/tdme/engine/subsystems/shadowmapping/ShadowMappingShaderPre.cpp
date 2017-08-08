// Generated from /tdme/src/tdme/engine/subsystems/shadowmapping/ShadowMappingShaderPre.java
#include <tdme/engine/subsystems/shadowmapping/ShadowMappingShaderPre.h>

#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <tdme/engine/subsystems/renderer/GLRenderer.h>
#include <tdme/math/Matrix4x4.h>

using tdme::engine::subsystems::shadowmapping::ShadowMappingShaderPre;
using java::lang::String;
using java::lang::StringBuilder;
using tdme::engine::subsystems::renderer::GLRenderer;
using tdme::math::Matrix4x4;

ShadowMappingShaderPre::ShadowMappingShaderPre(const ::default_init_tag&)
	: super(*static_cast< ::default_init_tag* >(0))
{
	clinit();
}

ShadowMappingShaderPre::ShadowMappingShaderPre(GLRenderer* renderer) 
	: ShadowMappingShaderPre(*static_cast< ::default_init_tag* >(0))
{
	ctor(renderer);
}

void ShadowMappingShaderPre::ctor(GLRenderer* renderer)
{
	super::ctor();
	this->renderer = renderer;
	initialized = false;
}

bool ShadowMappingShaderPre::isInitialized()
{
	return initialized;
}

void ShadowMappingShaderPre::initialize()
{
	auto rendererVersion = renderer->getGLVersion();
	preVertexShaderGlId = renderer->loadShader(renderer->SHADER_VERTEX_SHADER, ::java::lang::StringBuilder().append(u"shader/"_j)->append(rendererVersion)
		->append(u"/shadowmapping"_j)->toString(), u"pre_vertexshader.c"_j);
	if (preVertexShaderGlId == 0)
		return;

	preFragmentShaderGlId = renderer->loadShader(renderer->SHADER_FRAGMENT_SHADER, ::java::lang::StringBuilder().append(u"shader/"_j)->append(rendererVersion)
		->append(u"/shadowmapping"_j)->toString(), u"pre_fragmentshader.c"_j);
	if (preFragmentShaderGlId == 0)
		return;

	preProgramGlId = renderer->createProgram();
	renderer->attachShaderToProgram(preProgramGlId, preVertexShaderGlId);
	renderer->attachShaderToProgram(preProgramGlId, preFragmentShaderGlId);
	if (renderer->isUsingProgramAttributeLocation() == true) {
		renderer->setProgramAttributeLocation(preProgramGlId, 0, u"inVertex"_j);
		renderer->setProgramAttributeLocation(preProgramGlId, 1, u"inNormal"_j);
		renderer->setProgramAttributeLocation(preProgramGlId, 2, u"inTextureUV"_j);
	}
	if (renderer->linkProgram(preProgramGlId) == false)
		return;

	preUniformMVPMatrix = renderer->getProgramUniformLocation(preProgramGlId, L"mvpMatrix");
	if (preUniformMVPMatrix == -1)
		return;

	initialized = true;
}

void ShadowMappingShaderPre::useProgram()
{
	renderer->useProgram(preProgramGlId);
}

void ShadowMappingShaderPre::unUseProgram()
{
}

void ShadowMappingShaderPre::setProgramMVPMatrix(Matrix4x4* mvpMatrix)
{
	renderer->setProgramUniformFloatMatrix4x4(preUniformMVPMatrix, mvpMatrix->getArray());
}

extern java::lang::Class* class_(const char16_t* c, int n);

java::lang::Class* ShadowMappingShaderPre::class_()
{
    static ::java::lang::Class* c = ::class_(u"tdme.engine.subsystems.shadowmapping.ShadowMappingShaderPre", 59);
    return c;
}

java::lang::Class* ShadowMappingShaderPre::getClass0()
{
	return class_();
}

