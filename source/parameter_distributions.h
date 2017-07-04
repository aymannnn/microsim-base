#pragma once

#include <boost/math/distributions/beta.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions/lognormal.hpp>
#include <boost/math/distributions/uniform.hpp>
#include <string>

enum param_type_t
{
    NOT_SET, PROBABILITY, RELATIVE_RISK, UTILITY, COST, NOT_A_TYPE
};

enum distribution_type_t
{
    BETA, NORMAL, GAMMA, LOGNORMAL, UNIFORM
};

class parameter
{
public:
    parameter();
    std::string key;
    double current_value;
    virtual double standard_deviation();
    virtual double pdf(const double &value);
    param_type_t param_type;
};

class beta_param : public parameter
{
public:
    void set_beta_dist(const double &success, const double &trials,
                       const param_type_t &type);
    double standard_deviation();
    double pdf(const double &value);
private:
    boost::math::beta_distribution<> beta_dist;
};

class normal_dist_param : public parameter
{
public:
    void set_normal_dist(const double &mean, const double &std,
                         const param_type_t &type);
    double standard_deviation();
    double pdf(const double &value);
private:
    boost::math::normal_distribution<> normal_dist;
};

class gamma_dist_param : public parameter
{
public:
    gamma_dist_param();
    void set_gamma_dist(const double &shape, const double &scale,
                        const param_type_t &type);
    double standard_deviation();
    double pdf(const double &value);
private:
    boost::math::gamma_distribution<> gamma_dist;
};

class lognormal_dist_param : public parameter
{
public:
    void set_lognormal_dist(const double &mu, const double &sigma,
                            const param_type_t &type);
    double standard_deviation();
    double pdf(const double &value);
private:
    boost::math::lognormal_distribution<> lognorm_dist;
};

class uniform_param : public parameter
{
public:
    void set_uniform_dist(const double &mean, const double &upper_minus_mean,
                          const param_type_t &type);
    double standard_deviation();
    double pdf(const double &value);
private:
    boost::math::uniform_distribution<> uniform_dist;
};