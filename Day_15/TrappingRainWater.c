// Problem number 42: Trapping Rain Water using Two Pointers

#include <stdio.h>
#include <stdlib.h>

int trap(int* height, int n) {
  int* leftMax = (int*)malloc(n * sizeof(int));
  int* rightMax = (int*)malloc(n * sizeof(int));

  // Compute the left max height
  leftMax[0] = height[0];
  for (int i = 1; i < n; i++) {
    leftMax[i] = (leftMax[i - 1] > height[i]) ? leftMax[i - 1] : height[i];
  }

  // Compute the right max height
  rightMax[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    rightMax[i] = (rightMax[i + 1] > height[i]) ? rightMax[i + 1] : height[i];
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res += ((leftMax[i] > rightMax[i]) ? rightMax[i] : leftMax[i]) > height[i] ? ((leftMax[i] > rightMax[i]) ? rightMax[i] : leftMax[i]) - height[i] : 0;
  }

  free(leftMax);
  free(rightMax);

  return res;
}

int main() {
  int n;
  printf("Enter the number of bars: ");
  scanf("%d", &n);

  int* height = (int*)malloc(n * sizeof(int));
  printf("Enter the height of each bar:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &height[i]);
  }

  printf("The amount of water that can be trapped: %d\n", trap(height, n));

  free(height);

  return 0;
}