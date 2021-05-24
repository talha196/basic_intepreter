#include "tokenizer.h"
#include <stdlib.h>
#include <string>

Token::Token(std::string type, int value)
:_type(type), _value(value)
{}

std::string Token::string_representation()
{

    std::string concatenated_string = "Token(" ;
    concatenated_string.append(_type) ;
    concatenated_string.append(", " );
    concatenated_string.append(std::to_string(_value));
    concatenated_string.append(")");

    return concatenated_string;

}
