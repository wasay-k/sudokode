#include <iostream>


class Token {
    public:
    enum TokenType {
        NUMBER,
        PLUS,
        MINUS,
        DIVIDE,
        MULTIPLY,
        PARENTHESIS,
        IDENITIFIER,
        ASSIGN
    };
    TokenType type;
    std::string value;
    Token(){};
    Token(TokenType type, std::string value): type(type), value(value) {};
};