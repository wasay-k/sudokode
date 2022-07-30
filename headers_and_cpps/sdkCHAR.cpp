#include "sdkCHAR.h"
#include <iostream>

sdkCHAR::sdkCHAR(std::string var_identifier, std::string init_type, char var_value)
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