#include <stdio.h>
#include <stdlib.h> // For exit() function

int main() {
    FILE *filePointer;
    char textToWrite[100];
    char textRead[100];

    // Writing to the file
    printf("Writing to hello.txt...\n");
    
    filePointer = fopen("hello.txt", "w"); // Open file for writing
    
    if (filePointer == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }
    
    printf("Enter text to write to file: ");
    fgets(textToWrite, sizeof(textToWrite), stdin); // Read input from user
    
    fprintf(filePointer, "%s", textToWrite); // Write to file
    fclose(filePointer); // Close the file
    
    printf("Text written to hello.txt successfully!\n\n");
    
    // Reading from the file
    printf("Reading from hello.txt...\n");
    
    filePointer = fopen("hello.txt", "r"); // Open file for reading
    
    if (filePointer == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }
    
    printf("File contents:\n");
    
    // Read and print file contents line by line
    while (fgets(textRead, sizeof(textRead), filePointer) != NULL) {
        printf("%s", textRead);
    }
    
    fclose(filePointer); // Close the file
    
    return 0;
}