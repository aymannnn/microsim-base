#pragma once

#include <memory>

namespace parameters
{
class Calibrated;
class Literature;
}

class patient
{
public:

    std::shared_ptr<parameters::Literature> lp;
    std::shared_ptr<parameters::Calibrated> cp;
    
    bool alive;
    int current_age;
    int age_of_death;
    bool detected_cancer;
    int age_detection;
    bool exists_malignancy;

public:

    void check_death();
    patient(std::shared_ptr<parameters::Literature> copy_lit_params,
            std::shared_ptr<parameters::Calibrated> copy_calib_params);



};