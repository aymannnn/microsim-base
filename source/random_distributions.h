#pragma once
#include <array>
#include <boost/random.hpp>

namespace modeling {

namespace random_numbers {

class RandomNumberGenerator {
 private:
  int seed_;

 public:
  boost::random::mt19937 generator_;
  RandomNumberGenerator(int const seed);
  const int get_seed();
};

double uniform(RandomNumberGenerator &rng, const double lower = 0,
               const double upper = 1);

double lognormal(RandomNumberGenerator &rng, const double mean,
                 const double std);

double weibull(RandomNumberGenerator &rng, const double shape,
               const double scale);

double normal(RandomNumberGenerator &rng, const double mean,
              const double standard_deviation);

int uniform_int(RandomNumberGenerator &rng, const int lower, const int upper);

double gamma(RandomNumberGenerator &rng, const double alpha, const double beta);

double beta(RandomNumberGenerator &rng, const double alpha, const double beta);

}  // namespace random_numbers

}  // namespace modeling
