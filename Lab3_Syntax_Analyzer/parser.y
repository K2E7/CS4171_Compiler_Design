%{
#include <stdio.h>
#include "tokens.h"
extern int yylex();
%}

%%

program: /* empty */
       | program statement
       ;

statement: declaration
        | expression SEMICOLON
        | if_statement
        | while_statement
        | do_while_statement
        ;

declaration: RESERVED_INT IDENTIFIER SEMICOLON
           | RESERVED_FLOAT IDENTIFIER SEMICOLON
           | RESERVED_CHAR IDENTIFIER SEMICOLON
           ;

expression: IDENTIFIER OPERATOR_ASSIGN expression
          | expression OPERATOR_PLUS expression
          | expression OPERATOR_MINUS expression
          | expression OPERATOR_MULTIPLY expression
          | expression OPERATOR_DIVIDE expression
          | expression OPERATOR_MODULO expression
          | expression OPERATOR_EQUAL expression
          | expression OPERATOR_NOT_EQUAL expression
          | expression OPERATOR_LESS_THAN expression
          | expression OPERATOR_GREATER_THAN expression
          | expression OPERATOR_LESS_EQUAL expression
          | expression OPERATOR_GREATER_EQUAL expression
          | expression OPERATOR_LOGICAL_AND expression
          | expression OPERATOR_LOGICAL_OR expression
          | expression OPERATOR_BITWISE_AND expression
          | expression OPERATOR_BITWISE_OR expression
          | OPERATOR_NOT expression
          | OPERATOR_BITWISE_XOR expression
          | PARENTHESIS_OPEN expression PARENTHESIS_CLOSE
          | INT_CONSTANT
          | IDENTIFIER
          ;

if_statement: RESERVED_IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
            | RESERVED_IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement RESERVED_ELSE statement
            ;

while_statement: RESERVED_WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
               ;

do_while_statement: RESERVED_DO statement RESERVED_WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE SEMICOLON
                  ;

%%

