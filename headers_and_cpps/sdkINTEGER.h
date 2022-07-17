#include <iostream>
#include <stdio.h>
#pragma once

class sdkINTEGER
{
private:
    std::string identifier;
    int value;
    int *ptr;

public:
    sdkINTEGER(std::string var_identifier, int var_value);
    void set_value(int value_to_set);
    int get_value();
    std::string get_identifier();
    ~sdkINTEGER();
};
