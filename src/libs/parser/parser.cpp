#include "parser.h"

void Parser::ParseExpression(){
    parseAssignmentExpression();
       if (currentToken.type != Token::EOS) {
           std::cerr << "Unexpected token: " << currentToken.value << std::endl;
           exit(1);
       }
}

void Parser::parseAssignmentExpression() {
    parseTerm();
    if (currentToken.type == Token::ASSIGN) {
        currentToken = lexer.nextToken();
        std::cout << "Assignment detected!" << std::endl;
        parseAssignmentExpression();
    }
}

void Parser::parseTerm() {
    parseFactor();
    while (currentToken.type == Token::PLUS || currentToken.type == Token::MINUS) {
        Token op = currentToken;
        currentToken = lexer.nextToken();
        parseFactor();
        std::cout << "Term with operator: " << op.value << std::endl;
    }
}

void Parser::parseFactor() {
    if (currentToken.type == Token::IDENTIFIER) {
        std::cout << "Identifier: " << currentToken.value << std::endl;
        currentToken = lexer.nextToken();
    } else if (currentToken.type == Token::NUMBER) {
        std::cout << "Number: " << currentToken.value << std::endl;
        currentToken = lexer.nextToken();
    } else {
        std::cerr << "Unexpected token: " << currentToken.value << std::endl;
        exit(1);
    }
}
