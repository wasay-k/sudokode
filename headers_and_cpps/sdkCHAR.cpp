#include "sdkCHAR.h"
#include <iostream>

sdkCHAR::sdkCHAR(std::string var_identifier, char var_value, std::string init_type)
{
    identifier = var_identifier;
    value = var_value;
    if (init_type == "CONST")
    {
        is_const = true;
    }
}
void sdkCHAR::set_value(char value_to_set)
{
    if (is_const == false)
    {
        value = value_to_set;
    }
    else
    {
        std::cout << "ERROR: Assigning value to a constant variable!" << std::endl;
    }
}
char sdkCHAR::get_value()
{
    return value;
}
std::string sdkCHAR::get_identifier()
{
    return identifier;
}
sdkCHAR::~sdkCHAR()
{
}