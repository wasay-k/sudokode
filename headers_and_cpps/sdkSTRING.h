#include <stdio.h>
#include <iostream>
#pragma once

class sdkSTRING
{
private:
    std::string identifier;
    std::string variable_value;
    std::string *ptr;

public:
    sdkSTRING(std::string var_identifier, std::string variable_value);
    void set_value(std::string var_value);
    std::string get_identifier();
    std::string get_value();
    sdkSTRING();
    ~sdkSTRING();
};
