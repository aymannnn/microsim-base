#pragma once
#include <vector>
#include <map>
#include <string>

namespace distributions
{

namespace literature
{

enum ParamType;
enum DistributionType;
class Base;

} // end forward declarations for literature

} // end forward declaration for distributions


namespace parameters
{

class Literature
{
public:
    Literature();
    std::map<std::string, distributions::literature::Base> params;
private:
    void add_parameter(
        distributions::literature::DistributionType const dist_type,
        distributions::literature::ParamType const param_type,
        const std::string param_key, const double param1, const double param2);
};


} // end namespace Parameters

