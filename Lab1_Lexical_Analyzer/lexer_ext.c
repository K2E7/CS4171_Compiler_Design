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

/* Global Variables */
char* yytext = NULL;
size_t yyleng = 0;
int yylineno = 1;
const size_t BUFFER_SIZE = 1024; // Adjust buffer size as needed

bool isValidIdentifierChar(char ch)
{
    return isalnum(ch) || ch == '-';
}

bool isValidDigit(char ch)
{
    return isdigit(ch) || ch == '.';
}

void tokenizeBuffer(const char* buffer, size_t bufferSize)
{
    size_t pos = 0;

    while (pos < bufferSize)
    {
        // Skip whitespace characters and update line number
        while (pos < bufferSize && isspace(buffer[pos]))
        {
            if (buffer[pos] == '\n')
            {
                yylineno++;
            }
            pos++;
        }

        // If we reached the end of the buffer, break
        if (pos == bufferSize)
        {
            break;
        }

        // Find the end of the current token
        size_t endPos = pos + 1;
        while (endPos < bufferSize && !isspace(buffer[endPos]))
        {
            endPos++;
        }

        yyleng = endPos - pos;
        yytext = (char*)malloc(yyleng + 1);
        strncpy(yytext, buffer + pos, yyleng);
        yytext[yyleng] = '\0';

        // Single Character Lexemes
        if (yyleng == 1)
        {
            switch (yytext[0])
            {
            case LPAREN_TOK:
            case GT_TOK:
            case RPAREN_TOK:
            case EQ_TOK:
            case MINUS_TOK:
            case SEMICOLON_TOK:
                printf("Operator: \t%c\n", yytext[0]);
                break;
            default:
                // Token is an identifier or constant
                if (isdigit(yytext[0]))
                {
                    // Constants
                    bool isFloat = false;
                    for (size_t i = 0; i < yyleng; i++)
                    {
                        if (!isValidDigit(yytext[i]))
                        {
                            printf("Invalid constant: \t%s\n", yytext);
                            free(yytext);
                            return;
                        }
                        if (yytext[i] == '.')
                        {
                            isFloat = true;
                        }
                    }
                    if (isFloat)
                    {
                        printf("Constant: \t%s (float)\n", yytext);
                    }
                    else
                    {
                        printf("Constant: \t%s (integer)\n", yytext);
                    }
                }
                else
                {
                    // Identifier
                    for (size_t i = 0; i < yyleng; i++)
                    {
                        if (!isValidIdentifierChar(yytext[i]))
                        {
                            printf("Invalid identifier: \t%s\n", yytext);
                            free(yytext);
                            return;
                        }
                    }
                    printf("Token: \t\t%s\n", yytext);
                }
            }
        }
        else
        {
            // Token is an identifier or reserved word
            for (size_t i = 0; i < yyleng; i++)
            {
                if (!isValidIdentifierChar(yytext[i]))
                {
                    printf("Invalid identifier: \t%s\n", yytext);
                    free(yytext);
                    return;
                }
            }

            // Check if the identifier is a reserved word
            if (strcmp(yytext, "while") == 0)
            {
                printf("Token: \t\t%s (reserved word: while)\n", yytext);
            }
            else if (strcmp(yytext, "for") == 0)
            {
                printf("Token: \t\t%s (reserved word: for)\n", yytext);
            }
            else if (strcmp(yytext, "if") == 0)
            {
                printf("Token: \t\t%s (reserved word: if)\n", yytext);
            }
            else if (strcmp(yytext, "else") == 0)
            {
                printf("Token: \t\t%s (reserved word: else)\n", yytext);
            }
            else if (strcmp(yytext, "int") == 0)
            {
                printf("Token: \t\t%s (reserved word: int)\n", yytext);
            }
            else if (strcmp(yytext, "float") == 0)
            {
                printf("Token: \t\t%s (reserved word: float)\n", yytext);
            }
            else if (strcmp(yytext, "char") == 0)
            {
                printf("Token: \t\t%s (reserved word: char)\n", yytext);
            }
            else
            {
                printf("Token: \t\t%s\n", yytext);
            }
        }

        free(yytext);
        pos = endPos;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Read the file in chunks and tokenize each chunk
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0)
    {
        tokenizeBuffer(buffer, bytesRead);
    }

    fclose(file);

    return 0;
}
