/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"

#include <iostream>
#include <list>
#include "../Lab2/include/ast.h"

extern int yylex();

void yyerror(NodeWrapper& nodeWrapper, const char* s){
    extern int yylineno;
    std::cerr << yylineno << ": error" << s << std::endl;
}


#line 85 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_L_BRACKET = 3,                  /* L_BRACKET  */
  YYSYMBOL_R_BRACKET = 4,                  /* R_BRACKET  */
  YYSYMBOL_L_BRACE = 5,                    /* L_BRACE  */
  YYSYMBOL_R_BRACE = 6,                    /* R_BRACE  */
  YYSYMBOL_L_SQUARE_BRACKET = 7,           /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 8,           /* R_SQUARE_BRACKET  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_SELECTION_FLAG = 10,            /* SELECTION_FLAG  */
  YYSYMBOL_DELETE_FLAG = 11,               /* DELETE_FLAG  */
  YYSYMBOL_INSERTION_FLAG = 12,            /* INSERTION_FLAG  */
  YYSYMBOL_UPDATE_FLAG = 13,               /* UPDATE_FLAG  */
  YYSYMBOL_NAME_TOKEN = 14,                /* NAME_TOKEN  */
  YYSYMBOL_REF_TOKEN = 15,                 /* REF_TOKEN  */
  YYSYMBOL_PROPS_TOKEN = 16,               /* PROPS_TOKEN  */
  YYSYMBOL_RELATIONS_TOKEN = 17,           /* RELATIONS_TOKEN  */
  YYSYMBOL_SUB_OPERATION_TOKEN = 18,       /* SUB_OPERATION_TOKEN  */
  YYSYMBOL_NODE_NAME = 19,                 /* NODE_NAME  */
  YYSYMBOL_NODE_CLASS = 20,                /* NODE_CLASS  */
  YYSYMBOL_FILTER_TOKEN = 21,              /* FILTER_TOKEN  */
  YYSYMBOL_OP_TOKEN = 22,                  /* OP_TOKEN  */
  YYSYMBOL_VAL_TOKEN = 23,                 /* VAL_TOKEN  */
  YYSYMBOL_LOGIC_OP = 24,                  /* LOGIC_OP  */
  YYSYMBOL_COMP_OP = 25,                   /* COMP_OP  */
  YYSYMBOL_LIKE_FILTER = 26,               /* LIKE_FILTER  */
  YYSYMBOL_INT_TOKEN = 27,                 /* INT_TOKEN  */
  YYSYMBOL_FLOAT_TOKEN = 28,               /* FLOAT_TOKEN  */
  YYSYMBOL_STRING_TOKEN = 29,              /* STRING_TOKEN  */
  YYSYMBOL_BOOL_TOKEN = 30,                /* BOOL_TOKEN  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_query = 32,                     /* query  */
  YYSYMBOL_select_query = 33,              /* select_query  */
  YYSYMBOL_delete_query = 34,              /* delete_query  */
  YYSYMBOL_insert_query = 35,              /* insert_query  */
  YYSYMBOL_update_query = 36,              /* update_query  */
  YYSYMBOL_selection_set = 37,             /* selection_set  */
  YYSYMBOL_result_set = 38,                /* result_set  */
  YYSYMBOL_arguments = 39,                 /* arguments  */
  YYSYMBOL_argument = 40,                  /* argument  */
  YYSYMBOL_logic_op = 41,                  /* logic_op  */
  YYSYMBOL_filter = 42,                    /* filter  */
  YYSYMBOL_objects = 43,                   /* objects  */
  YYSYMBOL_object = 44,                    /* object  */
  YYSYMBOL_fields = 45,                    /* fields  */
  YYSYMBOL_field = 46,                     /* field  */
  YYSYMBOL_relations = 47,                 /* relations  */
  YYSYMBOL_relation = 48,                  /* relation  */
  YYSYMBOL_sub_operations = 49,            /* sub_operations  */
  YYSYMBOL_sub_operation = 50,             /* sub_operation  */
  YYSYMBOL_name = 51,                      /* name  */
  YYSYMBOL_value = 52                      /* value  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   103,   103,   104,   105,   106,   108,   109,   110,   112,
     114,   116,   118,   119,   120,   121,   123,   124,   125,   126,
     128,   129,   130,   131,   133,   134,   135,   137,   138,   139,
     141,   142,   144,   145,   147,   149,   150,   152,   153,   155,
     156,   157,   158,   160,   161,   163,   165,   166,   168,   170,
     171,   173,   174,   176,   178,   179,   180,   181
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "L_BRACKET",
  "R_BRACKET", "L_BRACE", "R_BRACE", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "COMMA", "SELECTION_FLAG", "DELETE_FLAG",
  "INSERTION_FLAG", "UPDATE_FLAG", "NAME_TOKEN", "REF_TOKEN",
  "PROPS_TOKEN", "RELATIONS_TOKEN", "SUB_OPERATION_TOKEN", "NODE_NAME",
  "NODE_CLASS", "FILTER_TOKEN", "OP_TOKEN", "VAL_TOKEN", "LOGIC_OP",
  "COMP_OP", "LIKE_FILTER", "INT_TOKEN", "FLOAT_TOKEN", "STRING_TOKEN",
  "BOOL_TOKEN", "$accept", "query", "select_query", "delete_query",
  "insert_query", "update_query", "selection_set", "result_set",
  "arguments", "argument", "logic_op", "filter", "objects", "object",
  "fields", "field", "relations", "relation", "sub_operations",
  "sub_operation", "name", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,   -48,     7,   -48,   -48,   -48,   -48,    23,   -48,    30,
      19,    29,    -2,    -2,    39,    -2,    -2,    65,   100,     6,
     -15,    16,    67,     5,   102,   -48,   -48,     6,    91,   106,
     109,   110,    96,    58,   -48,    98,    79,   -48,   112,   -48,
     -48,   -48,   -48,    97,   -48,   -48,   101,   -48,   103,    -4,
     113,    -4,   104,   -48,   114,   -48,   116,   120,   -10,   -48,
      65,   119,   121,   100,   107,    20,   105,   108,    62,    84,
     -48,   -48,    24,    84,    15,    84,    70,   -48,    86,    -4,
     -48,    78,   125,   126,   127,   130,   -48,   -48,    71,   -48,
     133,   134,    75,   -48,    76,    77,   -48,    89,   132,   135,
     102,   137,   138,   -48,   -48,   -48,   -48,   -48,    95,   -48,
     -48,   -48,   -48,   -48,   143,   144,    32,    32,   -48,   -48,
     -48,   -48,   -10,   -10,   142,   145,    83,   -48,    32,    87,
     -48,   122,   -48,   -48,     2,   -10,   -48,   136,   -10,   -48,
     -48,   147,   -48,   -48,   -48,   -10,    88,   148,   -48
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    53,     0,     2,     3,     4,     5,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    22,    23,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    50,     0,    54,
      55,    56,    57,     0,    27,    30,     0,    32,     0,     0,
       0,     0,     0,    24,     0,     7,     0,     0,     0,    13,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
      20,    21,     0,     0,     0,     0,     0,    37,     0,     0,
      49,     0,     0,     0,     0,     0,    34,    18,     0,    19,
       0,     0,     0,     8,     0,     0,    39,     0,     0,     0,
      15,     0,     0,    29,    28,    31,    33,    10,     0,    26,
      25,    11,     6,     9,     0,     0,     0,     0,    35,    36,
      17,    16,     0,     0,     0,     0,     0,    44,     0,     0,
      47,     0,    52,    51,     0,     0,    45,     0,     0,    48,
      40,     0,    43,    41,    46,     0,     0,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,   -48,   -48,   -48,    50,   -18,   -47,    92,
     111,     4,   -48,    99,   -48,    21,    10,    22,   -48,    94,
       0,   -26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     5,     6,    23,    88,    24,    25,
      26,    43,    33,    34,   126,   127,   129,   130,    36,    37,
      27,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,    53,    68,    17,     1,    18,    38,     8,   140,    50,
       1,    19,     1,    19,    45,    20,    21,    20,    21,   141,
      22,    93,    22,    14,    46,    48,     9,    38,    15,     1,
      87,    52,   100,    39,    40,    41,    42,    38,    16,    83,
      10,    11,    12,    13,    29,    47,    91,    39,    40,    82,
      42,    39,    40,    90,    42,    92,    94,    95,    76,    39,
      40,    41,    42,    28,    59,    30,    31,    60,    86,    89,
      32,    51,    49,    89,    89,    89,    96,   107,    99,    97,
     108,   111,   112,   113,   108,   108,   108,    62,    63,   134,
     124,   125,   135,   137,   147,    54,   138,   138,     1,    87,
       1,    98,   136,   101,   102,   114,   115,    35,   121,     1,
     120,    51,    55,    56,    57,    58,    61,    64,    69,    73,
      65,    74,   128,   131,    66,    75,    67,    72,    78,    81,
      79,   103,   104,   105,    84,   128,   106,    85,   131,   109,
     110,   116,   143,    70,   117,   131,   118,   119,   122,   123,
     132,   139,   145,   133,   148,   146,   142,    80,     0,    77,
     144,     0,    71
};

static const yytype_int16 yycheck[] =
{
       0,    27,    49,     5,    14,     7,    21,     0,     6,     4,
      14,    15,    14,    15,    29,    19,    20,    19,    20,    17,
      24,     6,    24,     4,    20,    21,     3,    21,     9,    14,
      15,    27,    79,    27,    28,    29,    30,    21,     9,    65,
      10,    11,    12,    13,     5,    29,    72,    27,    28,    29,
      30,    27,    28,    29,    30,    73,    74,    75,    58,    27,
      28,    29,    30,    13,     6,    15,    16,     9,     6,    69,
       5,     9,     5,    73,    74,    75,     6,     6,    78,     9,
       9,     6,     6,     6,     9,     9,     9,     8,     9,     6,
     116,   117,     9,     6,     6,     4,     9,     9,    14,    15,
      14,    15,   128,    25,    26,    16,    17,     7,   108,    14,
      15,     9,     6,     4,     4,    19,    18,     5,     5,     5,
      23,     5,   122,   123,    23,     5,    23,    23,     9,    22,
       9,     6,     6,     6,    29,   135,     6,    29,   138,     6,
       6,     9,     6,    51,     9,   145,     9,     9,     5,     5,
       8,    29,     5,     8,     6,   145,   135,    63,    -1,    60,
     138,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    32,    33,    34,    35,    36,    51,     0,     3,
      10,    11,    12,    13,     4,     9,     9,     5,     7,    15,
      19,    20,    24,    37,    39,    40,    41,    51,    37,     5,
      37,    37,     5,    43,    44,     7,    49,    50,    21,    27,
      28,    29,    30,    42,    52,    29,    42,    29,    42,     5,
       4,     9,    42,    52,     4,     6,     4,     4,    19,     6,
       9,    18,     8,     9,     5,    23,    23,    23,    39,     5,
      40,    41,    23,     5,     5,     5,    51,    44,     9,     9,
      50,    22,    29,    52,    29,    29,     6,    15,    38,    51,
      29,    52,    38,     6,    38,    38,     6,     9,    15,    51,
      39,    25,    26,     6,     6,     6,     6,     6,     9,     6,
       6,     6,     6,     6,    16,    17,     9,     9,     9,     9,
      15,    51,     5,     5,    52,    52,    45,    46,    51,    47,
      48,    51,     8,     8,     6,     9,    52,     6,     9,    29,
       6,    17,    46,     6,    48,     5,    47,     6,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    32,    32,    33,    33,    33,    34,
      35,    36,    37,    37,    37,    37,    38,    38,    38,    38,
      39,    39,    39,    39,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    41,    42,    42,    43,    43,    44,
      44,    44,    44,    45,    45,    46,    47,    47,    48,    49,
      49,    50,    50,    51,    52,    52,    52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     9,     6,     8,     9,
       8,     8,     1,     3,     3,     5,     3,     3,     1,     1,
       3,     3,     1,     1,     2,     5,     5,     2,     5,     5,
       2,     5,     2,     5,     4,     5,     5,     3,     1,     4,
       9,     9,    13,     3,     1,     2,     3,     1,     2,     3,
       1,     7,     7,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (root, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, root); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, NodeWrapper& root)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (root);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, NodeWrapper& root)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, root);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, NodeWrapper& root)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, root); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, NodeWrapper& root)
{
  YY_USE (yyvaluep);
  YY_USE (root);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (NodeWrapper& root)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* query: select_query  */
