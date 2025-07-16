// Pointer Arithmetic

// Pointers can be incremented/decremented to access adjacent memory locations:

#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;

    for (int i = 0; i < 5; i++) {
        printf("Value at address %p is %d\n", (void*)ptr, *ptr);
        ptr++;  // Move to next memory location
    }

    return 0;
}