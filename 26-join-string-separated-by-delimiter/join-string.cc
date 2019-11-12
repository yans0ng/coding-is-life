#include <assert.h>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <typename Iter>
std::string join_strings(Iter begin, Iter end, char const* const separator) {
	std::ostringstream os;
	// This function assumes that Iter is a random-access iterator type
	std::copy(begin, end - 1,
		  std::ostream_iterator<std::string>(os, separator));
	os << *(end - 1);
	return os.str();
}

template <typename C>
std::string join_strings(const C& container, char const* const separator) {
	if (container.empty()) {
		return std::string();
	}
	return join_strings(container.begin(), container.end(), separator);
}

int main() {
	std::vector<std::string> v1{"this", "is", "an", "example"};
	std::vector<std::string> v2{"example"};
	std::vector<std::string> v3{};

	using namespace std::string_literals;
	assert(join_strings(v1, " ") == "this is an example"s);
	assert(join_strings(v2, " ") == "example"s);
	assert(join_strings(v3, " ") == ""s);
	return 0;
}
