#include <assert.h>
#include <sstream>
#include <string>
#include <vector>

template <class Elem>
using tstring =
    std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
using tstringstream =
    std::basic_stringstream<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <typename Elem>
std::vector<tstring<Elem>> split(tstring<Elem> text, const Elem delimiter) {
	auto sstr = tstringstream<Elem>(text);
	auto tokens = std::vector<tstring<Elem>>();
	auto token = tstring<Elem>();
	while (std::getline(sstr, token, delimiter)) {
		if (!token.empty()) {
			tokens.push_back(token);
		}
	}
	return tokens;
}

template <typename Elem>
std::vector<tstring<Elem>> split(tstring<Elem> text,
				 const tstring<Elem>& delimiters) {
	size_t pos, prev_pos = 0;
	std::vector<tstring<Elem>> tokens;
	while ((pos = text.find_first_of(delimiters, prev_pos)) !=
	       tstring<Elem>::npos) {
		if (pos > prev_pos) {
			tokens.push_back(text.substr(prev_pos, pos - prev_pos));
		}
		prev_pos = pos + 1;
	}
	return tokens;
}

int main() {
	using namespace std::string_literals;
	std::vector<std::string> expected{"this", "is", "a", "sample"};
	assert(expected == split("this is a sample"s, ' '));
	assert(expected == split("this,is a.sample!!"s, ",.! "s));
	return 0;
}
