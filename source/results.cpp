
#include "results.h"


// Because lazy...
char Results::ofs = '\t';
char Results::nl = '\n';

Results::Results() :
    cancer_incidence{},
    deaths{}
{
}

void Results::process_patient(Patient const & p)
{
    // now we add to the arrays where we want...
}

void Results::print_results()
{
    // etc...
}
