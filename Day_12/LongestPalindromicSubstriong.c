// 5. Longest palindromic substring.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
  int n = strlen(s);

  // Create a 2D table to store the lengths of palindromic substrings
  int** dp = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    dp[i] = (int*)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      dp[i][j] = 0;
    }
  }

  int start = 0, maxLen = 1;

  // All substrings with one character are palindromes
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }

  // Check for substring of length 2
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = 2;
      start = i;
      maxLen = 2;
    } else {
      dp[i][i + 1] = 1;
    }
  }

  // Check for lengths greater than 2
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      if (dp[i + 1][j - 1] && s[i] == s[j]) {
        dp[i][j] = dp[i + 1][j - 1] + 2;
        if (dp[i][j] > maxLen) {
          maxLen = dp[i][j];
          start = i;
        }
      }
    }
  }

  // Allocate memory for the longest palindromic substring
  char* palind = (char*)malloc(maxLen + 1);
  strncpy(palind, s + start, maxLen);
  palind[maxLen] = '\0';

  // Free the allocated memory for the dp table
  for (int i = 0; i < n; i++) {
    free(dp[i]);
  }
  free(dp);

  return palind;
}

int main() {
  char s[100];
  printf("Enter a string: ");
  fgets(s, 100, stdin);
  s[strcspn(s, "\n")] = 0; // Remove the newline character

  char* palind = longestPalindrome(s);
  printf("Longest palindromic substring: %s\n", palind);

  free(palind);
  return 0;
}