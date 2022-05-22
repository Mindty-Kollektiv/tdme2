#pragma once

#include <string>
#include <string_view>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/utilities/fwd-tdme.h>

using std::string;
using std::string_view;
using std::vector;

/**
 * String tools class
 * @author Andreas Drewke
 */
class tdme::utilities::StringTools final
{
public:

	/**
	 * UTF8 string character iterator
	 */
	class UTF8CharacterIterator {
	public:
		/**
		 * Public constructor
		 */
		UTF8CharacterIterator(const string& stringReference): stringReference(stringReference) {
			//
		}

		/**
		 * @return underlying buffer position
		 */
		inline int getPosition() {
			return position;
		}

		/**
		 * Set underlying buffer position
		 * @param position underlying buffer position
		 */
		inline void setPosition(int position) {
			this->position = position;
		}

		/**
		 * Seek character position
		 * @param characterPosition character position
		 */
		inline void seek(int characterPosition) {
			position = 0;
			for (auto i = 0; i < characterPosition; i++) {
				if (hasNext() == true) next();
			}
		}

		/**
		 * @return next code point available
		 */
		inline bool hasNext() {
			return position < stringReference.size() && error == false;
		}
		/**
		 * @return next code point
		 */
		int next() {
			// see: http://www.zedwood.com/article/cpp-utf8-char-to-codepoint
			int l = stringReference.size() - position;
			if (l < 1) return -1;
			unsigned char u0 = stringReference[position + 0];
			if (u0 >= 0 && u0 <= 127) {
				position++;
				return u0;
			}
			if (l < 2) {
				position++;
				return -1;
			}
			unsigned char u1 = stringReference[position + 1];
			if (u0 >= 192 && u0 <= 223) {
				position+= 2;
				return (u0 - 192) * 64 + (u1 - 128);
			}
			if (stringReference[position + 0] == 0xed && (stringReference[position + 1] & 0xa0) == 0xa0) {
				position+= 2;
				return -1; // code points, 0xd800 to 0xdfff
			}
			if (l < 3) {
				position+= 2;
				return -1;
			}
			unsigned char u2 = stringReference[position + 2];
			if (u0 >= 224 && u0 <= 239) {
				position+= 3;
				return (u0 - 224) * 4096 + (u1 - 128) * 64 + (u2 - 128);
			}
			if (l < 4) {
				position+= 3;
				return -1;
			}
			unsigned char u3 = stringReference[position + 3];
			if (u0 >= 240 && u0 <= 247) {
				position+= 4;
				return (u0 - 240) * 262144 + (u1 - 128) * 4096 + (u2 - 128) * 64 + (u3 - 128);
			}
			//
			position+= 4;
			return -1;
		}

	private:
		const string& stringReference;
		int position { 0 };
		bool error { false };
	};

	/**
	 * Checks if string starts with prefix
	 * @param src source string
     * @param prefix prefix string
	 * @return bool
	 */
	inline static const bool startsWith(const string& src, const string& prefix) {
		return src.find(prefix) == 0;
	}

	/**
	 * Checks if string starts with prefix
	 * @param src source string
     * @param prefix prefix string
	 * @return bool
	 */
	inline static const bool viewStartsWith(const string_view& src, const string& prefix) {
		return src.find(prefix) == 0;
	}

	/**
	 * Checks if string ends with suffix
	 * @param src source string
     * @param suffix suffix string
	 * @return bool
	 */
	inline static const bool endsWith(const string& src, const string& suffix) {
		return
			src.size() >= suffix.size() &&
			src.compare(src.size() - suffix.size(), suffix.size(), suffix) == 0;
	}

	/**
	 * Checks if string ends with suffix
	 * @param src source string
     * @param suffix suffix string
	 * @return bool
	 */
	inline static const bool viewEndsWith(const string_view& src, const string& suffix) {
		return
			src.size() >= suffix.size() &&
			src.compare(src.size() - suffix.size(), suffix.size(), suffix) == 0;
	}

	/**
	 * Replace char with another char
	 * @param src source string to be processed
	 * @param what what to replace
	 * @param by to replace by
	 * @param beginIndex index to begin with
	 * @return new string
	 */
	static const string replace(const string& src, const char what, const char by, int beginIndex = 0);

