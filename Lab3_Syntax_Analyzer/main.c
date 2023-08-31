#include <stdio.h>
#include "y.tab.h"  // Include the YACC-generated header

// Implement the lexer function (yylex) using Flex/Lex (in a separate .l file).

int main() {
    // Initialize the lexer (if needed) - you should have yylex implemented in a separate file.
    // You might also set up any necessgary data structures or perform other initialization here.
    
    // Call yyparse() to start the parsing process.
    int result = yyparse();

    // Perform additional actions or error handling as needed.
    
    // Optionally, you can print a message based on the parsing result.
    if (result == 0) {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Parsing encountered errors.\n");
    }
    
    return 0;
}
