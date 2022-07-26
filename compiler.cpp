#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "processor.h"
#include "headers_and_cpps/sdkSTRING.h"
#include "headers_and_cpps/sdkINTEGER.h"
#include "headers_and_cpps/sdkCHAR.h"
#include "utilities.h"
#include <vector>

int main(int argc, char **argv)
{
    std::vector<sdkINTEGER> global_ints;
    std::vector<sdkSTRING> global_strings;
    std::vector<sdkCHAR> global_chars;
    std::vector<sdkFLOAT> global_floats;
    std::vector<sdkMAPPER> global_mappers;
    std::ifstream codeFile;
    std::ofstream dump_file;
    if (std::filesystem::exists(argv[2]))
    {
        dump_file.open(argv[2], std::ofstream::out | std::ofstream::trunc);
    }
    else
    {
        dump_file.open(argv[2]);
    }

    codeFile.open(argv[1]);

    std::string line;
    if (codeFile.is_open())
    {
        while (getline(codeFile, line))
        {
            processLine(line, global_mappers, global_strings, global_ints, global_chars, global_floats, dump_file);
        }
        codeFile.close();
    }
    else
    {
        std::cout << "ERROR: File could not be opened." << std::endl;
    }
    codeFile.close();
    dump_file.close();

    return 0;
}
