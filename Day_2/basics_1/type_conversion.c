#include <stdio.h>

int num1 = 5;
int num2 = 2;

int main() {
    int num3 = num1 / num2;  // Integer division (result: 2)
    float num4 = (float)num1 / num2;  // Floating-point division (result: 2.5)
    
    printf("%d\n", num3);    // Prints integer (2)
    printf("%f\n", num4);    // Prints float (2.500000)
    
    return 0;
}