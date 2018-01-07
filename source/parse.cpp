#include "parse.h"
#include <sstream>

// public functions
bool Parse::string_to_bool(std::string const &string) {
  if (string == "1" || string == "true" || string == "True") {
    return true;

  } else {
    return false;
  }
}

Parse::tokens Parse::get_tokens(std::ifstream &input_file, const char comment,
                                const char delim) {
  // Ignore comments, lines starting with a whitespace, and lines with no
  // characters
  std::string line;
  do {
    if (input_file.eof()) break;
    std::getline(input_file, line);
  } while (line[0] == comment || line[0] == ' ' || line.size() == 0);
  // Now that we have our line, break it into tokens
  return break_line_into_tokens(line, delim);
}

// private functions

void Parse::strip_whitespace(std::string &token) {
  while (token[0] == ' ') {
    token.erase(token.begin());
  }
}

Parse::tokens Parse::break_line_into_tokens(std::string const &line,
                                            const char delim) {
  std::stringstream ss(line);
  tokens hold_broken_pieces;
  std::string token;
  while (std::getline(ss, token, delim)) {
    strip_whitespace(token);
    hold_broken_pieces.push_back(token);
  }
  return hold_broken_pieces;
}
