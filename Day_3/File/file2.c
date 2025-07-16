#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;
    char text[100];
    
    // Writing to a file
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    fprintf(fp, "Hello, File Operations!\n");
    fputs("This is a line of text.\n", fp);
    fclose(fp);
    
    // Reading from a file
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }
    
    printf("File contents:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    rewind(fp); // Go back to start
    
    printf("\nReading line by line:\n");
    while (fgets(text, sizeof(text), fp) != NULL) {
        printf("%s", text);
    }
    fclose(fp);
    
    // Binary file operations
    struct Data {
        int id;
        float value;
    } data = {1, 3.14}, readData;
    
    fp = fopen("data.bin", "wb");
    fwrite(&data, sizeof(struct Data), 1, fp);
    fclose(fp);
    
    fp = fopen("data.bin", "rb");
    fread(&readData, sizeof(struct Data), 1, fp);
    printf("\nRead from binary file: %d, %.2f\n", readData.id, readData.value);
    fclose(fp);
    
    // File positioning
    fp = fopen("example.txt", "r");
    fseek(fp, 6, SEEK_SET);
    fgets(text, 5, fp);
    printf("Text from position 6: %s\n", text);
    fclose(fp);
    
    return 0;
}