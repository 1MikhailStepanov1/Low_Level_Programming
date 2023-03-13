%{
#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/ast.h"
#include "parser.h"
%}

%option yylineno noyywrap nounput

%%

""                  { return CLASS_TYPE; }
"("                 { return L_BRACKET; }
")"                 { return R_BRACKET; }
"{"                 { return L_BRACE; }
"}"                 { return R_BRACE; }
"["                 { return L_SQUARE_BRACKET; }
"}"                 { return R_SQUARE_BRACKET; }
","                 { return COMMA; }
"select: true"      { return SELECTION_FLAG; }
"delete: true"      { return DELETE_FLAG; }
"insert: "          { return INSERTION_FLAG; }
"update: "          { return UPDATE_FLAG; }
""                  { return NAME_TOKEN; }
""                  { return PROPS_TOKEN; }
""                  { return RELATIONS_TOKEN; }
""                  { return SUB_OPERATION_TOKEN; }
"true"              { yylval.boolVal = true; return BOOL_TOKEN; }
"false"             { yylval.boolVal = false; return BOOL_TOKEN; }
\"[^\"]*\"          { yylval.str = strdup(yytext); return STRING_TOKEN; }
-?[0-9]+            { yylval.intVal = atoi(yytext); return INT_TOKEN; }
-?[0-9]+\.[0-9]+    { yylval.floatVal = atof(yytext); return FLOAT_TOKEN; }
[ \t\n]+            { /* ignore white spaces */ }
.                   { /* ignore everything else */ }


%%