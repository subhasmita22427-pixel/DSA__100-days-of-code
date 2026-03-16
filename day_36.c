#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;

    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));

    int front = 0, rear = -1;

    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);

        rear = (rear + 1) % n;
        queue[rear] = value;
    }

    scanf("%d", &m);

    // Dequeue operations
    for(int i = 0; i < m; i++)
    {
        front = (front + 1) % n;
    }

    // Display queue elements
    int count = n;
    int index = front;

    for(int i = 0; i < count; i++)
    {
        printf("%d ", queue[index]);
        index = (index + 1) % n;
    }

    free(queue);

    return 0;
}
