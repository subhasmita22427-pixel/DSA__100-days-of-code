#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // Simple hash map using arrays
    int hash[20001];  // range for prefix sum (-10000 to 10000)
    for (int i = 0; i < 20001; i++) {
        hash[i] = -2;  // -2 means not seen
    }

    // Important: prefix sum = 0 at index -1
    hash[10000] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = prefixSum + 10000;

        if (hash[index] != -2) {
            int len = i - hash[index];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[index] = i;
        }
    }

    printf("%d\n", maxLen);
    return 0;
}
