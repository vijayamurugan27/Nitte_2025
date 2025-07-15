#include <stdio.h>

int add1(int x, int y) {
    return x + y;
}

int main() {
    int result = add1(10, 5);
    printf("Result: %d\n", result);

    return 0;
}