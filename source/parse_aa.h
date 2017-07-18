#pragma once
#include <string>
#include <vector>
#include <fstream>

namespace parse
{
void strip_whitespace(std::string &token);
std::vector<std::string> break_line_into_tokens(std::string const &line,
                                                char const &delim);
bool string_to_bool(std::string const &string);

void getline_ignore_comments(std::ifstream & input_file, std::string & line,
                             char const & comment);
} // End namespace parse
