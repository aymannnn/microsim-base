
#include "life_tables.h"
#include "configuration.h"
#include <iostream>

// TODO: Use appropriate life tables.

std::array<double, 100> life_tables::male = 
{

};

std::array<double, 100> life_tables::female =
{

};

std::array<double, 100> life_tables::all =
{

};

std::array<double, 100> life_tables::table{ 0 };

void life_tables::set_table(gender const &gend)
{
    switch (gend)
    {
        case MALE:
            table = male;
            break;
        case FEMALE:
            table = female;
            break;
        case ALL:
            table = all;
            break;
        default:
            std::cout << "\nError setting life tables.";
    }
}