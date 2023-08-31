#include <stdio.h>

int main() {
    // This is a valid comment
    int x = 5;
    float y = 3.14;

    if (x > 3)         printf("x is greater than 3.\n");
    } else {
        printf("x is not greater than 3.\n");
    }

    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }

    char str[] = "Hello, world!";
    printf("%s\n", str);

    // This is an unterminated string literal

    /* This is a multiline comment
       that's missing the closing */
    /* Comment is also missing a closing *

    return 0;
}
