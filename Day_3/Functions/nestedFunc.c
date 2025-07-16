#include <stdio.h>

int main() {
    // Nested function (GCC extension, not standard C)
    void sayHello() {
        printf("Hello from nested function!\n");
    }
    
    sayHello();
    return 0;
}