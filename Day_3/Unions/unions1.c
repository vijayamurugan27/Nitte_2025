// Unions

// Unions are similar to structures but all members share the same memory location. Only one member can contain a value at any given time.

#include <stdio.h>
#include <string.h>

// Define a union
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;
    data.i = 10;
    printf("data.i: %d\n", data.i);  // Output: data.i: 10
    data.f = 220.5;
    printf("data.f: %.2f\n", data.f);  // Output: data.f: 220.50
    // Now i is corrupted because f overwrote the same memory location
    printf("data.i after assigning f: %d\n", data.i);  // Output: garbage value
    strcpy(data.str, "C Programming");
    printf("data.str: %s\n", data.str);  // Output: data.str: C Programming
    // Size of union is the size of its largest member
    printf("Size of union Data: %lu bytes\n", sizeof(union Data));
    return 0;
}