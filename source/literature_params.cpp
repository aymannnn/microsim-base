#include "literature_params.h"
#include "param_distributions.h"
#include <iostream>

namespace parameters
{

void Literature::add_parameter(distributions::DistributionType const dist_type,
                               distributions::ParamType const param_type,
                               const double param1,
                               const double param2)
{
    using namespace distributions;
    if (dist_type == BETA)
    {
        Beta param;
        param.set_beta_dist(param1, param2, param_type);
        container_.push_back(param);
    }
    else if (dist_type == NORMAL)
    {
        Normal param;
        param.set_normal_dist(param1, param2, param_type);
        container_.push_back(param);
    }
    else if (dist_type == GAMMA)
    {
        Gamma param;
        param.set_gamma_dist(param1, param2, param_type);
        container_.push_back(param);
    }
    else if (dist_type == LOGNORMAL)
    {
        Lognormal param;
        param.set_lognormal_dist(param1, param2, param_type);
        container_.push_back(param);
    }
    else if (dist_type == UNIFORM)
    {
        Uniform param;
        param.set_uniform_dist(param1, param2, param_type);
        container_.push_back(param);
    }
}

Literature::Literature()
{
    add_parameter(distributions::BETA, distributions::PROBABILITY, 5, 10);
}

}