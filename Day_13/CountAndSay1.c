#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to perform count-and-say on a digit string
void countAndSayDigits(const char* input, char* output) {
    int i = 0, j = 0;
    int len = strlen(input);

    while (i < len) {
        char digit = input[i];
        int count = 1;

        // Count consecutive same digits
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Append count and digit to output
        j += sprintf(output + j, "%d%c", count, digit);
        i++;
    }

    output[j] = '\0';  // Null-terminate
}

int main() {
    char input[MAX_LEN];
    char output[MAX_LEN * 2]; // Result can be longer than input

    printf("Enter a number: ");
    scanf("%s", input);

    countAndSayDigits(input, output);

    printf("Count-and-Say value: %s\n", output);

    return 0;
}
