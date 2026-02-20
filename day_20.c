#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // For simplicity (assuming values not extremely large)
    // Using dynamic array to store prefix frequency
    int size = 2 * n + 1;
    int offset = n; 
    int *freq = (int*)calloc(size, sizeof(int));

    freq[offset] = 1;  // prefixSum = 0 initially

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(freq[prefixSum + offset] > 0) {
            count += freq[prefixSum + offset];
        }

        freq[prefixSum + offset]++;
    }

    printf("%d", count);

    free(freq);
    return 0;
}
