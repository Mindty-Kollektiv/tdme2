#version 330

uniform sampler2D diffuseTextureUnits[16];

flat in int vsTextureIndex;
flat in int vsSpriteIndex;
flat in vec4 vsColor;
flat in ivec2 vsSpriteSheetDimension;
flat in vec4 vsEffectColorMul;
flat in vec4 vsEffectColorAdd;

out vec4 outColor;

#if defined(HAVE_DEPTH_FOG)
	#define FOG_DISTANCE_NEAR			100.0
	#define FOG_DISTANCE_MAX			250.0
	#define FOG_RED						(255.0 / 255.0)
	#define FOG_GREEN					(255.0 / 255.0)
	#define FOG_BLUE					(255.0 / 255.0)
	in float fragDepth;
#endif

void main(void) {
	vec2 spriteCoord =
		gl_PointCoord / vsSpriteSheetDimension +
		vec2(
			(1.0 / float(vsSpriteSheetDimension.x)) * int(vsSpriteIndex % vsSpriteSheetDimension.x), 
			1.0 - ((1.0 / float(vsSpriteSheetDimension.y)) * int(vsSpriteIndex / vsSpriteSheetDimension.y))
		);
	if (vsTextureIndex == 0)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[0], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 1)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[1], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 2)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[2], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 3)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[3], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 4)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[4], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 5)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[5], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 6)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[6], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 7)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[7], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 8)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[8], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 9)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[9], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 10)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[10], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 11)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[11], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 12)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[12], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 13)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[13], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 14)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[14], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0); else
	if (vsTextureIndex == 15)
		outColor = clamp(vsEffectColorAdd + texture(diffuseTextureUnits[15], spriteCoord) * vsColor * vsEffectColorMul, 0.0, 1.0);
	#if defined(HAVE_DEPTH_FOG)
		if (fragDepth > FOG_DISTANCE_NEAR) {
			float fogStrength = (clamp(fragDepth, FOG_DISTANCE_NEAR, FOG_DISTANCE_MAX) - FOG_DISTANCE_NEAR) * 1.0 / (FOG_DISTANCE_MAX - FOG_DISTANCE_NEAR);
			outColor = vec4(
				(outColor.rgb * (1.0 - fogStrength)) +
				vec3(FOG_RED, FOG_GREEN, FOG_BLUE) * fogStrength,
				outColor.a
			);
		}
	#endif
}
