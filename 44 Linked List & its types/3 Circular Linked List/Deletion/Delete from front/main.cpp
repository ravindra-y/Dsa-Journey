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

void deleteFront(Node*& tail) {
  if (!tail) return;
  if (tail->next == tail) { // only one node
    delete tail;
    tail = nullptr;
    return;
  }
  Node* head = tail->next;
  tail->next = head->next; // tail now skips to second node
  delete head;
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
  deleteFront(tail);
  display(tail);

  return 0;
}