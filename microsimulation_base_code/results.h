#pragma once
#include "stdafx.h"
#include <array>
#include "modeling_aa.hpp"

class patient;

class results
{
    using annual_array = std::array<double, 100>;
    // Just an example of a 2D array template that I really like to use
    // because std::array 2D arrays are ugly
    using age_calendar_array = often_aa::two_d_array<double, 100, 15>;
private:
    annual_array cancer_incidence;
    age_calendar_array deaths;
    static char ofs;
    static char nl;
public:
    results();
    void process_patient(patient const &p);
    void print_results();
};