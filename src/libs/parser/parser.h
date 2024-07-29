#include <iostream>
#include "../lexer/lexer.h"

class Parser {
    public:
    Parser(Lexer& lexer): lexer(lexer) {};
    void ParseExpression();
    private:
    Lexer& lexer;
    Token currentToken;
    void parseAssignmentExpression();
    void parseTerm();
    void parseFactor();
};