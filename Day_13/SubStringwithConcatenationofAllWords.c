// problemno 30 Substring with Concatenation of All Words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMatch(char* str, char** words, int wordsSize, int wordLen) {
    int* used = (int*)calloc(wordsSize, sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        int found = 0;
        for (int j = 0; j < wordsSize; j++) {
            if (!used[j] && strncmp(str + i * wordLen, words[j], wordLen) == 0) {
                used[j] = 1;
                found = 1;
                break;
            }
        }
        if (!found) {
            free(used);
            return 0;
        }
    }
    free(used);
    return 1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int sLen = strlen(s);
    int wordLen = strlen(words[0]);
    int totalLen = wordLen * wordsSize;
    int* result = (int*)malloc(sizeof(int) * sLen);
    *returnSize = 0;

    for (int i = 0; i <= sLen - totalLen; i++) {
        if (isMatch(s + i, words, wordsSize, wordLen)) {
            result[(*returnSize)++] = i;
        }
    }

    return result;
}

int main() {
    char s[100];
    printf("Enter the main string: ");
    scanf("%s", s);

    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char** words = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        words[i] = (char*)malloc(100);
        scanf("%s", words[i]);
    }

    int returnSize = 0;
    int* indices = findSubstring(s, words, n, &returnSize);

    printf("Output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);
    free(indices);

    return 0;
}
