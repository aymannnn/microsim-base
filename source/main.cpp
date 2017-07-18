#include "life_tables.h"
#include "configuration.h"
#include "common_modeling_aa.h"

int main()
{
    input_tables::Life::set_table(parameters::MALE);
    return 0;
}