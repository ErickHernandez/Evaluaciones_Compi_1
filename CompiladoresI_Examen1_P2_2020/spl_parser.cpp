#include "spl_parser.h"
#define DEBUG 0

void SplParser::start(){
    while(!stack.empty()){

        currSymbol = stack.top();

        //if(DEBUG) std::cout<<"currSymbol: "<<SplLexer::tokenToString(currSymbol);
        //if(DEBUG) std::cout<<" currToken: "<<SplLexer::tokenToString(currToken)<<"\n";
        
        if(isTerminal(currSymbol) && currSymbol == currToken){
            stack.pop();
            currToken = lexer.getNextToken();
        } else if(currSymbol == Symbol::Epsilon){
            stack.pop();
        }else if(isTerminal(currSymbol) && currSymbol != currToken){ 

            if(DEBUG) std::cerr<<"token: "<<SplLexer::tokenToString(currToken)<<" lex: "<<lexer.getText()<<" symbol: "<<SplLexer::tokenToString(currSymbol)<<"\n";
            throw "Error, currSymbol and currToken are different";
        } else {
            const Rule& prod = getEntry(currSymbol, currToken);
            
            if(prod.isEmpty()){
                if(DEBUG) std::cerr<<"token: "<<SplLexer::tokenToString(currToken)<<" lex: "<<lexer.getText()<<" symbol: "<<SplLexer::tokenToString(currSymbol)<<"\n";
                throw "Syntax error, no production found";
            }
            
            stack.pop();

            for(int i = prod.rhs.size()-1; i>=0; i--){
                stack.push(prod.rhs[i]);
            }
        }
    }

}