#include "patient.h"
#include "calibrated_params.h"
#include "literature_params.h"
#include "life_tables.h"
#include "common_modeling_aa.h"

patient::patient(std::shared_ptr<parameters::Literature> copy_lit_params, 
                 std::shared_ptr<parameters::Calibrated> copy_calib_params) :
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
    //if (input_tables::Life::get_probability(current_age) < 
    //    common_modeling_aa::distributions::uniform())
    //{
    //    alive = false;
    //    age_of_death = current_age;
    //}
    // can include a cancer mortality switch before if the person has cancer
    // or some other death influencing factor
}