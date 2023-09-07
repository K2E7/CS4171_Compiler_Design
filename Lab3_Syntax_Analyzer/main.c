#include <stdio.h>
#include "y.tab.h" // Include the generated parser header file
#include "token.h"     // Include the tokens header

extern FILE* yyin; // Declare the lexer input stream

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
    yyparse(); // Call the parser generated by Bison

    fclose(input_file);
    return 0;
}