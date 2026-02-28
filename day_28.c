#include <stdio.h>
#include <stdlib.h>

// Structure of Circular Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

// Insert at end in Circular Linked List
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty
    if(head == NULL) {
        head = newNode;
        newNode->next = head;   // Point to itself
        return head;
    }

    struct Node* temp = head;

    // Traverse till last node
    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;   // Make circular

    return head;
}

// Traverse Circular Linked List
void traverse(struct Node* head) {
    if(head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);  // Stop when back to head
}

int main() {

    int n, value;
    struct Node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Circular Linked List: ");
    traverse(head);

    return 0;
}
