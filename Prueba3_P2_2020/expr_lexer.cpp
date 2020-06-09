#include "expr_lexer.h"

std::string Lexer::tokenToString(Symbol tk)
{
    switch (tk)
    {
        case Symbol::Eof: return "Eof";
        case Symbol::Eol: return "Eol";
        case Symbol::KwPrint: return "KwPrint";
        case Symbol::Ident: return "Ident";
        case Symbol::OpAssign: return "OpAssign";
        case Symbol::Comma: return "Comma";
        case Symbol::Number: return "Number";
        case Symbol::OpAdd: return "OpAdd";
        case Symbol::OpSub: return "OpSub";
        case Symbol::OpMul: return "OpMul";
        case Symbol::OpDiv: return "OpDiv";
        case Symbol::OpenPar: return "OpenPar";
        case Symbol::ClosePar: return "ClosePar";
        default:
            return "Unknown:" + std::to_string(static_cast<unsigned>(tk));
    }
}