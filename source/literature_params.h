#pragma once
#include <vector>

namespace parameters
{

namespace distributions // forward declarations
{

enum ParamType;
enum DistributionType;
class Base;

} // end forward declarations for distributions

enum LiteratureEnum
{
    EXAMPLE_LP,
    NUMBER_OF_LPS
};

class Literature
{
public:
    Literature();
    std::vector<distributions::Base> container_;
private:
    void add_parameter(distributions::DistributionType const dist_type,
                       distributions::ParamType const param_type,
                       const double param1, const double param2);
};


} // end namespace Parameters

