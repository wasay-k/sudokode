#include <iostream>
#include <stdio.h>
#pragma once

class sdkCHAR
{
private:
    std::string identifier;
    char value;
    char *ptr;
    bool is_const = false;

public:
    sdkCHAR(std::string var_identifier, std::string init_type = "nCONST", char value_to_set = '~');
    void set_value(char value_to_set);
    char get_value();
    std::string get_identifier();
    ~sdkCHAR();
};
