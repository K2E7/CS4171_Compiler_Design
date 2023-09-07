%{
#include <stdio.h>
#include "lex.yy.c" // Include the lexer header
/* Define your data structures and functions here if needed */

extern int yylex();  // Define the lexer function
void yyerror(const char *s);  // Error handling function
%}

%token RESERVED_INT RESERVED_FLOAT RESERVED_CHAR RESERVED_FOR RESERVED_DO RESERVED_WHILE RESERVED_IF RESERVED_ELSE RESERVED_MAIN
%token OPERATOR_PLUS OPERATOR_MINUS OPERATOR_MULTIPLY OPERATOR_DIVIDE OPERATOR_MODULO OPERATOR_EQUAL OPERATOR_NOT_EQUAL
%token OPERATOR_LESS_THAN OPERATOR_GREATER_THAN OPERATOR_LESS_EQUAL OPERATOR_GREATER_EQUAL OPERATOR_LOGICAL_AND OPERATOR_LOGICAL_OR
%token OPERATOR_BITWISE_AND OPERATOR_BITWISE_OR OPERATOR_NOT OPERATOR_BITWISE_XOR OPERATOR_ASSIGN SEMICOLON
%token PARENTHESIS_OPEN PARENTHESIS_CLOSE CURLY_BRACE_OPEN CURLY_BRACE_CLOSE
%token IDENTIFIER INT_CONSTANT STRING_LITERAL COMMA  // Added COMMA token

%%

program : main_function user_defined_functions
        ;

main_function : RESERVED_INT RESERVED_MAIN PARENTHESIS_OPEN PARENTHESIS_CLOSE CURLY_BRACE_OPEN statements CURLY_BRACE_CLOSE
             ;

user_defined_functions : /* Empty or multiple user-defined functions */
                     | user_defined_functions function
                     ;

function : function_declaration CURLY_BRACE_OPEN statements CURLY_BRACE_CLOSE
         ;

function_declaration : data_type IDENTIFIER PARENTHESIS_OPEN parameter_list PARENTHESIS_CLOSE SEMICOLON
                    ;

parameter_list : /* Empty or multiple parameters */
               | data_type IDENTIFIER
               | parameter_list COMMA data_type IDENTIFIER  // Modified for COMMA
               ;

statements : /* Empty or multiple statements */
           | statements statement
           ;

statement : variable_declaration SEMICOLON
          | assignment_statement SEMICOLON
          | conditional_statement
          | iterative_statement
          | function_call SEMICOLON
          ;

variable_declaration : data_type IDENTIFIER
                    ;

data_type : RESERVED_INT
          | RESERVED_FLOAT
          | RESERVED_CHAR
          ;

assignment_statement : IDENTIFIER OPERATOR_ASSIGN expression
                    ;

conditional_statement : RESERVED_IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE CURLY_BRACE_OPEN statements CURLY_BRACE_CLOSE
                     | RESERVED_IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE CURLY_BRACE_OPEN statements CURLY_BRACE_CLOSE RESERVED_ELSE CURLY_BRACE_OPEN statements CURLY_BRACE_CLOSE
                     ;

iterative_statement : RESERVED_FOR PARENTHESIS_OPEN assignment_statement SEMICOLON expression SEMICOLON assignment_statement PARENTHESIS_CLOSE CURLY_BRACE_OPEN statements CURLY_BRACE_CLOSE
                   | RESERVED_DO CURLY_BRACE_OPEN statements CURLY_BRACE_CLOSE RESERVED_WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE SEMICOLON
                   | RESERVED_WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE CURLY_BRACE_OPEN statements CURLY_BRACE_CLOSE
                   ;

function_call : IDENTIFIER PARENTHESIS_OPEN argument_list PARENTHESIS_CLOSE
              ;

argument_list : /* Empty */
              | expression
              | argument_list COMMA expression
              ;

expression : /* Define your expression grammar here */
          ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

/*
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    yyin = input_file;
    yyparse();

    fclose(input_file);
    return 0;
}
*/