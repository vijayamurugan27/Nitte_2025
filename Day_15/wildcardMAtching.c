// Problem number 44: Wildcard Matching

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  // Don't forget this for `bool` in C

bool isMatch(char* s, char* p) {
  int m = strlen(s);
  int n = strlen(p);

  // Allocate DP table
  bool** dp = (bool**)malloc((m + 1) * sizeof(bool*));
  for (int i = 0; i <= m; i++) {
    dp[i] = (bool*)malloc((n + 1) * sizeof(bool));
    for (int j = 0; j <= n; j++) {
      dp[i][j] = false;  // Initialize all cells to false
    }
  }

  dp[0][0] = true;

  // Only * can match empty string
  for (int j = 1; j <= n; j++) {
    if (p[j - 1] == '*') {
      dp[0][j] = dp[0][j - 1];
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (p[j - 1] == '*') {
        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
      } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      }
    }
  }

  bool res = dp[m][n];

  // Free allocated memory
  for (int i = 0; i <= m; i++) {
    free(dp[i]);
  }
  free(dp);

  return res;
}

int main() {
  char s[100];
  char p[100];

  printf("Enter input string: ");
  scanf("%s", s);
  printf("Enter pattern: ");
  scanf("%s", p);

  if (isMatch(s, p)) {
    printf("The input string is matched by the pattern.\n");
  } else {
    printf("The input string is NOT matched by the pattern.\n");
  }

  return 0;
}
