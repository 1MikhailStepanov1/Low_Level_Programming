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

%parse-param { NodeWrapper& root}

%union {
    const char* str;
    float float_val;
    int int_val;
    bool bool_val;

    Node* node;
    Constant* constant;
}

%token CLASS_TYPE
%token L_BRACKET
%token R_BRACKET
%token L_BRACE
%token R_BRACE
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token COMMA
%token SELECTION_FLAG
%token DELETE_FLAG
%token INSERTION_FLAG
%token UPDATE_FLAG
%token NAME_TOKEN
%token PROPS_TOKEN
%token RELATIONS_TOKEN
%token SUB_OPERATION_TOKEN
%token INT_TOKEN
%token FLOAT_TOKEN
%token STRING_TOKEN
%token BOOL_TOKEN

%type<node> select_query delete_query insert_query update_query class_type
%type<constant> argument_value

%left SELECTION_FLAG
%left DELETE_FLAG
%left INSERTION_FLAG
%left UPDATE_FLAG

%%

query: select_query { root.node = $1;}
      | delete_query { root.node = $1; }
      | insert_query { root.node = $1; }
      | update_query { root.node = $1; }

select_query: CLASS_TYPE L_BRACKET SELECTION_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE { $$ = new QueryNode("select", $1); $$->setSelectionSet($4); $$->setResultSet($7); }

delete_query: CLASS_TYPE L_BRACKET DELETE_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE { $$ = new QueryNode("delete", $1); $$->setSelectionSet($4); $$->setResultSet($7); }

insert_query: CLASS_TYPE L_BRACKET INSERTION_FLAG selection_set R_BRACKET L_BRACE result_set R_BRACE { $$ = new QueryNode("insert", $1); $$->setSelectionSet($4); $$->setResultSet($7); }

update_query: CLASS_TYPE L_BRACKET UPDATE_FLAG selection_set R_BRACKET L_BRACE result_set R_BRACE { $$ = new QueryNode("update", $1); $$->setSelectionSet($4); $$->setResultSet($7); }

selection_set: arguments { $$ = new SelectionSetNode(); $$->add_args($1); }
               | L_BRACE objects R_BRACE { $$ = new SelectionSetNode(); $$->add_objs($1); }
               | L_SQUARE_BRACKET sub_operations R_SQUARE_BRACKET { $$ = new SelectionSetNode(); $$->add_subops($1); }
               | L_SQUARE_BRACKET sub_operations R_SQUARE_BRACKET COMMA arguments { $$ = new SelectionSetNode(); $$->add_subops($1); $$->add_args($3); }

result_set: fields { $$ = new ResultSetNode($1); }

arguments: arguments COMMA argument { $$ = $1; $1->add_attr($3); }
           | argument { $$ = new ArgumentWrapperNode(); $$->add_attr($1); }

argument: name value { $$ = new ArgumentNode($1, $2); }

objects: objects COMMA object { $$ = $1; $->add_attr($3); }
        | object { $$ = new ObjectWrapperNode(); $$->add_attr($1); }

object: L_BRACE name STRING_TOKEN COMMA name STRING_TOKEN R_BRACE{ $$ = new ObjectNode($3, $6); }
       | L_BRACE name STRING_TOKEN COMMA name STRING_TOKEN PROPS_TOKEN L_BRACE fields R_BRACE R_BRACE{ $$ = new ObjectNode($3, $6, $9); }
       | L_BRACE name STRING_TOKEN COMMA name STRING_TOKEN RELATIONS_TOKEN L_BRACE relations R_BRACE R_BRACE{ $$ = new ObjectNode($3, $6, $9); }
       | L_BRACE name STRING_TOKEN COMMA name STRING_TOKEN PROPS L_BRACE fields R_BRACE RELATIONS L_BRACE relations R_BRACE R_BRACE{ $$ = new ObjectNode($3, $6, $9, $13); }

fields: fields COMMA field { $$ = $1; $1->add_attr($3); }
       | field { $$ = new FieldsWrapper(); $$->add_attr($1); }

field: name value { $$ = new FieldNode($1, $2); }

relations: relations COMMA relation { $$ = $1; $1->add_attr($3); }
          | relation { $$ = new RelationWrapperNode(); $$->add_attr($1); }

relation: name { $$ = new RelationNode($1); }

sub_operations: sub_operations COMMA sub_operation { $$ = $1; $1->add_attr($3); }
               | sub_operation { $$ = new SubOperationWrapper(); $$->add_attr($1); }

sub_operation: L_SQUARE_BRACKET SUB_OPERATION_TOKEN COMMA name COMMA value R_SQUARE_BRACKET { $$ = new SubOperationNode($2, $4, $6); }

name: NAME_TOKEN { $$ = new StringConstant($1); }

value: INT_TOKEN { $$ = new IntConstant($1); }
      | FLOAT_TOKEN { $$ = new FloatConstant($1); }
      | STRING_TOKEN { $$ = new StringConstant($1); }
      | BOOL_TOKEN { $$ = new BoolConstant($1); }

%%