// problem no 14 Longest Common Prefix


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
  if (strsSize == 0) {
    char* result = (char*)malloc(sizeof(char));
    result[0] = '\0';
    return result;
  }

  int len = strlen(strs[0]);
  for (int i = 1; i < strsSize; i++) {
    int currentLen = strlen(strs[i]);
    if (currentLen < len) len = currentLen;
  }

  char* result = (char*)malloc(len + 1);
  if (!result) return NULL;
  result[len] = '\0';

  for (int i = 0; i < len; i++) {
    char ch = strs[0][i];
    for (int j = 1; j < strsSize; j++) {
      if (strs[j][i] != ch) {
        result[i] = '\0';
        return result;
      }
    }
    result[i] = ch;
  }

  return result;
}

int main() {
  int strsSize;
  printf("Enter the number of strings: ");
  scanf("%d", &strsSize);

  char** strs = (char**)malloc(strsSize * sizeof(char*));
  if (!strs) return 1;

  printf("Enter %d strings:\n", strsSize);
  for (int i = 0; i < strsSize; i++) {
    strs[i] = (char*)malloc(200 * sizeof(char));
    if (!strs[i]) return 1;
    scanf("%199s", strs[i]);
  }

  char* prefix = longestCommonPrefix(strs, strsSize);
  printf("The longest common prefix is: %s\n", prefix);

  free(prefix);
  for (int i = 0; i < strsSize; i++) {
    free(strs[i]);
  }
  free(strs);

  return 0;
}
