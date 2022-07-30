#include <iostream>
#include <stdio.h>
#include <vector>
#include "processor.h"
#include "utilities.h"
#include <sstream>

void processLine(std::string line, custom_types &global_types, std::ofstream &log_file)
{

    std::string block;
    std::stringstream line_stream(line);
    std::stringstream *ptr = &line_stream;
    line_stream >> block;
    if (block == "DECLARE")
    {
        declare_variable(line_stream, global_types, log_file);
    }
    else if (block == "CONSTANT")
    {
        declare_constant(line_stream, global_types, log_file);
    }
    else
    {
        bool identifier_found = false;
        for (auto &kw : global_types.mappers)
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
void declare_variable(std::stringstream &line, custom_types &global_types, std::ofstream &log_file)
{
    std::string var_identifier, symbol, var_type;
    line >> var_identifier >> symbol >> var_type;
    if (var_type == "STRING")
    {
        std::string var_value;
        sdkSTRING temp_str(var_identifier);
        line >> symbol;
        if (symbol == "<-")
        {
            line >> var_value;
            temp_str.set_value(var_value);
            dump(log_file, "Initialized " + temp_str.get_identifier() + " of type STRING with value " + temp_str.get_value());
            global_types.strings.push_back(temp_str);
            sdkMAPPER temp_map(global_types.strings.back().get_identifier(), &(global_types.strings.back()));
            global_types.mappers.push_back(temp_map);
        }
        else
        {
            dump(log_file, "Initialized " + temp_str.get_identifier() + " of type STRING with uninitialized value.");
            global_types.strings.push_back(temp_str);
            sdkMAPPER temp_map(global_types.strings.back().get_identifier(), &(global_types.strings.back()));
            global_types.mappers.push_back(temp_map);
        }
    }
    else if (var_type == "INTEGER")
    {
        int var_value;
        sdkINTEGER temp_int(var_identifier);
        line >> symbol;
        if (symbol == "<-")
        {
            line >> var_value;
            temp_int.set_value(var_value);
            dump(log_file, "Initialized " + temp_int.get_identifier() + " of type INTEGER with value " + std::to_string(temp_int.get_value()));
            global_types.ints.push_back(temp_int);
            sdkMAPPER temp_map(global_types.ints.back().get_identifier(), &(global_types.ints.back()));
            global_types.mappers.push_back(temp_map);
        }
        else
        {
            dump(log_file, "Initialized" + temp_int.get_identifier() + " of type INTEGER with uninitialized value.");
            global_types.ints.push_back(temp_int);
            sdkMAPPER temp_map(global_types.ints.back().get_identifier(), &(global_types.ints.back()));
            global_types.mappers.push_back(temp_map);
        }
    }
    else if (var_type == "CHAR")
    {
        std::string var_value;
        sdkCHAR temp_char(var_identifier);
        line >> symbol;
        std::cout << symbol << std::endl;
        if (symbol == "<-")
        {
            line >> var_value;
            var_value.erase(0, 1);
            var_value.erase(var_value.end() - 1);
            char real_value = var_value[0];
            temp_char.set_value(real_value);
            dump(log_file, "Initizalized var with identifier" + temp_char.get_identifier() + " of type char with value " + temp_char.get_value());
            global_types.chars.push_back(temp_char);
            sdkMAPPER temp_map(global_types.chars.back().get_identifier(), &(global_types.chars.back()));
            global_types.mappers.push_back(temp_map);
        }
        else
        {
            dump(log_file, "Initialized var with identifier " + temp_char.get_identifier() + " of type char with uninitialized value.");
            global_types.chars.push_back(temp_char);
            sdkMAPPER temp_map(global_types.chars.back().get_identifier(), &(global_types.chars.back()));
            global_types.mappers.push_back(temp_map);
        }
    }
    else if (var_type == "FLOAT")
    {
        float var_value;
        sdkFLOAT temp_float(var_identifier);
        line >> symbol;
        if (symbol == "<-")
        {
            line >> var_value;
            temp_float.set_value(var_value);
            dump(log_file, "Initialized var wiht identifier " + temp_float.get_identifier() + " of type float with value " + std::to_string(temp_float.get_value()));
            global_types.floats.push_back(temp_float);
            sdkMAPPER temp_map(global_types.floats.back().get_identifier(), &(global_types.floats.back()));
            global_types.mappers.push_back(temp_map);
        }
        else
        {
            dump(log_file, "Inititialized var with identifier " + temp_float.get_identifier() + " of type float with uninitialized value.");
            global_types.floats.push_back(temp_float);
            sdkMAPPER temp_map(global_types.floats.back().get_identifier(), &(global_types.floats.back()));
            global_types.mappers.push_back(temp_map);
        }
    }
}

void declare_constant(std::stringstream &line_stream, custom_types &global_types, std::ofstream &log_file)
{
    std::string var_identifier, symbol, var_value;
    line_stream >> var_identifier >> symbol >> var_value;
    char value_dtype = evaluate_dtype(var_value);
    if (value_dtype == 'c')
    {
        var_value.erase(0, 1);
        var_value.erase(var_value.end() - 1);
        char real_value = var_value[0];
        sdkCHAR temp_char(var_identifier, "CONST", real_value);
        dump(log_file, "Initialized const of type char with value " + std::string(1, temp_char.get_value()) + " and identifier " + temp_char.get_identifier());
        global_types.chars.push_back(temp_char);
        sdkMAPPER temp_map(global_types.chars.back().get_identifier(), &(global_types.chars.back()));
        global_types.mappers.push_back(temp_map);
    }
    else if (value_dtype == 's')
    {
        var_value.erase(var_value.begin());
        var_value.erase(var_value.end() - 1);
        sdkSTRING temp_str(var_identifier, "CONST", var_value);
        dump(log_file, "Initialized const of type string with value " + temp_str.get_value() + " and identifier " + temp_str.get_identifier());
        global_types.strings.push_back(temp_str);
        sdkMAPPER temp_map(global_types.strings.back().get_identifier(), &(global_types.strings.back()));
        global_types.mappers.push_back(temp_map);
    }
    else if (value_dtype == 'i')
    {
        int real_value;
        std::stringstream(var_value) >> real_value;
        sdkINTEGER temp_int(var_identifier, "CONST", real_value);
        dump(log_file, "Initialized const of type int with value " + std::to_string(temp_int.get_value()) + " and identifier " + temp_int.get_identifier());
        global_types.ints.push_back(temp_int);
        sdkMAPPER temp_map(global_types.ints.back().get_identifier(), &(global_types.ints.back()));
        global_types.mappers.push_back(temp_map);
    }
    else if (value_dtype == 'f')
    {
        float real_value;
        std::stringstream(var_value) >> real_value;
        sdkFLOAT temp_float(var_identifier, "CONST", real_value);
        dump(log_file, "Initialized const of type float with value " + std::to_string(temp_float.get_value()) + " and identifier " + temp_float.get_identifier());
        global_types.floats.push_back(temp_float);
        sdkMAPPER temp_map(global_types.floats.back().get_identifier(), &(global_types.floats.back()));
        global_types.mappers.push_back(temp_map);
    }
}