#include <vector>
#include <functional>
#include "expr_slr_table.h"

Rule none;
static Rule rules[] = {
    /*0*/ {Symbol::input, {Symbol::stmt_list, }},
    /*1*/ {Symbol::stmt_list, {Symbol::stmt_list, Symbol::opt_stmt, }},
    /*2*/ {Symbol::stmt_list, {Symbol::opt_stmt, }},
    /*3*/ {Symbol::opt_stmt, {Symbol::opt_eol, }},
    /*4*/ {Symbol::opt_stmt, {Symbol::stmt, }},
    /*5*/ {Symbol::stmt, {Symbol::assign, }},
    /*6*/ {Symbol::stmt, {Symbol::KwPrint, Symbol::expr, }},
    /*7*/ {Symbol::stmt, {Symbol::fun_decl, }},
    /*8*/ {Symbol::opt_eol, {Symbol::opt_eol, Symbol::Eol, }},
    /*9*/ {Symbol::opt_eol, {Symbol::Eol, }},
    /*10*/ {Symbol::assign, {Symbol::Ident, Symbol::OpAssign, Symbol::expr, }},
    /*11*/ {Symbol::fun_decl, {Symbol::Ident, Symbol::arg_list, Symbol::OpAssign, Symbol::expr, }},
    /*12*/ {Symbol::arg_list, {Symbol::arg_list, Symbol::Comma, Symbol::arg, }},
    /*13*/ {Symbol::arg_list, {Symbol::arg, }},
    /*14*/ {Symbol::arg, {Symbol::Number, }},
    /*15*/ {Symbol::arg, {Symbol::Ident, }},
    /*16*/ {Symbol::expr, {Symbol::expr, Symbol::OpAdd, Symbol::term, }},
    /*17*/ {Symbol::expr, {Symbol::expr, Symbol::OpSub, Symbol::term, }},
    /*18*/ {Symbol::expr, {Symbol::term, }},
    /*19*/ {Symbol::term, {Symbol::term, Symbol::OpMul, Symbol::factor, }},
    /*20*/ {Symbol::term, {Symbol::term, Symbol::OpDiv, Symbol::factor, }},
    /*21*/ {Symbol::term, {Symbol::factor, }},
    /*22*/ {Symbol::factor, {Symbol::Ident, Symbol::opt_arg_list, }},
    /*23*/ {Symbol::factor, {Symbol::Number, }},
    /*24*/ {Symbol::factor, {Symbol::OpenPar, Symbol::expr, Symbol::ClosePar, }},
    /*25*/ {Symbol::opt_arg_list, {Symbol::arg_list, }},
    /*26*/ {Symbol::opt_arg_list, {Symbol::_epsilon, }},
};

static std::string rules_str[] = {
"input -> stmt_list",
"stmt_list -> stmt_list opt_stmt",
"stmt_list -> opt_stmt",
"opt_stmt -> opt_eol",
"opt_stmt -> stmt",
"stmt -> assign",
"stmt -> KwPrint expr",
"stmt -> fun_decl",
"opt_eol -> opt_eol Eol",
"opt_eol -> Eol",
"assign -> Ident OpAssign expr",
"fun_decl -> Ident arg_list OpAssign expr",
"arg_list -> arg_list Comma arg",
"arg_list -> arg",
"arg -> Number",
"arg -> Ident",
"expr -> expr OpAdd term",
"expr -> expr OpSub term",
"expr -> term",
"term -> term OpMul factor",
"term -> term OpDiv factor",
"term -> factor",
"factor -> Ident opt_arg_list",
"factor -> Number",
"factor -> OpenPar expr ClosePar",
"opt_arg_list -> arg_list",
"opt_arg_list -> %epsilon",
};

inline PAction shift(int index)
{
    return PAction(PAction::Shift, index);
}

inline PAction reduce(int index)
{
    return PAction(PAction::Reduce, index);
}

