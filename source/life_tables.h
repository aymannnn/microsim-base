#pragma once

#include <array>

enum gender;

class life_tables
{
public:
    static void set_table(gender const &gend);
    static std::array<double, 100> table;
private:
    static std::array<double, 100> male;
    static std::array<double, 100> female;
    static std::array<double, 100> all;
};