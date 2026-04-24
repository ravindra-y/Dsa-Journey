#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

// Insert at end
void insertEnd(Node*& tail, int val) {
  Node* newNode = new Node(val);

  if (!tail) {
    newNode->next = newNode;
    tail = newNode;
    return;
  }

  newNode->next = tail->next;
  tail->next = newNode;
  tail = newNode;
}

// Traverse function
void traverse(Node* tail) {
  if (!tail) {
    cout << "List is empty\n";
    return;
  }

  Node* curr = tail->next;
  do {
    cout << curr->data << " -> ";
    curr = curr->next;
  } while (curr != tail->next);

  cout << "(back to head)\n";
}

// Split function (your logic)
void splitList(Node* tail, Node*& tail1, Node*& tail2) {
  if (!tail || tail->next == tail) {
    tail1 = tail;
    tail2 = nullptr;
    return;
  }

  Node* head = tail->next;
  Node* slow = head;
  Node* fast = head;

  // Move fast by 2 and slow by 1
  while (fast->next != head && fast->next->next != head) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // For even number of nodes
  if (fast->next->next == head) fast = fast->next;

  // Set tails
  tail1 = slow;
  tail2 = fast;

  // Make two circular lists
  tail1->next = head;
  tail2->next = slow->next;
}

// Main function
int main() {
  Node* tail = nullptr;

  insertEnd(tail, 10);
  insertEnd(tail, 20);
  insertEnd(tail, 30);
  insertEnd(tail, 40);
  insertEnd(tail, 50);

  cout << "Original List:\n";
  traverse(tail);

  Node* tail1 = nullptr;
  Node* tail2 = nullptr;

  splitList(tail, tail1, tail2);

  cout << "\nFirst Half:\n";
  traverse(tail1);

  cout << "\nSecond Half:\n";
  traverse(tail2);

  return 0;
}