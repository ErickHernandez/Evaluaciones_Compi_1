#ifndef _LEXER_H
#define _LEXER_H

#include "spl_symbols.h"
#include <iostream>
#include <string>
#include <fstream>

class SplLexer {
    public:
    SplLexer(std::istream& input): input(input) {}

    std::string getText() { return text; }
    int getNextChar() { return input.get(); }
    void ungetChar(int ch) { input.unget(); }
    
    Symbol getNextToken();
    static const char *tokenToString(Symbol tk);
    //static Symbol findKeyword(const std::string& str);
    private:
    std::string text;
    std::istream& input;
};

#endif
