// problem number 58: Length of Last Word


#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
  int n = strlen(s);
  int i = n - 1;

  // Find the start of the last word
  while (i >= 0 && s[i] == ' ') {
    i--;
  }

  // Find the end of the last word
  int end = i;
  while (i >= 0 && s[i] != ' ') {
    i--;
  }

  return end - i;
}

int main() {
  char s[100];
  printf("Enter a string: ");
  fgets(s, 100, stdin);
  s[strcspn(s, "\n")] = 0; // Remove the newline character at the end of the string
  printf("The length of the last word is: %d\n", lengthOfLastWord(s));
  return 0;
}