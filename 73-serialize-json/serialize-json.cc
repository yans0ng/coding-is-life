#include <nlohmann/json.hpp>
#include <string>

struct Actor {
  std::string star;
  std::string role;
};

struct Movie {
  int id;
  std::string title;
  int year;
  int length;
  std::vector<Actor> cast;
  std::vector<std::string> directors;
  std::vector<std::string> writers;
};

using MoveList = std::vector<Movie>;

int main() { return 0; }