#pragma once
#include <boost/math/distributions/beta.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions/lognormal.hpp>
#include <boost/math/distributions/uniform.hpp>
#include <string>

namespace distributions
{

namespace literature
{

enum ParamType
{
    NOT_SET, PROBABILITY, RELATIVE_RISK, UTILITY, COST, NOT_A_TYPE
};

enum DistributionType
{
    BETA, NORMAL, GAMMA, LOGNORMAL, UNIFORM
};

class Base
{
public:
    Base();
    std::string key_;
    const double get_current_value();
    virtual double standard_deviation();
    virtual double pdf(const double value);
    ParamType param_type_;
protected:
    double current_value_;
};

class Beta : public Base
{
public:
    void set_beta_dist(const double success, const double trials,
                       const ParamType type);
    double standard_deviation();
    double pdf(const double value);
private:
    boost::math::beta_distribution<> beta_dist_;
};

class Normal : public Base
{
public:
    void set_normal_dist(const double mean, const double std,
                         const ParamType type);
    double standard_deviation();
    double pdf(const double value);
private:
    boost::math::normal_distribution<> normal_dist_;
};

class Gamma : public Base
{
public:
    Gamma();
    void set_gamma_dist(const double shape, const double scale,
                        const ParamType type);
    double standard_deviation();
    double pdf(const double value);
private:
    boost::math::gamma_distribution<> gamma_dist_;
};

class Lognormal : public Base
{
public:
    void set_lognormal_dist(const double mu, const double sigma,
                            const ParamType type);
    double standard_deviation();
    double pdf(const double value);
private:
    boost::math::lognormal_distribution<> lognorm_dist;
};

class Uniform : public Base
{
public:
    void set_uniform_dist(const double mean, const double upper_minus_mean,
                          const ParamType type);
    double standard_deviation();
    double pdf(const double value);
private:
    boost::math::uniform_distribution<> uniform_dist;
};

} // end namespace literature

} // end namespace distributions