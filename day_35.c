#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation for queue array
    int *queue = (int *)malloc(n * sizeof(int));

    int front = 0, rear = -1;

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);

        rear++;
        queue[rear] = value;   // Enqueue operation
    }

    printf("Queue elements:\n");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    free(queue);   // Free allocated memory

    return 0;
}
