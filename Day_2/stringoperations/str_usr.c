#include <stdio.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    printf("You entered: %s\n", input);

    return 0;
}