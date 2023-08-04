#include <stdio.h>

int main() {
    int x = 10;
    float y = 3.14;
    if (x > 0) {
        while (y >= 1) {
            printf("Hello, world!\n");
            y = y - 1;
        }
    }
    return 0;
}