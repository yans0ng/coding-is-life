#include <assert.h>
#include <string_view>
#include <vector>
#include <stdexcept>

unsigned char hexchar_to_int(const char ch) {
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	else if (ch >= 'A' && ch <= 'F')
		return ch - 'A' + 10;
	else if (ch >= 'a' && ch <= 'f')
		return ch - 'a' + 10;
	else
		throw std::invalid_argument("Invalid hexadecimal character");
}

std::vector<unsigned char> hexhexchar_to_int(std::string_view str) {
	std::vector<unsigned char> result;
	for (size_t i = 0; i < str.size(); i += 2) {
		result.push_back((hexchar_to_int(str[i]) << 4) |
				 hexchar_to_int(str[i + 1]));
	}
	return result;
}

int main() {
	std::vector<unsigned char> expected{0xBA, 0xAD, 0xF0, 0x0D, 0x42};
	assert(hexhexchar_to_int("BAADF00D42") == expected);
	assert(hexhexchar_to_int("BaaDF00D42") == expected);
	return 0;
}
