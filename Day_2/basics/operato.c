#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;

    printf("Addition: %d\n", x + y);
    printf("Subtraction: %d\n", x - y);
    printf("Multiplication: %d\n", x * y);
    printf("Division: %d\n", x / y);
    printf("Modulus: %d\n", x % y);

    printf("Equal: %d\n", x == y);
    printf("Not Equal: %d\n", x != y);
    printf("Greater Than: %d\n", x > y);
    printf("Less Than: %d\n", x < y);

    x = 10;
    y = 5;
    printf("Assignment: %d\n", x = y);

    return 0;
}