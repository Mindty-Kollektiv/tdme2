// Generated from /Library/Java/JavaVirtualMachines/1.6.0.jdk/Contents/Classes/classes.jar

#pragma once

#include <tdme/utils/fwd-tdme.h>

#include <vector>

using std::vector;

/**
 * Buffer
 */
class tdme::utils::Buffer
{
private:
	bool createdBuffer;
	int32_t position { 0 };
	vector<uint8_t>* buffer { nullptr };

public:

	/**
	 * Clear
	 */
	inline Buffer* clear() {
		position = 0;
		return this;
	}

	/**
	 * @returns capacity
	 */
	inline virtual int32_t getCapacity() {
		return buffer->size();
	}

	/**
	 * @returns position
	 */
	inline virtual int32_t getPosition() {
		return position;
	}

	/**
	 * @returns value at given position
	 * @param position
	 */
	inline uint8_t get(int32_t position) {
		return (*buffer)[position];
	}

	/**
	 * Put value into buffer
	 */
	inline Buffer* put(uint8_t value) {
		(*buffer)[position++] = value;
		return this;
	}

	/**
	 * @returns pointer to underlying data
	 */
	inline uint8_t* getBuffer() {
		return buffer->data();
	}

	/**
	 * Public constructor
	 * @param capacity
	 */
	inline Buffer(int32_t capacity) {
		this->createdBuffer = true;
		this->position = 0;
		this->buffer = new vector<uint8_t>(capacity);
	}

	/**
	 * Public constructor
	 * @param buffer
	 */
	inline Buffer(Buffer* buffer) {
		this->createdBuffer = false;
		this->position = 0;
		this->buffer = buffer->buffer;
	}

	/**
	 * Public constructor
	 * @param data
	 */
	inline Buffer(vector<uint8_t>* data) {
		this->createdBuffer = false;
		this->position = 0;
		this->buffer = data;
	}

	/**
	 * Destructor
	 */
	inline ~Buffer() {
		if (createdBuffer == true) {
			delete this->buffer;
		}
	}
};
