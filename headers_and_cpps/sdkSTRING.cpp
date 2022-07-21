#include "sdkSTRING.h"
#include <iostream>

sdkSTRING::sdkSTRING(std::string var_identifier, std::string var_value, std::string init_type)
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
    if (is_const == false)
    {
        value = value_to_set;
    }
    else
    {
        std::cout << "ERROR: Attempting to assign value to a constant variable" << std::endl;
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