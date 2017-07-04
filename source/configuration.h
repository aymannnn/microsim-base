#pragma once

namespace parameters
{

enum Gender
{
    MALE, FEMALE, ALL, NUMBER_GENDER_SETTINGS
};

enum Runtype
{
    CALIBRATION, REGULAR_SIMULATION
};


class Configuration
{
public:
    Configuration();
    Gender m_gender;
private:
    void parse_input_file();
    static const char comment;
};

// Constant global parameter settings: will read from an input file.
// Sets up life tables, etc.
} // end namespace parameters

extern const parameters::Configuration settings;