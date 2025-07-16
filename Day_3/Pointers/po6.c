// Memory Manipulation Functions

// C provides functions for working with memory blocks:

#include <stdio.h>
#include <string.h>

int main() {
    char src[50] = "Hello, World!";
    char dest[50];

    // Copy memory
    memcpy(dest, src, strlen(src) + 1);
    printf("Copied string: %s\n", dest);

    // Set memory
    memset(dest, 0, sizeof(dest));  // Zero out the array
    printf("Memory after memset: ");
    for (int i = 0; i < sizeof(dest); i++) {
        printf("%02X ", dest[i]);
    }
    printf("\n");

    // Compare memory
    if (memcmp(src, dest, sizeof(src)) == 0) {
        printf("Memory blocks are identical\n");
    } else {
        printf("Memory blocks are not identical\n");
    }

    return 0;
}