#include "basic_interpreter.h"
#include "tokenizer.h"




   Interpreter::Interpreter(std::string text)
   :_text(text),_pos(0), _current_token({}), _current_char((_text[_pos])){}


    void Interpreter::advance()
    {
        _pos+=1;
        if(_pos > _text.length())
        {
            _current_char ='\0';
        }
        else
        {
            _current_char = _text[_pos];
        }
    }
    void Interpreter::skip_whitespace()
    {
        while(_current_char != '\0' && std::isspace(_current_char))
        {
            advance();
        }

    }
    int Interpreter::integer()
    {
        std::string result = {};
        while (_current_char != '\0' && std::isdigit(_current_char))
        {
            result += _current_char;
            advance();
        }
        return stoi(result);
    }
    void Interpreter::eat(std::string token_type)
    {
        if (_current_token == token_type)
        {
            _current_token = get_next_token();
        }


    }
    Token Interpreter::get_next_token()
    {
        while (_current_char != '\0')
        {
            if (isspace(_current_char))
            {
                skip_whitespace();
                continue;
            }
            if (std::isdigit(_current_char))
            {
                return Token(INTEGER, integer());
            }
            if (_current_char == '+')
            {
                return Token(PLUS, '+');
            }
                if (_current_char == '-')
            {
                return Token(MINUS, '-');
            }
        }
        return Token(END_OF_FILE, 0);
    }