#include "stdafx.h"
#include "configuration.h"
#include "parse_aa.hpp"
#include <fstream>
#include <string>
#include <vector>
#include "life_tables.h"


// Declaration of external constant to hold model settings.

const configuration_params settings;
const char configuration_params::comment = '#';

configuration_params::configuration_params()
{
    parse_input_file();
    life_tables::set_table(m_gender);
}

void configuration_params::parse_input_file()
{
    using namespace std;
    ifstream input_file("../../input/configuration");
    string hold_line;

    parse::getline_ignore_comments(input_file, hold_line, comment);    
    // Need to staticly cast integers to enumerator values.
    m_gender = static_cast<gender>(stoi(hold_line));

    input_file.close();
}