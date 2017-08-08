#pragma once

#include <memory>

namespace parameters
{
class Calibrated;
class Literature;
}

class Results;

class Patient
{

    static std::unique_ptr<Results> results;
    static std::unique_ptr<parameters::Literature> lp_;
    static std::unique_ptr<parameters::Calibrated> cp_;

private:

    bool alive_;
    int current_age_;
    int age_of_death_;
    bool detected_cancer_;
    int age_detection_;
    bool exists_malignancy_;
    void check_death();

public:

    Patient();
    void update_lit_params(std::unique_ptr<parameters::Literature> lp);
    void update_calib_params(std::unique_ptr<parameters::Calibrated> cp);
};