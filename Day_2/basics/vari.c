#include <stdio.h>

int main() {
    int x = 10;
    float y = 3.14;
    char z = 'A';
    double w = 2.71;

    printf("Integer: %d\n", x);
    printf("Float: %.2f\n", y);
    printf("Character: %c\n", z);
    printf("Double: %.2lf\n", w);

    return 0;
}