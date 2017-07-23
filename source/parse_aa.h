#pragma once
#include <string>
#include <vector>
#include <fstream>

namespace parse
{
void strip_whitespace(std::string &token);

std::vector<std::string> break_line_into_tokens(std::string const &line,
                                                const char delim);

bool string_to_bool(std::string const &string);

void getline_ignore_comments(std::ifstream & input_file, std::string & line,
                             const char comment);

std::vector<std::string> get_tokenized_line(std::ifstream &input_file,
                                            const char comment,
                                            const char delim);
} // End namespace parse
