#include <stdio.h>

int main() 
{
    int n, pos, x;
    int a[100];
    printf("enter lenght of array  :");
    scanf("%d", &n);
    printf("enter the array:");
    for(int i = 0; i < n; i++) 
    { scanf("%d", &a[i]);}
    printf("enter the position where element is to be inserted :");
    scanf("%d", &pos);
    printf("enter the element to be inserted :");
    scanf("%d", &x);
    for(int i = n; i >= pos; i--) 
    { a[i] = a[i - 1];}

    a[pos - 1] = x;

    for(int i = 0; i <= n; i++) 
    { printf("%d ", a[i]);}

    return 0;
}
