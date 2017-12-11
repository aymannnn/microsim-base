#pragma once

namespace modeling {

template <typename T, int ROWS, int COLS>
using array_2d = std::array<std::array<T, COLS>, ROWS>;

bool dbl_eq(const double a, const double b);

double rate_to_probability(const double rate);

double probability_to_rate(const double p);

double change_probability_time_interval(const double initial_probability,
                                        const int time_division);

double probability_times_relative_risk(const double initial_probability,
                                       const double relative_risk);

}  // namespace modeling
