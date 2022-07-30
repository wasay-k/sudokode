#include "sdkSTRING.h"
#include <iostream>

sdkSTRING::sdkSTRING(std::string var_identifier, std::string init_type, std::string var_value)
{
    identifier = var_identifier;
    value = var_value;
    if (init_type == "CONST")
    {
        is_const = true;
    }
}
void sdkSTRING::set_value(std::string value_to_set)
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
std::string sdkSTRING::get_value()
{
    return value;
}
std::string sdkSTRING::get_identifier()
{
    return identifier;
}
sdkSTRING::~sdkSTRING()
{
}