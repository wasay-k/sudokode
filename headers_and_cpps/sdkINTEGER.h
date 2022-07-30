#include <iostream>
#include <stdio.h>
#pragma once

class sdkINTEGER
{
private:
    std::string identifier;
    int value;
    int *ptr;
    bool is_const = false;

public:
    sdkINTEGER(std::string var_identifier, std::string init_type = "nCONST", int var_value = 2364367);
    void set_value(int value_to_set);
    int get_value();
    std::string get_identifier();
    ~sdkINTEGER();
};
