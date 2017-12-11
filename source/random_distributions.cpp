#include "random_distributions.h"

namespace modeling {

namespace random_numbers {

RandomNumberGenerator::RandomNumberGenerator(int const seed) {
  seed_ = seed;
  generator_.seed(seed_);
}

const int RandomNumberGenerator::get_seed() { return seed_; }

double uniform(RandomNumberGenerator &rng, const double lower,
               const double upper) {
  boost::random::uniform_real_distribution<> dis(lower, upper);
  return dis(rng.generator_);
}

double lognormal(RandomNumberGenerator &rng, const double mean,
                 const double std) {
  boost::random::lognormal_distribution<> dis(mean, std);
  return dis(rng.generator_);
}

double weibull(RandomNumberGenerator &rng, const double shape,
               const double scale) {
  boost::random::weibull_distribution<> dis(shape, scale);
  return dis(rng.generator_);
}

double normal(RandomNumberGenerator &rng, const double mean,
              const double standard_deviation) {
  boost::random::normal_distribution<> dis(mean, standard_deviation);
  return dis(rng.generator_);
}

int uniform_int(RandomNumberGenerator &rng, const int lower, const int upper) {
  boost::random::uniform_int_distribution<> dis(lower, upper);
  return dis(rng.generator_);
}

double gamma(RandomNumberGenerator &rng, const double alpha,
             const double beta) {
  boost::random::gamma_distribution<> dis(alpha, beta);
  return dis(rng.generator_);
}

double beta(RandomNumberGenerator &rng, const double alpha, const double beta) {
  double x = gamma(rng, alpha, 1.0);
  double y = gamma(rng, beta, 1.0);
  return (x / (x + y));
}

}  // namespace random_numbers

}  // namespace modeling
