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
#define EQ_TOK '='
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

bool isValidIdentifierChar(char ch)
{
    return isalnum(ch) || ch == '-';
}

bool isValidDigit(char ch)
{
    return isdigit(ch) || ch == '.';
}

void yylex(FILE *file)
{
    int token;
    int ch;

    while ((ch = fgetc(file)) != EOF)
    {
        switch (ch)
        {
        // Single Character Lexemes
        case LPAREN_TOK:
        case GT_TOK:
        case RPAREN_TOK:
        case EQ_TOK:
        case MINUS_TOK:
        case SEMICOLON_TOK:
            printf("Operator: \t%c\n", ch);
            break;

        // Reserved words and identifiers
        default:
            if (isalpha(ch) || ch == '_')
            {
                int i = 0;
                char identifier[100];

                while (isalpha(ch) || ch == '_' || isdigit(ch))
                {
                    identifier[i++] = ch;
                    ch = fgetc(file);
                }
                identifier[i] = '\0';
                ungetc(ch, file);

                // Check if the identifier is a reserved word
                if (strcmp(identifier, "while") == 0)
                {
                    token = WHILE_TOK;
                }
                else if (strcmp(identifier, "for") == 0)
                {
                    token = FOR_TOK;
                }
                else if (strcmp(identifier, "if") == 0)
                {
                    token = IF_TOK;                                                     /* Watermark: K2E7-Sriparno-Ganguly-2023 */
                }
                else if (strcmp(identifier, "else") == 0)
                {
                    token = ELSE_TOK;
                }
                else if (strcmp(identifier, "int") == 0)
                {
                    token = INT_TOK;
                }
                else if (strcmp(identifier, "float") == 0)
                {
                    token = FLOAT_TOK;
                }
                else if (strcmp(identifier, "char") == 0)
                {
                    token = CHAR_TOK;
                }
                else
                {
                    token = ID_TOK;
                }

                printf("Token: \t\t%s\n", identifier);
            }
            /* Watermark: K2E7-Sriparno-Ganguly-2023 */
            // Constants
            else if (isdigit(ch))
            {
                int i = 0;
                char constant[100];

                while (isValidDigit(ch))
                {
                    constant[i++] = ch;
                    ch = fgetc(file);
                }
                constant[i] = '\0';
                ungetc(ch, file);

                printf("Constant: \t%s\n", constant);
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