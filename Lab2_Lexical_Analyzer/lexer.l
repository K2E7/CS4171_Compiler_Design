%{
#define RESERVED_INT 1001
#define RESERVED_FLOAT 1002
#define RESERVED_CHAR 1003
#define RESERVED_FOR 1004
#define RESERVED_DO 1005
#define RESERVED_WHILE 1006
#define RESERVED_IF 1007
#define RESERVED_ELSE 1008

#define OPERATOR_PLUS 2001
#define OPERATOR_MINUS 2002
#define OPERATOR_MULTIPLY 2003
#define OPERATOR_DIVIDE 2004
#define OPERATOR_MODULO 2005
#define OPERATOR_EQUAL 2006
#define OPERATOR_NOT_EQUAL 2007
#define OPERATOR_LESS_THAN 2008
#define OPERATOR_GREATER_THAN 2009
#define OPERATOR_LESS_EQUAL 2010
#define OPERATOR_GREATER_EQUAL 2011
#define OPERATOR_LOGICAL_AND 2012
#define OPERATOR_LOGICAL_OR 2013
#define OPERATOR_BITWISE_AND 2014
#define OPERATOR_BITWISE_OR 2015
#define OPERATOR_NOT 2016
#define OPERATOR_BITWISE_XOR 2017
#define OPERATOR_ASSIGN 2018
#define SEMICOLON 2019

#define PARENTHESIS_OPEN 3001
#define PARENTHESIS_CLOSE 3002
#define CURLY_BRACE_OPEN 3003
#define CURLY_BRACE_CLOSE 3004

#define IDENTIFIER 4001
#define INT_CONSTANT 4002

#define STRING_LITERAL 5001

int comment_flag = 0; // Flag to track multi-line comments                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               // /* Watermark: K2E7-Sriparno-Ganguly-2023 */
%}

DIGIT [0-9]
LETTER [a-zA-Z]
ID {LETTER}({LETTER}|{DIGIT})*
INT_CONST {DIGIT}+

%%

"int"       { printf("Line %d: Reserved Word: \t\tint \t\t(ID: %d)\n", yylineno, RESERVED_INT); }
"float"     { printf("Line %d: Reserved Word: \t\tfloat \t\t(ID: %d)\n", yylineno, RESERVED_FLOAT); }
"char"      { printf("Line %d: Reserved Word: \t\tchar \t\t(ID: %d)\n", yylineno, RESERVED_CHAR); }
"for"       { printf("Line %d: Reserved Word: \t\tfor \t\t(ID: %d)\n", yylineno, RESERVED_FOR); }
"do"        { printf("Line %d: Reserved Word: \t\tdo \t\t(ID: %d)\n", yylineno, RESERVED_DO); }
"while"     { printf("Line %d: Reserved Word: \t\twhile \t\t(ID: %d)\n", yylineno, RESERVED_WHILE); }
"if"        { printf("Line %d: Reserved Word: \t\tif \t\t(ID: %d)\n", yylineno, RESERVED_IF); }
"else"      { printf("Line %d: Reserved Word: \t\telse \t\t(ID: %d)\n", yylineno, RESERVED_ELSE); }

"+"         { printf("Line %d: Operator: \t\t+ \t\t(ID: %d)\n", yylineno, OPERATOR_PLUS); }
"-"         { printf("Line %d: Operator: \t\t- \t\t(ID: %d)\n", yylineno, OPERATOR_MINUS); }
"*"         { printf("Line %d: Operator: \t\t* \t\t(ID: %d)\n", yylineno, OPERATOR_MULTIPLY); }
"/"         { printf("Line %d: Operator: \t\t/ \t\t(ID: %d)\n", yylineno, OPERATOR_DIVIDE); }
"%"         { printf("Line %d: Operator: \t\t%% \t\t(ID: %d)\n", yylineno, OPERATOR_MODULO); }
"=="        { printf("Line %d: Operator: \t\t== \t\t(ID: %d)\n", yylineno, OPERATOR_EQUAL); }
"!="        { printf("Line %d: Operator: \t\t!= \t\t(ID: %d)\n", yylineno, OPERATOR_NOT_EQUAL); }
"<"         { printf("Line %d: Operator: \t\t< \t\t(ID: %d)\n", yylineno, OPERATOR_LESS_THAN); }
">"         { printf("Line %d: Operator: \t\t> \t\t(ID: %d)\n", yylineno, OPERATOR_GREATER_THAN); }
"<="        { printf("Line %d: Operator: \t\t<= \t\t(ID: %d)\n", yylineno, OPERATOR_LESS_EQUAL); }
">="        { printf("Line %d: Operator: \t\t>= \t\t(ID: %d)\n", yylineno, OPERATOR_GREATER_EQUAL); }
"&&"        { printf("Line %d: Operator: \t\t&& \t\t(ID: %d)\n", yylineno, OPERATOR_LOGICAL_AND); }
"||"        { printf("Line %d: Operator: \t\t|| \t\t(ID: %d)\n", yylineno, OPERATOR_LOGICAL_OR); }
"&"         { printf("Line %d: Operator: \t\t& \t\t(ID: %d)\n", yylineno, OPERATOR_BITWISE_AND); }
"|"         { printf("Line %d: Operator: \t\t| \t\t(ID: %d)\n", yylineno, OPERATOR_BITWISE_OR); }
"!"         { printf("Line %d: Operator: \t\t! \t\t(ID: %d)\n", yylineno, OPERATOR_NOT); }
"^"         { printf("Line %d: Operator: \t\t^ \t\t(ID: %d)\n", yylineno, OPERATOR_BITWISE_XOR); }
"="         { printf("Line %d: Operator: \t\t= \t\t(ID: %d)\n", yylineno, OPERATOR_ASSIGN); }
";"         { printf("Line %d: Semicolon: \t\t; \t\t(ID: %d)\n", yylineno, SEMICOLON); }

"("         { printf("Line %d: Parenthesis: \t\t( \t\t(ID: %d)\n", yylineno, PARENTHESIS_OPEN); }
")"         { printf("Line %d: Parenthesis: \t\t) \t\t(ID: %d)\n", yylineno, PARENTHESIS_CLOSE); }
"{"         { printf("Line %d: Curly Brace: \t\t{ \t\t(ID: %d)\n", yylineno, CURLY_BRACE_OPEN); }
"}"         { printf("Line %d: Curly Brace: \t\t} \t\t(ID: %d)\n", yylineno, CURLY_BRACE_CLOSE); }

{ID}        { printf("Line %d: Identifier: \t\t%s \t\t(ID: %d)\n", yylineno, yytext, IDENTIFIER); }
{INT_CONST} { printf("Line %d: Integer Constant: \t%s \t(ID: %d)\n", yylineno, yytext, INT_CONSTANT); }
{DIGIT}+{LETTER}({LETTER}|{DIGIT})*   { printf("Line %d: Lexical Error - Invalid Identifier: %s\n", yylineno, yytext); }

\"[^\"\n]*\" { printf("Line %d: String Literal: \t%s \t(ID: %d)\n", yylineno, yytext, STRING_LITERAL); }

"#".*                ; 
[ \t]+               ; 
"//".*               ; 

"/*"        { comment_flag = 1; } 
"*/"        { comment_flag = 0; } 
"/*"([^*]|\*[^/])*"*/" { } 

.           { printf("Line %d: Unknown token: \t\t%s\n", yylineno, yytext); }

\n          { yylineno++; }

%%


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: \t\t%s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    yyin = input_file;
    yylex();

    fclose(input_file);
    return 0;
}
