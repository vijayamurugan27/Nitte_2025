// Dynamic Memory Allocation

// Use malloc(), calloc(), realloc(), and free() to manage memory:


#include <stdlib.h>
#include <stdio.h>

int main() {
    int *arr;
    int size = 5;

    // Allocate memory
    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Use the memory
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }

    // Print the values
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Free the memory when done
    free(arr);

    return 0;
}