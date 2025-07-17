// Dynamic Memory Allocation

// Use malloc(), calloc(), realloc(), and free() to manage memory:

// malloc - Memory Allocation

    // Syntax:  void* malloc(size_t size);
        // Allocates a single block of memory  of the specified size (in bytes).
        // Returns a pointer to the first byte of the allocated memory.
        // The memory is not initialized , so it contains garbage values.
    
// calloc() – Contiguous Memory Allocation
    // Syntax:  void* calloc(size_t num, size_t size);
        // Allocates memory for an array of num elements each of size size.
        // Initializes all bytes to zero .
        // Slower than malloc() due to zeroing.

// realloc() – Reallocate Memory Block
    // Syntax:  void* realloc(void* ptr, size_t size);
        // Changes the size of the previously allocated memory block pointed to by ptr.
        // Can be used to expand or shrink memory.
        // If needed, copies old data to new location and frees the old block.

// free() – Free Allocated Memory
    //Syntax:  void free(void* ptr);
        // Deallocates the memory block pointed to by ptr, which was previously allocated with malloc, calloc, or realloc.
        // After calling free(), the pointer becomes dangling  (points to invalid memory), so it's good practice to set it to NULL.
     
     
     
     

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