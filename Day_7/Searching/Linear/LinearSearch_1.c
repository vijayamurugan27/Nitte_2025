#include <stdio.h>
#include <math.h>

int JumpSearch(int arr[], int n, int jump, int target) 
{
 int start =0, end = jump;

 while (end < n) 
 {
 if (arr[end] < target) 
 {
 start = end;
 end = end + jump;
 }
 else 
 {
 while (start <= end && start < n) 
 {
 if (arr[start] == target) 
 return start;
 start++;
 }
 return -1;
 }
 }

 // Final block linear search (if not already found)
 while (start < n) 
 {
 if (arr[start] == target) 
 return start;
 start++;
 }

 return -1;
}

int main() 
{
 int target, n, jump, option;
 int arr[] = {1,2,3,4,5,6,7,8,9,10};
 n = sizeof(arr) / sizeof(arr[0]);
 jump = (int)sqrt(n);

 char cont = 'y';
 
 do 
 {
 printf("\nMenu:\n");
 printf("1. Search for an element\n");
 printf("2. Display array\n");
 printf("3. Exit\n");
 printf("Enter your option: ");
 scanf("%d", &option);

 switch (option) 
 {
 case 1:
 printf("Enter the element to search: ");
 scanf("%d", &target);

 int index = JumpSearch(arr, n, jump, target);

 if (index == -1) 
 printf("Element not found\n");
 else 
 printf("Element found at index %d\n", index +1);
 break;

 case 2:
 printf("Array: ");
 for (int i =0; i < n; i++)
 printf("%d ", arr[i]);
 printf("\n");
 break;

 case 3:
 printf("Exiting program...\n");
 cont = 'n';
 break;

 default:
 printf("Invalid option. Please try again.\n");
 }
 
 } 
 while (cont == 'y' || cont == 'Y' || cont == 'y');

 return 0;
}