#ifndef _EXPR_PARSER_H
#define _EXPR_PARSER_H

#include <iosfwd>
#include "lexer.h"

class Parser {
public:
	Parser(Lexer &lexer): lexer (lexer) { }
	void parse() {
        currToken = lexer.getNextToken();
        input();

		if(currToken != Token::Eof){
			std::cerr<<"Syntax Error not EoF Reached. Found token: "<<Lexer::tokenToString(currToken)<<" Lexema: "<<lexer.getText(); // Imprimir numero de linea, columna
		} else {
			std::cout<<"Perfect Sintax!"<<"\n";
		}
    }

private:
	void input();
	void stmt_list();
	void opt_eol();
	void stmt();
	void assign();
	void fun_decl();
	void opt_arg_list();
	void arg_list();
	void arg();
	void expr();
	void term();
	void factor();

private:
	Lexer &lexer;
	Token currToken;
};

#endif
