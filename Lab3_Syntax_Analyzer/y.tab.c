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
#line 1 "syntx.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno; // Declare the external variable for line number

// Function to handle syntax errors
void yyerror(const char* message) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, message);
}

// Define other necessary global variables and data structures here

#line 86 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,                      /* ID  */
    INT = 259,                     /* INT  */
    FLOAT = 260,                   /* FLOAT  */
    CHAR = 261,                    /* CHAR  */
    STRING = 262,                  /* STRING  */
    MAIN = 263,                    /* MAIN  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    WHILE = 266,                   /* WHILE  */
    FOR = 267,                     /* FOR  */
    RETURN = 268,                  /* RETURN  */
    VOID = 269,                    /* VOID  */
    PLUS = 270,                    /* PLUS  */
    MINUS = 271,                   /* MINUS  */
    MULT = 272,                    /* MULT  */
    DIV = 273,                     /* DIV  */
    MOD = 274,                     /* MOD  */
    EQ = 275,                      /* EQ  */
    NEQ = 276,                     /* NEQ  */
    LT = 277,                      /* LT  */
    GT = 278,                      /* GT  */
    LEQ = 279,                     /* LEQ  */
    GEQ = 280,                     /* GEQ  */
    AND = 281,                     /* AND  */
    OR = 282,                      /* OR  */
    NOT = 283,                     /* NOT  */
    SEMICOLON = 284,               /* SEMICOLON  */
    COMMA = 285,                   /* COMMA  */
    COLON = 286,                   /* COLON  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    LBRACE = 289,                  /* LBRACE  */
    RBRACE = 290,                  /* RBRACE  */
    LBRACKET = 291,                /* LBRACKET  */
    RBRACKET = 292,                /* RBRACKET  */
    ASSIGN = 293,                  /* ASSIGN  */
    QUESTION = 294,                /* QUESTION  */
    LSHIFT = 295,                  /* LSHIFT  */
    RSHIFT = 296,                  /* RSHIFT  */
    SIZEOF = 297,                  /* SIZEOF  */
    DOT = 298,                     /* DOT  */
    ARROW = 299,                   /* ARROW  */
    INC = 300,                     /* INC  */
    DEC = 301,                     /* DEC  */
    ERROR = 302                    /* ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INT 259
#define FLOAT 260
#define CHAR 261
#define STRING 262
#define MAIN 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define FOR 267
#define RETURN 268
#define VOID 269
#define PLUS 270
#define MINUS 271
#define MULT 272
#define DIV 273
#define MOD 274
#define EQ 275
#define NEQ 276
#define LT 277
#define GT 278
#define LEQ 279
#define GEQ 280
#define AND 281
#define OR 282
#define NOT 283
#define SEMICOLON 284
#define COMMA 285
#define COLON 286
#define LPAREN 287
#define RPAREN 288
#define LBRACE 289
#define RBRACE 290
#define LBRACKET 291
#define RBRACKET 292
#define ASSIGN 293
#define QUESTION 294
#define LSHIFT 295
#define RSHIFT 296
#define SIZEOF 297
#define DOT 298
#define ARROW 299
#define INC 300
#define DEC 301
#define ERROR 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_MAIN = 8,                       /* MAIN  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MULT = 17,                      /* MULT  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_MOD = 19,                       /* MOD  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_LEQ = 24,                       /* LEQ  */
  YYSYMBOL_GEQ = 25,                       /* GEQ  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_COLON = 31,                     /* COLON  */
  YYSYMBOL_LPAREN = 32,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 33,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 34,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 35,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 36,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 37,                  /* RBRACKET  */
  YYSYMBOL_ASSIGN = 38,                    /* ASSIGN  */
  YYSYMBOL_QUESTION = 39,                  /* QUESTION  */
  YYSYMBOL_LSHIFT = 40,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 41,                    /* RSHIFT  */
  YYSYMBOL_SIZEOF = 42,                    /* SIZEOF  */
  YYSYMBOL_DOT = 43,                       /* DOT  */
  YYSYMBOL_ARROW = 44,                     /* ARROW  */
  YYSYMBOL_INC = 45,                       /* INC  */
  YYSYMBOL_DEC = 46,                       /* DEC  */
  YYSYMBOL_ERROR = 47,                     /* ERROR  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* '|'  */
  YYSYMBOL_51_ = 51,                       /* '^'  */
  YYSYMBOL_52_ = 52,                       /* '&'  */
  YYSYMBOL_53_ = 53,                       /* '*'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_external_declaration = 56,      /* external_declaration  */
  YYSYMBOL_function_definition = 57,       /* function_definition  */
  YYSYMBOL_parameter_list_opt = 58,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 59,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 60,     /* parameter_declaration  */
  YYSYMBOL_type_specifier = 61,            /* type_specifier  */
  YYSYMBOL_declaration = 62,               /* declaration  */
  YYSYMBOL_init_declarator_list = 63,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 64,           /* init_declarator  */
  YYSYMBOL_declarator = 65,                /* declarator  */
  YYSYMBOL_direct_declarator = 66,         /* direct_declarator  */
  YYSYMBOL_constant_expression_opt = 67,   /* constant_expression_opt  */
  YYSYMBOL_constant_expression = 68,       /* constant_expression  */
  YYSYMBOL_initializer = 69,               /* initializer  */
  YYSYMBOL_compound_statement = 70,        /* compound_statement  */
  YYSYMBOL_declaration_list_opt = 71,      /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 72,          /* declaration_list  */
  YYSYMBOL_statement_list_opt = 73,        /* statement_list_opt  */
  YYSYMBOL_statement_list = 74,            /* statement_list  */
  YYSYMBOL_statement = 75,                 /* statement  */
  YYSYMBOL_expression_statement = 76,      /* expression_statement  */
  YYSYMBOL_expression_opt = 77,            /* expression_opt  */
  YYSYMBOL_selection_statement = 78,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 79,       /* iteration_statement  */
  YYSYMBOL_expression_statement_opt = 80,  /* expression_statement_opt  */
  YYSYMBOL_jump_statement = 81,            /* jump_statement  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_assignment_expression = 83,     /* assignment_expression  */
  YYSYMBOL_conditional_expression = 84,    /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 85,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 86,    /* logical_and_expression  */
  YYSYMBOL_inclusive_or_expression = 87,   /* inclusive_or_expression  */
  YYSYMBOL_exclusive_or_expression = 88,   /* exclusive_or_expression  */
  YYSYMBOL_and_expression = 89,            /* and_expression  */
  YYSYMBOL_equality_expression = 90,       /* equality_expression  */
  YYSYMBOL_relational_expression = 91,     /* relational_expression  */
  YYSYMBOL_shift_expression = 92,          /* shift_expression  */
  YYSYMBOL_additive_expression = 93,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 94, /* multiplicative_expression  */
  YYSYMBOL_cast_expression = 95,           /* cast_expression  */
  YYSYMBOL_unary_expression = 96,          /* unary_expression  */
  YYSYMBOL_postfix_expression = 97,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 98,        /* primary_expression  */
  YYSYMBOL_argument_expression_list_opt = 99, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 100  /* argument_expression_list  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
       2,     2,     2,     2,     2,     2,     2,     2,    52,     2,
      48,    49,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    50,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    45,    45,    46,    49,    50,    51,    54,    55,    56,
      59,    60,    63,    64,    67,    68,    71,    72,    73,    74,
      75,    78,    79,    82,    83,    86,    87,    88,    91,    94,
      95,    96,    97,    98,    99,   102,   103,   104,   107,   108,
     111,   112,   115,   118,   119,   122,   123,   124,   127,   128,
     131,   132,   135,   136,   137,   138,   139,   140,   143,   146,
     147,   148,   151,   152,   153,   154,   155,   156,   159,   160,
     161,   162,   165,   166,   169,   170,   173,   174,   177,   178,
     179,   182,   183,   184,   185,   188,   189,   190,   193,   194,
     195,   198,   199,   200,   203,   204,   205,   208,   209,   210,
     213,   214,   215,   216,   219,   220,   221,   222,   223,   224,
     227,   228,   229,   230,   233,   234,   235,   236,   239,   240,
     241,   242,   243,   246,   247,   250,   251,   252,   253,   254,
     255,   256,   257,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   273,   274,   275,   276,   277,   278,
     279,   282,   283,   286,   287,   288
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT", "FLOAT",
  "CHAR", "STRING", "MAIN", "IF", "ELSE", "WHILE", "FOR", "RETURN", "VOID",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LEQ",
  "GEQ", "AND", "OR", "NOT", "SEMICOLON", "COMMA", "COLON", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "ASSIGN",
  "QUESTION", "LSHIFT", "RSHIFT", "SIZEOF", "DOT", "ARROW", "INC", "DEC",
  "ERROR", "'('", "')'", "'|'", "'^'", "'&'", "'*'", "$accept", "program",
  "external_declaration", "function_definition", "parameter_list_opt",
  "parameter_list", "parameter_declaration", "type_specifier",
  "declaration", "init_declarator_list", "init_declarator", "declarator",
  "direct_declarator", "constant_expression_opt", "constant_expression",
  "initializer", "compound_statement", "declaration_list_opt",
  "declaration_list", "statement_list_opt", "statement_list", "statement",
  "expression_statement", "expression_opt", "selection_statement",
  "iteration_statement", "expression_statement_opt", "jump_statement",
  "expression", "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "postfix_expression", "primary_expression",
  "argument_expression_list_opt", "argument_expression_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-191)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-152)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,     4,  -191,  -191,  -191,  -191,   539,  -191,  -191,    27,
    -191,  -191,  -191,  -191,     8,    96,    74,   -14,  -191,   -16,
       0,  -191,    17,    34,  -191,    13,  -191,    74,   526,   152,
      19,   107,  -191,  -191,    36,    68,  -191,    28,  -191,  -191,
     169,  -191,  -191,  -191,  -191,  -191,   556,   586,   586,   616,
     586,   646,   646,  -191,  -191,  -191,    66,    78,    77,    73,
      81,    67,   164,   105,   135,   112,  -191,  1075,   252,  -191,
     115,   119,   103,  -191,   124,  -191,    83,   106,  -191,   221,
     168,    10,   237,  -191,  -191,   456,   616,   134,   160,   474,
    -191,   111,  -191,  -191,   404,   143,  -191,  -191,   474,  -191,
    -191,  -191,   676,   706,   736,   766,   796,   826,   856,   646,
     886,   646,   646,   646,   916,   646,   946,   646,   976,   646,
     646,   166,   646,   456,   616,   203,   208,  -191,  -191,  -191,
    -191,  -191,  -191,   216,   184,   191,   197,   463,  -191,   196,
     274,  -191,  -191,   206,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,     9,  -191,   211,   217,   209,  -191,  -191,  -191,
    1358,    78,   269,   226,  1338,    77,  1316,    73,  1290,    81,
    1263,    67,  1205,   164,   164,   305,   105,   105,   105,   105,
    1237,   135,   135,  1242,   112,   112,   474,  -191,  -191,  -191,
     646,  -191,   225,   227,  -191,  -191,  -191,  1006,   616,   496,
    1120,   236,  -191,  -191,  -191,  -191,   646,  -191,   646,  1036,
    -191,  -191,  -191,  1029,   233,   234,  1138,   423,  -191,  -191,
    -191,  -191,  1376,  -191,   327,   359,   327,  1102,  -191,    16,
     258,  1168,   259,  -191,   327,   327,   327,   327,   391,  -191,
    -191,  -191,  -191,  1168,  -191
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    16,    17,    18,    19,     0,     2,     4,     0,
       5,     6,     1,     3,     0,     0,     0,     0,    23,    25,
      28,    22,     0,     0,    29,     0,    21,     0,     0,     0,
       0,     0,     8,    20,     0,    11,    12,     0,    30,    24,
     124,   144,   145,   146,   147,   148,     0,     0,     0,     0,
       0,     0,     0,    26,    40,    78,    81,    85,    88,    91,
      94,    97,   100,   104,   110,   114,   118,     0,   125,   133,
      20,     0,     0,    38,     0,    36,    47,     0,    45,     0,
       0,     0,     0,    15,    14,     0,     0,     0,     0,   132,
     126,   150,   127,   128,   124,     0,    76,   131,   124,   129,
     123,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,    34,
      32,    33,    31,   124,     0,     0,     0,     0,    53,     0,
       0,    50,    52,     0,    54,    55,    56,    60,    46,     9,
       7,    13,   124,   153,     0,   152,     0,   142,   143,   149,
     124,    86,   124,     0,   124,    89,   124,    92,   124,    95,
     124,    98,   103,   101,   102,   109,   105,   106,   107,   108,
     113,   111,   112,   117,   115,   116,   122,   119,   120,   121,
       0,    79,     0,     0,   136,   137,    57,     0,     0,     0,
     124,     0,    42,    51,    58,   141,     0,   140,     0,     0,
      80,   135,   134,   124,     0,     0,   124,     0,    75,    74,
     154,    83,   124,    82,     0,     0,     0,   124,    73,     0,
      66,    67,    62,    68,     0,     0,     0,     0,     0,    71,
      70,    69,    64,    65,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,   265,  -191,   243,  -191,   194,    12,   -30,  -191,
     255,   275,  -191,  -191,  -191,  -191,    -3,  -191,  -191,  -191,
    -191,  -135,  -190,   155,  -191,  -191,  -191,  -191,    -7,   -28,
     -41,  -191,   192,   189,   199,   193,   204,   100,    82,   104,
     123,   -38,   -44,  -191,  -191,   187,  -191
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,    34,    35,    36,    37,    10,    17,
      18,    19,    20,    74,    75,    53,   138,    79,    80,   139,
     140,   141,   142,   143,   144,   145,   229,   146,   147,    96,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,   154,   155
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    78,    90,    92,    93,   203,    97,   100,   100,   217,
    -150,   149,     9,    99,   101,    26,    27,   235,     9,    32,
      72,     1,    28,    73,     2,     3,     4,   228,    14,    83,
      15,    84,    29,    11,     5,    33,    30,    21,     2,     3,
       4,    85,    95,    77,    31,    86,    38,  -150,     5,   236,
     148,    31,    87,    88,  -150,  -150,   -35,   153,   100,    16,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,    24,   150,   156,
     187,   188,   189,   -10,   -20,    81,   -20,   108,   109,   230,
     232,   233,    77,   102,   191,   153,   163,    22,    82,   239,
     240,   241,   242,   244,   104,   103,    16,    14,    76,    24,
     -43,     2,     3,     4,   -43,   -20,   -43,   193,   -43,   -43,
     -43,     5,   -43,   -43,   106,   -29,   -29,   105,   -29,   118,
     119,   120,   -29,   107,   -29,   -43,   -43,   157,    16,   -43,
     131,   -43,   -43,    85,    23,   114,   115,    86,   129,   -43,
     116,   117,   130,    70,    87,    88,     2,     3,     4,   -43,
     -43,   132,   210,   158,   100,   100,     5,   221,   223,    33,
    -150,   -44,     2,     3,     4,   -44,   159,   -44,   220,   -44,
     -44,   -44,     5,   -44,   -44,   -10,   110,   111,   112,   113,
     214,   215,   176,   177,   178,   179,   -44,   -44,   -27,   -27,
     -44,    85,   -44,   -44,   190,    86,   194,  -150,   173,   174,
     -44,   195,    87,    88,  -150,  -150,   197,  -150,   181,   182,
     -44,   -44,   133,   198,    41,    42,    43,    44,    45,   199,
     134,   202,   135,   136,   137,   204,    46,    47,    33,   184,
     185,     2,     3,     4,   205,   196,   207,   206,    85,    48,
     -59,     5,    86,    49,  -150,    31,   -48,   209,   211,    87,
      88,  -150,  -150,    50,   212,   219,   225,   226,   237,   238,
    -150,    13,    71,    51,    52,   133,   151,    41,    42,    43,
      44,    45,    39,   134,   123,   135,   136,   137,   124,    46,
      47,    25,   201,   165,   161,   125,   126,   127,   128,   169,
     208,    85,    48,   -59,   167,    86,    49,  -150,    31,   -49,
     192,   171,    87,    88,  -150,  -150,    50,     0,     0,     0,
    -124,  -124,  -124,  -124,  -124,     0,    51,    52,   133,     0,
      41,    42,    43,    44,    45,     0,   134,    85,   135,   136,
     137,    86,    46,    47,     0,  -124,  -124,     0,    87,    88,
    -150,  -150,     0,     0,     0,    48,   -59,     0,     0,    49,
     231,    31,    41,    42,    43,    44,    45,     0,   134,    50,
     135,   136,   137,     0,    46,    47,     0,     0,     0,    51,
      52,     0,     0,     0,     0,     0,     0,    48,   -59,     0,
       0,    49,   243,    31,    41,    42,    43,    44,    45,     0,
     134,    50,   135,   136,   137,  -150,    46,    47,     0,     0,
       0,    51,    52,     0,     0,     0,     0,     0,     0,    48,
     -59,     0,     0,    49,   227,    31,    41,    42,    43,    44,
      45,     0,     0,    50,     0,     0,    85,   -77,    46,    47,
      86,   -77,  -150,    51,    52,     0,     0,    87,    88,  -150,
    -150,    48,   -59,     0,     0,    49,   -72,   152,     0,    41,
      42,    43,    44,    45,   200,    50,    41,    42,    43,    44,
      45,    46,    47,     0,     0,    51,    52,     0,    46,    47,
       0,     0,     0,     0,    48,     0,     0,     0,    49,  -151,
       0,    48,   -59,     0,     0,    49,     0,   216,    50,    41,
      42,    43,    44,    45,     0,    50,    85,     0,    51,    52,
      86,    46,    47,     0,     0,    51,    52,    87,    88,  -150,
    -150,     0,     0,     0,    48,   -59,     0,    40,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,    12,
       1,    46,    47,     2,     3,     4,     0,     0,    51,    52,
       0,     0,     0,     5,    48,     0,     0,    89,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,    91,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,    94,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,    98,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   160,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   162,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   164,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   166,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   168,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   170,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   172,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   175,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   180,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   183,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   186,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,     0,     0,     0,    48,     0,     0,   213,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
    -150,     0,     0,     0,    48,     0,     0,   222,    49,    41,
      42,    43,    44,    45,     0,     0,     0,     0,    50,     0,
       0,    46,    47,     0,     0,     0,     0,     0,    51,    52,
       0,    85,   224,     0,    48,    86,     0,  -150,    49,     0,
       0,     0,    87,    88,  -150,  -150,   121,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -150,  -123,  -123,  -123,     0,  -123,     0,
       0,     0,  -123,   122,  -123,  -123,  -123,     0,     0,     0,
       0,  -150,     0,     0,     0,  -123,  -123,  -123,     0,     0,
       0,   -61,     0,     0,    85,   234,     0,     0,    86,  -150,
    -150,     0,     0,     0,     0,    87,    88,  -150,  -150,   218,
       0,     0,    85,     0,     0,     0,    86,     0,  -150,     0,
       0,     0,     0,    87,    88,  -150,  -150,   -61,     0,     0,
      85,     0,     0,     0,    86,     0,  -150,     0,     0,     0,
       0,    87,    88,  -150,  -150,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,     0,   196,     0,     0,
      85,     0,     0,     0,    86,     0,  -150,  -124,  -124,  -124,
       0,    87,    88,  -150,  -150,     0,     0,     0,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,     0,     0,  -124,  -124,  -124,
    -124,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,    86,     0,     0,     0,  -124,  -124,     0,    87,    88,
    -150,  -150,  -124,  -124,  -124,  -124,  -124,     0,     0,  -124,
    -124,  -124,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,    86,    85,     0,     0,     0,    86,     0,
      87,    88,  -150,  -150,     0,    87,    88,  -150,  -150,   -99,
     -99,     0,   -99,   -99,   -99,    85,   -99,     0,     0,    86,
     -99,     0,   -99,     0,     0,     0,    87,    88,  -150,  -150,
       0,     0,     0,   -99,   -99,   -99,   -96,   -96,     0,   -96,
     -96,   -96,    85,   -96,     0,     0,    86,   -96,     0,   -96,
       0,     0,     0,    87,    88,  -150,  -150,     0,     0,     0,
     -96,   -96,   -93,   -93,     0,   -93,   -93,   -93,    85,   -93,
       0,     0,    86,   -93,     0,   -93,     0,     0,     0,    87,
      88,  -150,  -150,     0,   -90,   -90,   -93,   -90,   -90,   -90,
      85,   -90,     0,     0,    86,   -90,     0,   -90,     0,     0,
       0,    87,    88,  -150,  -150,   -87,     0,   -87,   -87,   -87,
      85,   -87,     0,     0,    86,   -87,     0,   -87,     0,     0,
       0,    87,    88,  -150,  -150,   -84,   -84,   -84,    85,   -84,
       0,     0,    86,   -84,     0,     0,     0,     0,     0,    87,
      88,  -150,  -150
};

static const yytype_int16 yycheck[] =
{
      28,    31,    46,    47,    48,   140,    50,    51,    52,   199,
       1,     1,     0,    51,    52,    29,    30,     1,     6,    22,
       1,     1,    38,     4,     4,     5,     6,   217,     1,     1,
       3,     3,    32,    29,    14,     1,    36,    29,     4,     5,
       6,    32,    49,    31,    34,    36,    33,    38,    14,    33,
      80,    34,    43,    44,    45,    46,    37,    85,   102,    32,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     3,    81,    86,
     118,   119,   120,    49,     1,    49,     3,    20,    21,   224,
     225,   226,    80,    27,   122,   123,   103,     1,    30,   234,
     235,   236,   237,   238,    26,    39,    32,     1,     1,     3,
       3,     4,     5,     6,     7,    32,     9,   124,    11,    12,
      13,    14,    15,    16,    51,    29,    30,    50,    32,    17,
      18,    19,    36,    52,    38,    28,    29,     3,    32,    32,
      37,    34,    35,    32,    48,    40,    41,    36,    33,    42,
      15,    16,    33,     1,    43,    44,     4,     5,     6,    52,
      53,    37,   190,     3,   208,   209,    14,   208,   209,     1,
       1,     3,     4,     5,     6,     7,    33,     9,   206,    11,
      12,    13,    14,    15,    16,    33,    22,    23,    24,    25,
     197,   198,   110,   111,   112,   113,    28,    29,    29,    30,
      32,    32,    34,    35,    38,    36,     3,    38,   108,   109,
      42,     3,    43,    44,    45,    46,    32,     1,   114,   115,
      52,    53,     1,    32,     3,     4,     5,     6,     7,    32,
       9,    35,    11,    12,    13,    29,    15,    16,     1,   116,
     117,     4,     5,     6,    33,    29,    37,    30,    32,    28,
      29,    14,    36,    32,    38,    34,    35,    31,    33,    43,
      44,    45,    46,    42,    37,    29,    33,    33,    10,    10,
       1,     6,    29,    52,    53,     1,    82,     3,     4,     5,
       6,     7,    27,     9,    32,    11,    12,    13,    36,    15,
      16,    16,   137,   104,   102,    43,    44,    45,    46,   106,
      31,    32,    28,    29,   105,    36,    32,    38,    34,    35,
     123,   107,    43,    44,    45,    46,    42,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    -1,    52,    53,     1,    -1,
       3,     4,     5,     6,     7,    -1,     9,    32,    11,    12,
      13,    36,    15,    16,    -1,    40,    41,    -1,    43,    44,
      45,    46,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
       1,    34,     3,     4,     5,     6,     7,    -1,     9,    42,
      11,    12,    13,    -1,    15,    16,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,     1,    34,     3,     4,     5,     6,     7,    -1,
       9,    42,    11,    12,    13,     1,    15,    16,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,     1,    34,     3,     4,     5,     6,
       7,    -1,    -1,    42,    -1,    -1,    32,    33,    15,    16,
      36,    37,    38,    52,    53,    -1,    -1,    43,    44,    45,
      46,    28,    29,    -1,    -1,    32,    33,     1,    -1,     3,
       4,     5,     6,     7,     1,    42,     3,     4,     5,     6,
       7,    15,    16,    -1,    -1,    52,    53,    -1,    15,    16,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,    33,
      -1,    28,    29,    -1,    -1,    32,    -1,     1,    42,     3,
       4,     5,     6,     7,    -1,    42,    32,    -1,    52,    53,
      36,    15,    16,    -1,    -1,    52,    53,    43,    44,    45,
      46,    -1,    -1,    -1,    28,    29,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,     0,
       1,    15,    16,     4,     5,     6,    -1,    -1,    52,    53,
      -1,    -1,    -1,    14,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
       1,    -1,    -1,    -1,    28,    -1,    -1,     1,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    32,    33,    -1,    28,    36,    -1,    38,    32,    -1,
      -1,    -1,    43,    44,    45,    46,     1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     1,    29,    30,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    -1,    -1,    36,     1,
      38,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    29,
      -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    38,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    29,    -1,    -1,
      32,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      32,    -1,    -1,    -1,    36,    -1,    38,    39,    40,    41,
      -1,    43,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      15,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    40,    41,    -1,    43,    44,
      45,    46,    15,    16,    17,    18,    19,    -1,    -1,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    36,    32,    -1,    -1,    -1,    36,    -1,
      43,    44,    45,    46,    -1,    43,    44,    45,    46,    26,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    36,
      37,    -1,    39,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    51,    52,    26,    27,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    36,    37,    -1,    39,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    51,    26,    27,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    -1,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    26,    27,    50,    29,    30,    31,
      32,    33,    -1,    -1,    36,    37,    -1,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    27,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    36,    37,    -1,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     4,     5,     6,    14,    55,    56,    57,    61,
      62,    29,     0,    56,     1,     3,    32,    63,    64,    65,
      66,    29,     1,    48,     3,    65,    29,    30,    38,    32,
      36,    34,    70,     1,    58,    59,    60,    61,    33,    64,
       1,     3,     4,     5,     6,     7,    15,    16,    28,    32,
      42,    52,    53,    69,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       1,    58,     1,     4,    67,    68,     1,    61,    62,    71,
      72,    49,    30,     1,     3,    32,    36,    43,    44,     1,
      96,     1,    96,    96,     1,    82,    83,    96,     1,    95,
      96,    95,    27,    39,    26,    50,    51,    52,    20,    21,
      22,    23,    24,    25,    40,    41,    15,    16,    17,    18,
      19,     1,    38,    32,    36,    43,    44,    45,    46,    33,
      33,    37,    37,     1,     9,    11,    12,    13,    70,    73,
      74,    75,    76,    77,    78,    79,    81,    82,    62,     1,
      70,    60,     1,    83,    99,   100,    82,     3,     3,    33,
       1,    86,     1,    82,     1,    87,     1,    88,     1,    89,
       1,    90,     1,    91,    91,     1,    92,    92,    92,    92,
       1,    93,    93,     1,    94,    94,     1,    95,    95,    95,
      38,    83,    99,    82,     3,     3,    29,    32,    32,    32,
       1,    77,    35,    75,    29,    33,    30,    37,    31,    31,
      83,    33,    37,     1,    82,    82,     1,    76,    29,    29,
      83,    84,     1,    84,    33,    33,    33,     1,    76,    80,
      75,     1,    75,    75,    33,     1,    33,    10,    10,    75,
      75,    75,    75,     1,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    62,    62,    63,    63,    64,    64,    64,    65,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    76,    77,
      77,    77,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    84,    84,    84,    84,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    89,    89,    89,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      94,    94,    94,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     6,     4,     6,
       0,     1,     1,     3,     2,     2,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     1,     3,     3,     1,     1,
       3,     4,     4,     4,     4,     0,     1,     1,     1,     1,
       1,     1,     4,     0,     1,     1,     2,     1,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     2,     0,
       1,     1,     5,     7,     7,     7,     5,     5,     5,     6,
       6,     6,     0,     1,     3,     3,     1,     1,     1,     3,
       4,     1,     5,     5,     5,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     4,     4,     3,     3,     2,     2,
       4,     4,     3,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     1,     1,     3,     1
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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
yyparse (void)
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
  case 6: /* external_declaration: error SEMICOLON  */
