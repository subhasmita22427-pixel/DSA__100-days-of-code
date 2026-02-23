#include <iostream>

using namespace std;

// Define the Linked List Node
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert at the end of the list
void insert(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to merge two sorted lists
Node* mergeLists(Node* head1, Node* head2) {
    // Dummy node to simplify edge cases
    Node dummy(0);
    Node* tail = &dummy;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (head1) tail->next = head1;
    if (head2) tail->next = head2;

    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << (head->next ? " " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, m, val;
    Node *head1 = nullptr, *tail1 = nullptr;
    Node *head2 = nullptr, *tail2 = nullptr;

    // Input List 1
    if (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> val;
            insert(head1, tail1, val);
        }
    }

    // Input List 2
    if (cin >> m) {
        for (int i = 0; i < m; i++) {
            cin >> val;
            insert(head2, tail2, val);
        }
    }

    // Merge and Print
    Node* mergedHead = mergeLists(head1, head2);
    printList(mergedHead);

    return 0;
}
