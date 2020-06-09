#ifndef _EXPR_PARSER_H
#define _EXPR_PARSER_H

#include "expr_lexer.h"
//#include "grammar.h"
#include <stack>

class Parser {
public:
	Parser(Lexer &lexer): lexer (lexer)	{ }
	
	void parse();

// private:
// 	const char* symbolToString(Symbol symbol);

private:
    Lexer &lexer;
	std::stack<Symbol> symbolStk;
	std::stack<int> stateStk;
	Symbol currToken;
	//Symbol currSymbol;
	unsigned currState;
};

#endif
