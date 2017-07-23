#pragma once
#include <boost/random.hpp>

namespace modeling
{

class RandomNumberGenerator
{
private:
    int seed_;

public:
    boost::random::mt19937 generator_;
    RandomNumberGenerator(int const seed);
    const int get_seed();
};

bool dbl_eq(const double a, const double b);

double rate_to_probability(const double rate);

double probability_to_rate(const double p);

double change_probability_time_interval(const double initial_probability, 
                                        const int time_division);

double probability_times_relative_risk(const double initial_probability,
                                       const double relative_risk);

namespace distributions
{

double uniform(RandomNumberGenerator &rng, const double lower = 0,
               const double upper = 1);

double lognormal(RandomNumberGenerator &rng, const double mean,
                 const double std);

double weibull(RandomNumberGenerator &rng, const double shape,
               const double scale);

double normal(RandomNumberGenerator &rng, const double mean,
              const double standard_deviation);

int uniform_int(RandomNumberGenerator &rng, const int lower, const int upper);

double gamma(RandomNumberGenerator &rng, const double alpha,
             const double beta);

double beta(RandomNumberGenerator &rng, const double alpha, const double beta);

} // End namespace distributions

} // End namespace statistics_aa
