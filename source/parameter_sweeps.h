#pragma once
#include <string>

struct UserDefinedItems {
  struct CalibrationParameters {
    void step();
    void random();
    void print();
    // Default constructor
    CalibrationParameters();
    // Assignment operator overload
    CalibrationParameters &operator=(const CalibrationParameters &rhs);
  };
  static double function_to_minimize(const CalibrationParameters &cp);
  static void print_results(const CalibrationParameters &cp);
};

namespace modeling {

namespace parameter_search {

void simulated_annealing();
void greedy_randomized_adaptive_search();
void greedy();
void totally_random();
void original_ayman();

}  // namespace parameter_search

}  // namespace modeling
