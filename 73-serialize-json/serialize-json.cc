#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using Json = nlohmann::json;

struct Actor {
  std::string star;
  std::string role;
  // Implicit conversion
  operator Json() const { return {{"star", {star}}, {"role", {role}}}; }
};

struct Movie {
  int id;
  std::string title;
  int year;
  int length;
  std::vector<Actor> cast;
  std::vector<std::string> directors;
  std::vector<std::string> writers;

  operator Json() const {
    return {{"id", {id}},
            {"title", {title}},
            {"year", {year}},
            {"length", {length}},
            {"directors", {directors}},
            {"writers", {writers}},
            {"cast", {cast}}};
  }
};

using MovieList = std::vector<Movie>;

int main() {
  Movie m1 = {9871,
              "Forrest Gump",
              1994,
              202,
              {{"Tom Hanks", "Forrest Gump"}, {"Sally Field", "Mrs. Gump"}},
              {"Robert Zemeckis"},
              {"Winston Groom", "Eric Roth"}};
  Movie m2 = {9999,
              "Cinema Paradiso",
              1988,
              173,
              {{"Philippe Noiret", "Alfredo"},
               {"Salvatore Cascio", "Salvatore Di Vita"},
               {"Agnese Nano", "Elena Mendola"}},
              {"Giuseppe Tornatore"},
              {"Giuseppe Tornatore"}};
  MovieList movies = {m1, m2};
  constexpr int indentation = 2;
  Json json = movies;
  std::cout << json.dump(indentation) << std::endl;
  return 0;
}