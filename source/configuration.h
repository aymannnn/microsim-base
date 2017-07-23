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

enum CalibrationType
{
    SIMULATED_ANNEALING, GREEDY, GRASP
};

struct ExternalCalibrationSettings
{
    double step_size;
    CalibrationType calibration_type;
};

class Configuration
{
public:
    Configuration();
    Gender gender_;
    ExternalCalibrationSettings calibration;
private:
    void parse_input_file();
    static const char comment_;
    static const char delim_;
};

// Constant global parameter settings: will read from an input file.
// Sets up life tables, etc.
} // end namespace parameters

extern const parameters::Configuration settings;