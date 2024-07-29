#include <iostream>


class Token {
    public:
    enum TokenType {
        NUMBER,
        OPERATOR,
        PARENTHESIS,
        IDENITIFIER,
        ASSIGN
    };
    TokenType type;
    std::string value;
    Token(TokenType type, std::string value): type(type), value(value) {};
};