#line 103 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                    { root.node = (yyvsp[0].queryNode);}
#line 1488 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 3: /* query: delete_query  */
#line 104 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                     { root.node = (yyvsp[0].queryNode); }
#line 1494 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 4: /* query: insert_query  */
#line 105 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                     { root.node = (yyvsp[0].queryNode); }
#line 1500 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 5: /* query: update_query  */
#line 106 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                     { root.node = (yyvsp[0].queryNode); }
#line 1506 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 6: /* select_query: name L_BRACKET SELECTION_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE  */
#line 108 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                                     { QueryNode* node = new QueryNode("select", (yyvsp[-8].stringConstant)); node->setSelectionSet((yyvsp[-4].selectionSetNode)); node->setResultSet((yyvsp[-1].resultSetNode)); (yyval.queryNode) = node; }
#line 1512 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 7: /* select_query: name L_BRACKET SELECTION_FLAG R_BRACKET L_BRACE R_BRACE  */
#line 109 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                      { QueryNode* node = new QueryNode("select", (yyvsp[-5].stringConstant)); (yyval.queryNode) = node; }
#line 1518 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 8: /* select_query: name L_BRACKET SELECTION_FLAG COMMA selection_set R_BRACKET L_BRACE R_BRACE  */
#line 110 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                          { QueryNode* node = new QueryNode("select", (yyvsp[-7].stringConstant)); node->setSelectionSet((yyvsp[-3].selectionSetNode)); (yyval.queryNode) = node; }
#line 1524 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 9: /* delete_query: name L_BRACKET DELETE_FLAG COMMA selection_set R_BRACKET L_BRACE result_set R_BRACE  */
#line 112 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                                  { QueryNode* node = new QueryNode("delete", (yyvsp[-8].stringConstant)); node->setSelectionSet((yyvsp[-4].selectionSetNode)); node->setResultSet((yyvsp[-1].resultSetNode)); (yyval.queryNode) = node; }
#line 1530 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 10: /* insert_query: name L_BRACKET INSERTION_FLAG selection_set R_BRACKET L_BRACE result_set R_BRACE  */
#line 114 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                               { QueryNode* node = new QueryNode("insert", (yyvsp[-7].stringConstant)); node->setSelectionSet((yyvsp[-4].selectionSetNode)); node->setResultSet((yyvsp[-1].resultSetNode)); (yyval.queryNode) = node; }
#line 1536 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 11: /* update_query: name L_BRACKET UPDATE_FLAG selection_set R_BRACKET L_BRACE result_set R_BRACE  */
#line 116 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                            { QueryNode* node = new QueryNode("update", (yyvsp[-7].stringConstant)); node->setSelectionSet((yyvsp[-4].selectionSetNode)); node->setResultSet((yyvsp[-1].resultSetNode)); (yyval.queryNode) = node; }
#line 1542 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 12: /* selection_set: arguments  */
#line 118 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                         { SelectionSetNode* node = new SelectionSetNode(); node->set_args((yyvsp[0].argumentWrapperNode)); (yyval.selectionSetNode) = node; }
#line 1548 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 13: /* selection_set: L_BRACE objects R_BRACE  */
#line 119 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                        { SelectionSetNode* node = new SelectionSetNode(); node->set_objs((yyvsp[-1].objectWrapperNode)); (yyval.selectionSetNode) = node; }
#line 1554 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 14: /* selection_set: L_SQUARE_BRACKET sub_operations R_SQUARE_BRACKET  */
#line 120 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                 { SelectionSetNode* node = new SelectionSetNode(); node->set_subops((yyvsp[-1].subOperationWrapperNode)); (yyval.selectionSetNode) = node; }
#line 1560 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 15: /* selection_set: L_SQUARE_BRACKET sub_operations R_SQUARE_BRACKET COMMA arguments  */
#line 121 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                 { SelectionSetNode* node = new SelectionSetNode(); node->set_subops((yyvsp[-3].subOperationWrapperNode)); node->set_args((yyvsp[0].argumentWrapperNode)); (yyval.selectionSetNode) = node; }
#line 1566 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 16: /* result_set: result_set COMMA name  */
#line 123 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                  { (yyval.resultSetNode) = (yyvsp[-2].resultSetNode); (yyvsp[-2].resultSetNode)->add_attr((yyvsp[0].stringConstant)); }
#line 1572 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 17: /* result_set: result_set COMMA REF_TOKEN  */
#line 124 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                        { (yyval.resultSetNode) = (yyvsp[-2].resultSetNode); (yyvsp[-2].resultSetNode)->add_attr(new StringConstant((yyvsp[0].str))); }
#line 1578 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 18: /* result_set: REF_TOKEN  */
#line 125 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                       { (yyval.resultSetNode) = new ResultSetNode(); (yyval.resultSetNode)->add_attr(new StringConstant((yyvsp[0].str))); }
#line 1584 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 19: /* result_set: name  */
#line 126 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                  { (yyval.resultSetNode) = new ResultSetNode(); (yyval.resultSetNode)->add_attr((yyvsp[0].stringConstant)); }
#line 1590 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 20: /* arguments: arguments COMMA argument  */
#line 128 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                    { (yyval.argumentWrapperNode) = (yyvsp[-2].argumentWrapperNode); (yyvsp[-2].argumentWrapperNode)->add_attr((yyvsp[0].argumentNode)); }
#line 1596 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 21: /* arguments: arguments COMMA logic_op  */
#line 129 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                     { (yyval.argumentWrapperNode) = (yyvsp[-2].argumentWrapperNode); (yyvsp[-2].argumentWrapperNode)->add_attr((yyvsp[0].logicalOperationNode)); }
#line 1602 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 22: /* arguments: argument  */
#line 130 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                     { (yyval.argumentWrapperNode) = new ArgumentWrapperNode(); (yyval.argumentWrapperNode)->add_attr((yyvsp[0].argumentNode)); }
#line 1608 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 23: /* arguments: logic_op  */
#line 131 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                     { (yyval.argumentWrapperNode) = new ArgumentWrapperNode(); (yyval.argumentWrapperNode)->add_attr((yyvsp[0].logicalOperationNode)); }
#line 1614 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 24: /* argument: name value  */
#line 133 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                     { (yyval.argumentNode) = new ArgumentNode((yyvsp[-1].stringConstant), (yyvsp[0].constant)); }
#line 1620 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 25: /* argument: name filter VAL_TOKEN value R_BRACE  */
#line 134 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                               { ArgumentNode* node = new ArgumentNode((yyvsp[-4].stringConstant), (yyvsp[-1].constant)); node->set_filter((yyvsp[-3].filterNode)); (yyval.argumentNode) = node; }
#line 1626 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 26: /* argument: name filter VAL_TOKEN STRING_TOKEN R_BRACE  */
#line 135 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                      { ArgumentNode* node = new ArgumentNode((yyvsp[-4].stringConstant), new StringConstant((yyvsp[-1].str))); node->set_filter((yyvsp[-3].filterNode)); (yyval.argumentNode) = node; }
#line 1632 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 27: /* argument: REF_TOKEN value  */
#line 137 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                           { (yyval.argumentNode) = new ArgumentNode(new StringConstant((yyvsp[-1].str)), (yyvsp[0].constant)); }
#line 1638 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 28: /* argument: REF_TOKEN filter VAL_TOKEN value R_BRACE  */
#line 138 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                    { ArgumentNode* node = new ArgumentNode(new StringConstant((yyvsp[-4].str)), (yyvsp[-1].constant)); node->set_filter((yyvsp[-3].filterNode)); (yyval.argumentNode) = node; }
#line 1644 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 29: /* argument: REF_TOKEN filter VAL_TOKEN STRING_TOKEN R_BRACE  */
#line 139 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                           { ArgumentNode* node = new ArgumentNode(new StringConstant((yyvsp[-4].str)), new StringConstant((yyvsp[-1].str))); node->set_filter((yyvsp[-3].filterNode)); (yyval.argumentNode) = node; }
#line 1650 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 30: /* argument: NODE_NAME STRING_TOKEN  */
#line 141 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                  { (yyval.argumentNode) = new ArgumentNode(new StringConstant("node_name"), new StringConstant((yyvsp[0].str))); }
#line 1656 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 31: /* argument: NODE_NAME filter VAL_TOKEN STRING_TOKEN R_BRACE  */
#line 142 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                           { ArgumentNode* node = new ArgumentNode(new StringConstant("node_name"), new StringConstant((yyvsp[-1].str))); node->set_filter((yyvsp[-3].filterNode)); (yyval.argumentNode) = node; }
#line 1662 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 32: /* argument: NODE_CLASS STRING_TOKEN  */
#line 144 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                   { (yyval.argumentNode) = new ArgumentNode(new StringConstant("node_class"), new StringConstant((yyvsp[0].str))); }
#line 1668 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 33: /* argument: NODE_CLASS filter VAL_TOKEN STRING_TOKEN R_BRACE  */
#line 145 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                            { ArgumentNode* node = new ArgumentNode(new StringConstant("node_class"), new StringConstant((yyvsp[-1].str))); node->set_filter((yyvsp[-3].filterNode)); (yyval.argumentNode) = node; }
#line 1674 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 34: /* logic_op: LOGIC_OP L_BRACE arguments R_BRACE  */
#line 147 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                             { LogicalOperationNode* node = new LogicalOperationNode((yyvsp[-3].logical_op)); node->set_attr((yyvsp[-1].argumentWrapperNode)); (yyval.logicalOperationNode) = node; }
#line 1680 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 35: /* filter: FILTER_TOKEN L_BRACE OP_TOKEN COMP_OP COMMA  */
#line 149 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                    { (yyval.filterNode) = new FilterNode((yyvsp[-1].filter_op)); }
#line 1686 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 36: /* filter: FILTER_TOKEN L_BRACE OP_TOKEN LIKE_FILTER COMMA  */
#line 150 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                         { (yyval.filterNode) = new FilterNode((yyvsp[-1].filter_op)); }
#line 1692 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 37: /* objects: objects COMMA object  */
#line 152 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                              { (yyval.objectWrapperNode) = (yyvsp[-2].objectWrapperNode); (yyval.objectWrapperNode)->add_attr((yyvsp[0].objectNode)); }
#line 1698 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 38: /* objects: object  */
#line 153 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                 { (yyval.objectWrapperNode) = new ObjectWrapperNode(); (yyval.objectWrapperNode)->add_attr((yyvsp[0].objectNode)); }
#line 1704 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 39: /* object: L_BRACE NODE_NAME name R_BRACE  */
#line 155 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                      { (yyval.objectNode) = new ObjectNode((yyvsp[-1].stringConstant)); }
#line 1710 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 40: /* object: L_BRACE NODE_NAME name COMMA PROPS_TOKEN L_BRACE fields R_BRACE R_BRACE  */
#line 156 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                { (yyval.objectNode) = new ObjectNode((yyvsp[-6].stringConstant)); (yyval.objectNode)->add_props((yyvsp[-2].fieldsWrapperNode)); }
#line 1716 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 41: /* object: L_BRACE NODE_NAME name COMMA RELATIONS_TOKEN L_BRACE relations R_BRACE R_BRACE  */
#line 157 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                       { (yyval.objectNode) = new ObjectNode((yyvsp[-6].stringConstant)); (yyval.objectNode)->add_rels((yyvsp[-2].relationWrapperNode)); }
#line 1722 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 42: /* object: L_BRACE NODE_NAME name COMMA PROPS_TOKEN L_BRACE fields R_BRACE RELATIONS_TOKEN L_BRACE relations R_BRACE R_BRACE  */
#line 158 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                                                          { (yyval.objectNode) = new ObjectNode((yyvsp[-10].stringConstant)); (yyval.objectNode)->add_props((yyvsp[-6].fieldsWrapperNode)); (yyval.objectNode)->add_rels((yyvsp[-2].relationWrapperNode)); }
#line 1728 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 43: /* fields: fields COMMA field  */
#line 160 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                           { (yyval.fieldsWrapperNode) = (yyvsp[-2].fieldsWrapperNode); (yyvsp[-2].fieldsWrapperNode)->add_attr((yyvsp[0].fieldNode)); }
#line 1734 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 44: /* fields: field  */
#line 161 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
               { (yyval.fieldsWrapperNode) = new FieldsWrapperNode(); (yyval.fieldsWrapperNode)->add_attr((yyvsp[0].fieldNode)); }
