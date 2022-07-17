#include <iostream>
#include <stdio.h>
#include <vector>
#include "processor.h"
#include <sstream>
void processLine(std::string line, std::vector<sdkSTRING> &str_v, std::vector<sdkINTEGER> &int_v)
{

    std::string block;
    std::stringstream line_stream(line);
    std::stringstream *ptr = &line_stream;
    line_stream >> block;
    std::cout << block << std::endl;
    if (block == "DECLARE")
    {
        std::cout << "Variable initialization started" << std::endl;
        std::string var_identifier, symbol, var_type;
        line_stream >> var_identifier >> symbol >> var_type;
        if (var_type == "STRING")
        {
            std::string var_value;
            sdkSTRING temp_str(var_identifier, " ");
            line_stream >> symbol;
            std::cout << "symbol is " << symbol << std::endl;
            if (symbol == "=")
            {
                line_stream >> var_value;
                temp_str.set_value(var_value);
                std::cout << "Trynna initialize " << temp_str.get_identifier() << " with value " << temp_str.get_value() << std::endl;
                str_v.push_back(temp_str);
            }
            else
            {
                std::cout << "Trynna initialize " << temp_str.get_identifier() << " uninitialized value" << std::endl;
                str_v.push_back(temp_str);
            }
        }
        else if (var_type == "INTEGER")
        {
            int var_value;
            sdkINTEGER temp_int(var_identifier, -255);
            line_stream >> symbol;
            if (symbol == "=")
            {
                line_stream >> var_value;
                temp_int.set_value(var_value);
                std::cout << "Trynna initialize " << temp_int.get_identifier() << " with value " << temp_int.get_value() << std::endl;
                int_v.push_back(temp_int);
            }
            else
            {
                std::cout << "Trynna initialize " << temp_int.get_identifier() << " uninitialized value" << std::endl;
                int_v.push_back(temp_int);
            }
        }
    }
}