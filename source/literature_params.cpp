
#include "literature_params.h"
#include "parameter_distributions.h"

void literature_params::add_parameter(distribution_type_t const & dist_type,
                                      param_type_t const & param_type,
                                      const double & param1,
                                      const double & param2)
{
    if (dist_type == BETA)
    {
        beta_param param;
        param.set_beta_dist(param1, param2, param_type);
        container_.push_back(param);
    }
    else if (dist_type == NORMAL)
    {
        normal_dist_param param;
        param.set_normal_dist(param1, param2, param_type);
        container_.push_back(param);
    }
    else if (dist_type == GAMMA)
    {
        gamma_dist_param param;
        param.set_gamma_dist(param1, param2, param_type);
        container_.push_back(param);
    }
    else if (dist_type == LOGNORMAL)
    {
        lognormal_dist_param param;
        param.set_lognormal_dist(param1, param2, param_type);
        container_.push_back(param);
    }
    else if (dist_type == UNIFORM)
    {
        uniform_param param;
        param.set_uniform_dist(param1, param2, param_type);
        container_.push_back(param);
    }
}

literature_params::literature_params()
{
    add_parameter(BETA, PROBABILITY, 5, 10);
}


