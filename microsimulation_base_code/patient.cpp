#include "stdafx.h"
#include "patient.h"
#include "calibrated_params.h"
#include "literature_params.h"
#include "life_tables.h"
#include "modeling_aa.hpp"

patient::patient(std::shared_ptr<LiteratureParams> copy_lit_params, 
                 std::shared_ptr<calibrated_params> copy_calib_params) :
    lp(copy_lit_params),
    cp(copy_calib_params),
    alive(true),
    current_age(0),
    age_of_death(-100),
    detected_cancer(false),
    age_detection(-100),
    exists_malignancy(false)
{
    // Empty, no current calls.
}

void patient::check_death()
{
    // check lookup table for death, use life tables file static member
    // that switches based on the settings
    if (life_tables::table[current_age] < often_aa::rng::uniform())
    {
        alive = false;
        age_of_death = current_age;
    }
    // can include a cancer mortality switch before if the person has cancer
    // or some other death influencing factor
}