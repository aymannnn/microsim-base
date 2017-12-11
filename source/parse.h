#pragma once
#include <fstream>
#include <string>
#include <vector>

class Parse {
 public:
  using tokens = std::vector<std::string>;
  static bool string_to_bool(std::string const &string);
  static tokens get_tokens(std::ifstream &input_file, const char comment,
                           const char delim);

 private:
  static void strip_whitespace(std::string &token);
  static tokens break_line_into_tokens(std::string const &line,
                                       const char delim);
};  // End namespace parse
