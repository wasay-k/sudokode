#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "headers_and_cpps/sdkSTRING.h"
#include "headers_and_cpps/sdkINTEGER.h"
#include "headers_and_cpps/sdkCHAR.h"
#include "headers_and_cpps/sdkMAPPER.h"
#include "headers_and_cpps/sdkFLOAT.h"
#include "utilities.h"

void declare_variable(std::stringstream &line, custom_types &global_types, std::ofstream &log_file);
void declare_constant(std::stringstream &line, custom_types &global_types, std::ofstream &log_file);
void processLine(std::string line, custom_types &global_types, std::ofstream &log_file);
void processLine(std::string line, custom_types &global_types, custom_types &, std::ofstream &log_file);
