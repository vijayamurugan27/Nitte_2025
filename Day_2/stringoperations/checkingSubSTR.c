#include <stdio.h>
#include <string.h>

int contains(const char *haystack, const char *needle) {
    return strstr(haystack, needle) != NULL;
}

int main() {
    char str[] = "Hello, World!";
    char *substr = "World";

    if (contains(str, substr)) {
        printf("String contains '%s'\n", substr);
    } else {
        printf("String does not contain '%s'\n", substr);
    }

    return 0;
}