#pragma once

#include <vector>

#include <tdme/tdme.h>
#include <tdme/utilities/fwd-tdme.h>
#include <tdme/utilities/Buffer.h>
#include <tdme/utilities/FloatBuffer.h>
#include <tdme/utilities/IntBuffer.h>
#include <tdme/utilities/ShortBuffer.h>

using std::vector;

using tdme::utilities::Buffer;
using tdme::utilities::FloatBuffer;
using tdme::utilities::IntBuffer;
using tdme::utilities::ShortBuffer;

/**
 * Byte buffer class
 * @author Andreas Drewke
 */
class tdme::utilities::ByteBuffer: public Buffer
{
public:
	/**
	 * Allocate byte buffer
	 */
	inline static ByteBuffer* allocate(int64_t capacity) {
		return new ByteBuffer(capacity);
	}

	/**
	 * @return this buffer as float buffer
	 */
	inline FloatBuffer asFloatBuffer() {
		return FloatBuffer(this);
	}

	/**
	 * @return this buffer as int buffer
	 */
	inline IntBuffer asIntBuffer() {
		return IntBuffer(this);
	}

	/**
	 * @return this buffer as short buffer
	 */
	inline ShortBuffer asShortBuffer() {
		return ShortBuffer(this);
	}

	/**
	 * Move operator
	 * @param fromBuffer from buffer
	 * @return this buffer
	 */
	inline ByteBuffer& operator=(ByteBuffer&& fromBuffer) {
		// delete old buffer
		if (this->ownsBuffer == true && this->buffer != nullptr && this->buffer != fromBuffer.buffer) delete this->buffer;
		// do the move
		this->ownsBuffer = fromBuffer.ownsBuffer;
		this->buffer = fromBuffer.buffer;
		this->position = 0;
		fromBuffer.ownsBuffer = false;
		fromBuffer.buffer = nullptr;
		return *this;
	}

	/**
	 * Assign operator
	 * @param fromBuffer from buffer
	 * @return this buffer
	 */
	inline void operator=(const ByteBuffer& fromBuffer) {
		// delete old buffer
		if (this->ownsBuffer == true && this->buffer != nullptr && this->buffer != fromBuffer.buffer) delete this->buffer;
		// do the assign
		this->ownsBuffer = fromBuffer.ownsBuffer;
		this->buffer = nullptr;
		this->position = 0;
		if (this->ownsBuffer == true) {
			if (fromBuffer.buffer != nullptr) {
				this->buffer = new vector<uint8_t>(0);
				*this->buffer = *fromBuffer.buffer;
			}
		} else {
			this->buffer = fromBuffer.buffer;
		}
	}

	/**
	 * Move constructor
	 * @param fromBuffer from buffer
	 */
	inline ByteBuffer(ByteBuffer&& fromBuffer) {
		ownsBuffer = fromBuffer.ownsBuffer;
		buffer = fromBuffer.buffer;
		position = 0;
		fromBuffer.ownsBuffer = false;
		fromBuffer.buffer = nullptr;
	}

	/**
	 * Assign constructor
	 * @param fromBuffer from buffer
	 */
	inline ByteBuffer(const ByteBuffer& fromBuffer) {
		this->ownsBuffer = fromBuffer.ownsBuffer;
		this->buffer = nullptr;
		this->position = 0;
		if (this->ownsBuffer == true) {
			if (fromBuffer.buffer != nullptr) {
				this->buffer = new vector<uint8_t>(0);
				*this->buffer = *fromBuffer.buffer;
			}
		} else {
			this->buffer = fromBuffer.buffer;
		}
	}

	/**
	 * Public constructor
	 */
	inline ByteBuffer() : Buffer() {
	}

	/**
	 * Public constructor
	 * @param capacity capacity
	 */
	inline ByteBuffer(int64_t capacity) : Buffer(capacity) {
	}

	/**
	 * Public constructor
	 * @param data data
	 */
	inline ByteBuffer(const vector<uint8_t>& data) : Buffer(data) {
	}

};