#line 1740 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 45: /* field: name value  */
#line 163 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                  { (yyval.fieldNode) = new FieldNode((yyvsp[-1].stringConstant), (yyvsp[0].constant)); }
#line 1746 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 46: /* relations: relations COMMA relation  */
#line 165 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                    { (yyval.relationWrapperNode) = (yyvsp[-2].relationWrapperNode); (yyvsp[-2].relationWrapperNode)->add_attr((yyvsp[0].relationNode)); }
#line 1752 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 47: /* relations: relation  */
#line 166 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                     { (yyval.relationWrapperNode) = new RelationWrapperNode(); (yyval.relationWrapperNode)->add_attr((yyvsp[0].relationNode)); }
#line 1758 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 48: /* relation: name STRING_TOKEN  */
#line 168 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                            { (yyval.relationNode) = new RelationNode((yyvsp[-1].stringConstant), new StringConstant((yyvsp[0].str))); }
#line 1764 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 49: /* sub_operations: sub_operations COMMA sub_operation  */
#line 170 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                   { (yyval.subOperationWrapperNode) = (yyvsp[-2].subOperationWrapperNode); (yyvsp[-2].subOperationWrapperNode)->add_attr((yyvsp[0].subOperationNode)); }
#line 1770 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 50: /* sub_operations: sub_operation  */
#line 171 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                               { (yyval.subOperationWrapperNode) = new SubOperationWrapperNode(); (yyval.subOperationWrapperNode)->add_attr((yyvsp[0].subOperationNode)); }
#line 1776 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 51: /* sub_operation: L_SQUARE_BRACKET SUB_OPERATION_TOKEN COMMA name COMMA value R_SQUARE_BRACKET  */
#line 173 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                            { (yyval.subOperationNode) = new SubOperationNode((yyvsp[-5].sub_op), (yyvsp[-3].stringConstant), (yyvsp[-1].constant)); }
#line 1782 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 52: /* sub_operation: L_SQUARE_BRACKET SUB_OPERATION_TOKEN COMMA REF_TOKEN COMMA value R_SQUARE_BRACKET  */
#line 174 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                                                                                                  { (yyval.subOperationNode) = new SubOperationNode((yyvsp[-5].sub_op), new StringConstant((yyvsp[-3].str)), (yyvsp[-1].constant)); }
#line 1788 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 53: /* name: NAME_TOKEN  */
#line 176 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                 { (yyval.stringConstant) = new StringConstant((yyvsp[0].str)); }
#line 1794 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 54: /* value: INT_TOKEN  */
#line 178 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                 { (yyval.constant) = new IntConstant((yyvsp[0].int_val)); }
#line 1800 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 55: /* value: FLOAT_TOKEN  */
#line 179 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                    { (yyval.constant) = new FloatConstant((yyvsp[0].float_val)); }
#line 1806 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 56: /* value: STRING_TOKEN  */
#line 180 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                     { (yyval.constant) = new StringConstant((yyvsp[0].str)); }
#line 1812 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;

  case 57: /* value: BOOL_TOKEN  */
#line 181 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
                   { (yyval.constant) = new BoolConstant((yyvsp[0].bool_val)); }
#line 1818 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"
    break;


#line 1822 "/home/mikhail/CLionProjects/Low_Level_Programming/Lab2/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (root, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, root);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (root, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, root);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, root);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 183 "/home/mikhail/CLionProjects/Low_Level_Programming/./Lab2/parser.y"
