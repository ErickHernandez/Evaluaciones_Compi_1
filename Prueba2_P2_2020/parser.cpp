#include "parser.h"

void Parser::input(){
    stmt_list();
    opt_eol();
}

void Parser::stmt_list(){
    stmt();

    while(currToken == Token::Eol){
        currToken = lexer.getNextToken();
        stmt();
    }
}

void Parser::opt_eol(){
    if(currToken == Token::Eol){
        currToken = lexer.getNextToken();
    }
}

void Parser::stmt(){
    if(currToken == Token::Ident){
        currToken = lexer.getNextToken();

        if(currToken == Token::OpAssign){
            //currToken == lexer.getPrevToken();
            currToken = lexer.getNextToken();
            assign();
        } else {
            fun_decl();
        }

        assign();
    } else if(currToken == Token::KwPrint){
        currToken = lexer.getNextToken();
        if(currToken == Token::OpenPar){
            currToken == lexer.getNextToken();
            
            expr();
            
            if(currToken != Token::ClosePar)
                throw "Syntax Error: Not closing parenthesis found";
            
            currToken = lexer.getNextToken();
        }
    } else {
        throw "Syntax Error. function stmt()";
    }
}

void Parser::assign(){
    expr();
}

void Parser::fun_decl(){
    if(currToken == Token::Ident){
        currToken = lexer.getNextToken();
        opt_arg_list();

        if(currToken == Token::OpAssign){
            currToken = lexer.getNextToken();
            expr();
        } else {
            throw "Syntax Error token assign expected";
        }
    } else {
        throw "Syntax Error. function fun_decl()";
    }
}

void Parser::opt_arg_list(){
    if(currToken == Token::Number || currToken == Token::Ident){
        currToken = lexer.getNextToken();
        arg_list();
    } 
    // else donothing();
}

void Parser::arg_list(){
    arg();

    while(currToken == Token::Number || currToken == Token::Ident){
        currToken = lexer.getNextToken();
        arg();
    }
}

void Parser::arg(){
    if(currToken == Token::Number){
        currToken = lexer.getNextToken();
    } else if(currToken == Token::Ident){
        currToken = lexer.getNextToken();
    } else{
        throw "Syntax Error. function: arg";
    }
}

void Parser::expr(){
    term();

    while(currToken == Token::OpAdd){
        currToken = lexer.getNextToken();        
        term();
    }

    while(currToken == Token::OpSub){
        currToken = lexer.getNextToken();        
        term();
    }
}

void Parser::term(){
    factor();

    while(currToken == Token::OpMul){
        currToken = lexer.getNextToken();
        factor();
    }

    while(currToken == Token::OpDiv){
        currToken = lexer.getNextToken();
        factor();
    }
}

void Parser::factor(){
    if(currToken == Token::Number){
        currToken = lexer.getNextToken();
    } else if(currToken == Token::OpenPar){
        currToken = lexer.getNextToken();
        expr();
        if(currToken != Token::ClosePar){
            //Error
            throw "Syntax Error not closing parenthesis found. function: factor";
        }
        currToken = lexer.getNextToken();
    } else if(currToken == Token::Ident){
        currToken = lexer.getNextToken();
    }else {
        //Error
        throw "Syntax Error. function: factor";
    }
}
