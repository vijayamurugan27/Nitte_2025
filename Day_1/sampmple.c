#include <stdio.h>

int main() {
    char c;

    // Display ANSI values of A-Z
    printf("ANSI Values of A-Z:\n");
    for (c = 'A'; c <= 'Z'; c++) {
        printf("%c = %d\n", c, c);
    }

    // Display ANSI values of a-z
    printf("\nANSI Values of a-z:\n");
    for (c = 'a'; c <= 'z'; c++) {
        printf("%c = %d\n", c, c);
    }

    return 0;
}