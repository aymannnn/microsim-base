#pragma once
#include <array>
#include <vector>
#include <atomic>

class Patient;


class Results
{
    using annual_array = std::array<double, 100>;
    using two_d_vec_double = std::vector<std::vector<double>>;

private:
    annual_array cancer_incidence;
    annual_array deaths;
    static char ofs;
    static char nl;
public:
    Results();
    void process_patient(Patient const &p);
    void print_results();
};