#include "sdkMAPPER.h"

sdkMAPPER::sdkMAPPER(std::string var_identifier, sdkSTRING *ptrarg)
{
    type = 's';
    identifier = var_identifier;
    str_ptr = ptrarg;
}
sdkMAPPER::sdkMAPPER(std::string var_identifier, sdkINTEGER *ptr)
{
    type = 'i';
    identifier = var_identifier;
    int_ptr = ptr;
}
sdkMAPPER::sdkMAPPER(std::string var_identifier, sdkCHAR *ptr)
{
    type = 'c';
    identifier = var_identifier;
    char_ptr = ptr;
}
sdkSTRING *sdkMAPPER::get_str_ptr()
{
    return str_ptr;
}
sdkINTEGER *sdkMAPPER::get_int_ptr()
{
    return int_ptr;
}
sdkCHAR *sdkMAPPER::get_char_ptr()
{
    return char_ptr;
}
char sdkMAPPER::get_type()
{
    return type;
}
std::string sdkMAPPER::get_identifier()
{
    return identifier;
}

sdkMAPPER::~sdkMAPPER()
{
}
