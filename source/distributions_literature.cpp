#include <iostream>
#include "distributions_literature.h"

namespace distributions
{

namespace literature
{

Base::Base() : current_value_(-1), param_type_(NOT_SET) {};

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

const double Base::get_current_value()
{
    return current_value_;
}

void Beta::set_beta_dist(const double success, const double trials,
                         const ParamType type)
{
    boost::math::beta_distribution<> set(success, trials - success);
    beta_dist_ = set;
    param_type_ = type;
    current_value_ = boost::math::mean(beta_dist_);
}

double Beta::standard_deviation()
{
    return boost::math::standard_deviation(beta_dist_);
}

double Beta::pdf(const double value)
{
    return boost::math::pdf(beta_dist_, value);
}

void Normal::set_normal_dist(const double mean, const double std,
                             const ParamType type)
{
    boost::math::normal_distribution<> set(mean, std);
    normal_dist_ = set;
    param_type_ = type;
    current_value_ = boost::math::mean(normal_dist_);
}

double Normal::standard_deviation()
{
    return boost::math::standard_deviation(normal_dist_);
}

double Normal::pdf(const double value)
{
    return boost::math::pdf(normal_dist_, value);
}

// Gamma distribution doesn't have a default constructor ...
Gamma::Gamma() : gamma_dist_(1, 1) {}

void Gamma::set_gamma_dist(const double shape, const double scale,
                           const ParamType type)
{
    boost::math::gamma_distribution<> set(shape, scale);
    param_type_ = type;
    gamma_dist_ = set;
    current_value_ = boost::math::mean(gamma_dist_);
}

double Gamma::standard_deviation()
{
    return boost::math::standard_deviation(gamma_dist_);
}

double Gamma::pdf(const double value)
{
    return boost::math::pdf(gamma_dist_, value);
}

void Lognormal::set_lognormal_dist(const double mu, const double sigma,
                                   const ParamType type)
{
    boost::math::lognormal_distribution<> set(mu, sigma);
    lognorm_dist = set;
    param_type_ = type;
    current_value_ = boost::math::mean(lognorm_dist);
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
    param_type_ = type;
    current_value_ = boost::math::mean(uniform_dist);
}

double Uniform::standard_deviation()
{
    return boost::math::standard_deviation(uniform_dist);
}

double Uniform::pdf(const double value)
{
    return boost::math::pdf(uniform_dist, value);
}

} // end namespace literature





} // end namespace distributions