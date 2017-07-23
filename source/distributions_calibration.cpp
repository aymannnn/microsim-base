#include "distributions_calibration.h"
#include <iostream>
#include "configuration.h"
#include "common_modeling_aa.h"

namespace distributions
{
namespace calibration
{

DefiningValue::DefiningValue() :
    upper_bound(1),
    lower_bound(0),
    value(0.5)
{}

DefiningValue::DefiningValue(const std::string val, const std::string low,
                             const std::string up)
{
    value = std::stod(val);
    lower_bound = std::stod(low);
    upper_bound = std::stod(up);
}

void DefiningValue::step_defining_value(modeling::RandomNumberGenerator &rng,
                               const double step_size)
{
    // uniform step between a bounded region from (value - step, value + step)
    // first three lines is just bound checking

    double lower_range = 0, upper_range = 0;
    (value - step_size) < lower_bound ? lower_range = lower_bound :
        lower_range = value - step_size;
    (value + step_size) > upper_bound ? upper_range = upper_bound :
        upper_range = value + step_size;
    value = modeling::distributions::uniform(rng, lower_range, upper_range);
}

Base::Base() :
    key_("Parameter not set")
{}

void Base::step_defining_values(modeling::RandomNumberGenerator &rng)
{
    std::cout << "Cannot step calibrated parameter as it has not been set." 
        "Parameter key is " << key_ << ".\n";
    std::cout << "Current RNG seed -> " << rng.get_seed();
}

void Constant::set_constant_param(const DefiningValue &value)
{
    defining_val = value;
}

void Constant::step_defining_values(modeling::RandomNumberGenerator &rng)
{
    // can write your own function to step a constant parameter.
    // currently, will be using as a default a step within a bounded
    // range of +/- step size
    double default_step_size = settings.calibration.step_size;
    defining_val.step_defining_value(rng, default_step_size);
}

const double Constant::get_value()
{
    return defining_val.value;
}

void Linear::set_linear_dist(const DefiningValue &intercept,
                             const DefiningValue &slope)
{
    intercept_ = intercept;
    slope_ = slope;
}

void Linear::step_defining_values(modeling::RandomNumberGenerator &rng)
{
    double default_step_size = settings.calibration.step_size;
    intercept_.step_defining_value(rng, default_step_size);
    slope_.step_defining_value(rng, default_step_size);
}

template<typename T>
const double Linear::get_value(const T)
{
    return (intercept_.value + slope_.value*T);
}

void Logistic::set_logistic_param(const DefiningValue &h_asymptote,
                                  const DefiningValue &h_shift,
                                  const DefiningValue &steepness)
{
    h_asymptote_ = h_asymptote;
    h_shift_ = h_shift;
    steepness_ = steepness;
}

void Logistic::step_defining_values(modeling::RandomNumberGenerator & rng)
{
    double default_step_size = settings.calibration.step_size;
    h_asymptote_.step_defining_value(rng, default_step_size);
    h_shift_.step_defining_value(rng, default_step_size);
    steepness_.step_defining_value(rng, default_step_size);
}

template<typename T>
const double Logistic::get_value(const T)
{
    // Logistic in the form L / ( 1 + e ^ (-r (x - x_o) ))
    return (
        h_asymptote_.value /
        (1 + std::exp(-steepness_.value(T - h_shift_)))
        );
}

} // end namespace calibration
} // end namespace distributions