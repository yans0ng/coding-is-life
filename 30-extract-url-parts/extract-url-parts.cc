#include <iostream>
#include <optional>
#include <regex>
#include <string>

struct UriParts {
  std::string protocol;
  std::string domain;
  std::optional<int> port;
  std::optional<std::string> path;
  std::optional<std::string> query;
  std::optional<std::string> fragment;
};

std::ostream &operator<<(std::ostream &os, const UriParts &uriParts) {
  const std::string delimiter = " ";
  os << "protocol: " << uriParts.protocol << delimiter
     << "domain: " << uriParts.domain << delimiter;
  if (uriParts.port.has_value()) {
    os << "port: " << uriParts.port.value() << delimiter;
  }
  if (uriParts.path.has_value()) {
    os << "path: " << uriParts.path.value() << delimiter;
  }
  if (uriParts.query.has_value()) {
    os << "port: " << uriParts.query.value() << delimiter;
  }
  if (uriParts.fragment.has_value()) {
    os << "port: " << uriParts.fragment.value() << delimiter;
  }
  return os;
}

std::string url_regex_expression() {
  //   protocol_expr = R"(\w+)";
  //   domain_expr = R"([\w.-]+)"; // domain might contain dot and
  //                                  dash (e.g. www.hello-world.com)
  //   port_expr = R"(:(\d+))?";
  //   path_expr = R"([\w\/.]+)?";
  //   query_expr = R"(\?([\w=&]+))*";
  //   fragment_expr = R"(#(\w+))?";
  return R"(^(\w+):\/\/([\w.-]+)(:(\d+))?([\w\/.]+)?(\?([\w=&]+))*(#(\w+))?$)";
}

std::optional<UriParts> parse_uri(std::string uri) {
  std::regex rx(url_regex_expression());
  auto matches = std::smatch{};
  if (std::regex_match(uri, matches, rx)) {
    if (matches[1].matched && matches[2].matched) {
      UriParts parts;
      parts.protocol = matches[1];
      parts.domain = matches[2];
      if (matches[4].matched) {
        parts.port = std::atoi(matches[4].str().c_str());
      }
      if (matches[5].matched) {
        parts.path = matches[5];
      }
      if (matches[7].matched) {
        parts.query = matches[7];
      }
      if (matches[9].matched) {
        parts.fragment = matches[9];
      }
      return parts;
    }
  }
  return {};
}

int main() {
  std::string uri;
  std::cin >> uri;
  auto uriParts = parse_uri(uri);
  if (uriParts.has_value()) {
    std::cout << uriParts.value() << std::endl;
  } else {
    std::cout << "Parse failed" << std::endl;
  }

  return 0;
}