#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "headers_and_cpps/sdkSTRING.h"
#include "headers_and_cpps/sdkINTEGER.h"
#include "headers_and_cpps/sdkCHAR.h"
#include "headers_and_cpps/sdkMAPPER.h"

void processLine(std::string line, std::vector<sdkMAPPER> &map_vector, std::vector<sdkSTRING> &str_v, std::vector<sdkINTEGER> &int_v, std::vector<sdkCHAR> &char_v, std::ofstream& log_file);
