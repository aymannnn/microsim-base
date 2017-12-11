#include "modeling.h"
#include <cmath>
#include <limits>

namespace modeling {

bool dbl_eq(const double a, const double b) {
  double epsilon = std::numeric_limits<double>::epsilon();
  return (std::abs(b - a) <= 2 * epsilon);
}

double rate_to_probability(const double rate) { return (1 - exp(-rate)); }

double probability_to_rate(const double p) { return (-log(1.0 - p)); }

double change_probability_time_interval(const double initial_probability,
                                        const int time_division) {
  double rate = -log(1.0 - initial_probability) / time_division;
  return rate_to_probability(rate);
}

double probability_times_relative_risk(const double initial_probability,
                                       const double relative_risk) {
  double initial_rate = -log(1 - initial_probability);
  double relative_rate = initial_rate * relative_risk;
  return rate_to_probability(relative_rate);
}

}  // namespace modeling
