// Pointer basics

// Pointers store memory addresses and allow you to work directly with memory locations.

#include <stdio.h>

int main() {
    int var = 10;       // integer variable
    int *ptr = &var;    // pointer to integer, storing var's address

    printf("Value of var: %d\n", var);       // Output: 10
    printf("Address of var: %p\n", (void*)&var);    // Output: memory address
    printf("Value via pointer: %d\n", *ptr); // Output: 10

    return 0;
}