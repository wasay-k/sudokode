#include <iostream>
#include <stdio.h>
#include <fstream>
#include "libs/parser/parser.h"

int main(int argc, char** argv){

    std::ifstream file;
    std::string filePath = argv[1];
    file.open(filePath);


    if(file.is_open()){
        std::string line;
        while(getline(file, line)){
            std::cout << line << std::endl;
        }
        Lexer lexer(filePath);
        Parser parser(lexer);
    }else{
        std::cerr << "Error: File not found" << std::endl;
    }
    return 0;
}