#line 51 "syntx.y"
                                     { yyerror("Invalid external_declaration"); }
#line 1727 "y.tab.c"
    break;

  case 8: /* function_definition: type_specifier ID error compound_statement  */
#line 55 "syntx.y"
                                                                { yyerror("Invalid function_definition"); }
#line 1733 "y.tab.c"
    break;

  case 9: /* function_definition: type_specifier ID '(' parameter_list_opt ')' error  */
#line 56 "syntx.y"
                                                                        { yyerror("Invalid function_definition"); }
#line 1739 "y.tab.c"
    break;

  case 15: /* parameter_declaration: type_specifier error  */
#line 68 "syntx.y"
                                          { yyerror("Invalid parameter_declaration"); }
#line 1745 "y.tab.c"
    break;

  case 20: /* type_specifier: error  */
#line 75 "syntx.y"
                     { yyerror("Invalid type_specifier"); }
#line 1751 "y.tab.c"
    break;

  case 22: /* declaration: type_specifier error SEMICOLON  */
#line 79 "syntx.y"
                                            { yyerror("Invalid declaration"); }
#line 1757 "y.tab.c"
    break;

  case 27: /* init_declarator: declarator ASSIGN error  */
#line 88 "syntx.y"
                                        { yyerror("Invalid init_declarator"); }
