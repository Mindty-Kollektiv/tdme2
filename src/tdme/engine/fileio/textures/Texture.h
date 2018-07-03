#pragma once

#include <string>

#include <tdme/tdme.h>
#include <tdme/utils/fwd-tdme.h>
#include <tdme/engine/fileio/textures/fwd-tdme.h>

using std::string;

using tdme::utils::ByteBuffer;

/** 
 * Texture
 * @version $Id$
 * @author Andreas Drewke
 */
class tdme::engine::fileio::textures::Texture
{
public:

	/**
	 * Public constructor
	 * @param id
	 * @param depth
	 * @param width
	 * @param height
	 * @param texture width
	 * @param texture height
	 * @param texture data
	 */
	inline Texture(
		const string& id,
		int32_t depth,
		int32_t width, int32_t height,
		int32_t textureWidth, int32_t textureHeight,
		ByteBuffer* textureData)
		:
		id(id),
		depth(depth),
		width(width),
		height(height),
		textureWidth(textureWidth),
		textureHeight(textureHeight),
		textureData(textureData),
		useMipMap(true) {
		//
	}

	/**
	 * Destructor
	 */
	~Texture();

	/** 
	 * @return id
	 */
	inline const string& getId()  {
		return id;
	}

	/** 
	 * @return depth in bits per pixel
	 */
	inline int32_t getDepth() {
		return depth;
	}

	/** 
	 * @return image width
	 */
	inline int32_t getWidth() {
		return width;
	}

	/** 
	 * @return image height
	 */
	inline int32_t getHeight() {
		return height;
	}

	/** 
	 * @return texture height
	 */
	inline int32_t getTextureHeight() {
		return textureHeight;
	}

	/** 
	 * @return texture width
	 */
	inline int32_t getTextureWidth() {
		return textureWidth;
	}

	/** 
	 * @return texture data wrapped in a byte buffer
	 */
	inline ByteBuffer* getTextureData() {
		return textureData;
	}

	/**
	 * @return use mip map
	 */
	inline bool isUseMipMap() {
		return useMipMap;
	}

	/**
	 * Set if to use mip map
	 * @param mip map enabled
	 */
	inline void setUseMipMap(bool useMipMap) {
		this->useMipMap = useMipMap;
	}

private:
	string id;
	int32_t depth;
	int32_t width;
	int32_t height;
	int32_t textureHeight;
	int32_t textureWidth;
	ByteBuffer* textureData;
	bool useMipMap;
};
