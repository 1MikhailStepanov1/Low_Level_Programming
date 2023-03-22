/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_MIKHAIL_CLIONPROJECTS_LOW_LEVEL_PROGRAMMING_LAB2_PARSER_H_INCLUDED
# define YY_YY_HOME_MIKHAIL_CLIONPROJECTS_LOW_LEVEL_PROGRAMMING_LAB2_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    L_BRACKET = 258,               /* L_BRACKET  */
    R_BRACKET = 259,               /* R_BRACKET  */
    L_BRACE = 260,                 /* L_BRACE  */
    R_BRACE = 261,                 /* R_BRACE  */
    L_SQUARE_BRACKET = 262,        /* L_SQUARE_BRACKET  */
    R_SQUARE_BRACKET = 263,        /* R_SQUARE_BRACKET  */
    COMMA = 264,                   /* COMMA  */
    SELECTION_FLAG = 265,          /* SELECTION_FLAG  */
    DELETE_FLAG = 266,             /* DELETE_FLAG  */
    INSERTION_FLAG = 267,          /* INSERTION_FLAG  */
    UPDATE_FLAG = 268,             /* UPDATE_FLAG  */
    NAME_TOKEN = 269,              /* NAME_TOKEN  */
    REF_TOKEN = 270,               /* REF_TOKEN  */
    PROPS_TOKEN = 271,             /* PROPS_TOKEN  */
    RELATIONS_TOKEN = 272,         /* RELATIONS_TOKEN  */
    SUB_OPERATION_TOKEN = 273,     /* SUB_OPERATION_TOKEN  */
    NODE_NAME = 274,               /* NODE_NAME  */
    NODE_CLASS = 275,              /* NODE_CLASS  */
    FILTER_TOKEN = 276,            /* FILTER_TOKEN  */
    OP_TOKEN = 277,                /* OP_TOKEN  */
    VAL_TOKEN = 278,               /* VAL_TOKEN  */
    LOGIC_OP = 279,                /* LOGIC_OP  */
    COMP_OP = 280,                 /* COMP_OP  */
    LIKE_FILTER = 281,             /* LIKE_FILTER  */
    INT_TOKEN = 282,               /* INT_TOKEN  */
    FLOAT_TOKEN = 283,             /* FLOAT_TOKEN  */
    STRING_TOKEN = 284,            /* STRING_TOKEN  */
    BOOL_TOKEN = 285               /* BOOL_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"

    const char* str;
    float float_val;
    int int_val;
    bool bool_val;
    filter_operation filter_op;
    logical_operation logical_op;
    sub_operation sub_op;

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

#line 123 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (NodeWrapper& root);


#endif /* !YY_YY_HOME_MIKHAIL_CLIONPROJECTS_LOW_LEVEL_PROGRAMMING_LAB2_PARSER_H_INCLUDED  */
