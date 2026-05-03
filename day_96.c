#include <stdio.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;      // left subarray
    int j = mid + 1;   // right subarray
    int k = left;
    int inv_count = 0;

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            // Count inversions
            inv_count = inv_count + (mid - i + 1);
        }
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right) {

    int mid, inv_count = 0;

    if (left < right) {

        mid = (left + right) / 2;

        // Left subarray
        inv_count += mergeSort(arr, temp, left, mid);

        // Right subarray
        inv_count += mergeSort(arr, temp, mid + 1, right);

        // Merge and count inversions
        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int inversions = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions = %d\n", inversions);

    return 0;
}
