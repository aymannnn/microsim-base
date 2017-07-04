#pragma once

#include <memory>

class calibrated_params;
class LiteratureParams;

// File will hold patient class and characteristics.

class patient
{
public:

    std::shared_ptr<LiteratureParams> lp;
    std::shared_ptr<calibrated_params> cp;
    
    bool alive;
    int current_age;
    int age_of_death;
    bool detected_cancer;
    int age_detection;
    bool exists_malignancy;

public:

    void check_death();
    patient(std::shared_ptr<LiteratureParams> copy_lit_params,
            std::shared_ptr<calibrated_params> copy_calib_params);



};