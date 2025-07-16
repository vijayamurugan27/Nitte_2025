// Variadic Functions (Variable Arguments)

#include <stdio.h>
#include <stdarg.h>

double average(int count, ...) {
    va_list ap;
    double sum = 0;
    
    va_start(ap, count);
    for (int i = 0; i < count; i++) {
        sum += va_arg(ap, int);
    }
    va_end(ap);
    
    return sum / count;
}

int main() {
    printf("Average: %.2f\n", average(3, 10, 20, 30));
    printf("Average: %.2f\n", average(5, 1, 2, 3, 4, 5));
    return 0;
}