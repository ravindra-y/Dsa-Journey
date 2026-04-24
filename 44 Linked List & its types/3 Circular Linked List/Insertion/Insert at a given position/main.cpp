#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

void insertFront(Node*& tail, int val) {
  Node* newNode = new Node(val);
  if (!tail) {
    newNode->next = newNode;
    tail = newNode;
    return;
  }
  newNode->next = tail->next;
  tail->next = newNode;
}

void insertAt(Node*& tail, int val, int pos) {
  if (!tail || pos == 0) {
    insertFront(tail, val);
    return;
  }

  Node* curr = tail->next; // start at head

  for (int i = 0; i < pos - 1; i++) {
    curr = curr->next;
    if (curr == tail->next) return; // out of bounds
  }
  
  Node* newNode = new Node(val);
  newNode->next = curr->next;
  curr->next = newNode;
  if (curr == tail) tail = newNode; // if inserted after tail, update tail
}

void display(Node* tail) {
  if (!tail) {
    cout << "List is empty.\n";
    return;
  }
  Node* curr = tail->next; // start from head
  do {
    cout << curr->data << " -> ";
    curr = curr->next;
  } while (curr != tail->next);
  cout << "(head)\n";
}

int main() {
  Node* tail = nullptr;

  insertFront(tail, 30);
  insertFront(tail, 20);
  insertFront(tail, 10);
  insertFront(tail, 5);

  display(tail); // 5 -> 10 -> 20 -> 30 -> (head)

  return 0;
}