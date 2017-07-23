#include "parse_aa.h"
#include <sstream>


namespace parse
{

void strip_whitespace(std::string &token)
{
    while (token[0] == ' ')
    {
        token.erase(token.begin());
    }
}

std::vector<std::string> break_line_into_tokens(std::string const &line,
                                                const char delim)
{
    std::stringstream ss(line);
    std::vector<std::string> hold_broken_pieces;
    std::string token;
    while (std::getline(ss, token, delim))
    {
        strip_whitespace(token);
        hold_broken_pieces.push_back(token);
    }
    return hold_broken_pieces;
}

bool string_to_bool(std::string const &string)
{
    return (string == "1");
}

void getline_ignore_comments(std::ifstream &input_file,
                             std::string &line, const char comment)
{
    do
    {
        std::getline(input_file, line);
    } while (line[0] == comment || line[0] == ' ' || line.size() == 0);
}

std::vector<std::string> get_tokenized_line(std::ifstream &input_file,
                                            const char comment,
                                            const char delim)
{
    std::string untokenized_line;
    getline_ignore_comments(input_file, untokenized_line, comment);
    auto tokenized_line = break_line_into_tokens(untokenized_line, delim);
    return tokenized_line;
}

} // End namespace parse
