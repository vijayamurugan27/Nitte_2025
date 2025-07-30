#include <stdio.h>

// Function to check if a number is a palindrome
int isPalindrome(int x) {
  if (x < 0) {
    return 0; // Negative numbers are not palindromes
  }

  int original = x;
  int reversed = 0;

  while (x != 0) {
    int remainder = x % 10;
    reversed = reversed * 10 + remainder;
    x /= 10;
  }

  return (original == reversed);
}

int main() {
  int x;
  printf("Enter an integer: ");
  scanf("%d", &x);

  if (isPalindrome(x)) {
    printf("%d is a palindrome.\n", x);
  } else {
    printf("%d is not a palindrome.\n", x);
  }

  return 0;
}