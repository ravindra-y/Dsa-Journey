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

  newNode->next = tail->next; // point to head
  tail->next = newNode;
  tail = newNode;
}

// Traverse function (your function)
void traverse(Node* tail) {
  if (!tail) return;

  Node* curr = tail->next; // start at head
  do {
    cout << curr->data << " -> ";
    curr = curr->next;
  } while (curr != tail->next);

  cout << "(back to head)\n";
}

// Main function
int main() {
  Node* tail = nullptr;

  insertEnd(tail, 10);
  insertEnd(tail, 20);
  insertEnd(tail, 30);
  insertEnd(tail, 40);

  cout << "Circular Linked List:\n";
  traverse(tail);

  return 0;
}