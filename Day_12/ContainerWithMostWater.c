// 11 problem with the most water

#include <stdio.h>

int maxArea(int* height, int n) {
  int left = 0;
  int right = n - 1;
  int maxArea = 0;

  while (left < right) {
    // Calculate the width of the current area
    int width = right - left;

    // Calculate the height of the current area
    int minHeight = height[left] < height[right] ? height[left] : height[right];
    int area = width * minHeight;

    // Update the maximum area
    if (area > maxArea) {
      maxArea = area;
    }

    // Move the pointer with the smaller height towards the other pointer
    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }

  return maxArea;
}

int main() {
  int height[] = {1,8,6,2,5,4,8,3,7};
  int n = sizeof(height) / sizeof(height[0]);
  printf("Maximum area: %d\n", maxArea(height, n));

  return 0;
}