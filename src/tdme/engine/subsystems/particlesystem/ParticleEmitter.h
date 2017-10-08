
#pragma once

#include <tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/model/fwd-tdme.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/engine/subsystems/particlesystem/fwd-tdme.h>
#include <tdme/math/fwd-tdme.h>

using tdme::engine::Transformations;
using tdme::engine::model::Color4;
using tdme::engine::subsystems::particlesystem::Particle;
using tdme::math::Vector3;

/** 
 * Particle Emitter Interface
 * @author Andreas Drewke
 * @version $Id$
 */
struct tdme::engine::subsystems::particlesystem::ParticleEmitter
{

	/** 
	 * @return number of particles to emit in one second
	 */
	virtual int32_t getCount() = 0;

	/** 
	 * @return color start
	 */
	virtual Color4& getColorStart() = 0;

	/** 
	 * @return color end
	 */
	virtual Color4& getColorEnd() = 0;

	/** 
	 * Emits particles
	 * @param particle
	 */
	virtual void emit(Particle* particle) = 0;

	/** 
	 * Update transformation with given transformations
	 * @param transformations
	 */
	virtual void fromTransformations(Transformations* transformations) = 0;
};
