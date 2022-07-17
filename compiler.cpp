#include <stdio.h>
#include <iostream>
#include <fstream>
#include "processor.h"
#include "headers_and_cpps/sdkSTRING.h"
#include "headers_and_cpps/sdkINTEGER.h"
#include <vector>

void declare_var();

int main(int argc, char **argv)
{
    std::vector<sdkINTEGER> global_ints;
    std::vector<sdkSTRING> global_strings;
    std::ifstream codeFile;
    codeFile.open(argv[1]);
    std::string line;
    while (getline(codeFile, line))
    {
        processLine(line, global_strings, global_ints);
        // codeFile >> line;

        /*  // initializing variables

     }
    */
    }
    codeFile.close();
}
