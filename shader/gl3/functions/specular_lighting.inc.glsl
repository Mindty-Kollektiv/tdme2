// Based on:
//	of some code of 3Dlabs Inc. Ltd.
//	and http://stackoverflow.com/questions/11365399/opengl-shader-a-spotlight-and-a-directional-light?answertab=active#tab-top
/************************************************************************
*                                                                       *
*                                                                       *
*        Copyright (C) 2002-2004  3Dlabs Inc. Ltd.                      *
*                                                                       *
*                        All rights reserved.                           *
*                                                                       *
* Redistribution and use in source and binary forms, with or without    *
* modification, are permitted provided that the following conditions    *
* are met:                                                              *
*                                                                       *
*     Redistributions of source code must retain the above copyright    *
*     notice, this list of conditions and the following disclaimer.     *
*                                                                       *
*     Redistributions in binary form must reproduce the above           *
*     copyright notice, this list of conditions and the following       *
*     disclaimer in the documentation and/or other materials provided   *
*     with the distribution.                                            *
*                                                                       *
*     Neither the name of 3Dlabs Inc. Ltd. nor the names of its         *
*     contributors may be used to endorse or promote products derived   *
*     from this software without specific prior written permission.     *
*                                                                       *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS   *
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS     *
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE        *
* COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, *
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  *
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER      *
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT    *
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN     *
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                           *
*                                                                       *
************************************************************************/

struct Light {
	int enabled;
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec4 position;
	vec3 spotDirection;
	float spotExponent;
	float spotCosCutoff;
	float constantAttenuation;
	float linearAttenuation;
	float quadraticAttenuation;
	float radius;
};

#define FALSE		0
#define MAX_LIGHTS	8

uniform Light lights[MAX_LIGHTS];

//
vec4 computeSpecularLight(in int i, in vec3 normal, in vec3 position, in vec3 eyeDirection, in Material inMaterial) {
	vec3 lightDirection = lights[i].position.xyz - position.xyz;
	float lightDistance = length(lightDirection);
	lightDirection = normalize(lightDirection);
	vec3 reflectionDirection = normalize(reflect(-lightDirection, normal));

	// compute attenuation
	float lightAttenuation =
		1.0 /
		(
			lights[i].constantAttenuation +
			lights[i].linearAttenuation * lightDistance +
			lights[i].quadraticAttenuation * lightDistance * lightDistance
		);

	// see if point on surface is inside cone of illumination
	float lightSpotDot = dot(-lightDirection, normalize(lights[i].spotDirection));
	float lightSpotAttenuation = 0.0;
	if (lightSpotDot >= lights[i].spotCosCutoff) {
		lightSpotAttenuation = pow(lightSpotDot, lights[i].spotExponent);
	}

	// Combine the spotlight and distance attenuation.
	lightAttenuation *= lightSpotAttenuation;

	// add color components to fragment color
	return
		clamp(lights[i].ambient * inMaterial.ambient, 0.0, 1.0) +
		clamp(lights[i].diffuse * inMaterial.diffuse * max(dot(normal, lightDirection), 0.0) * lightAttenuation, 0.0, 1.0) +
		clamp(lights[i].specular * inMaterial.specular * pow(max(dot(reflectionDirection, eyeDirection), 0.0), 0.3 * inMaterial.shininess) * lightAttenuation, 0.0, 1.0);
}

//
vec4 computeSpecularLighting(in vec3 normal, in vec3 position, in vec3 eyeDirection, in Material inMaterial) {
	vec4 fragColor = vec4(0.0, 0.0, 0.0, 0.0);
	// process each light
	for (int i = 0; i < MAX_LIGHTS; i++) {
		// skip on disabled lights
		if (lights[i].enabled == FALSE || (lights[i].radius > 0.0 && length(lights[i].position.xyz - position.xyz) > lights[i].radius)) continue;

		// compute light
		fragColor+= computeSpecularLight(i, normal, position, eyeDirection, inMaterial);
	}
	//
	return fragColor;
}
