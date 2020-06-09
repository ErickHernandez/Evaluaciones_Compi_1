#ifndef _LEXER_H
#define _LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "expr_slr_table.h"

#define _Print {Symbol::KwPrint, "Print" }
#define _Eol {Symbol::Eol, "\\n" }
#define _OpenPar {Symbol::OpenPar, "(" }
#define _ClosePar {Symbol::ClosePar, ")" }
#define _Comma {Symbol::Comma, "," }
#define _OpAssign {Symbol::OpAssign, "=" }
#define _OpAdd {Symbol::OpAdd, "+" }
#define _OpSub {Symbol::OpSub, "-" }
#define _OpMul {Symbol::OpMul, "*" }
#define _OpDiv {Symbol::OpDiv, "/" }
#define _Number(txt) {Symbol::Number, txt }
#define _Ident(txt) {Symbol::Ident, txt }
#define _Eof {Symbol::Eof, "<Eof>" }

struct TokenInfo {
    Symbol token_id;
    std::string token_text;
};

class Lexer {
public:
	Lexer(const std::vector<TokenInfo>& tklst): tklist(tklst) {
        it = tklist.begin();
    }

    int getLineNo() { return 1; }

    Symbol getNextToken()
    {
        if (it == tklist.end())
        {
            return Symbol::Eof;
        }

        Symbol tk = it->token_id;
        text = it->token_text;
        it++;
        
        return tk;
    }
    
    bool hasTokens() { return it != tklist.end(); }
    std::string getText() { return text; }
    static std::string tokenToString(Symbol tk);

private:
    std::string text;
    std::vector<TokenInfo> tklist;
    std::vector<TokenInfo>::iterator it;
};
#endif
