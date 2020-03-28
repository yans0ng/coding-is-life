#include <iostream>
#include <regex>
#include <string>
#include <string_view>

std::string transform_date(std::string_view text) {
  auto rx = std::regex(R"((\d{1,2})(-|.|\/)(\d{1,2})(-|.|\/)(\d{4}))");
  return std::regex_replace(text.data(), rx, R"($5-$3-$1)");
}

int main() {
  using namespace std::string_literals;
  int total = 0, passed = 0;

  for (std::string input, expected;
       std::getline(std::cin, input) && std::getline(std::cin, expected);
       total++) {
    auto output = transform_date(input);
    if (output == expected) {
      passed++;
    } else {
      std::cerr << "[ERROR] Assertion failed.\nExpected: " << expected
                << "\nReceived: " << output << std::endl;
    }
  }
  std::cout << passed << " / " << total << " cases passed" << std::endl;
}