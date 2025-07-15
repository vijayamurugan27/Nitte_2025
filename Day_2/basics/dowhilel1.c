#include <stdio.h>

int main(){
    int num;
    do{
        printf("Enter a number between 1 to 10 : ");
        scanf("%d",&num);
    } while (num<1 || num>10);

    return 0;
}
