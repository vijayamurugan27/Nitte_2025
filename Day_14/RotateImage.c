// Problem number 48 Rotate Image

#include <stdio.h>
#include <stdlib.h>  // <-- You forgot this

void rotate(int** matrix, int n) {
  // Transpose the matrix
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }

  // Reverse each row
  for (int i = 0; i < n; i++) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
      int temp = matrix[i][left];
      matrix[i][left] = matrix[i][right];
      matrix[i][right] = temp;
      left++;
      right--;
    }
  }
}

int main() {
  int n;
  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  // Allocate memory
  int** matrix = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    matrix[i] = (int*)malloc(n * sizeof(int));
  }

  printf("Enter the matrix elements:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("Original matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  rotate(matrix, n);

  printf("Rotated matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
