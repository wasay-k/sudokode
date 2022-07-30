#include <iostream>
#include <stdio.h>
#pragma once
class sdkFLOAT
{
private:
    std::string identifier;
    float value;
    float *ptr;
    bool is_const = false;

public:
    sdkFLOAT(std::string var_identifier, std::string init_type = "nCONST", float var_value = 457547845.98574357);
    void set_value(float value_to_set);
    float get_value();
    std::string get_identifier();
    ~sdkFLOAT();
};
