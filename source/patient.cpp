#include "patient.h"
#include "calibrated_params.h"
#include "literature_params.h"
#include "life_tables.h"
#include "common_modeling_aa.h"
#include "results.h"

// initialize static declarations
std::unique_ptr<parameters::Literature> Patient::lp_{
    std::make_unique<parameters::Literature>() };
std::unique_ptr<parameters::Calibrated> Patient::cp_{
    std::make_unique<parameters::Calibrated>() };
std::unique_ptr<Results> Patient::results{ std::make_unique<Results>() };

Patient::Patient() :
    alive_(true),
    current_age_(0),
    age_of_death_(-100),
    detected_cancer_(false),
    age_detection_(-100),
    exists_malignancy_(false)
{
    // Empty, no current calls.
}

void Patient::update_lit_params(std::unique_ptr<parameters::Literature> lp)
{
    lp_.swap(lp);
}

void Patient::update_calib_params(std::unique_ptr<parameters::Calibrated> cp)
{
    cp_.swap(cp);
}

void Patient::check_death()
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