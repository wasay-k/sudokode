#include <stdio.h>
#include <iostream>
#include "utilities.h"

char evaluate_dtype(std::string data)
{
    bool is_string = false;
    bool is_int = false;
    bool is_char = false;
    auto result = data.find("\"");
    if (result != std::string::npos)
    {
        is_string = true;
        return 's';
    }
    else
    {
        auto result = data.find("\'");
        if (result != std::string::npos)
        {
            is_char = true;
            return 'c';
        }
        else
        {
            int result = int(data[0]);
            if (result >= 48 && result <= 57 && (data.find(".") == std::string::npos))
            {
                return 'i';
            }
            else
            {
                auto result = data.find(".");
                if (result != std::string::npos)
                {
                    return 'f';
                }
            }
        }
    }
}

void dump(std::ofstream &dump_file, std::string d_to_dump)
{
    dump_file << d_to_dump << '\n';
}
