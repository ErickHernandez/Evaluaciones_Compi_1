#include <vector>
#include <functional>
#include "spl_symbols.h"

Rule none;
static Rule rules[] = {
    /*0*/ {Symbol::input, {Symbol::opt_func_list, }},
    /*1*/ {Symbol::opt_func_list, {Symbol::func_list, }},
    /*2*/ {Symbol::opt_func_list, {Symbol::Epsilon, }},
    /*3*/ {Symbol::func_list, {Symbol::func_decl, Symbol::func_listPrime, }},
    /*4*/ {Symbol::func_listPrime, {Symbol::func_decl, Symbol::func_listPrime, }},
    /*5*/ {Symbol::func_listPrime, {Symbol::Epsilon, }},
    /*6*/ {Symbol::func_decl, {Symbol::IDENT, Symbol::OPEN_PARENTHESIS, Symbol::opt_arg_list, Symbol::CLOSE_PARENTHESIS, Symbol::block, }},
    /*7*/ {Symbol::opt_arg_list, {Symbol::arg_list, }},
    /*8*/ {Symbol::opt_arg_list, {Symbol::Epsilon, }},
    /*9*/ {Symbol::arg_list, {Symbol::IDENT, Symbol::arg_listPrime, }},
    /*10*/ {Symbol::arg_listPrime, {Symbol::COMMA, Symbol::IDENT, Symbol::arg_listPrime, }},
    /*11*/ {Symbol::arg_listPrime, {Symbol::Epsilon, }},
    /*12*/ {Symbol::block, {Symbol::OPEN_BRACE, Symbol::stmt_list, Symbol::CLOSE_BRACE, }},
    /*13*/ {Symbol::stmt_list, {Symbol::stmt, Symbol::stmt_listPrime, }},
    /*14*/ {Symbol::stmt_listPrime, {Symbol::stmt, Symbol::stmt_listPrime, }},
    /*15*/ {Symbol::stmt_listPrime, {Symbol::Epsilon, }},
    /*16*/ {Symbol::stmt, {Symbol::IDENT, Symbol::stmtPrime, }},
    /*17*/ {Symbol::stmtPrime, {Symbol::EQUAL, Symbol::expr, Symbol::SEMICOLON, }},
    /*18*/ {Symbol::stmtPrime, {Symbol::OPEN_PARENTHESIS, Symbol::expr_list, Symbol::CLOSE_PARENTHESIS, Symbol::SEMICOLON, }},
    /*19*/ {Symbol::expr_list, {Symbol::expr, Symbol::expr_listPrime, }},
    /*20*/ {Symbol::expr_listPrime, {Symbol::COMMA, Symbol::expr, Symbol::expr_listPrime, }},
    /*21*/ {Symbol::expr_listPrime, {Symbol::Epsilon, }},
    /*22*/ {Symbol::expr, {Symbol::term, Symbol::exprPrime, }},
    /*23*/ {Symbol::exprPrime, {Symbol::PLUS, Symbol::term, Symbol::exprPrime, }},
    /*24*/ {Symbol::exprPrime, {Symbol::Epsilon, }},
    /*25*/ {Symbol::term, {Symbol::factor, Symbol::termPrime, }},
    /*26*/ {Symbol::termPrime, {Symbol::ASTERISK, Symbol::factor, Symbol::termPrime, }},
    /*27*/ {Symbol::termPrime, {Symbol::Epsilon, }},
    /*28*/ {Symbol::factor, {Symbol::NUMBER, }},
    /*29*/ {Symbol::factor, {Symbol::IDENT, Symbol::factorPrime, }},
    /*30*/ {Symbol::factor, {Symbol::OPEN_PARENTHESIS, Symbol::expr, Symbol::CLOSE_PARENTHESIS, }},
    /*31*/ {Symbol::factorPrime, {Symbol::OPEN_PARENTHESIS, Symbol::expr_list, Symbol::CLOSE_PARENTHESIS, }},
    /*32*/ {Symbol::factorPrime, {Symbol::Epsilon, }},
};

