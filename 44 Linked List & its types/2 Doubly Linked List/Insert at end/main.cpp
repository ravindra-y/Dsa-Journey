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

void freeList(Node*& head) {
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  Node* head = nullptr;
  Node* tail = nullptr;

  insertEnd(head, tail, 10);
  insertEnd(head, tail, 20);
  insertEnd(head, tail, 30);

  display(head);
}