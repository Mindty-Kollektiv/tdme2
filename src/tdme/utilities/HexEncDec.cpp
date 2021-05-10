#include <string.h>

#include <tdme/utilities/HexEncDec.h>

using std::string;

using tdme::utilities::HexEncDec;

void HexEncDec::encodeInt(const uint64_t decodedInt, string& encodedString) {
	encodedString = "";
	char encodingCharSet[] = "0123456789abcdef";
	auto _decodedInt = decodedInt;
	for (auto i = 0; i < 32; i++) {
		auto charIdx = _decodedInt & 15;
		encodedString = encodingCharSet[charIdx] + encodedString;
		_decodedInt>>= 4;
		if (_decodedInt == 0) break;
	}
}

bool HexEncDec::decodeInt(const string& encodedString, uint64_t& decodedInt) {
	char encodingCharSet[] = "0123456789abcdef";
	decodedInt = 0;
	for (auto i = 0; i < encodedString.length(); i++) {
		auto codeIdx = -1;
		char c = encodedString[encodedString.length() - i - 1];
		char* codePtr = strchr(encodingCharSet, c);
		if (codePtr == NULL) {
			return false;
		} else {
			codeIdx = codePtr - encodingCharSet;
		}
		decodedInt+= codeIdx << (i * 4);
	}
	return true;
}
