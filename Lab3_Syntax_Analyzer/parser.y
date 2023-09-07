%{
#include <stdio.h>
extern int yylex();
%}

%token RESERVED_INT RESERVED_FLOAT RESERVED_CHAR RESERVED_FOR RESERVED_DO RESERVED_WHILE RESERVED_IF RESERVED_ELSE
%token OPERATOR_PLUS OPERATOR_MINUS OPERATOR_MULTIPLY OPERATOR_DIVIDE OPERATOR_MODULO OPERATOR_EQUAL OPERATOR_NOT_EQUAL OPERATOR_LESS_THAN OPERATOR_GREATER_THAN OPERATOR_LESS_EQUAL OPERATOR_GREATER_EQUAL OPERATOR_LOGICAL_AND OPERATOR_LOGICAL_OR OPERATOR_BITWISE_AND OPERATOR_BITWISE_OR OPERATOR_NOT OPERATOR_BITWISE_XOR OPERATOR_ASSIGN SEMICOLON
%token PARENTHESIS_OPEN PARENTHESIS_CLOSE CURLY_BRACE_OPEN CURLY_BRACE_CLOSE
%token IDENTIFIER INT_CONSTANT STRING_LITERAL

%left OPERATOR_LOGICAL_OR
%left OPERATOR_LOGICAL_AND
%left OPERATOR_BITWISE_OR
%left OPERATOR_BITWISE_XOR
%left OPERATOR_BITWISE_AND
%left OPERATOR_EQUAL OPERATOR_NOT_EQUAL
%left OPERATOR_LESS_THAN OPERATOR_GREATER_THAN OPERATOR_LESS_EQUAL OPERATOR_GREATER_EQUAL
%left OPERATOR_PLUS OPERATOR_MINUS
%left OPERATOR_MULTIPLY OPERATOR_DIVIDE OPERATOR_MODULO
%right OPERATOR_NOT
%nonassoc PARENTHESIS_OPEN

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
          | expression OPERATOR_LOGICAL_OR expression
          | expression OPERATOR_LOGICAL_AND expression
          | expression OPERATOR_BITWISE_OR expression
          | expression OPERATOR_BITWISE_XOR expression
          | expression OPERATOR_BITWISE_AND expression
          | expression OPERATOR_EQUAL expression
          | expression OPERATOR_NOT_EQUAL expression
          | expression OPERATOR_LESS_THAN expression
          | expression OPERATOR_GREATER_THAN expression
          | expression OPERATOR_LESS_EQUAL expression
          | expression OPERATOR_GREATER_EQUAL expression
          | expression OPERATOR_PLUS expression
          | expression OPERATOR_MINUS expression
          | expression OPERATOR_MULTIPLY expression
          | expression OPERATOR_DIVIDE expression
          | expression OPERATOR_MODULO expression
          | OPERATOR_NOT expression %prec OPERATOR_NOT
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
