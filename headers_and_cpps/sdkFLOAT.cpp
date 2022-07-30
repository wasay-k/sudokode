#include "sdkFLOAT.h"

sdkFLOAT::sdkFLOAT(std::string var_identifier, std::string init_type, float var_value)
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
    if (!is_const)
    {
        value = value_to_set;
        std::cout << "Set value " << value << " to variable " << identifier << '.' << std::endl;
    }
    else
    {
        std::cout << "ERROR: Assigning value to constant variable " << identifier << std::endl;
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