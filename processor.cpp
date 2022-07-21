#include <iostream>
#include <stdio.h>
#include <vector>
#include "processor.h"
#include "utilities.h"
#include <sstream>
void processLine(std::string line, std::vector<std::string> &id_vector, std::vector<sdkSTRING> &str_v, std::vector<sdkINTEGER> &int_v, std::vector<sdkCHAR> &char_v)
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
            sdkSTRING temp_str(var_identifier, " ", "nCONST");
            line_stream >> symbol;
            std::cout << "symbol is " << symbol << std::endl;
            if (symbol == "=")
            {
                line_stream >> var_value;
                temp_str.set_value(var_value);
                std::cout << "Trynna initialize " << temp_str.get_identifier() << " with value " << temp_str.get_value() << std::endl;
                id_vector.push_back(temp_str.get_identifier());
                str_v.push_back(temp_str);
            }
            else
            {
                std::cout << "Trynna initialize " << temp_str.get_identifier() << " uninitialized value" << std::endl;
                id_vector.push_back(temp_str.get_identifier());
                str_v.push_back(temp_str);
            }
        }
        else if (var_type == "INTEGER")
        {
            int var_value;
            sdkINTEGER temp_int(var_identifier, -255, "nCONST");
            line_stream >> symbol;
            if (symbol == "=")
            {
                line_stream >> var_value;
                temp_int.set_value(var_value);
                std::cout << "Trynna initialize " << temp_int.get_identifier() << " with value " << temp_int.get_value() << std::endl;
                id_vector.push_back(temp_int.get_identifier());
                int_v.push_back(temp_int);
            }
            else
            {
                std::cout << "Trynna initialize " << temp_int.get_identifier() << " uninitialized value" << std::endl;
                id_vector.push_back(temp_int.get_identifier());
                int_v.push_back(temp_int);
            }
        }
        else if (var_type == "CHAR")
        {
            char var_value;
            sdkCHAR temp_char(var_identifier, '`', "nCONST");
            line_stream >> symbol;
            if (symbol == "=")
            {
                line_stream >> var_value;
                temp_char.set_value(var_value);
                std::cout << "Trynna initialize " << temp_char.get_identifier() << " with value " << temp_char.get_value() << std::endl;
                id_vector.push_back(temp_char.get_identifier());
                char_v.push_back(temp_char);
            }
            else
            {
                std::cout << "Trynna initialize " << temp_char.get_identifier() << " uninitialized value" << std::endl;
                id_vector.push_back(temp_char.get_identifier());
                char_v.push_back(temp_char);
            }
        }
    }
    else if (block == "CONSTANT")
    {
        std::string var_identifier, symbol, var_value;
        line_stream >> var_identifier >> symbol >> var_value;
        char value_dtype = evaluate_dtype(var_value);
        if (value_dtype == 'c')
        {
            var_value.erase(0, 1);
            var_value.erase(var_value.end() - 1);
            char real_value = var_value[0];
            sdkCHAR temp_char(var_identifier, real_value, "CONST");
            std::cout << "Initiazlzing const of type char with value " << temp_char.get_value() << " and identifier " << temp_char.get_identifier() << std::endl;
            id_vector.push_back(temp_char.get_identifier());
            char_v.push_back(temp_char);
        }
        else if (value_dtype == 's')
        {
            var_value.erase(var_value.begin());
            var_value.erase(var_value.end() - 1);
            sdkSTRING temp_str(var_identifier, var_value, "CONST");
            std::cout << "Initiazlzing const of type string with value " << temp_str.get_value() << " and identifier " << temp_str.get_identifier() << std::endl;
            id_vector.push_back(temp_str.get_identifier());
            str_v.push_back(temp_str);
        }
        else if (value_dtype == 'i')
        {
            var_value.erase(var_value.begin());
            var_value.erase(var_value.end() - 1);
            std::cout << var_value << std::endl;
            /*  for(auto &ch : var_value){

             }
             sdkINTEGER temp_int(var_identifier, var_value, "CONST");
             std::cout << "Initiazlzing const of type string with value " << temp_str.get_value() << " and identifier " << temp_str.get_identifier() << std::endl;
             id_vector.push_back(temp_str.get_identifier());
             str_v.push_back(temp_str); */
        }
    }
}