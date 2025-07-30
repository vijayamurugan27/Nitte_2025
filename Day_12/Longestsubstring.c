// Problemno3 Longest substring with repeating characters.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the length of the longest substring without duplicate characters
int lengthOfLongestSubstring(char* s) {
  int maxLength = 0;
  int windowStart = 0;
  int* charIndex = (int*)calloc(256, sizeof(int)); // Assuming ASCII characters

  for (int windowEnd = 0; s[windowEnd] != '\0'; windowEnd++) {
    int rightChar = s[windowEnd];

    // If the character is already in the window, move the windowStart to the right of the previous occurrence
    if (charIndex[rightChar] > 0) {
      windowStart = (windowStart > charIndex[rightChar]) ? windowStart : charIndex[rightChar];
    }

    // Update the character index and maxLength
    charIndex[rightChar] = windowEnd + 1;
    maxLength = (maxLength > windowEnd - windowStart + 1) ? maxLength : windowEnd - windowStart + 1;
  }

  free(charIndex); // Don't forget to free the allocated memory
  return maxLength;
}

int main() {
  char* s = (char*)malloc(100 * sizeof(char)); // Allocate memory for the string
  printf("Enter a string: ");
  fgets(s, 100, stdin);
  s[strcspn(s, "\n")] = 0; // Remove the newline character

  int length = lengthOfLongestSubstring(s);
  printf("Length of the longest substring without duplicate characters: %d\n", length);

  free(s); // Don't forget to free the allocated memory
  return 0;
}