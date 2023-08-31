%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structures for AST here if needed

// Function to handle syntax errors
void yyerror(const char* message) {
    fprintf(stderr, "Syntax Error: %s\n", message);
}

// Define other necessary global variables and data structures here
%}

%token ID INT FLOAT CHAR STRING
%token MAIN IF ELSE WHILE FOR RETURN VOID
%token PLUS MINUS MULT DIV MOD
%token EQ NEQ LT GT LEQ GEQ
%token AND OR NOT
%token SEMICOLON COMMA COLON
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token ASSIGN
%token QUESTION  // Define QUESTION token
%token LSHIFT    // Define LSHIFT token
%token RSHIFT    // Define RSHIFT token
%token SIZEOF    // Define SIZEOF token
%token DOT       // Define DOT token
%token ARROW     // Define ARROW token
%token INC       // Define INC token
%token DEC       // Define DEC token
%token ERROR

%left OR
%left AND
%left EQ NEQ
%left LT GT LEQ GEQ
%left PLUS MINUS
%left MULT DIV MOD
%left NOT

%%

program: external_declaration
       | program external_declaration
       ;

external_declaration: function_definition
                   | declaration
                   | error SEMICOLON
                   ;

function_definition: type_specifier ID '(' parameter_list_opt ')' compound_statement
                   | type_specifier ID error compound_statement
                   | type_specifier ID '(' parameter_list_opt ')' error
                   ;

parameter_list_opt: /* empty */
                  | parameter_list
                  ;

parameter_list: parameter_declaration
              | parameter_list COMMA parameter_declaration
              ;

parameter_declaration: type_specifier ID
                   | type_specifier error
                   ;

type_specifier: INT
             | FLOAT
             | CHAR
             | VOID
             | error
             ;

declaration: type_specifier init_declarator_list SEMICOLON
           | type_specifier error SEMICOLON
           ;

init_declarator_list: init_declarator
                   | init_declarator_list COMMA init_declarator
                   ;

init_declarator: declarator
              | declarator ASSIGN initializer
              | declarator ASSIGN error
              ;

declarator: direct_declarator
          ;

direct_declarator: ID
                | LPAREN declarator RPAREN
                | direct_declarator LBRACKET constant_expression_opt RBRACKET
                | direct_declarator LPAREN parameter_list_opt RPAREN
                | direct_declarator LBRACKET error RBRACKET
                | direct_declarator LPAREN error RPAREN
                ;

constant_expression_opt: /* empty */
                      | constant_expression
                      | error
                      ;

constant_expression: INT
                  | error
                  ;

initializer: assignment_expression
           | error
           ;

compound_statement: LBRACE declaration_list_opt statement_list_opt RBRACE
                 ;

declaration_list_opt: /* empty */
                   | declaration_list
                   ;

declaration_list: declaration
               | declaration_list declaration
               | error
               ;

statement_list_opt: /* empty */
                 | statement_list
                 ;

statement_list: statement
              | statement_list statement
              ;

statement: expression_statement
         | compound_statement
         | selection_statement
         | iteration_statement
         | jump_statement
         | error SEMICOLON
         ;

expression_statement: expression_opt SEMICOLON
                   ;

expression_opt: /* empty */
              | expression
              | error
              ;

selection_statement: IF LPAREN expression RPAREN statement
                  | IF LPAREN expression RPAREN statement ELSE statement
                  | IF LPAREN error RPAREN statement ELSE statement
                  | IF LPAREN expression RPAREN statement ELSE error
                  | IF LPAREN error RPAREN statement
                  | IF LPAREN expression RPAREN error
                  ;

iteration_statement: WHILE LPAREN expression RPAREN statement
                  | FOR LPAREN expression_statement expression_statement_opt RPAREN statement
                  | FOR LPAREN expression_statement expression_statement_opt error statement
                  | FOR LPAREN expression_statement error RPAREN statement
                  ;

expression_statement_opt: /* empty */
                      | expression_statement
                      ;

jump_statement: RETURN expression_opt SEMICOLON
              | RETURN error SEMICOLON
              ;

expression: assignment_expression
          | error
          ;

assignment_expression: conditional_expression
                   | unary_expression ASSIGN assignment_expression
                   | unary_expression error assignment_expression
                   ;

conditional_expression: logical_or_expression
                   | logical_or_expression QUESTION expression COLON conditional_expression
                   | logical_or_expression QUESTION error COLON conditional_expression
                   | logical_or_expression QUESTION expression COLON error
                   ;

logical_or_expression: logical_and_expression
                   | logical_or_expression OR logical_and_expression
                   | logical_or_expression OR error
                   ;

logical_and_expression: inclusive_or_expression
                   | logical_and_expression AND inclusive_or_expression
                   | logical_and_expression AND error
                   ;

inclusive_or_expression: exclusive_or_expression
                   | inclusive_or_expression '|' exclusive_or_expression
                   | inclusive_or_expression '|' error
                   ;

exclusive_or_expression: and_expression
                   | exclusive_or_expression '^' and_expression
                   | exclusive_or_expression '^' error
                   ;

and_expression: equality_expression
             | and_expression '&' equality_expression
             | and_expression '&' error
             ;

equality_expression: relational_expression
                  | equality_expression EQ relational_expression
                  | equality_expression NEQ relational_expression
                  | equality_expression EQ error
                  ;

relational_expression: shift_expression
                   | relational_expression LT shift_expression
                   | relational_expression GT shift_expression
                   | relational_expression LEQ shift_expression
                   | relational_expression GEQ shift_expression
                   | relational_expression LT error
                   ;

shift_expression: additive_expression
               | shift_expression LSHIFT additive_expression
               | shift_expression RSHIFT additive_expression
               | shift_expression LSHIFT error
               ;

additive_expression: multiplicative_expression
                 | additive_expression PLUS multiplicative_expression
                 | additive_expression MINUS multiplicative_expression
                 | additive_expression PLUS error
                 ;

multiplicative_expression: cast_expression
                       | multiplicative_expression MULT cast_expression
                       | multiplicative_expression DIV cast_expression
                       | multiplicative_expression MOD cast_expression
                       | multiplicative_expression MULT error
                       ;

cast_expression: unary_expression
              | error
              ;

unary_expression: postfix_expression
               | PLUS unary_expression
               | MINUS unary_expression
               | NOT unary_expression
               | '&' cast_expression
               | '*' cast_expression
               | SIZEOF unary_expression
               | PLUS error
               ;

postfix_expression: primary_expression
                 | postfix_expression LBRACKET expression RBRACKET
                 | postfix_expression LPAREN argument_expression_list_opt RPAREN
                 | postfix_expression DOT ID
                 | postfix_expression ARROW ID
                 | postfix_expression INC
                 | postfix_expression DEC
                 | error LBRACKET expression RBRACKET
                 | error LPAREN argument_expression_list_opt RPAREN
                 | error DOT ID
                 | error ARROW ID
                 ;

primary_expression: ID
                 | INT
                 | FLOAT
                 | CHAR
                 | STRING
                 | LPAREN expression RPAREN
                 | error
                 ;

argument_expression_list_opt: /* empty */
                           | argument_expression_list
                           ;

argument_expression_list: assignment_expression
                      | argument_expression_list COMMA assignment_expression
                      | error
                      ;

%%
