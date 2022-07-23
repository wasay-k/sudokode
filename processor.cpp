#include <iostream>
#include <stdio.h>
#include <vector>
#include "processor.h"
#include "utilities.h"
#include <sstream>
void processLine(std::string line, std::vector<sdkMAPPER> &map_vector, std::vector<sdkSTRING> &str_v, std::vector<sdkINTEGER> &int_v, std::vector<sdkCHAR> &char_v, std::ofstream &log_file)
{

    std::string block;
    std::stringstream line_stream(line);
    std::stringstream *ptr = &line_stream;
    line_stream >> block;
    if (block == "DECLARE")
    {
        std::string var_identifier, symbol, var_type;
        line_stream >> var_identifier >> symbol >> var_type;
        if (var_type == "STRING")
        {
            std::string var_value;
            sdkSTRING temp_str(var_identifier, " ", "nCONST");
            line_stream >> symbol;
            std::cout << "symbol is " << symbol << std::endl;
            if (symbol == "<-")
            {
                line_stream >> var_value;
                temp_str.set_value(var_value);
                dump(log_file, "Trynna initialize " + temp_str.get_identifier() + " with value " + temp_str.get_value());
                str_v.push_back(temp_str);
                sdkMAPPER temp_map(str_v.back().get_identifier(), &(str_v.back()));
                map_vector.push_back(temp_map);
            }
            else
            {
                dump(log_file, "Trynna initialize " + temp_str.get_identifier() + " uninitialized value");
                str_v.push_back(temp_str);
                std::cout << str_v.size();
                sdkMAPPER temp_map(str_v.back().get_identifier(), &(str_v.back()));
                map_vector.push_back(temp_map);
            }
        }
        else if (var_type == "INTEGER")
        {
            int var_value;
            sdkINTEGER temp_int(var_identifier, -255, "nCONST");
            line_stream >> symbol;
            if (symbol == "<-")
            {
                line_stream >> var_value;
                temp_int.set_value(var_value);
                dump(log_file, "Trynna initialize " + temp_int.get_identifier() + " with value " + std::to_string(temp_int.get_value()));
                int_v.push_back(temp_int);
                sdkMAPPER temp_map(int_v.back().get_identifier(), &(int_v.back()));
                map_vector.push_back(temp_map);
            }
            else
            {
                dump(log_file, "Trynna initialize " + temp_int.get_identifier() + " uninitialized value");
                int_v.push_back(temp_int);
                sdkMAPPER temp_map(int_v.back().get_identifier(), &(int_v.back()));
                map_vector.push_back(temp_map);
            }
        }
        else if (var_type == "CHAR")
        {
            char var_value;
            sdkCHAR temp_char(var_identifier, '`', "nCONST");
            line_stream >> symbol;
            if (symbol == "<-")
            {
                line_stream >> var_value;
                temp_char.set_value(var_value);
                dump(log_file, "Trynna initialize " + temp_char.get_identifier() + " with value " + temp_char.get_value());
                char_v.push_back(temp_char);
                sdkMAPPER temp_map(char_v.back().get_identifier(), &(char_v.back()));
                map_vector.push_back(temp_map);
            }
            else
            {
                dump(log_file, "Trynna initialize " + temp_char.get_identifier() + " uninitialized value");
                char_v.push_back(temp_char);
                sdkMAPPER temp_map(char_v.back().get_identifier(), &(char_v.back()));
                map_vector.push_back(temp_map);
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
            dump(log_file, "Initiazlzing const of type char with value " + std::to_string(temp_char.get_value()) + " and identifier " + temp_char.get_identifier());
            char_v.push_back(temp_char);
            sdkMAPPER temp_map(char_v.back().get_identifier(), &(char_v.back()));
            map_vector.push_back(temp_map);
        }
        else if (value_dtype == 's')
        {
            var_value.erase(var_value.begin());
            var_value.erase(var_value.end() - 1);
            sdkSTRING temp_str(var_identifier, var_value, "CONST");
            dump(log_file, "Initiazlzing const of type string with value " + temp_str.get_value() + " and identifier " + temp_str.get_identifier());
            str_v.push_back(temp_str);
            sdkMAPPER temp_map(str_v.back().get_identifier(), &(str_v.back()));
            map_vector.push_back(temp_map);
        }
        else if (value_dtype == 'i')
        {
            int real_value;
            std::stringstream(var_value) >> real_value;
            sdkINTEGER temp_int(var_identifier, real_value, "CONST");
            dump(log_file, "Initiazlzing const of type int with value " + std::to_string(temp_int.get_value()) + " and identifier " + temp_int.get_identifier());
            int_v.push_back(temp_int);
            sdkMAPPER temp_map(int_v.back().get_identifier(), &(int_v.back()));
            map_vector.push_back(temp_map);
        }
    }
    else
    {
        bool identifier_found = false;
        for (auto &kw : map_vector)
        {
            if (block == kw.get_identifier())
            {
                identifier_found = true;
                std::cout << "Identifier " << kw.get_identifier() << " of type " << kw.get_type();
                if (kw.get_type() == 's')
                {
                    std::cout << " found at address " << kw.get_str_ptr() << std::endl;
                }
                else if (kw.get_type() == 'i')
                {
                    std::cout << " found at address " << kw.get_int_ptr() << std::endl;
                }
                else if (kw.get_type() == 'c')
                {
                    std::cout << " found at address " << kw.get_char_ptr() << std::endl;
                }

                break;
            }
        }
        if (!identifier_found)
        {
            dump(log_file, "Identifier " + block + " is undefined");
        }
    }
}