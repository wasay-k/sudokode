#include "sdkFLOAT.h"

sdkFLOAT::sdkFLOAT(std::string var_identifier, float var_value, std::string init_type)
{
    identifier = var_identifier;
    value = var_value;
    if (init_type == "CONST")
    {
        is_const = true;
    }
}
void sdkFLOAT::set_value(float value_to_set)
{
    if (is_const = false)
    {
        value = value_to_set;
    }
    else
    {
        std::cout << "ERROR: Attempting to assign value to a constant variable" << std::endl;
    }
}
float sdkFLOAT::get_value()
{
    return value;
}
std::string sdkFLOAT::get_identifier()
{
    return identifier;
}
sdkFLOAT::~sdkFLOAT()
{
}