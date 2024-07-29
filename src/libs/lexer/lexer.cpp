#include <iostream>
#include "lexer.h"

Token Lexer::nextToken(){
	while(isspace(input[index])){
        index++;
    };
    if (isalpha(input[index])){ //checks if the character is an alphabetical letter
        std::string identifier;
        while(isalnum(input[index])){
            identifier += input[index];
            index++;
        }
        return Token(Token::IDENITIFIER, identifier);
    }else if (isdigit(input[index])){ //checks if the character is a digit
        std::string number;
        while(isdigit(input[index])){
            number+= input[index];
            index++;
        }
        return Token(Token::NUMBER, number);
    }else{
        char nextChar = input[index++];
        switch (nextChar)
        {
        case '+':
            return Token(Token::OPERATOR, "+");
        case '-':
        return Token(Token::OPERATOR, "-");
        case '*':
        return Token(Token::OPERATOR, "*");
        case '/':
        return Token(Token::OPERATOR, "/");
        case '(':
        return Token(Token::PARENTHESIS, "(");
        case ')':
        return Token(Token::PARENTHESIS, ")");
        case '=':
        return Token(Token::ASSIGN, "=");
        default:
            std::cerr << "Error: Invalid character: "<< nextChar << std::endl;
            exit(1);
        }

    }
    
    
}