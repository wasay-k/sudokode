#include "sdkINTEGER.h"
#include <iostream>

sdkINTEGER::sdkINTEGER(std::string var_identifier, int var_value, std::string init_type)
{
    identifier = var_identifier;
    value = var_value;
    if (init_type == "CONST")
    {
        is_const = true;
    }
}
void sdkINTEGER::set_value(int value_to_set)
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
int sdkINTEGER::get_value()
{
    return value;
}
std::string sdkINTEGER::get_identifier()
{
    return identifier;
}
sdkINTEGER::~sdkINTEGER()
{
}