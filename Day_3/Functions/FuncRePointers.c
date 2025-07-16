// Functions Returning Pointers

#include <stdio.h>
#include <stdlib.h>
 
int* createArray(int size) {
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

int main() {
    int *myArray = createArray(5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
    }
    free(myArray);
    return 0;
}