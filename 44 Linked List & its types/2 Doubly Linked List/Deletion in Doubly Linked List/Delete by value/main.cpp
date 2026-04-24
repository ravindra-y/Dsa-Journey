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

void deleteByValue(Node*& head, Node*& tail, int val) {
  Node* curr = head;

  while (curr && curr->data != val) {
    curr = curr->next;
  }

  if (!curr) return;

  if (curr->prev) {
    curr->prev->next = curr->next;
  } else {
    head = curr->next;
  }

  if (curr->next) {
    curr->next->prev = curr->prev;
  } else {
    tail = curr->prev;
  }

  delete curr;
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  insertEnd(head, tail, 10);
  insertEnd(head, tail, 20);
  insertEnd(head, tail, 30);

  deleteByValue(head, tail, 20);
  display(head);
}