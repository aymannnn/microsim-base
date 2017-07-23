#include "calibrated_params.h"
#include "distributions_calibration.h"
#include "configuration.h"
#include <fstream>
#include "parse_aa.h"
#include <iostream>
#include <cstdlib>

namespace parameters
{

Calibrated::Calibrated(std::string input_file_name) :
    input_file_name_(input_file_name)
{
    set_up_default();
    read_input_file();
}

// Add parameters here!
void Calibrated::set_up_default()
{
    using distributions::calibration::Constant;
    using distributions::calibration::Linear;
    using distributions::calibration::Logistic;

    params_["BATHROOM_AFTER_COFFEE"] = Constant();
    params_["NEED_HELP_NOW"] = Logistic();
}

void Calibrated::read_input_file()
{
    using std::ifstream;
    using std::string;
    using std::vector;

    ifstream input_file(input_file_name_, std::ios::in);

    if (!input_file)
    {
        std::cout << "\nFailed to open input file for calibration";
        std::cout << "\nEnsure that there's either no calibrated parameters,"
            " or fix the file path in calibrated_params.cpp.";
    }
    vector<string> tokenized_line;
    while (!input_file.eof())
    {
        tokenized_line = parse::get_tokenized_line(input_file, comment_,
                                                   delim_);
        add_parameter(tokenized_line);
    }
}

void Calibrated::add_parameter(std::vector<std::string> &param_as_string)
{

    using distributions::calibration::DefiningValue;
    using distributions::calibration::Constant;
    using distributions::calibration::Linear;
    using distributions::calibration::Logistic;
    
    std::string param_key = param_as_string[0];
    if (!params_.count(param_key))
    {
        std::cout << "\nParameter key in input file does not match "
            "parameter key hard-coded into model. Key in question is -> "
            << param_key << ".\nSimulation will terminate.";
        std::exit(0);
    }
    std::string param_type = param_as_string[1];
    int index = 2; // index at which parameter starts
    std::vector<DefiningValue> defining_values;
    while (index < param_as_string.size())
    {
        // string[index] = val, [index+1] = lower, [index+2] = upper
        // quick bounds check, a bit crudge but it does the trick
        if (index + 2 >= param_as_string.size())
        {
            std::cout << "\nCalibrated parameter line is incomplete or "
                "overcomplete. Parameter in question is " << param_key;
            std::cout << "\nTerminating simulation.";
            std::exit(0);
        }
        auto def_val = DefiningValue(param_as_string[index],
                                     param_as_string[index + 1],
                                     param_as_string[index + 2]);
        defining_values.push_back(def_val);
        index += 3;
    }
    if (param_type == "CONSTANT")
    {
        if (defining_values.size() != 1)
        {
            std::cout << "\nWrong number of defining values for parameter -> "
                << param_key << ". Terminating simulation.";
            std::exit(0);
        }
        Constant add;
        add.set_constant_param(defining_values[0]); // value
        this->params_[param_key] = add;
        
    }
    else if (param_type == "LINEAR")
    {
        if (defining_values.size() != 2)
        {
            std::cout << "\nWrong number of defining values for parameter -> "
                << param_key << ". Terminating simulation.";
            std::exit(0);
        }
        Linear add;
        add.set_linear_dist(defining_values[0], // intercept
                            defining_values[1]); // slope
        this->params_[param_key] = add;
    }
    else if (param_type == "LOGISTIC")
    {
        if (defining_values.size() != 3)
        {
            std::cout << "\nWrong number of defining values for parameter -> "
                << param_key << ". Terminating simulation.";
            std::exit(0);
        }

        Logistic add;
        add.set_logistic_param(defining_values[0], // horizontal asymptote
                               defining_values[1], // horizontal shift
                               defining_values[2]); // steepness
        this->params_[param_key] = add;
    }
    else
    {
        std::cout << "\nParameter type is undefined, please ensure that it's"
            " either CONSTANT, LINEAR, or LOGISTIC in the calibrated_params"
            " file.";
        std::cout << "\nName of parameter -> " << param_key << "."
            " Terminating simulation.";
        std::exit(0);
    }

}

}
