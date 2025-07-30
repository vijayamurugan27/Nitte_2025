// problem no 38 Count and say

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 500  // Allocate sufficient space for intermediate strings

// Function to perform run-length encoding
void runLengthEncode(const char* input, char* output) {
    int i = 0, j = 0;
    int len = strlen(input);

    while (i < len) {
        char current = input[i];
        int count = 1;

        // Count repeating characters
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Append count and character to output
        j += sprintf(output + j, "%d%c", count, current);
        i++;
    }

    output[j] = '\0'; // Null-terminate the string
}

// Function to get the nth count-and-say number
char* countAndSay(int n) {
    if (n <= 0 || n > 30) return NULL;

    char* current = (char*)malloc(MAX_LEN);
    char* next = (char*)malloc(MAX_LEN);
    strcpy(current, "1");

    for (int i = 1; i < n; i++) {
        runLengthEncode(current, next);

        // Swap pointers
        char* temp = current;
        current = next;
        next = temp;
    }

    free(next); // Only one buffer is needed at the end
    return current;
}

int main() {
    int n;
    printf("Enter a number (1 to 30): ");
    scanf("%d", &n);

    if (n < 1 || n > 30) {
        printf("Invalid input. Please enter a number between 1 and 30.\n");
        return 1;
    }

    char* result = countAndSay(n);
    printf("The %dth element of the count-and-say sequence: %s\n", n, result);

    free(result);
    return 0;
}
