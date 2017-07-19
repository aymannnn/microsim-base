#include "param_distributions.h"
#include <iostream>

namespace parameters
{

namespace distributions
{

Base::Base() : current_value(-1), param_type(NOT_SET) {};

double Base::standard_deviation()
{
    std::cout << "STD not set for the parameter type." << std::endl;
    return -DBL_MAX;
}

double Base::pdf(const double value)
{
    std::cout << "PDF function not set for the parameter type." << std::endl;
    return value;
}

void Beta::set_beta_dist(const double success, const double trials,
                         const ParamType type)
{
    boost::math::beta_distribution<> set(success, trials - success);
    beta_dist = set;
    param_type = type;
    current_value = boost::math::mean(beta_dist);
}

double Beta::standard_deviation()
{
    return boost::math::standard_deviation(beta_dist);
}

double Beta::pdf(const double value)
{
    return boost::math::pdf(beta_dist, value);
}

void Normal::set_normal_dist(const double mean, const double std,
                             const ParamType type)
{
    boost::math::normal_distribution<> set(mean, std);
    normal_dist = set;
    param_type = type;
    current_value = boost::math::mean(normal_dist);
}

double Normal::standard_deviation()
{
    return boost::math::standard_deviation(normal_dist);
}

double Normal::pdf(const double value)
{
    return boost::math::pdf(normal_dist, value);
}

// Gamma distribution doesn't have a default constructor ...
Gamma::Gamma() : gamma_dist(1, 1) {}

void Gamma::set_gamma_dist(const double shape, const double scale,
                           const ParamType type)
{
    boost::math::gamma_distribution<> set(shape, scale);
    param_type = type;
    gamma_dist = set;
    current_value = boost::math::mean(gamma_dist);
}

double Gamma::standard_deviation()
{
    return boost::math::standard_deviation(gamma_dist);
}

double Gamma::pdf(const double value)
{
    return boost::math::pdf(gamma_dist, value);
}

void Lognormal::set_lognormal_dist(const double mu, const double sigma,
                                   const ParamType type)
{
    boost::math::lognormal_distribution<> set(mu, sigma);
    lognorm_dist = set;
    param_type = type;
    current_value = boost::math::mean(lognorm_dist);
}

double Lognormal::standard_deviation()
{
    return boost::math::standard_deviation(lognorm_dist);
}

double Lognormal::pdf(const double value)
{
    return boost::math::pdf(lognorm_dist, value);
}

void Uniform::set_uniform_dist(const double mean,
                               const double mean_to_bound,
                               const ParamType type)
{
    boost::math::uniform_distribution<> set(mean - mean_to_bound,
                                            mean + mean_to_bound);
    uniform_dist = set;
    param_type = type;
    current_value = boost::math::mean(uniform_dist);
}

double Uniform::standard_deviation()
{
    return boost::math::standard_deviation(uniform_dist);
}

double Uniform::pdf(const double value)
{
    return boost::math::pdf(uniform_dist, value);
}

} // distributions
} // end namespace parameters