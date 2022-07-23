#include <stdio.h>
#include <iostream>
#include <fstream>
#include "processor.h"
#include "headers_and_cpps/sdkSTRING.h"
#include "headers_and_cpps/sdkINTEGER.h"
#include "headers_and_cpps/sdkCHAR.h"
#include "utilities.h"
#include <vector>

void declare_var();

int main(int argc, char **argv)
{
    std::vector<sdkINTEGER> global_ints;
    std::vector<sdkSTRING> global_strings;
    std::vector<sdkCHAR> global_chars;
    std::vector<sdkMAPPER> global_mappers;
    std::ifstream codeFile;
    std::ofstream dump_file;
    codeFile.open(argv[1]);

    std::string line;
    if (codeFile.is_open())
    {
        while (getline(codeFile, line))
        {
            processLine(line, global_mappers, global_strings, global_ints, global_chars, dump_file);
        }
        codeFile.close();
    }
    else
    {
        std::cout << "File could not be opened." << std::endl;
    }
}
