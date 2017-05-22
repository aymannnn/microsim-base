#pragma once
#include "stdafx.h"
#include <memory>

class calibrated_params;
class literature_params;

// File will hold patient class and characteristics.

class patient
{
public:

    std::shared_ptr<literature_params> lp;
    std::shared_ptr<calibrated_params> cp;
    
    bool alive;
    int current_age;
    int age_of_death;
    bool detected_cancer;
    int age_detection;
    bool exists_malignancy;

public:

    void check_death();
    patient(std::shared_ptr<literature_params> copy_lit_params,
            std::shared_ptr<calibrated_params> copy_calib_params);



};