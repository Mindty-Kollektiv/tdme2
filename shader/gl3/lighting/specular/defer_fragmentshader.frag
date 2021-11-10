#version 330 core

{$DEFINITIONS}

struct Material {
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec4 emission;
	float shininess;
	float reflection;
};

uniform Material material;

// passed from vertex shader
in vec2 vsFragTextureUV;
in vec3 vsNormal;
in vec3 vsPosition;
in vec3 vsTangent;
in vec3 vsBitangent;
in vec4 vsEffectColorMul;
in vec4 vsEffectColorAdd;
in vec3 vsEyeDirection;

#if defined(HAVE_TERRAIN_SHADER)
	in vec3 terrainVertex;
	in vec3 terrainNormal;
	in float terrainHeight;
	in float terrainSlope;
#else
	uniform sampler2D diffuseTextureUnit;
	uniform int diffuseTextureAvailable;
	uniform int diffuseTextureMaskedTransparency;
	uniform float diffuseTextureMaskedTransparencyThreshold;

	uniform int textureAtlasSize;
	uniform vec2 textureAtlasPixelDimension;

	uniform sampler2D specularTextureUnit;
	uniform int specularTextureAvailable;

	uniform sampler2D normalTextureUnit;
	uniform int normalTextureAvailable;

	// material shininess
	float materialShininess;
#endif

#if defined(HAVE_DEPTH_FOG)
	in float fragDepth;
#endif

// out
layout (location = 0) out vec3 outPosition;
layout (location = 1) out vec3 outNormal;
layout (location = 2) out vec4 outMaterialShininessReflectionFragDepthType;
layout (location = 3) out vec4 outMaterialAmbient;
layout (location = 4) out vec4 outMaterialDiffuse;
layout (location = 5) out vec4 outMaterialSpecular;
layout (location = 6) out vec4 outMaterialEmission;
layout (location = 7) out vec4 outDiffuse;

void main(void) {
	#if defined(HAVE_TERRAIN_SHADER)
		//
		outPosition = terrainVertex;
		outNormal = terrainNormal;
		#if defined(HAVE_DEPTH_FOG)
			outMaterialShininessReflectionFragDepthType = vec4(terrainHeight, terrainSlope, fragDepth, 1.0);
		#else
			outMaterialShininessReflectionFragDepthType = vec4(terrainHeight, terrainSlope, 0.0, 1.0);
		#endif
		#if defined(HAVE_SOLID_SHADING)
			outMaterialAmbient = vec4(1.0, 1.0, 1.0, 1.0);
			outMaterialDiffuse = vec4(0.0, 0.0, 0.0, 1.0);
			outMaterialSpecular = vec4(0.0, 0.0, 0.0, 1.0);;
			outMaterialEmission = vsEffectColorAdd;
		#else
			outMaterialAmbient = material.ambient;
			outMaterialDiffuse = material.diffuse;
			outMaterialSpecular = material.specular;
			outMaterialEmission = material.emission + vsEffectColorAdd;
		#endif
		outDiffuse = vsEffectColorMul;
	#else
		// texture coordinate, also take atlas into account
		vec2 fragTextureUV;
		if (textureAtlasSize > 1) {
			#define ATLAS_TEXTURE_BORDER	32
			vec2 diffuseTextureAtlasIdx = floor(vsFragTextureUV / 1000.0);
			vec2 diffuseTextureAtlasCoord = vsFragTextureUV - 500.0 - diffuseTextureAtlasIdx * 1000.0;
			vec2 diffuseTextureAtlasTextureDimensions = vec2(1.0 / float(textureAtlasSize));
			fragTextureUV =
				mod(diffuseTextureAtlasCoord, vec2(1.0 - textureAtlasPixelDimension)) /
				float(textureAtlasSize) *
				vec2((diffuseTextureAtlasTextureDimensions - (float(ATLAS_TEXTURE_BORDER) * 2.0 * textureAtlasPixelDimension)) / diffuseTextureAtlasTextureDimensions) +
				vec2(float(ATLAS_TEXTURE_BORDER) * textureAtlasPixelDimension) +
				diffuseTextureAtlasTextureDimensions * diffuseTextureAtlasIdx;
		} else {
			fragTextureUV = vsFragTextureUV;
		}

		// diffuse texture color
		vec4 diffuseTextureColor = vec4(1.0, 1.0, 1.0, 1.0);
		if (diffuseTextureAvailable == 1) {
			diffuseTextureColor = texture(diffuseTextureUnit, fragTextureUV);
			// check if to handle diffuse texture masked transparency
			if (diffuseTextureMaskedTransparency == 1) {
				// discard if beeing transparent
				if (diffuseTextureColor.a < diffuseTextureMaskedTransparencyThreshold) discard;
				// set to opqaue
				diffuseTextureColor.a = 1.0;
			}
		}

		// specular
		materialShininess = material.shininess;
		if (specularTextureAvailable == 1) {
			vec3 specularTextureValue = texture(specularTextureUnit, fragTextureUV).rgb;
			materialShininess =
				((0.33 * specularTextureValue.r) +
				(0.33 * specularTextureValue.g) +
				(0.33 * specularTextureValue.b)) * 255.0;
		}

		// compute normal
		vec3 normal = vsNormal;
		if (normalTextureAvailable == 1) {
			vec3 normalVector = normalize(texture(normalTextureUnit, fragTextureUV).rgb * 2.0 - 1.0);
			normal = vec3(0.0, 0.0, 0.0);
			normal+= vsTangent * normalVector.x;
			normal+= vsBitangent * normalVector.y;
			normal+= vsNormal * normalVector.z;
		}

		//
		outPosition = vsPosition;
		outNormal = normal;
		#if defined(HAVE_DEPTH_FOG)
			outMaterialShininessReflectionFragDepthType = vec4(materialShininess, material.reflection, fragDepth, 0.0);
		#else
			outMaterialShininessReflectionFragDepthType = vec4(materialShininess, material.reflection, 0.0, 0.0);
		#endif
		#if defined(HAVE_SOLID_SHADING)
			outMaterialAmbient = vec4(1.0, 1.0, 1.0, 1.0);
			outMaterialDiffuse = vec4(0.0, 0.0, 0.0, 1.0);
			outMaterialSpecular = vec4(0.0, 0.0, 0.0, 1.0);;
			outMaterialEmission = vsEffectColorAdd;
		#else
			outMaterialAmbient = material.ambient;
			outMaterialDiffuse = material.diffuse;
			outMaterialSpecular = material.specular;
			outMaterialEmission = material.emission + vsEffectColorAdd;
		#endif
		outDiffuse = diffuseTextureColor * vsEffectColorMul;
	#endif
	#if defined(HAVE_BACK)
		gl_FragDepth = 1.0;
	#endif
	#if defined(HAVE_FRONT)
		gl_FragDepth = 0.0;
	#endif
}
