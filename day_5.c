#include <stdio.h>

int main() {
    int p, q;
    int i = 0, j = 0, k = 0;
    int a[100], b[100], c[200];

    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    printf("Enter %d sorted arrival times for server log 1:\n", p);
    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    printf("Enter %d sorted arrival times for server log 2:\n", q);
    for (i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < p) {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < q) {
        c[k] = b[j];
        j++;
        k++;
    }

    printf("Merged chronological log:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
