%{
#include "lex.yy.c"

void yyerror(char *);

void parsed(const char * msg) {
    printf("[line: %d] => %s syntax is OK\n", yylineno, msg);
}

%}

// Token Definitions (Matching Lexer Tokens)
%token LT_TOK
%token GT_TOK
%token EQ_TOK
%token MINUS_TOK
%token PLUS_TOK
%token MULT_TOK
%token DIV_TOK
%token MOD_TOK
%token BNOT_TOK
%token NOT_TOK
%token AND_TOK
%token OR_TOK
%token XOR_TOK
%token LBRACE_TOK
%token RBRACE_TOK
%token LBRACKET_TOK
%token RBRACKET_TOK
%token LPAREN_TOK
%token RPAREN_TOK
%token SEMICOLON_TOK
%token COMMA_TOK
%token SINGLE_QUOTE_TOK
%token DOUBLE_QUOTE_TOK
%token MAIN_TOK
%token WHILE_TOK
%token DO_TOK
%token FOR_TOK
%token BREAK_TOK
%token CONTINUE_TOK
%token IF_TOK
%token ELSE_TOK
%token SWITCH_TOK
%token CASE_TOK
%token VOID_TOK
%token INT_TOK
%token FLOAT_TOK
%token CHAR_TOK
%token RETURN_TOK
%token ID_TOK
%token LT_EQ_TOK
%token GT_EQ_TOK
%token EQ_EQ_TOK
%token PLUS_EQ_TOK
%token MINUS_EQ_TOK
%token MULT_EQ_TOK
%token DIV_EQ_TOK
%token MOD_EQ_TOK
%token PLUS_PLUS_TOK
%token MINUS_MINUS_TOK
%token LOG_AND_TOK
%token LOG_OR_TOK
%token INTCONST
%token FLOATCONST
%token CHARCONST
%token STRCONST

// Start symbol
%start S

%%

S               : S statement
                | S main
                | S function
                | statement
                | main
                | function
                ;

main            : datatype  MAIN_TOK LPAREN_TOK RPAREN_TOK block       {parsed("Main function");}
                ;

block           : LBRACE_TOK  statements  blocks  RBRACE_TOK
                ;

blocks          : block statements blocks
                | // Required for an empty block
                ;

statements      : statements statement
                | statements if_statement
                | statements for_statement
                | statements while_statement
                | // Required for an empty statement
                ;

statement       : operation SEMICOLON_TOK
                | return_statement
                ;

operation       : declaration
                | assignment
                | expression
                | condition
                ;

declaration     : datatype id_token                      {parsed("Declaration statement");}
                ;

assignment      : datatype id_token EQ_TOK expression    {parsed("Assignment statement");}
                | id_token EQ_TOK expression              {parsed("Assignment statement");}
                ;     

return_statement: RETURN_TOK expression SEMICOLON_TOK    {parsed("Return statement");}
                ;

function        : datatype id_token LPAREN_TOK params RPAREN_TOK block {parsed("Function");}
                ;

params          : datatype id_token COMMA_TOK params
                | datatype id_token     
                | // Required for empty params
                ;                

function_call   : id_token LPAREN_TOK args RPAREN_TOK {parsed("Function call");}
                ;

args            : expression COMMA_TOK args
                | expression
                | // Required for empty args
                ;           

expression      : function_call
                | id_token
                | INTCONST
                | FLOATCONST
                | CHARCONST
                | STRCONST
                | SEMICOLON_TOK
                | LPAREN_TOK expression RPAREN_TOK
                | expression arithmetic_op expression
                | expression relational_op expression
                | expression PLUS_PLUS_TOK
                | expression MINUS_MINUS_TOK
                ;  

if_statement    : IF_TOK LPAREN_TOK condition RPAREN_TOK block                  {parsed("If statement");}
                | IF_TOK LPAREN_TOK condition RPAREN_TOK block ELSE_TOK block   {parsed("If-else statement");}
                | IF_TOK LPAREN_TOK condition RPAREN_TOK block ELSE_TOK if_statement {parsed("Else-if statement");}
                ;

for_statement   : FOR_TOK LPAREN_TOK operation SEMICOLON_TOK operation SEMICOLON_TOK operation RPAREN_TOK block {parsed("For statement");}
                ;

while_statement : WHILE_TOK LPAREN_TOK condition RPAREN_TOK block {parsed("While statement");}
                ;

condition       : expression relational_op expression
                | expression
                ;

arithmetic_op   : PLUS_TOK
                | MINUS_TOK
                | MULT_TOK
                | DIV_TOK
                | MOD_TOK
                | PLUS_EQ_TOK
                | MINUS_EQ_TOK
                | MULT_EQ_TOK
                | DIV_EQ_TOK
                | MOD_EQ_TOK
                ;

relational_op   : LT_TOK
                | GT_TOK
                | EQ_TOK
                | LT_EQ_TOK
                | GT_EQ_TOK
                | EQ_EQ_TOK
                ;

datatype        : INT_TOK
                | VOID_TOK
                | CHAR_TOK
                | FLOAT_TOK
                ;

id_token        : id_token COMMA_TOK ID_TOK
                | ID_TOK
                ;

%%

void yyerror(char *s) {
    printf("Parsing Error: %s\n", s);
}

int main() {
    if (yyparse() == 0) {
        printf("\nParsing Completed Successfully ✅\n");
    } else {
        printf("\nParsing Error (at line no: %d) ❌\n", yylineno);
    }

    return 0;
}