#line 1763 "y.tab.c"
    break;

  case 33: /* direct_declarator: direct_declarator LBRACKET error RBRACKET  */
#line 98 "syntx.y"
                                                            { yyerror("Invalid direct_declarator"); }
#line 1769 "y.tab.c"
    break;

  case 34: /* direct_declarator: direct_declarator LPAREN error RPAREN  */
#line 99 "syntx.y"
                                                        { yyerror("Invalid direct_declarator"); }
#line 1775 "y.tab.c"
    break;

  case 37: /* constant_expression_opt: error  */
#line 104 "syntx.y"
                              { yyerror("Invalid constant_expression"); }
#line 1781 "y.tab.c"
    break;

  case 39: /* constant_expression: error  */
#line 108 "syntx.y"
                          { yyerror("Invalid constant_expression"); }
#line 1787 "y.tab.c"
    break;

  case 41: /* initializer: error  */
#line 112 "syntx.y"
                   { yyerror("Invalid initializer"); }
#line 1793 "y.tab.c"
    break;

  case 47: /* declaration_list: error  */
#line 124 "syntx.y"
                       { yyerror("Invalid declaration_list"); }
#line 1799 "y.tab.c"
    break;

  case 57: /* statement: error SEMICOLON  */
#line 140 "syntx.y"
                           { yyerror("Invalid statement"); }
