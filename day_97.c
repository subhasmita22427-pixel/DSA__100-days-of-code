#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heap Insert
void heapInsert(int heap[], int *size, int value) {

    int i = (*size)++;
    heap[i] = value;

    while (i > 0) {

        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i])
            break;

        swap(&heap[parent], &heap[i]);

        i = parent;
    }
}

// Min Heap Remove
void heapRemove(int heap[], int *size) {

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {

        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;

        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);

        i = smallest;
    }
}

int minMeetingRooms(int intervals[][2], int n) {

    // Sort by start time
    qsort(intervals, n, sizeof(intervals[0]), compare);

    int heap[n];
    int heapSize = 0;

    // First meeting
    heapInsert(heap, &heapSize, intervals[0][1]);

    for (int i = 1; i < n; i++) {

        int start = intervals[i][0];
        int end = intervals[i][1];

        // Reuse room
        if (start >= heap[0]) {
            heapRemove(heap, &heapSize);
        }

        // Add current meeting end time
        heapInsert(heap, &heapSize, end);
    }

    return heapSize;
}

int main() {

    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int intervals[n][2];

    printf("Enter start and end times:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    int ans = minMeetingRooms(intervals, n);

    printf("Minimum meeting rooms required = %d\n", ans);

    return 0;
}
