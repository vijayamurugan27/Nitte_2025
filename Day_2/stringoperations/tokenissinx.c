#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello,World,in,C";
    char *token;

    // First call to strtok requires the string to tokenize
    token = strtok(str, ",");
    while(token != NULL) {
        printf("%s\n", token);

        // Subsequent calls should be with NULL
        token = strtok(NULL, ",");
    }

    return 0;
}