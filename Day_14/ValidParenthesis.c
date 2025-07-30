// problem number 20 Valid Parenthesis

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for stack
typedef struct {
  char* stack;
  int top;
  int capacity;
} Stack;

// Function to create a stack
Stack* createStack() {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->stack = (char*)malloc(MAX * sizeof(char));
  stack->top = -1;
  stack->capacity = MAX;
  return stack;
}

// Function to push an element on the stack
void push(Stack* stack, char c) {
  stack->stack[++stack->top] = c;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
  if (stack->top == -1) {
    return '\0';
  }
  return stack->stack[stack->top--];
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
  return stack->top == -1;
}

// Function to check if the string is valid
int isValid(char* s) {
  Stack* stack = createStack();

  for (int i = 0; i < strlen(s); i++) {
    char c = s[i];

    switch (c) {
      case '(':
      case '[':
      case '{':
        push(stack, c);
        break;
      case ')':
        if (isEmpty(stack) || pop(stack) != '(') {
          free(stack->stack);
          free(stack);
          return 0;
        }
        break;
      case ']':
        if (isEmpty(stack) || pop(stack) != '[') {
          free(stack->stack);
          free(stack);
          return 0;
        }
        break;
      case '}':
        if (isEmpty(stack) || pop(stack) != '{') {
          free(stack->stack);
          free(stack);
          return 0;
        }
        break;
      default:
        break;
    }
  }

  free(stack->stack);
  free(stack);

  return isEmpty(stack);
}

int main() {
  char s[100];
  printf("Enter a string: ");
  scanf("%s", s);

  int result = isValid(s);
  printf("The string is %svalid\n", result ? "" : "not ");

  return 0;
}