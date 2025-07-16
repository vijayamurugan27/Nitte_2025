// Function Pointers


#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

int main() {
    int (*operation)(int, int);  // Function pointer declaration
    
    operation = add;
    printf("Addition: %d\n", operation(10, 5));
    
    operation = subtract;
    printf("Subtraction: %d\n", operation(10, 5));
    
    return 0;
}