const Rule& getEntry(Symbol non_term, Symbol term)
{
    switch (non_term) {
        case Symbol::input:
            switch (term) {
                case Symbol::Eof:
                case Symbol::IDENT:
                    return rules[0];
            }
            break;
        case Symbol::opt_func_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[1];
                case Symbol::Eof:
                    return rules[2];
            }
            break;
        case Symbol::func_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[3];
            }
            break;
        case Symbol::func_decl:
            switch (term) {
                case Symbol::IDENT:
                    return rules[6];
            }
            break;
        case Symbol::func_listPrime:
            switch (term) {
                case Symbol::IDENT:
                    return rules[4];
                case Symbol::Eof:
                    return rules[5];
            }
            break;
        case Symbol::opt_arg_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[7];
                case Symbol::CLOSE_PARENTHESIS:
                    return rules[8];
            }
            break;
        case Symbol::block:
            switch (term) {
                case Symbol::OPEN_BRACE:
                    return rules[12];
            }
            break;
        case Symbol::arg_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[9];
            }
            break;
        case Symbol::arg_listPrime:
            switch (term) {
                case Symbol::COMMA:
                    return rules[10];
                case Symbol::CLOSE_PARENTHESIS:
                    return rules[11];
            }
            break;
        case Symbol::stmt_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[13];
            }
            break;
        case Symbol::stmt:
            switch (term) {
                case Symbol::IDENT:
                    return rules[16];
            }
            break;
        case Symbol::stmt_listPrime:
            switch (term) {
                case Symbol::IDENT:
                    return rules[14];
                case Symbol::CLOSE_BRACE:
                    return rules[15];
            }
            break;
        case Symbol::stmtPrime:
            switch (term) {
                case Symbol::EQUAL:
                    return rules[17];
                case Symbol::OPEN_PARENTHESIS:
                    return rules[18];
            }
            break;
        case Symbol::expr:
            switch (term) {
                case Symbol::IDENT:
                case Symbol::OPEN_PARENTHESIS:
                case Symbol::NUMBER:
                    return rules[22];
            }
            break;
        case Symbol::expr_list:
            switch (term) {
                case Symbol::IDENT:
                case Symbol::OPEN_PARENTHESIS:
                case Symbol::NUMBER:
                    return rules[19];
            }
            break;
        case Symbol::expr_listPrime:
            switch (term) {
                case Symbol::COMMA:
                    return rules[20];
                case Symbol::CLOSE_PARENTHESIS:
                    return rules[21];
            }
            break;
        case Symbol::term:
            switch (term) {
                case Symbol::IDENT:
                case Symbol::OPEN_PARENTHESIS:
                case Symbol::NUMBER:
                    return rules[25];
            }
            break;
        case Symbol::exprPrime:
            switch (term) {
                case Symbol::PLUS:
                    return rules[23];
                case Symbol::CLOSE_PARENTHESIS:
                case Symbol::COMMA:
                case Symbol::SEMICOLON:
                    return rules[24];
            }
            break;
        case Symbol::factor:
            switch (term) {
                case Symbol::NUMBER:
                    return rules[28];
                case Symbol::IDENT:
                    return rules[29];
                case Symbol::OPEN_PARENTHESIS:
                    return rules[30];
            }
            break;
        case Symbol::termPrime:
            switch (term) {
                case Symbol::ASTERISK:
                    return rules[26];
                case Symbol::CLOSE_PARENTHESIS:
                case Symbol::COMMA:
                case Symbol::SEMICOLON:
                case Symbol::PLUS:
                    return rules[27];
            }
            break;
        case Symbol::factorPrime:
            switch (term) {
                case Symbol::OPEN_PARENTHESIS:
                    return rules[31];
                case Symbol::CLOSE_PARENTHESIS:
                case Symbol::COMMA:
                case Symbol::SEMICOLON:
                case Symbol::PLUS:
                case Symbol::ASTERISK:
                    return rules[32];
            }
            break;
    }

    return none;
}
