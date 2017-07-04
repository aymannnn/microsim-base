#pragma once


#include <array>

enum gender
{
    MALE, FEMALE, ALL, NUMBER_GENDER_SETTINGS
};

enum type_of_run
{
    CALIBRATION, 
};

class configuration_params
{
public:
    configuration_params();
    gender m_gender;
private:
    void parse_input_file();
    static const char comment;
};

// Constant global parameter settings: will read from an input file.
// Sets up life tables, etc.

extern const configuration_params settings;