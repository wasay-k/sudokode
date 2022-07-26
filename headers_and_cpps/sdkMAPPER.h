#include <iostream>
#include <stdio.h>
#include "sdkCHAR.h"
#include "sdkSTRING.h"
#include "sdkINTEGER.h"
#include "sdkFLOAT.h"
#pragma once
class sdkMAPPER
{
private:
    std::string identifier;
    char type;
    sdkSTRING *str_ptr;
    sdkINTEGER *int_ptr;
    sdkCHAR *char_ptr;
    sdkFLOAT *float_ptr;

public:
    sdkMAPPER(std::string var_identifier, sdkSTRING *str_ptr);
    sdkMAPPER(std::string var_identifier, sdkINTEGER *int_ptr);
    sdkMAPPER(std::string var_identifier, sdkCHAR *char_ptr);
    sdkMAPPER(std::string var_identifier, sdkFLOAT *ptr);
    char get_type();
    sdkSTRING *get_str_ptr();
    sdkINTEGER *get_int_ptr();
    sdkCHAR *get_char_ptr();
    sdkFLOAT *get_float_ptr();

    std::string get_identifier();
    ~sdkMAPPER();
};