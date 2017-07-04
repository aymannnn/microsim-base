
#include "results.h"


// Because lazy...
char results::ofs = '\t';
char results::nl = '\n';

results::results() :
    cancer_incidence{},
    deaths{}
{
}

void results::process_patient(patient const & p)
{
    // now we add to the arrays where we want...
}

void results::print_results()
{
    // etc...
}
