// problem number 64 : Minimum Path Sum


#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum sum path
int minSumPath(int** grid, int m, int n) {
  // Create a 2D table to store the minimum sum at each cell
  int** dp = (int**)malloc(m * sizeof(int*));
  for (int i = 0; i < m; i++) {
    dp[i] = (int*)malloc(n * sizeof(int));
  }

  // Initialize the first cell
  dp[0][0] = grid[0][0];

  // Fill the first row
  for (int j = 1; j < n; j++) {
    dp[0][j] = dp[0][j - 1] + grid[0][j];
  }

  // Fill the first column
  for (int i = 1; i < m; i++) {
    dp[i][0] = dp[i - 1][0] + grid[i][0];
  }

  // Fill the rest of the table
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = grid[i][j] + (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
    }
  }

  // The minimum sum path is stored in the bottom-right cell
  int minSum = dp[m - 1][n - 1];

  // Free the allocated memory
  for (int i = 0; i < m; i++) {
    free(dp[i]);
  }
  free(dp);

  return minSum;
}

int main() {
  int m, n;
  printf("Enter the number of rows: ");
  scanf("%d", &m);
  printf("Enter the number of columns: ");
  scanf("%d", &n);

  int** grid = (int**)malloc(m * sizeof(int*));
  for (int i = 0; i < m; i++) {
    grid[i] = (int*)malloc(n * sizeof(int));
  }

  printf("Enter the grid elements:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  int minSum = minSumPath(grid, m, n);
  printf("The minimum sum of a path from top left to bottom right: %d\n", minSum);

  // Free the allocated memory
  for (int i = 0; i < m; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}