#include "configuration.h"
#include "parse_aa.h"
#include "life_tables.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

// Declaration of external constant to hold model settings.

const parameters::Configuration settings;
const char parameters::Configuration::comment_ = '#';
const char parameters::Configuration::delim_ = ',';

namespace parameters
{
Configuration::Configuration()
{
    parse_input_file();
    input_tables::Life::set_table(gender_);
}

void Configuration::parse_input_file()
{
    using std::ifstream;
    using std::string;
    using std::vector;

    ifstream input_file("../input/calibrated_params", std::ios::in);

    if (!input_file) {
        std::cout << "\nFailed to open input file for configuration";
    }
    vector<string> tokenized_line; 
    tokenized_line= parse::get_tokenized_line(input_file, comment_, delim_);
    // Need to staticly cast integers to enumerator values.
    gender_ = static_cast<Gender>(std::stoi(tokenized_line[0]));
    input_file.close();
}
} // end namespace parameters