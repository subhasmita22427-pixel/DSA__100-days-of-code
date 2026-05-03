#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    int index;
};

void merge(struct Node arr[],
           int left,
           int mid,
           int right,
           int count[]) {

    int n = right - left + 1;

    struct Node temp[n];

    int i = left;
    int j = mid + 1;
    int k = 0;

    int rightCount = 0;

    while (i <= mid && j <= right) {

        if (arr[i].value > arr[j].value) {

            // Right element smaller
            rightCount++;

            temp[k++] = arr[j++];
        }
        else {

            count[arr[i].index] += rightCount;

            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {

        count[arr[i].index] += rightCount;

        temp[k++] = arr[i++];
    }

    while (j <= right) {

        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = left; i <= right; i++) {

        arr[i] = temp[i - left];
    }
}

void mergeSort(struct Node arr[],
               int left,
               int right,
               int count[]) {

    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);

    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int main() {

    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];
    struct Node arr[n];
    int count[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d", &nums[i]);

        arr[i].value = nums[i];
        arr[i].index = i;

        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Counts of smaller elements on right:\n");

    for (int i = 0; i < n; i++) {

        printf("%d ", count[i]);
    }

    return 0;
}
