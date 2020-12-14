#pragma once

#include <string>

#include <tdme/tdme.h>
#include <tdme/engine/fileio/textures/fwd-tdme.h>
#include <tdme/tools/shared/model/fwd-tdme.h>

using std::string;

using tdme::engine::fileio::textures::Texture;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_BoundingBoxParticleEmitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_CircleParticleEmitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_CircleParticleEmitterPlaneVelocity;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_Emitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_ObjectParticleSystem;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_PointParticleEmitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_SphereParticleEmitter;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem_Type;
using tdme::tools::shared::model::LevelEditorEntityParticleSystem;

/**
 * Point particle system
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::tools::shared::model::LevelEditorEntityParticleSystem_PointParticleSystem final
{
private:
	int maxPoints{ 4000 };
	float pointSize{ 0.1f };
	string textureFileName;
	string transparencyTextureFileName;
	Texture* texture { nullptr };
	int textureHorizontalSprites{ 1 };
	int textureVerticalSprites{ 1 };
	bool autoEmit{ true };
	float textureSpritesFPS { 10.0f };

public:
	/**
	 * Public constructor
	 */
	LevelEditorEntityParticleSystem_PointParticleSystem();

	/**
	 * Public destructor
	 */
	~LevelEditorEntityParticleSystem_PointParticleSystem();

	/**
	 * @return max points
	 */
	inline int getMaxPoints() {
		return maxPoints;
	}

	/**
	 * Set max points
	 * @param maxPoints max points
	 */
	inline void setMaxPoints(int maxPoints) {
		this->maxPoints = maxPoints;
	}

	/**
	 * @return point size
	 */
	inline float getPointSize() {
		return pointSize;
	}

	/**
	 * Set point size
	 * @param pointSize point size
	 */
	inline void setPointSize(float pointSize) {
		this->pointSize = pointSize;
	}

	/**
	 * @return texture
	 */
	inline Texture* getTexture() {
		return texture;
	}

	/**
	 * @return texture file name
	 */
	inline const string& getTextureFileName() {
		return textureFileName;
	}

	/**
	 * @return transparency texture file name
	 */
	inline const string& getTransparencyTextureFileName() {
		return transparencyTextureFileName;
	}

	/**
	 * Set texture file name with optional transparency texture
	 * @param textureFileName texture file name
	 * @param transparencyTextureFileName transparency texture file name
	 */
	void setTextureFileName(const string& textureFileName, const string& transparencyTextureFileName = string());

	/**
	 * @return horizontal number of sprites in texture
	 */
	inline int getTextureHorizontalSprites() {
		return textureHorizontalSprites;
	}

	/**
	 * Set texture horizontal number of sprites
	 * @param textureHorizontalSprites horizontal number of sprites
	 */
	inline void setTextureHorizontalSprites(int textureHorizontalSprites) {
		this->textureHorizontalSprites = textureHorizontalSprites;
	}

	/**
	 * @return vertical number of sprites in texture
	 */
	inline int getTextureVerticalSprites() {
		return textureVerticalSprites;
	}

	/**
	 * Set texture vertical number of sprites
	 * @param textureVerticalSprites vertical number of sprites
	 */
	inline void setTextureVerticalSprites(int textureVerticalSprites) {
		this->textureVerticalSprites = textureVerticalSprites;
	}

	/**
	 * @return texture sprites frames per second
	 */
	inline float getTextureSpritesFPS() {
		return textureSpritesFPS;
	}

	/**
	 * Set texture sprites frames per second
	 * @param textureSpritesFPS frames per second
	 */
	inline void setTextureSpritesFPS(float textureSpritesFPS) {
		this->textureSpritesFPS = textureSpritesFPS;
	}

	/**
	 * @return is auto emit
	 */
	inline bool isAutoEmit() {
		return autoEmit;
	}

	/**
	 * Set auto emit
	 * @param autoEmit auto emit
	 */
	inline void setAutoEmit(bool autoEmit) {
		this->autoEmit = autoEmit;
	}

};
