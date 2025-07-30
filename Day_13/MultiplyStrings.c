// problemno43: Multiply Strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char* zero = (char*)malloc(2);
        strcpy(zero, "0");
        return zero;
    }

    int* result = (int*)calloc(len1 + len2, sizeof(int));

    // Multiply digits from right to left
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int pos1 = i + j;
            int pos2 = i + j + 1;

            int sum = mul + result[pos2];
            result[pos2] = sum % 10;
            result[pos1] += sum / 10;
        }
    }

    // Convert the result array to string
    char* resStr = (char*)malloc(len1 + len2 + 1);
    int index = 0;
    int started = 0;
    for (int i = 0; i < len1 + len2; i++) {
        if (!started && result[i] == 0) continue;
        started = 1;
        resStr[index++] = result[i] + '0';
    }
    resStr[index] = '\0';

    free(result);
    return resStr;
}

int main() {
    char num1[201], num2[201];
    printf("Enter first number: ");
    scanf("%s", num1);
    printf("Enter second number: ");
    scanf("%s", num2);

    char* product = multiply(num1, num2);
    printf("Product: %s\n", product);

    free(product);
    return 0;
}