	/**
	 * Replace string with another string
	 * @param src source string to be processed
	 * @param what what to replace
	 * @param by to replace by
	 * @param beginIndex index to begin with
	 * @return new string
	 */
	static const string replace(const string& src, const string& what, const string& by, int beginIndex = 0);

	/**
	 * Finds first index of given character
	 * @param src source string
	 * @param what what
	 * @return index or -1 if not found
	 */
	inline static int32_t firstIndexOf(const string& src, char what) {
		return src.find_first_of(what);
	}

	/**
	 * Finds first index of characters provided within given string
	 * @param src source string
	 * @param what what
	 * @return index or -1 if not found
	 */
	inline static int32_t firstIndexOf(const string& src, const string& what) {
		return src.find_first_of(what);
	}

	/**
	 * Finds last index of given character
	 * @param src source string
	 * @param what what
	 * @return index or -1 if not found
	 */
	inline static int32_t lastIndexOf(const string& src, char what) {
		return src.find_last_of(what);
	}

	/**
	 * Finds last index of characters provided within given string
	 * @param src source string
	 * @param what what
	 * @return index or -1 if not found
	 */
	inline static int32_t lastIndexOf(const string& src, const string& what) {
		return src.find_last_of(what);
	}

	/**
	 * Returns substring of given string from begin index
	 * @param src source string
	 * @param beginIndex begin index
	 * @return new string
	 */
	inline static const string substring(const string& src, int32_t beginIndex) {
		return src.substr(beginIndex);
	}

	/**
	 * Returns substring of given string from begin index
	 * @param src source string
	 * @param beginIndex begin index
	 * @return new string
	 */
	inline static const string_view viewSubstring(const string_view& src, int32_t beginIndex) {
		return src.substr(beginIndex);
	}

	/**
	 * Returns substring of given string from begin index to end index
	 * @param src source string
	 * @param beginIndex begin index
	 * @param endIndex end index
	 * @return new string
	 */
	inline static const string substring(const string& src, int32_t beginIndex, int32_t endIndex) {
		return src.substr(beginIndex, endIndex - beginIndex);
	}

	/**
	 * Returns substring of given string from begin index to end index
	 * @param src source string
	 * @param beginIndex begin index
	 * @param endIndex end index
	 * @return new string
	 */
	inline static const string_view viewSubstring(const string_view& src, int32_t beginIndex, int32_t endIndex) {
		return src.substr(beginIndex, endIndex - beginIndex);
	}

	/**
	 * Checks if string equals ignoring case
	 * @param string1 string 1
	 * @param string2 string 2
	 * @return equals
	 */
	static bool equalsIgnoreCase(const string& string1, const string& string2);

	/**
	 * Trim string
	 * @param src source string
	 * @return trimmed string
	 */
	static const string trim(const string& src);

	/**
	 * Trim string
	 * @param src source string
	 * @return trimmed string
	 */
	static const string_view viewTrim(const string_view& src);

	/**
	 * Transform string to lower case
	 * @param src source string
	 * @return transformed string
	 */
	static const string toLowerCase(const string& src);

	/**
	 * Transform string to upper case
	 * @param src source string
	 * @return transformed string
	 */
	static const string toUpperCase(const string& src);

	/**
	 * Do regex pattern matching
	 * @param src source string to test
	 * @param pattern pattern
	 * @return if patter matches
	 */
	static bool regexMatch(const string& src, const string& pattern);

	/**
	 * Replace regex pattern with given string
	 * @param src source string to operate on
	 * @param pattern pattern to search
	 * @param by string that will replace pattern occurrances
	 */
	static const string regexReplace(const string& src, const string& pattern, const string& by);

	/**
	 * Tokenize
	 * @param str string to tokenize
	 * @param delimiters delimiters
	 * @return tokens
	 */
	static const vector<string> tokenize(const string& str, const string& delimiters);

	/**
	 * Get Utf8 binary index
	 * @param str string
	 * @param charIdx character index
	 * @return UTF binary buffer position from given character/code point index
	 */
	static inline int getUtf8BinaryIndex(const string& str, int charIdx) {
		StringTools::UTF8CharacterIterator u8It(str);
		u8It.seek(charIdx);
		return u8It.getPosition();
	}

};