#line 1805 "y.tab.c"
    break;

  case 61: /* expression_opt: error  */
#line 148 "syntx.y"
                      { yyerror("Invalid expression"); }
#line 1811 "y.tab.c"
    break;

  case 64: /* selection_statement: IF LPAREN error RPAREN statement ELSE statement  */
#line 153 "syntx.y"
                                                                    { yyerror("Invalid selection_statement"); }
#line 1817 "y.tab.c"
    break;

  case 65: /* selection_statement: IF LPAREN expression RPAREN statement ELSE error  */
#line 154 "syntx.y"
                                                                     { yyerror("Invalid selection_statement"); }
#line 1823 "y.tab.c"
    break;

  case 66: /* selection_statement: IF LPAREN error RPAREN statement  */
#line 155 "syntx.y"
                                                     { yyerror("Invalid selection_statement"); }
#line 1829 "y.tab.c"
    break;

  case 67: /* selection_statement: IF LPAREN expression RPAREN error  */
#line 156 "syntx.y"
                                                      { yyerror("Invalid selection_statement"); }
#line 1835 "y.tab.c"
    break;

  case 70: /* iteration_statement: FOR LPAREN expression_statement expression_statement_opt error statement  */
#line 161 "syntx.y"
                                                                                             { yyerror("Invalid iteration_statement"); }
