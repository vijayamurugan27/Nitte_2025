#include <stdio.h>

int main() {
    int x = 1;

    switch (x) {
        case 1:
            printf("x is 1\n");
            break;
        case 2:
            printf("x is 2\n");
            break;
        default:
            printf("x is not 1 or 2\n");
            break;
    }

    return 0;
}