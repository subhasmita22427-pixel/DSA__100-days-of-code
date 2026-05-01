#include <stdio.h>

int integerSquareRoot(int n) {
    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // To avoid overflow
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        }
        else if (square < n) {
            ans = mid;      // Store possible answer
            low = mid + 1;  // Search in right half
        }
        else {
            high = mid - 1; // Search in left half
        }
    }

    return ans;
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    printf("Integer square root: %d\n", integerSquareRoot(n));

    return 0;
}
