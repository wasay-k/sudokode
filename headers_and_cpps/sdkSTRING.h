#include <stdio.h>
#include <iostream>
#pragma once

class sdkSTRING
{
private:
    std::string identifier;
    std::string value;
    std::string *ptr;
    bool is_const = false;

public:
    sdkSTRING(std::string var_identifier, std::string init_type = "nCONST", std::string variable_value = "undefined");
    void set_value(std::string var_value);
    std::string get_identifier();
    std::string get_value();
    sdkSTRING();
    ~sdkSTRING();
};
