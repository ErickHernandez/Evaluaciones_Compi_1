#ifndef _PARSER_H_
#define _PARSER_H_
#include "spl_lexer.h"
#include <stack>

class SplParser {
    public:
	SplParser(SplLexer &lexer): lexer (lexer)	{ }
	
	bool parse() {
        currToken = lexer.getNextToken();
		stack.push(Symbol::Eof);
		stack.push(Symbol::opt_func_list);

		try{
			start();

			if(currToken != Symbol::Eof){
				std::cerr<<"Syntax Error not EoF Reached. Found token: "<<SplLexer::tokenToString(currToken)<<" Lexema: "<<lexer.getText(); // Imprimir numero de linea, columna
                return false;
			} else {
				std::cout<<"Perfect Syntax!"<<"\n";
                return true;
			}
		}catch (const char* msg){
			std::cerr<<msg<<"\n";
		}

        return false;

    }

    private:
	void start();
	//Symbol tokenToSymbol(Token tk);
	const char* symbolToString(Symbol symbol);

    private:
        Symbol currToken;
        SplLexer &lexer;
        std::stack<Symbol> stack;
        Symbol currSymbol;
};

#endif
