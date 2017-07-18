#include "configuration.h"
#include "parse_aa.h"
#include "life_tables.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

// Declaration of external constant to hold model settings.

const parameters::Configuration settings;
const char parameters::Configuration::comment = '#';


namespace parameters
{
Configuration::Configuration()
{
    parse_input_file();
    input_tables::Life::set_table(m_gender);
}

void Configuration::parse_input_file()
{
    using std::ifstream;
    using std::string;
    using std::vector;

    ifstream input_file("../input/configuration");

    if (!input_file) {
        std::cout << "\nFailed to open input file";
    }
    string hold_line;

    parse::getline_ignore_comments(input_file, hold_line, comment);
    // Need to staticly cast integers to enumerator values.
    m_gender = static_cast<Gender>(stoi(hold_line));

    input_file.close();
}
} // end namespace parameters