// 14 Longest Common prefix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int n) {
  if (n <= 0) {
    return "";
  }

  int minLen = strlen(strs[0]);
  for (int i = 1; i < n; i++) {
    int len = strlen(strs[i]);
    if (len < minLen) {
      minLen = len;
    }
  }

  char* prefix = (char*)malloc(minLen + 1);
  for (int i = 0; i < minLen; i++) {
    if (strs[0][i] != strs[1][i]) {
      prefix[i] = '\0';
      break;
    }
    prefix[i] = strs[0][i];
  }
  prefix[minLen] = '\0';

  for (int i = 2; i < n; i++) {
    for (int j = 0; j < minLen; j++) {
      if (strs[i][j] != prefix[j]) {
        prefix[j] = '\0';
        break;
      }
    }
  }

  return prefix;
}

int main() {
  char* strs[] = {"flower","flow","flight"};
  int n = sizeof(strs) / sizeof(strs[0]);
  char* prefix = longestCommonPrefix(strs, n);
  printf("Longest common prefix: %s\n", prefix);

  free(prefix);
  return 0;
}