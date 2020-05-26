#include "spl_lexer.h"

enum class State {
    start_q0,
    identifier_q0,
    identifier_q1,
    Number_q0,
    Number_q1,
    MathOP_q0,
    MathOP_q1,
    MathOP_q3,
    relational_op_q0,
    relational_op_q3,
    symbols_q0,
    symbols_q1,
    symbols_q15,
    symbols_q17,
    symbols_q18,
    symbols_q2,
    symbols_q20,
    symbols_q3,
};

Symbol SplLexer::getNextToken()
{
    text = "";
        State state = State::start_q0;
    int ch = getNextChar();

    while (true) {
        switch (state) {
            // start
            case State::start_q0:
                if (ch == EOF) {
                    text += ch;
                    return Symbol::Eof;
                }
                else if ((ch == ' ') || (ch == '\t')) {
                    state = State::start_q0;
                    ch = getNextChar();
                }
                else if (ch == '\n') {
                    text += ch;
                    return Symbol::EoL;
                }
                else {
                    // Trying next automaton 'identifier
                    state = State::identifier_q0;
                }
                break;
            // identifier
            case State::identifier_q0:
                if ((ch == '_') || ((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) {
                    text += ch;
                    state = State::identifier_q1;
                    ch = getNextChar();
                }
                else {
                    // Trying next automaton 'Number
                    state = State::Number_q0;
                }
                break;
            case State::identifier_q1:
                if (((ch >= '0') && (ch <= '9')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) || (ch == '_')) {
                    text += ch;
                    state = State::identifier_q1;
                    ch = getNextChar();
                }
                else {
                    ungetChar(ch);
                    return Symbol::IDENT;
                }
                break;
            // Number
            case State::Number_q0:
                if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = State::Number_q1;
                    ch = getNextChar();
                }
                else {
                    // Trying next automaton 'MathOP
                    state = State::MathOP_q0;
                }
                break;
            case State::Number_q1:
                if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = State::Number_q1;
                    ch = getNextChar();
                }
                else {
                    ungetChar(ch);
                    return Symbol::NUMBER;
                }
                break;
            // MathOP
            case State::MathOP_q0:
                if (ch == '*') {
                    text += ch;
                    state = State::MathOP_q3;
                    ch = getNextChar();
                }
                else if (ch == '+') {
                    text += ch;
                    state = State::MathOP_q1;
                    ch = getNextChar();
                }
                else {
                    // Trying next automaton 'relational_op
                    state = State::relational_op_q0;
                }
                break;
            case State::MathOP_q1:
                ungetChar(ch);
                return Symbol::PLUS;
                break;
            case State::MathOP_q3:
                ungetChar(ch);
                return Symbol::ASTERISK;
                break;
            // relational_op
            case State::relational_op_q0:
                if (ch == '=') {
                    text += ch;
                    state = State::relational_op_q3;
                    ch = getNextChar();
                }
                else {
                    // Trying next automaton 'symbols
                    state = State::symbols_q0;
                }
                break;
            case State::relational_op_q3:
                ungetChar(ch);
                return Symbol::EQUAL;
                break;
            // symbols
            case State::symbols_q0:
                if (ch == '}') {
                    text += ch;
                    state = State::symbols_q20;
                    ch = getNextChar();
                }
                else if (ch == '(') {
                    text += ch;
                    state = State::symbols_q1;
                    ch = getNextChar();
                }
                else if (ch == '{') {
                    text += ch;
                    state = State::symbols_q17;
                    ch = getNextChar();
                }
                else if (ch == ';') {
                    text += ch;
                    state = State::symbols_q3;
                    ch = getNextChar();
                }
                else if (ch == ',') {
                    text += ch;
                    state = State::symbols_q15;
                    ch = getNextChar();
                }
                else if (ch == ')') {
                    text += ch;
                    state = State::symbols_q2;
                    ch = getNextChar();
                }
                else {
                    reportError(ch);
                    ch = getNextChar();
                    state = State::start_q0;
                }
                break;
            case State::symbols_q1:
                ungetChar(ch);
                return Symbol::OPEN_PARENTHESIS;
                break;
            case State::symbols_q15:
                ungetChar(ch);
                return Symbol::COMMA;
                break;
            case State::symbols_q17:
                ungetChar(ch);
                return Symbol::OPEN_BRACE;
                break;
            case State::symbols_q2:
                ungetChar(ch);
                return Symbol::CLOSE_PARENTHESIS;
                break;
            case State::symbols_q20:
                ungetChar(ch);
                return Symbol::CLOSE_BRACE;
                break;
            case State::symbols_q3:
                ungetChar(ch);
                return Symbol::SEMICOLON;
                break;
        }
    }

}

const char *SplLexer::tokenToString(Symbol tk)
{
        switch (tk) {
        case Symbol::SEMICOLON: return "SEMICOLON";
        case Symbol::OPEN_BRACE: return "OPEN_BRACE";
        case Symbol::OPEN_PARENTHESIS: return "OPEN_PARENTHESIS";
        case Symbol::EoL: return "EoL";
        case Symbol::Eof: return "Eof";
        case Symbol::CLOSE_BRACE: return "CLOSE_BRACE";
        case Symbol::IDENT: return "IDENT";
        case Symbol::CLOSE_PARENTHESIS: return "CLOSE_PARENTHESIS";
        case Symbol::PLUS: return "PLUS";
        case Symbol::NUMBER: return "NUMBER";
        case Symbol::COMMA: return "COMMA";
        case Symbol::EQUAL: return "EQUAL";
        case Symbol::ASTERISK: return "ASTERISK";
        default: return "Unknown";
    }

}

