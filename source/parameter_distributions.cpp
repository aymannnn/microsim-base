
#include "parameter_distributions.h"
#include <iostream>

parameter::parameter() : current_value(-1), param_type(NOT_SET) {};

double parameter::standard_deviation()
{
    std::cout << "STD not set for the parameter type." << std::endl;
    return -DBL_MAX;
}

double parameter::pdf(const double &value)
{
    std::cout << "PDF function not set for the parameter type." << std::endl;
    return value;
}

void beta_param::set_beta_dist(const double &success, const double &trials,
                               const param_type_t &type)
{
    boost::math::beta_distribution<> set(success, trials - success);
    beta_dist = set;
    param_type = type;
    current_value = boost::math::mean(beta_dist);
}

double beta_param::standard_deviation()
{
    return boost::math::standard_deviation(beta_dist);
}

double beta_param::pdf(const double &value)
{
    return boost::math::pdf(beta_dist, value);
}

void normal_dist_param::set_normal_dist(const double &mean, const double &std,
                                        const param_type_t &type)
{
    boost::math::normal_distribution<> set(mean, std);
    normal_dist = set;
    param_type = type;
    current_value = boost::math::mean(normal_dist);
}

double normal_dist_param::standard_deviation()
{
    return boost::math::standard_deviation(normal_dist);
}

double normal_dist_param::pdf(const double &value)
{
    return boost::math::pdf(normal_dist, value);
}

// Gamma distribution doesn't have a default constructor ...
gamma_dist_param::gamma_dist_param() : gamma_dist(1, 1) {}

void gamma_dist_param::set_gamma_dist(const double &shape, const double &scale,
                                      const param_type_t &type)
{
    boost::math::gamma_distribution<> set(shape, scale);
    param_type = type;
    gamma_dist = set;
    current_value = boost::math::mean(gamma_dist);
}

double gamma_dist_param::standard_deviation()
{
    return boost::math::standard_deviation(gamma_dist);
}

double gamma_dist_param::pdf(const double &value)
{
    return boost::math::pdf(gamma_dist, value);
}

void lognormal_dist_param::set_lognormal_dist(const double & mu,
                                              const double & sigma, const param_type_t &type)
{
    boost::math::lognormal_distribution<> set(mu, sigma);
    lognorm_dist = set;
    param_type = type;
    current_value = boost::math::mean(lognorm_dist);
}

double lognormal_dist_param::standard_deviation()
{
    return boost::math::standard_deviation(lognorm_dist);
}

double lognormal_dist_param::pdf(const double &value)
{
    return boost::math::pdf(lognorm_dist, value);
}

void uniform_param::set_uniform_dist(const double &mean,
                                     const double &mean_to_bound, const param_type_t &type)
{
    boost::math::uniform_distribution<> set(mean - mean_to_bound,
                                            mean + mean_to_bound);
    uniform_dist = set;
    param_type = type;
    current_value = boost::math::mean(uniform_dist);
}

double uniform_param::standard_deviation()
{
    return boost::math::standard_deviation(uniform_dist);
}

double uniform_param::pdf(const double &value)
{
    return boost::math::pdf(uniform_dist, value);
}