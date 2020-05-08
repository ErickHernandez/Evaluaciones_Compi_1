#include "const_lexer.h"

enum class State {
    start_q0,
    constans_q0,
    constans_q1,
    constans_q2,
    constans_q3,
    constans_q4,
    constans_q5,
    constans_q6,
    constans_q9,
};

Token ConstLexer::getNextToken()
{
    text = "";
        State state = State::start_q0;
    int ch = getNextChar();

    while (true) {
        switch (state) {
            // start
            case State::start_q0:
                if ((ch == '\n') || (ch == ' ') || (ch == '\t')) {
                    state = State::start_q0;
                    ch = getNextChar();
                }
                else if (ch == EOF) {
                    text += ch;
                    return Token::Eof;
                }
                else {
                    // Trying next automaton 'constans
                    state = State::constans_q0;
                }
                break;
            // constans
            case State::constans_q0:
                if ((ch >= '8') && (ch <= '9')) {
                    text += ch;
                    state = State::constans_q3;
                    ch = getNextChar();
                }
                else if ((ch >= '0') && (ch <= '1')) {
                    text += ch;
                    state = State::constans_q1;
                    ch = getNextChar();
                }
                else if (((ch >= 'a') && (ch <= 'f')) || ((ch >= 'A') && (ch <= 'F'))) {
                    text += ch;
                    state = State::constans_q5;
                    ch = getNextChar();
                }
                else if ((ch >= '2') && (ch <= '7')) {
                    text += ch;
                    state = State::constans_q2;
                    ch = getNextChar();
                }
                else {
                    reportError(ch);
                    ch = getNextChar();
                    state = State::start_q0;
                }
                break;
            case State::constans_q1:
                if ((ch >= '2') && (ch <= '7')) {
                    text += ch;
                    state = State::constans_q2;
                    ch = getNextChar();
                }
                else if (((ch >= 'c') && (ch <= 'f')) || ((ch >= 'C') && (ch <= 'F'))) {
                    text += ch;
                    state = State::constans_q5;
                    ch = getNextChar();
                }
                else if (ch == 'b') {
                    text += ch;
                    state = State::constans_q4;
                    ch = getNextChar();
                }
                else if ((ch >= '8') && (ch <= '9')) {
                    text += ch;
                    state = State::constans_q3;
                    ch = getNextChar();
                }
                else if ((ch >= '0') && (ch <= '1')) {
                    text += ch;
                    state = State::constans_q1;
                    ch = getNextChar();
                }
                else {
                    reportError(ch);
                    ch = getNextChar();
                    state = State::start_q0;
                }
                break;
            case State::constans_q2:
                if ((ch >= '0') && (ch <= '7')) {
                    text += ch;
                    state = State::constans_q2;
                    ch = getNextChar();
                }
                else if (((ch >= 'A') && (ch <= 'F')) || ((ch >= 'a') && (ch <= 'f'))) {
                    text += ch;
                    state = State::constans_q5;
                    ch = getNextChar();
                }
                else if (ch == 'o') {
                    text += ch;
                    state = State::constans_q9;
                    ch = getNextChar();
                }
                else if ((ch >= '8') && (ch <= '9')) {
                    text += ch;
                    state = State::constans_q3;
                    ch = getNextChar();
                }
                else {
                    reportError(ch);
                    ch = getNextChar();
                    state = State::start_q0;
                }
                break;
            case State::constans_q3:
                if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = State::constans_q3;
                    ch = getNextChar();
                }
                else if (((ch >= 'A') && (ch <= 'F')) || ((ch >= 'a') && (ch <= 'f'))) {
                    text += ch;
                    state = State::constans_q5;
                    ch = getNextChar();
                }
                else {
                    ungetChar(ch);
                    return Token::Decimal;
                }
                break;
            case State::constans_q4:
                if (((ch >= 'A') && (ch <= 'F')) || ((ch >= 'a') && (ch <= 'f')) || ((ch >= '0') && (ch <= '9'))) {
                    text += ch;
                    state = State::constans_q5;
                    ch = getNextChar();
                }
                else {
                    ungetChar(ch);
                    return Token::Binary;
                }
                break;
            case State::constans_q5:
                if (ch == 'h') {
                    text += ch;
                    state = State::constans_q6;
                    ch = getNextChar();
                }
                else if (((ch >= '0') && (ch <= '9')) || ((ch >= 'a') && (ch <= 'f')) || ((ch >= 'A') && (ch <= 'F'))) {
                    text += ch;
                    state = State::constans_q5;
                    ch = getNextChar();
                }
                else {
                    reportError(ch);
                    ch = getNextChar();
                    state = State::start_q0;
                }
                break;
            case State::constans_q6:
                ungetChar(ch);
                return Token::Hex;
                break;
            case State::constans_q9:
                ungetChar(ch);
                return Token::Octal;
                break;
        }
    }

}

const char *ConstLexer::tokenToString(Token tk)
{
        switch (tk) {
        case Token::Octal: return "Octal";
        case Token::Binary: return "Binary";
        case Token::Eof: return "Eof";
        case Token::Hex: return "Hex";
        case Token::Decimal: return "Decimal";
        default: return "Unknown";
    }

}