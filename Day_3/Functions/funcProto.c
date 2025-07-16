// A function prototype, also known as a function declaration, specifies the name, return type, and parameters of a function.



#include <stdio.h>

// Function prototype (declaration)
int multiply(int x, int y);

int main() {
    int product = multiply(4, 5);
    printf("Product: %d\n", product);
    return 0;
}

// Function definition
int multiply(int x, int y) {
    return x * y;
}