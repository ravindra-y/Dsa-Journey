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

  insertFront(tail, 10);
  insertFront(tail, 20);
  insertFront(tail, 30);
  insertFront(tail, 40);

  display(tail);

  return 0;
}