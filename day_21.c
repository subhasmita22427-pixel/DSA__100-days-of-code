#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        // Read the integer value
        scanf("%d", &value);

        // Allocate memory for the new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            // First node becomes the head
            head = newNode;
            temp = head;
        } else {
            // Link the new node to the end of the list
            temp->next = newNode;
            temp = newNode; // Move temp to the new last node
        }
    }

    // Traversal: Print the linked list
    temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" "); // Print space between numbers
        }
        temp = temp->next;
    }

    // Free allocated memory (Good practice)
    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
