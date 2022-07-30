#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "headers_and_cpps/sdkSTRING.h"
#include "headers_and_cpps/sdkINTEGER.h"
#include "headers_and_cpps/sdkCHAR.h"
#include "headers_and_cpps/sdkFLOAT.h"
#include "headers_and_cpps/sdkMAPPER.h"
#pragma once

char evaluate_dtype(std::string data);
void dump(std::ofstream &dump_file, std::string d_to_dump);
struct custom_types
{
   std::vector<sdkINTEGER> ints;
   std::vector<sdkSTRING> strings;
   std::vector<sdkCHAR> chars;
   std::vector<sdkFLOAT> floats;
   std::vector<sdkMAPPER> mappers;
};