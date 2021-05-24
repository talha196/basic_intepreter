#include <stdlib.h>
#include <iostream>
#include <string>

#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef enum  Tokens_t{

INTEGER,
PLUS,
MINUS,
END_OF_FILE

};
class Token
{
    private:
        Tokens_t _type;
        int _value;


    public:
        Token(Tokens_t type, int value);
        std::string string_representation();


};






#endif