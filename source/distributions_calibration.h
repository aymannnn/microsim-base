#pragma once
#include <string>
#include <vector>

// forward declaration for RNG
namespace modeling
{
class RandomNumberGenerator;
}

namespace distributions
{

namespace calibration
{

enum ParamType
{
    NOT_SET, CONSTANT, LINEAR, LOGISTIC
};

struct DefiningValue
{
    DefiningValue();
    DefiningValue(const std::string val, const std::string low, 
                  const std::string up);
    double upper_bound;
    double lower_bound;
    double value;
    void step_defining_value(modeling::RandomNumberGenerator &rng,
                             const double step_size);
};

class Base
{
public:
    Base();
    std::string key_;
    virtual void step_defining_values(modeling::RandomNumberGenerator &rng); 
};

class Constant : public Base
{
public:
    void step_defining_values(modeling::RandomNumberGenerator &rng);
    void set_constant_param(const DefiningValue &value);
    const double get_value();
private:
    DefiningValue defining_val;
};

class Linear : public Base
{
public:
    void set_linear_dist(const DefiningValue &intercept,
                         const DefiningValue &slope);
    void step_defining_values(modeling::RandomNumberGenerator &rng);
    template<typename T>
    const double get_value(const T);
private:
    DefiningValue intercept_;
    DefiningValue slope_;
};

class Logistic : public Base
{
public:
    void step_defining_values(modeling::RandomNumberGenerator &rng);
    void set_logistic_param(const DefiningValue &h_asymptote,
                            const DefiningValue &h_shift,
                            const DefiningValue &steepness);
    template<typename T>
    const double get_value(const T);
private:
    DefiningValue h_asymptote_;
    DefiningValue h_shift_;
    DefiningValue steepness_;
};


} // end namespace distributions
} // end namespace calibration