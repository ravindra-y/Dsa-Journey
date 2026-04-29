#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Helper: insert node at tail
void insertAtTail(Node*& tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

// Sort function
Node* sortList(Node* head) {
    if (!head || !head->next) return head;

    // Dummy heads
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    // Split into 3 lists (FIXED PART)
    while (curr != nullptr) {
        Node* nextNode = curr->next; // store next
        curr->next = nullptr;        // break old link

        if (curr->data == 0) {
            insertAtTail(zeroTail, curr);
        } 
        else if (curr->data == 1) {
            insertAtTail(oneTail, curr);
        } 
        else {
            insertAtTail(twoTail, curr);
        }

        curr = nextNode;
    }

    // Merge lists
    if (oneHead->next != nullptr) {
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = nullptr;

    // New head
    Node* newHead = zeroHead->next;

    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    cout << "Before: ";
    printList(head);

    head = sortList(head);

    cout << "After: ";
    printList(head);

    return 0;
}