PAction empty;
namespace lr
{
    PAction Action(int state, Symbol term)
    {
        switch(state)
        {
            case 0:
                switch(term)
                {
                    case Symbol::KwPrint:
                        return shift(3);
                    case Symbol::Eol:
                        return shift(8);
                    case Symbol::Ident:
                        return shift(1);
                }
                break;
            case 1:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(10);
                    case Symbol::OpAssign:
                        return shift(12);
                    case Symbol::Number:
                        return shift(13);
                }
                break;
            case 2:
                switch(term)
                {
                    case Symbol::Eof:
                    case Symbol::Ident:
                    case Symbol::Eol:
                    case Symbol::KwPrint:
                        return reduce(7);
                }
                break;
            case 3:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(17);
                    case Symbol::Number:
                        return shift(16);
                    case Symbol::OpenPar:
                        return shift(15);
                }
                break;
            case 4:
                switch(term)
                {
                    case Symbol::Eol:
                        return shift(21);
                    case Symbol::KwPrint:
                    case Symbol::Ident:
                    case Symbol::Eof:
                        return reduce(3);
                }
                break;
            case 5:
                switch(term)
                {
                    case Symbol::KwPrint:
                        return shift(3);
                    case Symbol::Eol:
                        return shift(8);
                    case Symbol::Ident:
                        return shift(1);
                    case Symbol::Eof:
                        return reduce(0);
                }
                break;
            case 6:
                switch(term)
                {
                    case Symbol::Eof:
                    case Symbol::Ident:
                    case Symbol::Eol:
                    case Symbol::KwPrint:
                        return reduce(2);
                }
                break;
            case 7:
                switch(term)
                {
                    case Symbol::KwPrint:
                    case Symbol::Eol:
                    case Symbol::Ident:
                    case Symbol::Eof:
                        return reduce(4);
                }
                break;
            case 8:
                switch(term)
                {
                    case Symbol::Eof:
                    case Symbol::Ident:
                    case Symbol::KwPrint:
                    case Symbol::Eol:
                        return reduce(9);
                }
                break;
            case 9:
                switch(term)
                {
                    case Symbol::Eof:
                    case Symbol::Ident:
                    case Symbol::Eol:
                    case Symbol::KwPrint:
                        return reduce(5);
                }
                break;
            case 10:
                switch(term)
                {
                    case Symbol::Comma:
                    case Symbol::OpAssign:
                    case Symbol::OpAdd:
                    case Symbol::Eof:
                    case Symbol::Ident:
                    case Symbol::Eol:
                    case Symbol::OpSub:
                    case Symbol::KwPrint:
                    case Symbol::OpMul:
                    case Symbol::ClosePar:
                    case Symbol::OpDiv:
                        return reduce(15);
                }
                break;
            case 11:
                switch(term)
                {
                    case Symbol::OpDiv:
                    case Symbol::ClosePar:
                    case Symbol::OpMul:
                    case Symbol::KwPrint:
                    case Symbol::OpSub:
                    case Symbol::Eol:
                    case Symbol::Ident:
                    case Symbol::Eof:
                    case Symbol::OpAdd:
                    case Symbol::OpAssign:
                    case Symbol::Comma:
                        return reduce(13);
                }
                break;
            case 12:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(17);
                    case Symbol::Number:
                        return shift(16);
                    case Symbol::OpenPar:
                        return shift(15);
                }
                break;
            case 13:
                switch(term)
                {
                    case Symbol::Comma:
                    case Symbol::OpAssign:
                    case Symbol::OpAdd:
                    case Symbol::Eof:
                    case Symbol::Ident:
                    case Symbol::Eol:
                    case Symbol::OpSub:
                    case Symbol::KwPrint:
                    case Symbol::OpMul:
                    case Symbol::ClosePar:
                    case Symbol::OpDiv:
                        return reduce(14);
                }
                break;
            case 14:
                switch(term)
                {
                    case Symbol::OpAssign:
                        return shift(25);
                    case Symbol::Comma:
                        return shift(24);
                }
                break;
            case 15:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(17);
                    case Symbol::Number:
                        return shift(16);
                    case Symbol::OpenPar:
                        return shift(15);
                }
                break;
            case 16:
                switch(term)
                {
                    case Symbol::OpDiv:
                    case Symbol::Eol:
                    case Symbol::ClosePar:
                    case Symbol::OpMul:
                    case Symbol::KwPrint:
                    case Symbol::Ident:
                    case Symbol::OpSub:
                    case Symbol::Eof:
                    case Symbol::OpAdd:
                        return reduce(23);
                }
                break;
            case 17:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(10);
                    case Symbol::Number:
                        return shift(13);
                    case Symbol::_epsilon:
                        return shift(27);
                }
                break;
            case 18:
                switch(term)
                {
                    case Symbol::OpAdd:
                    case Symbol::Eof:
                    case Symbol::OpSub:
                    case Symbol::Ident:
                    case Symbol::KwPrint:
                    case Symbol::OpMul:
                    case Symbol::ClosePar:
                    case Symbol::Eol:
                    case Symbol::OpDiv:
                        return reduce(21);
                }
                break;
            case 19:
                switch(term)
                {
                    case Symbol::OpAdd:
                        return shift(31);
                    case Symbol::OpSub:
                        return shift(30);
                    case Symbol::Eof:
                    case Symbol::Ident:
                    case Symbol::Eol:
                    case Symbol::KwPrint:
                        return reduce(6);
                }
                break;
            case 20:
                switch(term)
                {
                    case Symbol::OpMul:
                        return shift(33);
                    case Symbol::OpDiv:
                        return shift(32);
                    case Symbol::KwPrint:
                    case Symbol::Eol:
                    case Symbol::Ident:
                    case Symbol::OpSub:
                    case Symbol::Eof:
                    case Symbol::OpAdd:
                    case Symbol::ClosePar:
                        return reduce(18);
                }
                break;
            case 21:
                switch(term)
                {
                    case Symbol::Eof:
                    case Symbol::Ident:
                    case Symbol::KwPrint:
                    case Symbol::Eol:
                        return reduce(8);
                }
                break;
            case 22:
                switch(term)
                {
                    case Symbol::Eof:
                    case Symbol::Ident:
                    case Symbol::Eol:
                    case Symbol::KwPrint:
                        return reduce(1);
                }
                break;
            case 23:
                switch(term)
                {
                    case Symbol::OpAdd:
                        return shift(31);
                    case Symbol::OpSub:
                        return shift(30);
                    case Symbol::KwPrint:
                    case Symbol::Eol:
                    case Symbol::Ident:
                    case Symbol::Eof:
                        return reduce(10);
                }
                break;
            case 24:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(10);
                    case Symbol::Number:
                        return shift(13);
                }
                break;
            case 25:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(17);
                    case Symbol::Number:
                        return shift(16);
                    case Symbol::OpenPar:
                        return shift(15);
                }
                break;
            case 26:
                switch(term)
                {
                    case Symbol::OpAdd:
                        return shift(31);
                    case Symbol::OpSub:
                        return shift(30);
                    case Symbol::ClosePar:
                        return shift(36);
                }
                break;
            case 27:
                switch(term)
                {
                    case Symbol::OpAdd:
                    case Symbol::Eof:
                    case Symbol::OpSub:
                    case Symbol::Ident:
                    case Symbol::KwPrint:
                    case Symbol::OpMul:
                    case Symbol::ClosePar:
                    case Symbol::Eol:
                    case Symbol::OpDiv:
                        return reduce(26);
                }
                break;
            case 28:
                switch(term)
                {
                    case Symbol::OpDiv:
                    case Symbol::Eol:
                    case Symbol::ClosePar:
                    case Symbol::OpMul:
                    case Symbol::KwPrint:
                    case Symbol::Ident:
                    case Symbol::OpSub:
                    case Symbol::Eof:
                    case Symbol::OpAdd:
                        return reduce(22);
                }
                break;
            case 29:
                switch(term)
                {
                    case Symbol::Comma:
                        return shift(24);
                    case Symbol::OpAdd:
                    case Symbol::Eof:
                    case Symbol::OpSub:
                    case Symbol::Ident:
                    case Symbol::KwPrint:
                    case Symbol::OpMul:
                    case Symbol::ClosePar:
                    case Symbol::Eol:
                    case Symbol::OpDiv:
                        return reduce(25);
                }
                break;
            case 30:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(17);
                    case Symbol::Number:
                        return shift(16);
                    case Symbol::OpenPar:
                        return shift(15);
                }
                break;
            case 31:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(17);
                    case Symbol::Number:
                        return shift(16);
                    case Symbol::OpenPar:
                        return shift(15);
                }
                break;
            case 32:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(17);
                    case Symbol::Number:
                        return shift(16);
                    case Symbol::OpenPar:
                        return shift(15);
                }
                break;
            case 33:
                switch(term)
                {
                    case Symbol::Ident:
                        return shift(17);
                    case Symbol::Number:
                        return shift(16);
                    case Symbol::OpenPar:
                        return shift(15);
                }
                break;
            case 34:
                switch(term)
                {
                    case Symbol::OpDiv:
                    case Symbol::ClosePar:
                    case Symbol::OpMul:
                    case Symbol::KwPrint:
                    case Symbol::OpSub:
                    case Symbol::Eol:
                    case Symbol::Ident:
                    case Symbol::Eof:
                    case Symbol::OpAdd:
                    case Symbol::OpAssign:
                    case Symbol::Comma:
                        return reduce(12);
                }
                break;
            case 35:
                switch(term)
                {
                    case Symbol::OpAdd:
                        return shift(31);
                    case Symbol::OpSub:
                        return shift(30);
                    case Symbol::KwPrint:
                    case Symbol::Eol:
                    case Symbol::Ident:
                    case Symbol::Eof:
                        return reduce(11);
                }
                break;
            case 36:
                switch(term)
                {
                    case Symbol::OpDiv:
                    case Symbol::Eol:
                    case Symbol::ClosePar:
                    case Symbol::OpMul:
                    case Symbol::KwPrint:
                    case Symbol::Ident:
                    case Symbol::OpSub:
                    case Symbol::Eof:
                    case Symbol::OpAdd:
                        return reduce(24);
                }
                break;
            case 37:
                switch(term)
                {
                    case Symbol::OpMul:
                        return shift(33);
                    case Symbol::OpDiv:
                        return shift(32);
                    case Symbol::KwPrint:
                    case Symbol::Eol:
                    case Symbol::Ident:
                    case Symbol::OpSub:
                    case Symbol::Eof:
                    case Symbol::OpAdd:
                    case Symbol::ClosePar:
                        return reduce(17);
                }
                break;
            case 38:
                switch(term)
                {
                    case Symbol::OpMul:
                        return shift(33);
                    case Symbol::OpDiv:
                        return shift(32);
                    case Symbol::KwPrint:
                    case Symbol::Eol:
                    case Symbol::Ident:
                    case Symbol::OpSub:
                    case Symbol::Eof:
                    case Symbol::OpAdd:
                    case Symbol::ClosePar:
                        return reduce(16);
                }
                break;
            case 39:
                switch(term)
                {
                    case Symbol::OpAdd:
                    case Symbol::Eof:
                    case Symbol::OpSub:
                    case Symbol::Ident:
                    case Symbol::KwPrint:
                    case Symbol::OpMul:
                    case Symbol::ClosePar:
                    case Symbol::Eol:
                    case Symbol::OpDiv:
                        return reduce(20);
                }
                break;
            case 40:
                switch(term)
                {
                    case Symbol::OpAdd:
                    case Symbol::Eof:
                    case Symbol::OpSub:
                    case Symbol::Ident:
                    case Symbol::KwPrint:
                    case Symbol::OpMul:
                    case Symbol::ClosePar:
                    case Symbol::Eol:
                    case Symbol::OpDiv:
                        return reduce(19);
                }
                break;
        }

        return empty;
    }

    int Goto(int state, Symbol non_term)
    {
        switch(state)
        {
            case 0:
                switch(non_term)

                {
                    case Symbol::stmt_list:
                        return 5;
                    case Symbol::opt_stmt:
                        return 6;
                    case Symbol::opt_eol:
                        return 4;
                    case Symbol::stmt:
                        return 7;
                    case Symbol::assign:
                        return 9;
                    case Symbol::fun_decl:
                        return 2;
                }
                break;
            case 1:
                switch(non_term)

                {
                    case Symbol::arg_list:
                        return 14;
                    case Symbol::arg:
                        return 11;
                }
                break;
            case 3:
                switch(non_term)

                {
                    case Symbol::expr:
                        return 19;
                    case Symbol::term:
                        return 20;
                    case Symbol::factor:
                        return 18;
                }
                break;
            case 5:
                switch(non_term)

                {
                    case Symbol::opt_stmt:
                        return 22;
                    case Symbol::opt_eol:
                        return 4;
                    case Symbol::stmt:
                        return 7;
                    case Symbol::assign:
                        return 9;
                    case Symbol::fun_decl:
                        return 2;
                }
                break;
            case 12:
                switch(non_term)

                {
                    case Symbol::expr:
                        return 23;
                    case Symbol::term:
                        return 20;
                    case Symbol::factor:
                        return 18;
                }
                break;
            case 15:
                switch(non_term)

                {
                    case Symbol::expr:
                        return 26;
                    case Symbol::term:
                        return 20;
                    case Symbol::factor:
                        return 18;
                }
                break;
            case 17:
                switch(non_term)

                {
                    case Symbol::arg_list:
                        return 29;
                    case Symbol::arg:
                        return 11;
                    case Symbol::opt_arg_list:
                        return 28;
                }
                break;
            case 24:
                switch(non_term)

                {
                    case Symbol::arg:
                        return 34;
                }
                break;
            case 25:
                switch(non_term)

                {
                    case Symbol::expr:
                        return 35;
                    case Symbol::term:
                        return 20;
                    case Symbol::factor:
                        return 18;
                }
                break;
            case 30:
                switch(non_term)

                {
                    case Symbol::term:
                        return 37;
                    case Symbol::factor:
                        return 18;
                }
                break;
            case 31:
                switch(non_term)

                {
                    case Symbol::term:
                        return 38;
                    case Symbol::factor:
                        return 18;
                }
                break;
            case 32:
                switch(non_term)

                {
                    case Symbol::factor:
                        return 39;
                }
                break;
            case 33:
                switch(non_term)

                {
                    case Symbol::factor:
                        return 40;
                }
                break;
        }

        return -1;
    }

    const Rule& rule(int index)
    {
        return rules[index];
    }

    std::string ruleString(int index)
    {
        return rules_str[index];
    }
}