#line 1841 "y.tab.c"
    break;

  case 71: /* iteration_statement: FOR LPAREN expression_statement error RPAREN statement  */
#line 162 "syntx.y"
                                                                           { yyerror("Invalid iteration_statement"); }
#line 1847 "y.tab.c"
    break;

  case 75: /* jump_statement: RETURN error SEMICOLON  */
#line 170 "syntx.y"
                                       { yyerror("Invalid jump_statement"); }
#line 1853 "y.tab.c"
    break;

  case 77: /* expression: error  */
#line 174 "syntx.y"
                  { yyerror("Invalid expression"); }
#line 1859 "y.tab.c"
    break;

  case 80: /* assignment_expression: unary_expression error ASSIGN assignment_expression  */
#line 179 "syntx.y"
                                                                         { yyerror("Invalid assignment_expression"); }
#line 1865 "y.tab.c"
    break;

  case 83: /* conditional_expression: logical_or_expression QUESTION error COLON conditional_expression  */
#line 184 "syntx.y"
                                                                                       { yyerror("Invalid conditional_expression"); }
#line 1871 "y.tab.c"
    break;

  case 84: /* conditional_expression: logical_or_expression QUESTION expression COLON error  */
#line 185 "syntx.y"
                                                                           { yyerror("Invalid conditional_expression"); }
