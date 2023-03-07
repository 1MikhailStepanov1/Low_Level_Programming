%{
#include <iostream>
#include <list>
#include "../include/ast.h"

extern int yylex();

void yyerror(const char* s){
    extern int yylineno;
    std::cerr << yylineno << ": error" << s << std::endl;
}

%}

%define parse.error verbose


%union {
    const char* str;
    float float_val;
    int int_val;
    bool bool_val;

    Node* node;

}
%type<node>
%%

query:

%%