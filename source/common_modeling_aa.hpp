#pragma once
#include <boost/random.hpp>

// Source: https://github.com/namyaila/often_used

namespace often_aa
{

class RandomNumberGenerator
{
private:

    int seed_;

public:

    boost::random::mt19937 generator_;
    RandomNumberGenerator(int const seed) {
        seed_ = seed;
        generator_.seed(seed_);
    }

    const int get_seed() {
        return seed_;
    }

};

inline double uniform(RandomNumberGenerator &rng,
               const double lower = 0, const double upper = 1)
{
    boost::random::uniform_real_distribution<> dis(lower, upper);
    return dis(rng.generator_);
}

inline double lognormal(RandomNumberGenerator &rng,
                        const double mean, const double std)
{
    boost::random::lognormal_distribution<> dis(mean, std);
    return dis(rng.generator_);
}

inline double weibull(RandomNumberGenerator &rng,
                      const double shape, const double scale)
{
    boost::random::weibull_distribution<> dis(shape, scale);
    return dis(rng.generator_);
}

inline double normal(RandomNumberGenerator &rng,
                     const double mean, const double standard_deviation)
{
    boost::random::normal_distribution<> dis(mean, standard_deviation);
    return dis(rng.generator_);
}

inline int uniform_int(RandomNumberGenerator &rng,
                       const int &lower, const int &upper)
{
    boost::random::uniform_int_distribution<> dis(lower, upper);
    return dis(rng.generator_);
}

inline double gamma(RandomNumberGenerator &rng,
                    const double alpha, const double beta)
{
    boost::random::gamma_distribution<> dis(alpha, beta);
    return dis(rng.generator_);
}

inline double beta(RandomNumberGenerator &rng,
                   const double alpha, const double beta)
{
    double x = gamma(rng, alpha, 1.0);
    double y = gamma(rng, beta, 1.0);
    return (x / (x + y));
}

inline bool dbl_eq(const double a, const double b)
{
    double epsilon = std::numeric_limits<double>::epsilon();
    return (abs(b - a) <= 2 * epsilon);
}

inline double rate_to_probability(const double rate)
{
    return (1 - exp(-rate));
}

inline double probability_to_rate(const double p) {
    return (-log(1.0 - p));
}

inline double change_probability_time_interval(
    const double initial_probability, int const &time_division)
{
    double rate = -log(1.0 - initial_probability) / time_division;
    return rate_to_probability(rate);
}

inline double probability_times_relative_risk(
    const double initial_probability, const double relative_risk)
{
    double initial_rate = -log(1 - initial_probability);
    double relative_rate = initial_rate*relative_risk;
    return rate_to_probability(relative_rate);
}

inline double fast_exp(double x)
{
    x = 1.0 + x / 256.0;
    x *= x; x *= x; x *= x; x *= x;
    x *= x; x *= x; x *= x; x *= x;
    return x;
}

template<typename T, size_t ROWS, size_t COLUMNS>
using two_d_array = std::array<std::array<T, COLUMNS>, ROWS>;

} // End namespace often_aa
