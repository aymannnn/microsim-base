#include "stdafx.h"
#include "modeling_aa.hpp"
#include "life_tables.h"
#include "configuration.h"

boost::random::mt19937 often_aa::rng::generator_(15);

int main()
{
    life_tables::set_table(MALE);
    return 0;
}

