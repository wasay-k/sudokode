#include <iostream>
#include "../token/token.h"

class Lexer {
    public:
    Lexer(std::string input): index(0),input(input) {};
    Token nextToken();

    private:
    std::string input;
    size_t index;

};