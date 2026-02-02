#include<stdio.h>
int main()
{
    int n , pos;
    printf("enter size of array:\n ");
    scanf("%d", &n);

    int a[n];
     printf("enter elements of array :\n");
  for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

printf("enter position from where you want to delete element from array:\n");
scanf("%d",&pos);

for (int i = pos -1;i<n;i++)
{ a[i] = a [i+1];}

for (int i = 0 ; i <n ; i ++)
{printf("%d ", a[i]);}

return 0;
}
