#include <stdio.h>

int main() 
{
    int n, k, found = 0;
    int comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) 
    {scanf("%d", &a[i]); }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for(int i = 0; i < n; i++) 
    {   comparisons++;
        if(a[i] == k) 
        {  printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
    { printf("Not Found\n");}
    printf("Comparisons = %d", comparisons);

    return 0;
}
