%{
#include <iostream>
#include <list>
#include "../Lab2/include/ast.h"

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
    QueryNode* queryNode;
    SelectionSetNode* selectionSetNode;
    ResultSetNode* resultSetNode;
    ArgumentWrapperNode* argumentWrapperNode;
    ArgumentNode* argumentNode;
    ObjectWrapperNode* objectWrapperNode;
    ObjectNode* objectNode;
    FieldsWrapperNode fieldsWrapperNode;
    FieldNode* fieldNode;
    RelationWrapperNode* relationWrapperNode;
    RelationNode* relationNode;
    SubOperationWrapperNode subOperationWrapperNode;
    SubOperationNode subOperationNode;
    ConstantNode* constant;
}

%token<str> CLASS_TYPE
%token<str> L_BRACKET
%token<str> R_BRACKET
%token<str> L_BRACE
%token<str> R_BRACE
%token<str> L_SQUARE_BRACKET
%token<str> R_SQUARE_BRACKET
%token<str> COMMA
%token SELECTION_FLAG
%token DELETE_FLAG
%token INSERTION_FLAG
%token UPDATE_FLAG
%token<str> NAME_TOKEN
%token PROPS_TOKEN
%token RELATIONS_TOKEN
%token<str> SUB_OPERATION_TOKEN
%token NODE_NAME
%token NODE_CLASS
%token<int_val> INT_TOKEN
%token<float_val> FLOAT_TOKEN
%token<str> STRING_TOKEN
%token<bool_val> BOOL_TOKEN

%type<node> select_query delete_query insert_query update_query selection_set result_set arguments argument objects object fields field relations relation sub_operations sub_operation
%type<constant> value name

%left SELECTION_FLAG
%left DELETE_FLAG
%left INSERTION_FLAG
%left UPDATE_FLAG

%%

query: select_query { root.node = $1;}
      | delete_query { root.node = $1; }
      | insert_query { root.node = $1; }
      | update_query { root.node = $1; }

select_query: CLASS_TYPE L_BRACKET SELECTION_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE { QueryNode* node = new QueryNode("select", $1); node->setSelectionSet($5); node->setResultSet($8); $$ = node; }

delete_query: CLASS_TYPE L_BRACKET DELETE_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE { QueryNode* node = new QueryNode("delete", $1); node->setSelectionSet($5); node->setResultSet($8); $$ = node; }

insert_query: CLASS_TYPE L_BRACKET INSERTION_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE { QueryNode* node = new QueryNode("insert", $1); node->setSelectionSet($5); node->setResultSet($8); $$ = node; }

update_query: CLASS_TYPE L_BRACKET UPDATE_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE { QueryNode* node = new QueryNode("update", $1); node->setSelectionSet($5); node->setResultSet($8); $$ = node; }

selection_set: arguments { SelectionSetNode* node = new SelectionSetNode(); node->set_args($1); $$ = node; }
               | L_BRACE objects R_BRACE { SelectionSetNode* node = new SelectionSetNode(); node->set_objs($2); $$ = node; }
               | L_SQUARE_BRACKET sub_operations R_SQUARE_BRACKET { SelectionSetNode* node = new SelectionSetNode(); node->set_subops($2); $$ = node; }
               | L_SQUARE_BRACKET sub_operations R_SQUARE_BRACKET COMMA arguments { SelectionSetNode* node = new SelectionSetNode(); node->set_subops($2); node->set_args($5); $$ = node; }

result_set: result_set COMMA name { $$ = $1; $1->add_attr($3); }
           | name { $$ = new ResultSetNode(); $$->add_attr($1); }

arguments: arguments COMMA argument { $$ = $1; $1->add_attr($3); }
           | argument { $$ = new ArgumentWrapperNode(); $$->add_attr($1); }

argument: name value { $$ = new ArgumentNode($1, $2); }

objects: objects COMMA object { $$ = $1; $$->add_attr($3); }
        | object { $$ = new ObjectWrapperNode(); $$->add_attr($1); }

object: L_BRACE NODE_NAME name COMMA NODE_CLASS name R_BRACE{ $$ = new ObjectNode($3, $6); }
       | L_BRACE NODE_NAME name COMMA NODE_CLASS name PROPS_TOKEN L_BRACE fields R_BRACE R_BRACE{ $$ = new ObjectNode($3, $6); $$->add_props($9); }
       | L_BRACE NODE_NAME name COMMA NODE_CLASS name RELATIONS_TOKEN L_BRACE relations R_BRACE R_BRACE{ $$ = new ObjectNode($3, $6); $$->add_rels($9); }
       | L_BRACE NODE_NAME name COMMA NODE_CLASS name PROPS_TOKEN L_BRACE fields R_BRACE RELATIONS_TOKEN L_BRACE relations R_BRACE R_BRACE{ $$ = new ObjectNode($3, $6); $$->add_props($9); $$->add_rels($13); }

fields: fields COMMA field { $$ = $1; $1->add_attr($3); }
       | field { $$ = new FieldsWrapperNode(); $$->add_attr($1); }

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