#line 1877 "y.tab.c"
    break;

  case 87: /* logical_or_expression: logical_or_expression OR error  */
#line 190 "syntx.y"
                                                    { yyerror("Invalid logical_or_expression"); }
#line 1883 "y.tab.c"
    break;

  case 90: /* logical_and_expression: logical_and_expression AND error  */
#line 195 "syntx.y"
                                                      { yyerror("Invalid logical_and_expression"); }
#line 1889 "y.tab.c"
    break;

  case 93: /* inclusive_or_expression: inclusive_or_expression '|' error  */
#line 200 "syntx.y"
                                                       { yyerror("Invalid inclusive_or_expression"); }
#line 1895 "y.tab.c"
    break;

  case 96: /* exclusive_or_expression: exclusive_or_expression '^' error  */
#line 205 "syntx.y"
                                                       { yyerror("Invalid exclusive_or_expression"); }
#line 1901 "y.tab.c"
    break;

  case 99: /* and_expression: and_expression '&' error  */
#line 210 "syntx.y"
                                        { yyerror("Invalid and_expression"); }
#line 1907 "y.tab.c"
    break;

  case 103: /* equality_expression: equality_expression EQ error  */
#line 216 "syntx.y"
                                                 { yyerror("Invalid equality_expression"); }
#line 1913 "y.tab.c"
    break;

  case 109: /* relational_expression: relational_expression LT error  */
