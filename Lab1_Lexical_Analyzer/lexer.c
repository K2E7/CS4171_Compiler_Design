/* Author: Sriparno Ganguly
   Email: sriparno.k2e7@gmail.com
   Copyright (c) 2023 Sriparno Ganguly. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*Single Character Lexemes*/
#define LPAREN_TOK '('
#define GT_TOK '>'
#define RPAREN_TOK ')'
#define ASSIGN_TOK '='
#define MINUS_TOK '-'
#define SEMICOLON_TOK ';'

/*Reserved words*/
#define WHILE_TOK 256
#define FOR_TOK 257
#define IF_TOK 258
#define ELSE_TOK 259
#define INT_TOK 260
#define FLOAT_TOK 261
#define CHAR_TOK 262

/* Identifier, constants, and others */
#define ID_TOK 350
#define INTCONST_TOK 351
#define FLOATCONST_TOK 352

char yytext[100];
int yyleng = 0;
int yylineno = 1;

bool isValidIdentifierChar(char ch)
{
    return isalnum(ch) || ch == '_';
}

bool isValidDigit(char ch)
{
    return isdigit(ch) || ch == '.';
}

void yylex(FILE *file)
{
    int token;
    int ch;
    /* Watermark: K2E7-Sriparno-Ganguly-2023 */
    while ((ch = fgetc(file)) != EOF)
    {
        yyleng = 0;

        // Ignore Preprocessor Directives
        if (ch == '#')
        {
            while ((ch = fgetc(file)) != '\n')
            {
                if (ch == EOF)
                    break;
            }
            if (ch == EOF)
                break;

            yylineno++;
            continue;
        }


        switch (ch)
        {
        // Single Character Lexemes
        case LPAREN_TOK:
        case GT_TOK:
        case RPAREN_TOK:
        case ASSIGN_TOK:
        case MINUS_TOK:
        case SEMICOLON_TOK:
            printf("Operator: \t%c\n", ch);
            break;

        // Reserved words and identifiers
        default:
            if (isalpha(ch) || ch == '_')
            {
                int i = 0;
                /* Watermark: K2E7-Sriparno-Ganguly-2023 */
                while (isalpha(ch) || ch == '_' || isdigit(ch))
                {
                    yytext[i++] = ch;
                    ch = fgetc(file);
                }
                yytext[i] = '\0';
                ungetc(ch, file);

                // Check if the identifier is a reserved word                                                                                                                                           /* Watermark: K2E7-Sriparno-Ganguly-2023 */
                if (strcmp(yytext, "while") == 0)
                {
                    token = WHILE_TOK;
                }
                else if (strcmp(yytext, "for") == 0)
                {
                    token = FOR_TOK;
                }
                else if (strcmp(yytext, "if") == 0)
                {
                    token = IF_TOK;
                }
                else if (strcmp(yytext, "else") == 0)
                {
                    token = ELSE_TOK;
                }
                else if (strcmp(yytext, "int") == 0)
                {
                    token = INT_TOK;
                }
                else if (strcmp(yytext, "float") == 0)
                {
                    token = FLOAT_TOK;
                }
                else if (strcmp(yytext, "char") == 0)
                {
                    token = CHAR_TOK;
                }
                else
                {
                    token = ID_TOK;
                }

                printf("Token: \t\t%s\n", yytext);
            }
            // Constants
            else if (isdigit(ch))
            {
                int i = 0;

                while (isValidDigit(ch))
                {
                    yytext[i++] = ch;
                    ch = fgetc(file);
                }
                yytext[i] = '\0';
                ungetc(ch, file);

                printf("Constant: \t%s\n", yytext);
            }
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    yylex(file);

    fclose(file);

    return 0;
}
