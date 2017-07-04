#pragma once

#include <string>
#include <vector>

enum literature_params_t
{
    EXAMPLE_LP,
    NUMBER_OF_LPS
};


class parameter;
enum distribution_type_t;
enum param_type_t;

class literature_params
{
public:
    literature_params();
    std::vector<parameter> container_;
private:
    void add_parameter(distribution_type_t const &dist_type,
                       param_type_t const &param_type,
                       const double &param1, const double &param2);
};