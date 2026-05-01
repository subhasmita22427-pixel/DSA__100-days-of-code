#include <stdio.h>
#include <stdlib.h>

// Function to compare elements for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Check if cows can be placed with minimum distance = dist
int canPlaceCows(int stalls[], int n, int k, int dist) {

    int count = 1; // First cow placed in first stall
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++) {

        if (stalls[i] - lastPosition >= dist) {

            count++;
            lastPosition = stalls[i];
        }

        if (count >= k) {
            return 1;
        }
    }

    return 0;
}

// Function to find maximum minimum distance
int aggressiveCows(int stalls[], int n, int k) {

    // Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {

            ans = mid;
            low = mid + 1; // Try for larger distance
        }
        else {

            high = mid - 1; // Reduce distance
        }
    }

    return ans;
}

int main() {

    int n, k;

    printf("Enter number of stalls and cows: ");
    scanf("%d %d", &n, &k);

    int stalls[n];

    printf("Enter stall positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    int result = aggressiveCows(stalls, n, k);

    printf("Maximum minimum distance = %d\n", result);

    return 0;
}
