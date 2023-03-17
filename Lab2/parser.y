%{
#include <iostream>
#include <list>
#include "../Lab2/include/ast.h"

extern int yylex();

void yyerror(NodeWrapper& nodeWrapper, const char* s){
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
    filter_operation filter_op;
    logical_operation logical_op;

    Node* node;
    QueryNode* queryNode;
    SelectionSetNode* selectionSetNode;
    ResultSetNode* resultSetNode;
    ArgumentWrapperNode* argumentWrapperNode;
    ArgumentNode* argumentNode;
    ObjectWrapperNode* objectWrapperNode;
    ObjectNode* objectNode;
    FieldsWrapperNode* fieldsWrapperNode;
    FieldNode* fieldNode;
    RelationWrapperNode* relationWrapperNode;
    RelationNode* relationNode;
    SubOperationWrapperNode* subOperationWrapperNode;
    SubOperationNode* subOperationNode;
    FilterNode* filterNode;
    LogicalOperationNode* logicalOperationNode;
    ConstantNode* constant;
    StringConstant* stringConstant;
}

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
%token<str> REF_TOKEN
%token PROPS_TOKEN
%token RELATIONS_TOKEN
%token<str> SUB_OPERATION_TOKEN
%token NODE_NAME
%token NODE_CLASS
%token FILTER_TOKEN
%token OP_TOKEN
%token VAL_TOKEN
%token<logical_op> LOGIC_OP
%token<filter_op> COMP_OP
%token<filter_op> LIKE_FILTER
%token<int_val> INT_TOKEN
%token<float_val> FLOAT_TOKEN
%token<str> STRING_TOKEN
%token<bool_val> BOOL_TOKEN

%type<queryNode> select_query delete_query insert_query update_query
%type<selectionSetNode> selection_set
%type<resultSetNode> result_set
%type<argumentWrapperNode> arguments
%type<argumentNode> argument
%type<objectWrapperNode> objects
%type<objectNode> object
%type<fieldsWrapperNode> fields
%type<fieldNode> field
%type<relationWrapperNode> relations
%type<relationNode> relation
%type<subOperationWrapperNode> sub_operations
%type<subOperationNode> sub_operation
%type<filterNode> filter
%type<logicalOperationNode> logic_op
%type<constant> value
%type<stringConstant> name

%left LOGIC_OP
%left SELECTION_FLAG
%left DELETE_FLAG
%left INSERTION_FLAG
%left UPDATE_FLAG

%%

query: select_query { root.node = $1;}
      | delete_query { root.node = $1; }
      | insert_query { root.node = $1; }
      | update_query { root.node = $1; }

select_query: name L_BRACKET SELECTION_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE { QueryNode* node = new QueryNode("select", $1); node->setSelectionSet($5); node->setResultSet($8); $$ = node; }

delete_query: name L_BRACKET DELETE_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE { QueryNode* node = new QueryNode("delete", $1); node->setSelectionSet($5); node->setResultSet($8); $$ = node; }

insert_query: name L_BRACKET INSERTION_FLAG selection_set R_BRACKET L_BRACE result_set R_BRACE { QueryNode* node = new QueryNode("insert", $1); node->setSelectionSet($4); node->setResultSet($7); $$ = node; }

update_query: name L_BRACKET UPDATE_FLAG selection_set R_BRACKET L_BRACE result_set R_BRACE { QueryNode* node = new QueryNode("update", $1); node->setSelectionSet($4); node->setResultSet($7); $$ = node; }

selection_set: arguments { SelectionSetNode* node = new SelectionSetNode(); node->set_args($1); $$ = node; }
              | L_BRACE objects R_BRACE { SelectionSetNode* node = new SelectionSetNode(); node->set_objs($2); $$ = node; }
              | L_SQUARE_BRACKET sub_operations R_SQUARE_BRACKET { SelectionSetNode* node = new SelectionSetNode(); node->set_subops($2); $$ = node; }
              | L_SQUARE_BRACKET sub_operations R_SQUARE_BRACKET COMMA arguments { SelectionSetNode* node = new SelectionSetNode(); node->set_subops($2); node->set_args($5); $$ = node; }

result_set: result_set COMMA name { $$ = $1; $1->add_attr($3); }
           | result_set COMMA REF_TOKEN { $$ = $1; $1->add_attr(new StringConstant($3)); }
           | REF_TOKEN { $$ = new ResultSetNode(); $$->add_attr(new StringConstant($1)); }
           | name { $$ = new ResultSetNode(); $$->add_attr($1); }

arguments: arguments COMMA argument { $$ = $1; $1->add_attr($3); }
          | arguments COMMA logic_op { $$ = $1; $1->add_attr($3); }
          | argument { $$ = new ArgumentWrapperNode(); $$->add_attr($1); }
          | logic_op { $$ = new ArgumentWrapperNode(); $$->add_attr($1); }

argument: name value { $$ = new ArgumentNode($1, $2); }
         | name filter VAL_TOKEN value R_BRACE { ArgumentNode* node = new ArgumentNode($1, $4); node->set_filter($2); $$ = node; }
         | name filter VAL_TOKEN STRING_TOKEN R_BRACE { ArgumentNode* node = new ArgumentNode($1, new StringConstant($4)); node->set_filter($2); $$ = node; }

         | REF_TOKEN value { $$ = new ArgumentNode(new StringConstant($1), $2); }
         | REF_TOKEN filter VAL_TOKEN value R_BRACE { ArgumentNode* node = new ArgumentNode(new StringConstant($1), $4); node->set_filter($2); $$ = node; }
         | REF_TOKEN filter VAL_TOKEN STRING_TOKEN R_BRACE { ArgumentNode* node = new ArgumentNode(new StringConstant($1), new StringConstant($4)); node->set_filter($2); $$ = node; }

         | NODE_NAME STRING_TOKEN { $$ = new ArgumentNode(new StringConstant("node_name"), new StringConstant($2)); }
         | NODE_NAME filter VAL_TOKEN STRING_TOKEN R_BRACE { ArgumentNode* node = new ArgumentNode(new StringConstant("node_name"), new StringConstant($4)); node->set_filter($2); $$ = node; }

         | NODE_CLASS STRING_TOKEN { $$ = new ArgumentNode(new StringConstant("node_class"), new StringConstant($2)); }
         | NODE_CLASS filter VAL_TOKEN STRING_TOKEN R_BRACE { ArgumentNode* node = new ArgumentNode(new StringConstant("node_class"), new StringConstant($4)); node->set_filter($2); $$ = node; }

logic_op: LOGIC_OP L_BRACE arguments R_BRACE { LogicalOperationNode* node = new LogicalOperationNode($1); node->set_attr($3); $$ = node; }

filter: FILTER_TOKEN L_BRACE OP_TOKEN COMP_OP COMMA { $$ = new FilterNode($4); }
       | FILTER_TOKEN L_BRACE OP_TOKEN LIKE_FILTER COMMA { $$ = new FilterNode($4); }

objects: objects COMMA object { $$ = $1; $$->add_attr($3); }
        | object { $$ = new ObjectWrapperNode(); $$->add_attr($1); }

object: L_BRACE NODE_NAME name R_BRACE{ $$ = new ObjectNode($3); }
       | L_BRACE NODE_NAME name COMMA PROPS_TOKEN L_BRACE fields R_BRACE R_BRACE{ $$ = new ObjectNode($3); $$->add_props($7); }
       | L_BRACE NODE_NAME name COMMA RELATIONS_TOKEN L_BRACE relations R_BRACE R_BRACE{ $$ = new ObjectNode($3); $$->add_rels($7); }
       | L_BRACE NODE_NAME name COMMA PROPS_TOKEN L_BRACE fields R_BRACE RELATIONS_TOKEN L_BRACE relations R_BRACE R_BRACE{ $$ = new ObjectNode($3); $$->add_props($7); $$->add_rels($11); }

fields: fields COMMA field { $$ = $1; $1->add_attr($3); }
       | field { $$ = new FieldsWrapperNode(); $$->add_attr($1); }

field: name value { $$ = new FieldNode($1, $2); }

relations: relations COMMA relation { $$ = $1; $1->add_attr($3); }
          | relation { $$ = new RelationWrapperNode(); $$->add_attr($1); }

relation: name { $$ = new RelationNode($1); }

sub_operations: sub_operations COMMA sub_operation { $$ = $1; $1->add_attr($3); }
               | sub_operation { $$ = new SubOperationWrapperNode(); $$->add_attr($1); }

sub_operation: L_SQUARE_BRACKET SUB_OPERATION_TOKEN COMMA name COMMA value R_SQUARE_BRACKET { $$ = new SubOperationNode($2, $4, $6); }
              | L_SQUARE_BRACKET SUB_OPERATION_TOKEN COMMA REF_TOKEN COMMA value R_SQUARE_BRACKET { $$ = new SubOperationNode($2, new StringConstant($4), $6); }

name: NAME_TOKEN { $$ = new StringConstant($1); }

value: INT_TOKEN { $$ = new IntConstant($1); }
      | FLOAT_TOKEN { $$ = new FloatConstant($1); }
      | STRING_TOKEN { $$ = new StringConstant($1); }
      | BOOL_TOKEN { $$ = new BoolConstant($1); }

%%