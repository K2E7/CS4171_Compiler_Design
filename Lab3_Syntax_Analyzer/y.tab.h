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
    RESERVED_INT = 258,            /* RESERVED_INT  */
    RESERVED_FLOAT = 259,          /* RESERVED_FLOAT  */
    RESERVED_CHAR = 260,           /* RESERVED_CHAR  */
    RESERVED_FOR = 261,            /* RESERVED_FOR  */
    RESERVED_DO = 262,             /* RESERVED_DO  */
    RESERVED_WHILE = 263,          /* RESERVED_WHILE  */
    RESERVED_IF = 264,             /* RESERVED_IF  */
    RESERVED_ELSE = 265,           /* RESERVED_ELSE  */
    RESERVED_MAIN = 266,           /* RESERVED_MAIN  */
    OPERATOR_PLUS = 267,           /* OPERATOR_PLUS  */
    OPERATOR_MINUS = 268,          /* OPERATOR_MINUS  */
    OPERATOR_MULTIPLY = 269,       /* OPERATOR_MULTIPLY  */
    OPERATOR_DIVIDE = 270,         /* OPERATOR_DIVIDE  */
    OPERATOR_MODULO = 271,         /* OPERATOR_MODULO  */
    OPERATOR_EQUAL = 272,          /* OPERATOR_EQUAL  */
    OPERATOR_NOT_EQUAL = 273,      /* OPERATOR_NOT_EQUAL  */
    OPERATOR_LESS_THAN = 274,      /* OPERATOR_LESS_THAN  */
    OPERATOR_GREATER_THAN = 275,   /* OPERATOR_GREATER_THAN  */
    OPERATOR_LESS_EQUAL = 276,     /* OPERATOR_LESS_EQUAL  */
    OPERATOR_GREATER_EQUAL = 277,  /* OPERATOR_GREATER_EQUAL  */
    OPERATOR_LOGICAL_AND = 278,    /* OPERATOR_LOGICAL_AND  */
    OPERATOR_LOGICAL_OR = 279,     /* OPERATOR_LOGICAL_OR  */
    OPERATOR_BITWISE_AND = 280,    /* OPERATOR_BITWISE_AND  */
    OPERATOR_BITWISE_OR = 281,     /* OPERATOR_BITWISE_OR  */
    OPERATOR_NOT = 282,            /* OPERATOR_NOT  */
    OPERATOR_BITWISE_XOR = 283,    /* OPERATOR_BITWISE_XOR  */
    OPERATOR_ASSIGN = 284,         /* OPERATOR_ASSIGN  */
    SEMICOLON = 285,               /* SEMICOLON  */
    PARENTHESIS_OPEN = 286,        /* PARENTHESIS_OPEN  */
    PARENTHESIS_CLOSE = 287,       /* PARENTHESIS_CLOSE  */
    CURLY_BRACE_OPEN = 288,        /* CURLY_BRACE_OPEN  */
    CURLY_BRACE_CLOSE = 289,       /* CURLY_BRACE_CLOSE  */
    IDENTIFIER = 290,              /* IDENTIFIER  */
    INT_CONSTANT = 291,            /* INT_CONSTANT  */
    STRING_LITERAL = 292,          /* STRING_LITERAL  */
    COMMA = 293                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define RESERVED_INT 258
#define RESERVED_FLOAT 259
#define RESERVED_CHAR 260
#define RESERVED_FOR 261
#define RESERVED_DO 262
#define RESERVED_WHILE 263
#define RESERVED_IF 264
#define RESERVED_ELSE 265
#define RESERVED_MAIN 266
#define OPERATOR_PLUS 267
#define OPERATOR_MINUS 268
#define OPERATOR_MULTIPLY 269
#define OPERATOR_DIVIDE 270
#define OPERATOR_MODULO 271
#define OPERATOR_EQUAL 272
#define OPERATOR_NOT_EQUAL 273
#define OPERATOR_LESS_THAN 274
#define OPERATOR_GREATER_THAN 275
#define OPERATOR_LESS_EQUAL 276
#define OPERATOR_GREATER_EQUAL 277
#define OPERATOR_LOGICAL_AND 278
#define OPERATOR_LOGICAL_OR 279
#define OPERATOR_BITWISE_AND 280
#define OPERATOR_BITWISE_OR 281
#define OPERATOR_NOT 282
#define OPERATOR_BITWISE_XOR 283
#define OPERATOR_ASSIGN 284
#define SEMICOLON 285
#define PARENTHESIS_OPEN 286
#define PARENTHESIS_CLOSE 287
#define CURLY_BRACE_OPEN 288
#define CURLY_BRACE_CLOSE 289
#define IDENTIFIER 290
#define INT_CONSTANT 291
#define STRING_LITERAL 292
#define COMMA 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
