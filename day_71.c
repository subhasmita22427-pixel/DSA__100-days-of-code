#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hashFunction(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hashFunction(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table is full\n");
}

void search(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hashFunction(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char operation[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s", operation);
        scanf("%d", &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            search(table, m, key);
        }
    }

    return 0;
}
