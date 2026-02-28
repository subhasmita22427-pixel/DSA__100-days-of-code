#include <stdio.h>
#include <stdlib.h>

// Define structure for Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    return newNode;
}

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    // If list is empty
    if(head == NULL) {
        return newNode;
    }
    
    struct Node* temp = head;
    
    // Traverse to last node
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    // Insert at end
    temp->next = newNode;
    newNode->prev = temp;
    
    return head;
}

// Function to traverse and print list (forward)
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
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
    
    printf("Linked List (Forward): ");
    traverseForward(head);
    
    return 0;
}
