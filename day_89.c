#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int books[], int n, int m, int maxPages) {

    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {

        // If a single book has more pages than maxPages
        if (books[i] > maxPages) {
            return 0;
        }

        if (pagesSum + books[i] <= maxPages) {

            pagesSum += books[i];
        }
        else {

            students++;
            pagesSum = books[i];

            if (students > m) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to find minimum possible maximum pages
int allocateBooks(int books[], int n, int m) {

    int low = 0;
    int high = 0;
    int ans = -1;

    // Calculate total pages
    for (int i = 0; i < n; i++) {
        high += books[i];
    }

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(books, n, m, mid)) {

            ans = mid;
            high = mid - 1; // Try smaller maximum
        }
        else {

            low = mid + 1; // Increase limit
        }
    }

    return ans;
}

int main() {

    int n, m;

    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int books[n];

    printf("Enter pages in books: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    int result = allocateBooks(books, n, m);

    printf("Minimum possible maximum pages = %d\n", result);

    return 0;
}
