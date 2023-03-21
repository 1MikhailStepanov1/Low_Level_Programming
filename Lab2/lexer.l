%{
#include <iostream>
#include <string>
#include <cstdlib>
#include "../Lab2/include/ast.h"
#include "parser.h"
%}

%option yylineno noyywrap nounput noinput

%%

"("                                     { return L_BRACKET; }
")"                                     { return R_BRACKET; }
"{"                                     { return L_BRACE; }
"}"                                     { return R_BRACE; }
"["                                     { return L_SQUARE_BRACKET; }
"]"                                     { return R_SQUARE_BRACKET; }
","                                     { return COMMA; }
"gt"                                    { yylval.filter_op = filter_operation::GT; return COMP_OP; }
"ge"                                    { yylval.filter_op = filter_operation::GE; return COMP_OP; }
"lt"                                    { yylval.filter_op = filter_operation::LT; return COMP_OP; }
"le"                                    { yylval.filter_op = filter_operation::LE; return COMP_OP; }
"ne"                                    { yylval.filter_op = filter_operation::NE; return COMP_OP; }
"like"                                  { yylval.filter_op = filter_operation::LIKE; return LIKE_FILTER; }
"or"                                    { yylval.logical_op = logical_operation::OR; return LOGIC_OP; }
"and"                                   { yylval.logical_op = logical_operation::AND; return LOGIC_OP; }
"filter"                                { return FILTER_TOKEN; }
"op:"                                   { return OP_TOKEN; }
"val:"                                  { return VAL_TOKEN; }
"select: true"                          { return SELECTION_FLAG; }
"delete: true"                          { return DELETE_FLAG; }
"insert:"                               { return INSERTION_FLAG; }
"update:"                               { return UPDATE_FLAG; }
"props"                                 { return PROPS_TOKEN; }
"relations"                             { return RELATIONS_TOKEN; }
\"set\"                                 { yylval.sub_op = sub_operation::SET; return SUB_OPERATION_TOKEN; }
\"add\"                                 { yylval.sub_op = sub_operation::ADD; return SUB_OPERATION_TOKEN; }
\"sub\"                                 { yylval.sub_op = sub_operation::SUB; return SUB_OPERATION_TOKEN; }
"node_name: "                           { return NODE_NAME; }
"node_class: "                          { return NODE_CLASS; }
"true"                                  { yylval.bool_val = true; return BOOL_TOKEN; }
"false"                                 { yylval.bool_val = false; return BOOL_TOKEN; }
[A-Za-z]+[0-9A-z]*                      { yylval.str = strdup(yytext); return NAME_TOKEN; }
(props|relations)\.[A-Za-z]+[0-9A-z]*   { yylval.str = strdup(yytext); return REF_TOKEN;}
\"[^\"]*\"                              { yylval.str = strdup(yytext); return STRING_TOKEN; }
-?[0-9]+                                { yylval.int_val = atoi(yytext); return INT_TOKEN; }
-?[0-9]+\.[0-9]+                        { yylval.float_val = atof(yytext); return FLOAT_TOKEN; }
[ \t\n]+                                { /* ignore white spaces */ }
.                                       { /* ignore everything else */ }

%%