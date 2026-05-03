#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {

    return ((int*)a)[0] - ((int*)b)[0];
}

void mergeIntervals(int intervals[][2], int n) {

    // Sort intervals by start time
    qsort(intervals, n, sizeof(intervals[0]), compare);

    int merged[n][2];
    int index = 0;

    // First interval
    merged[0][0] = intervals[0][0];
    merged[0][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {

        // Overlapping interval
        if (intervals[i][0] <= merged[index][1]) {

            // Update ending time
            if (intervals[i][1] > merged[index][1]) {
                merged[index][1] = intervals[i][1];
            }
        }
        else {

            // Move to next interval
            index++;

            merged[index][0] = intervals[i][0];
            merged[index][1] = intervals[i][1];
        }
    }

    // Print merged intervals
    printf("Merged Intervals:\n");

    for (int i = 0; i <= index; i++) {

        printf("[%d, %d]\n", merged[i][0], merged[i][1]);
    }
}

int main() {

    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int intervals[n][2];

    printf("Enter intervals (start end):\n");

    for (int i = 0; i < n; i++) {

        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    mergeIntervals(intervals, n);

    return 0;
}
