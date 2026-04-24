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

void display(Node* head) {
  while (head != NULL) {
    cout << head->data << " <-> ";
    head = head->next;
  }
  cout << "NULL\n";
}

void reverse(Node*& head, Node*& tail) {
  Node* curr = head;
  Node* temp = nullptr;

  while (curr) {
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;
  }

  swap(head, tail);
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  insertEnd(head, tail, 10);
  insertEnd(head, tail, 20);
  insertEnd(head, tail, 30);

  display(head);
  reverse(head, tail);
  display(head);
}