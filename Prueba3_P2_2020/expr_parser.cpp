
#include "expr_parser.h"
#include <iostream>
#include <string>


void Parser::parse(){
    
    bool parsed = false;
    currToken = lexer.getNextToken();
    symbolStk.push(Symbol::input);
    stateStk.push(0);


    while(!parsed){
    
        currState = stateStk.top();
        const PAction& pact = lr::Action(currState, currToken);

        /* */
        if(currState == 5 && currToken == Symbol::Eof){
            parsed = true;
        } else if(pact.isShift()){
            symbolStk.push(currToken);
            stateStk.push(pact.getValue()); //In shift, getValue() returns a state number
            currToken = lexer.getNextToken();
        } else if(pact.isReduce()){
            const Rule& rule = lr::rule(pact.getValue()); //In reduce, getValue() returns a rule index

            if(!(rule.rhs.size() == 1 && rule.rhs[0] == Symbol::Epsilon)){
                for(int i=0; i<rule.rhs.size(); i++){
                    symbolStk.pop();
                    stateStk.pop();
                }

                currState = stateStk.top();
                unsigned st = lr::Goto(currState, rule.lhs);

                symbolStk.push(rule.lhs);
                stateStk.push(st);
            }
        } else {
            throw "Syntax Error, input not parsed \n";
        }
        

        //std::cerr<<"Syntax Error not EoF Reached. Found token: "<<Lexer::tokenToString(currToken)<<" Lexema: "<<lexer.getText();

    }

	std::cout<<"Perfect Syntax!"<<"\n";
			

}


// const char* Parser::symbolToString(Symbol symbol){
//     switch (symbol)
//     {
//         case Symbol::
//             return "OpPlus";
//         case Symbol::OpMul:
//             return "OpMult";
//         case Symbol::OpenPar:
//             return "OpenPar";
//         case Symbol::ClosePar:
//             return "ClosePar";
//         case Symbol::Eof:
//             return "Eof";
//         case Symbol::Number:
//             return "Number";
//         case Symbol::input:
//             return "input";
//         case Symbol::expr:
//             return "expr";
//         case Symbol::term:
//             return "term";
//         case Symbol::factor:
//             return "factor";
//         default:
//             throw "Error in symbolToString";
//     }
// }