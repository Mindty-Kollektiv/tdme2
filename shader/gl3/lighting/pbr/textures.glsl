in vec2 v_UVCoord1;
in vec2 v_UVCoord2;

// General Material
uniform int u_NormalSamplerAvailable;
uniform sampler2D u_NormalSampler;
uniform float u_NormalScale;

#ifdef HAS_EMISSIVE_MAP
uniform sampler2D u_EmissiveSampler;
uniform int u_EmissiveUVSet;
uniform vec3 u_EmissiveFactor;
uniform mat3 u_EmissiveUVTransform;
#endif

#ifdef HAS_OCCLUSION_MAP
uniform sampler2D u_OcclusionSampler;
uniform int u_OcclusionUVSet;
uniform float u_OcclusionStrength;
uniform mat3 u_OcclusionUVTransform;
#endif

#ifdef MATERIAL_METALLICROUGHNESS
// Metallic Roughness Material
uniform int u_BaseColorSamplerAvailable;
uniform sampler2D u_BaseColorSampler;
#endif

uniform int u_MetallicRoughnessSamplerAvailable;
uniform sampler2D u_MetallicRoughnessSampler;

// Specular Glossiness Material
#ifdef HAS_DIFFUSE_MAP
uniform sampler2D u_DiffuseSampler;
uniform int u_DiffuseUVSet;
uniform mat3 u_DiffuseUVTransform;
#endif

#ifdef HAS_SPECULAR_GLOSSINESS_MAP
uniform sampler2D u_SpecularGlossinessSampler;
uniform int u_SpecularGlossinessUVSet;
uniform mat3 u_SpecularGlossinessUVTransform;
#endif

// IBL
#ifdef USE_IBL
uniform samplerCube u_DiffuseEnvSampler;
uniform samplerCube u_SpecularEnvSampler;
uniform sampler2D u_brdfLUT;
#endif

vec2 getNormalUV()
{
    return v_UVCoord1;
}

vec4 getNormalColor()
{
    return texture(u_NormalSampler, getNormalUV());
}

#ifdef HAS_EMISSIVE_MAP
vec2 getEmissiveUV()
{
    vec3 uv = vec3(v_UVCoord1, 1.0);
    uv.xy = u_EmissiveUVSet < 1 ? v_UVCoord1 : v_UVCoord2;
    #ifdef HAS_EMISSIVE_UV_TRANSFORM
    uv *= u_EmissiveUVTransform;
    #endif
    return uv.xy;
}

vec4 getEmissiveColor()
{
	return texture(u_EmissiveSampler, getEmissiveUV());
}
#endif

#ifdef HAS_OCCLUSION_MAP
vec2 getOcclusionUV()
{
    vec3 uv = vec3(v_UVCoord1, 1.0);
    uv.xy = u_OcclusionUVSet < 1 ? v_UVCoord1 : v_UVCoord2;
    #ifdef HAS_OCCLSION_UV_TRANSFORM
    uv *= u_OcclusionUVTransform;
    #endif
    return uv.xy;
}

vec4 getOcclusionColor()
{
	return texture(u_OcclusionSampler,  getOcclusionUV());
}
#endif

vec2 getBaseColorUV()
{
    return v_UVCoord1;
}

vec4 getBaseColor()
{
    return texture(u_BaseColorSampler, getBaseColorUV());
}

#ifdef MATERIAL_METALLICROUGHNESS
vec2 getMetallicRoughnessUV()
{
    return v_UVCoord1;
}

vec4 getMetallicRoughnessColor()
{
    return texture(u_MetallicRoughnessSampler, getMetallicRoughnessUV());
}
#endif

#ifdef HAS_SPECULAR_GLOSSINESS_MAP
vec2 getSpecularGlossinessUV()
{
    vec3 uv = vec3(v_UVCoord1, 1.0);
    uv.xy = u_SpecularGlossinessUVSet < 1 ? v_UVCoord1 : v_UVCoord2;
    #ifdef HAS_SPECULARGLOSSINESS_UV_TRANSFORM
    uv *= u_SpecularGlossinessUVTransform;
    #endif
    return uv.xy;
}

vec4 getSpecularGlossinessColor() {
	return texture(u_SpecularGlossinessSampler, getSpecularGlossinessUV());
}
#endif

#ifdef HAS_DIFFUSE_MAP
vec2 getDiffuseUV()
{
    vec3 uv = vec3(v_UVCoord1, 1.0);
    uv.xy = u_DiffuseUVSet < 1 ? v_UVCoord1 : v_UVCoord2;
    #ifdef HAS_DIFFUSE_UV_TRANSFORM
    uv *= u_DiffuseUVTransform;
    #endif
    return uv.xy;
}

vec4 getDiffuseColor()
{
	return texture(u_DiffuseSampler, getDiffuseUV());
}
#endif