#include <stdio.h>

// Function to find maximum board length
int findMax(int boards[], int n) {

    int max = boards[0];

    for (int i = 1; i < n; i++) {
        if (boards[i] > max) {
            max = boards[i];
        }
    }

    return max;
}

// Function to find total sum of board lengths
int findSum(int boards[], int n) {

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += boards[i];
    }

    return sum;
}

// Check how many painters are needed
int paintersRequired(int boards[], int n, int maxTime) {

    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {

        if (currentTime + boards[i] <= maxTime) {

            currentTime += boards[i];
        }
        else {

            painters++;
            currentTime = boards[i];
        }
    }

    return painters;
}

// Function to find minimum painting time
int painterPartition(int boards[], int n, int k) {

    int low = findMax(boards, n);
    int high = findSum(boards, n);
    int ans = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int requiredPainters = paintersRequired(boards, n, mid);

        if (requiredPainters <= k) {

            ans = mid;
            high = mid - 1; // Try smaller maximum time
        }
        else {

            low = mid + 1; // Increase allowed time
        }
    }

    return ans;
}

int main() {

    int n, k;

    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];

    printf("Enter board lengths: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int result = painterPartition(boards, n, k);

    printf("Minimum time required = %d\n", result);

    return 0;
}
