#include "literature_params.h"
#include "distributions_literature.h"
#include <iostream>


namespace parameters
{

void Literature::add_parameter(
    distributions::literature::DistributionType const dist_type,
    distributions::literature::ParamType const param_type,
    const std::string param_key, const double param1, const double param2)
{
    using namespace distributions::literature;
    if (dist_type == BETA)
    {
        Beta param;
        param.set_beta_dist(param1, param2, param_type);
        params[param_key] = param;
    }
    else if (dist_type == NORMAL)
    {
        Normal param;
        param.set_normal_dist(param1, param2, param_type);
        params[param_key] = param;
    }
    else if (dist_type == GAMMA)
    {
        Gamma param;
        param.set_gamma_dist(param1, param2, param_type);
        params[param_key] = param;
    }
    else if (dist_type == LOGNORMAL)
    {
        Lognormal param;
        param.set_lognormal_dist(param1, param2, param_type);
        params[param_key] = param;
    }
    else if (dist_type == UNIFORM)
    {
        Uniform param;
        param.set_uniform_dist(param1, param2, param_type);
        params[param_key] = param;
    }
}

Literature::Literature()
{
    using namespace distributions::literature;
    add_parameter(BETA, PROBABILITY, "death", 5, 10);
}

}