#pragma once
#include <array>

namespace parameters
{
enum Gender;
}

namespace input_tables
{
class Life
{
    // Life tables are almost always from age 0 to 100 ... 
    // table[a] returns the probability of death from age [a, a+1)
public:
    static void set_table(parameters::Gender const gend);
    static const double get_probability(const int age_in_years);
private:
    static std::array<double, 100> table;
    static std::array<double, 100> male;
    static std::array<double, 100> female;
    static std::array<double, 100> all;
};

}