#line 224 "syntx.y"
                                                    { yyerror("Invalid relational_expression"); }
#line 1919 "y.tab.c"
    break;

  case 113: /* shift_expression: shift_expression LSHIFT error  */
#line 230 "syntx.y"
                                               { yyerror("Invalid shift_expression"); }
#line 1925 "y.tab.c"
    break;

  case 117: /* additive_expression: additive_expression PLUS error  */
#line 236 "syntx.y"
                                                  { yyerror("Invalid additive_expression"); }
#line 1931 "y.tab.c"
    break;

  case 122: /* multiplicative_expression: multiplicative_expression MULT error  */
#line 243 "syntx.y"
                                                              { yyerror("Invalid multiplicative_expression"); }
#line 1937 "y.tab.c"
    break;

  case 124: /* cast_expression: error  */
#line 247 "syntx.y"
                      { yyerror("Invalid cast_expression"); }
#line 1943 "y.tab.c"
    break;

  case 132: /* unary_expression: PLUS error  */
#line 257 "syntx.y"
                            { yyerror("Invalid unary_expression"); }
#line 1949 "y.tab.c"
    break;

  case 140: /* postfix_expression: error LBRACKET expression RBRACKET  */
#line 267 "syntx.y"
                                                      { yyerror("Invalid postfix_expression"); }
#line 1955 "y.tab.c"
    break;

  case 141: /* postfix_expression: error LPAREN argument_expression_list_opt RPAREN  */
#line 268 "syntx.y"
                                                                    { yyerror("Invalid postfix_expression"); }
#line 1961 "y.tab.c"
    break;

  case 142: /* postfix_expression: error DOT ID  */
#line 269 "syntx.y"
                                { yyerror("Invalid postfix_expression"); }
#line 1967 "y.tab.c"
    break;

  case 143: /* postfix_expression: error ARROW ID  */
#line 270 "syntx.y"
                                  { yyerror("Invalid postfix_expression"); }
#line 1973 "y.tab.c"
    break;

  case 150: /* primary_expression: error  */
#line 279 "syntx.y"
                         { yyerror("Invalid primary_expression"); }
#line 1979 "y.tab.c"
    break;

  case 155: /* argument_expression_list: error  */
#line 288 "syntx.y"
                              { yyerror("Invalid argument_expression_list"); }
#line 1985 "y.tab.c"
    break;


#line 1989 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 291 "syntx.y"

