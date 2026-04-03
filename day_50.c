#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Creating node with value %d\n", value);
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// BST Insert (to build tree)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// BST Search
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0; // Not found
    }

    if (root->data == key) {
        return 1; // Found
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    if (search(root, key)) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }

    return 0;
}
