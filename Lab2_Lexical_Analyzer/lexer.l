%{
#include <stdio.h>                                                                                                          
#include <stdlib.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 // /* Watermark: K2E7-Sriparno-Ganguly-2023 */
                if (strcmp(yytext, "while") == 0)
%}

DIGIT [0-9]
LETTER [a-zA-Z]
ID {LETTER}({LETTER}|{DIGIT})*
INT_CONST {DIGIT}+
WS [ \t\t\n]+

%%

"int"       { printf("Reserved Word: \t\tint\n"); }
"float"     { printf("Reserved Word: \t\tfloat\n"); }
"char"      { printf("Reserved Word: \t\tchar\n"); }
"for"       { printf("Reserved Word: \t\tfor\n"); }
"do"        { printf("Reserved Word: \t\tdo\n"); }
"while"     { printf("Reserved Word: \t\twhile\n"); }
"if"        { printf("Reserved Word: \t\tif\n"); }
"else"      { printf("Reserved Word: \t\telse\n"); }
                                                                                                                                                                                                    // /* Watermark: K2E7-Sriparno-Ganguly-2023 */
"+"         { printf("Operator: \t\t+\n"); }
"-"         { printf("Operator: \t\t-\n"); }
"*"         { printf("Operator: \t\t*\n"); }
"/"         { printf("Operator: \t\t/\n"); }
"%"         { printf("Operator: \t\t%%\n"); }
"=="        { printf("Operator: \t\t==\n"); }
"!="        { printf("Operator: \t\t!=\n"); }
"<"         { printf("Operator: \t\t<\n"); }
">"         { printf("Operator: \t\t>\n"); }
"<="        { printf("Operator: \t\t<=\n"); }
">="        { printf("Operator: \t\t>=\n"); }
"&&"        { printf("Operator: \t\t&&\n"); }
"||"        { printf("Operator: \t\t||\n"); }
"&"         { printf("Operator: \t\t&\n"); }
"|"         { printf("Operator: \t\t|\n"); }
"!"         { printf("Operator: \t\t!\n"); }
"^"         { printf("Operator: \t\t^\n"); }
"="         { printf("Operator: \t\t=\n"); }

"("         { printf("Parenthesis: \t\t(\n"); }
")"         { printf("Parenthesis: \t\t)\n"); }
"{"         { printf("Curly Brace: \t\t{\n"); }
"}"         { printf("Curly Brace: \t\t}\n"); }

{ID}        { printf("Identifier: \t\t%s\n", yytext); }
{INT_CONST} { printf("Integer Constant: \t%s\n", yytext); }
{WS}        ; // Ignore whitespace

.           { printf("Unknown token: \t\t%s\n", yytext); }

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
