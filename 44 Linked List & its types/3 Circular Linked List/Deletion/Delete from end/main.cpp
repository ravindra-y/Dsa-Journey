#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node*& tail, int val) {
  Node* newNode = new Node(val);
  if (!tail) {
    newNode->next = newNode;
    tail = newNode;
    return;
  }
  newNode->next = tail->next; // new node's next = head
  tail->next = newNode;       // old tail links to new node
  tail = newNode;             // advance tail
}

void deleteEnd(Node*& tail) {
  if (!tail) return;
  if (tail->next == tail) { // only one node
    delete tail;
    tail = nullptr;
    return;
  }
  Node* curr = tail->next; // start at head
  while (curr->next != tail)
    curr = curr->next;     // find node before tail
  curr->next = tail->next; // second-to-last now points to head
  delete tail;
  tail = curr; // update tail
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

  insertEnd(tail, 30);
  insertEnd(tail, 20);
  insertEnd(tail, 10);
  insertEnd(tail, 5);

  display(tail);
  deleteEnd(tail);
  display(tail);

  return 0;
}