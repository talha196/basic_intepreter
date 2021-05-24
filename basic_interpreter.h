#include <stdlib.h>
#include <string>
#include "tokenizer.h"

#ifndef BASIC_INTERPRETER_H
#define BASIC_INTERPRETER_H

class Interpreter
{

    private:
     std::string _text;
     int _pos;
     std::string _current_token;
     char  _current_char;

    public:
    Interpreter(std::string text);
    void advance();
    void skip_whitespace();
    int integer();
    void eat(std::string token_type);
    Token get_next_token();
};




#endif