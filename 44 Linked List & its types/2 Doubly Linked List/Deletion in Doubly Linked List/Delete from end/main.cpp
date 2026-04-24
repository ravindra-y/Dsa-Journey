#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;

  Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertEnd(Node*& head, Node*& tail, int val) {
  Node* newNode = new Node(val);
  if (!tail) {
    head = tail = newNode;
    return;
  }
  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
}

void display(Node* curr) {
  while (curr != NULL) {
    cout << curr->data << " <-> ";
    curr = curr->next;
  }
  cout << "NULL\n";
}

void deleteEnd(Node*& head, Node*& tail) {
    if (!tail) return;

    Node* temp = tail;
    tail = tail->prev;

    if (tail) {
      tail->next = nullptr;
    } else {
      head = nullptr;
    }

    delete temp;
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  insertEnd(head, tail, 10);
  insertEnd(head, tail, 20);
  insertEnd(head, tail, 30);

  deleteEnd(head, tail);
  display(head);
}