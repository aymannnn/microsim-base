#pragma once
#include <unordered_map>
#include <vector>
#include <string>


// forward declarations
namespace distributions
{
namespace calibration
{
class Base;
enum ParamType;
struct DefiningValue;
}
}


namespace parameters
{

class Calibrated
{
public:
    Calibrated(std::string input_file_name = "../input/calibrated_params");
    // empty for now...
    std::unordered_map<std::string, distributions::calibration::Base> params_;
private:
    std::string input_file_name_;
    void set_up_default();
    void read_input_file();
    char comment_ = '#';
    char delim_ = ',';
    void add_parameter(std::vector<std::string> &tokenized_from_file);
};

}

