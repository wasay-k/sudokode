#include <iostream>
#include <stdio.h>
#include <fstream>


int main(int argc, char** argv){
    
    std::ifstream file;
    std::string filePath = argv[1];
    file.open(filePath);


    if(file.is_open()){
        std::string line;
        while(getline(file, line)){
            std::cout << line << std::endl;
        }
    }else{
        std::cerr << "Error: File not found" << std::endl;
    }
    return 0;
}