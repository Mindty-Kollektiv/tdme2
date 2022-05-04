#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/engine/fileio/textures/fwd-tdme.h>
#include <tdme/utilities/fwd-tdme.h>

using std::string;
using std::unordered_map;
using std::vector;

using tdme::engine::fileio::textures::Texture;

/**
 * Texture atlas
 * @author Andreas Drewke
 */
class tdme::utilities::TextureAtlas {
public:
	static constexpr int TEXTURE_IDX_NONE { -1 };
	static constexpr int ATLAS_TEXTURE_SIZE { 512 };
	static constexpr int ATLAS_TEXTURE_BORDER { 32 };

	/**
	 * Public constructor
	 * @param id texture id
	 */
	TextureAtlas(const string& id);

	/**
	 * Public destructor
	 */
	~TextureAtlas();

	/**
	 * Returns specific atlas texture index within atlas
	 * @param texture texture
	 * @return atlas texture id
	 */
	inline int getTextureIdx(Texture* texture) {
		auto it = textureToAtlasTextureIdxMapping.find(texture);
		if (it == textureToAtlasTextureIdxMapping.end()) {
			return TEXTURE_IDX_NONE;
		}
		return it->second;
	}

	/**
	 * Add texture
	 * @param texture texture
	 * @return atlas texture id
	 */
	int addTexture(Texture* texture);

	/**
	 * Remove texture
	 * @param texture texture
	 */
	void removeTexture(Texture* texture);

	/**
	 * Update texture atlas
	 */
	void update();

	/**
	 * @return is needing update
	 */
	inline bool isNeedsUpdate() {
		return needsUpdate;
	}

	/**
	 * @return atlas texture
	 */
	inline Texture* getAtlasTexture() {
		return atlasTexture;
	}

private:
	bool needsUpdate { false };
	string atlasTextureId;
	Texture* atlasTexture { nullptr };
	unordered_map<Texture*, int> textureReferenceCounter;
	unordered_map<Texture*, int> textureToAtlasTextureIdxMapping;
	unordered_map<int, Texture*> atlasTextureIdxToTextureMapping;
	vector<int> freeTextureIds;
};
