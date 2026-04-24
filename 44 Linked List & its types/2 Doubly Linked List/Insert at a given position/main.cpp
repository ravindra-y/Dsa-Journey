#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;

  Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertFront(Node*& head, Node*& tail, int val) {
  Node* newNode = new Node(val);
  if (!head) {
    head = tail = newNode;
    return;
  }
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

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

void insertAt(Node*& head, Node*& tail, int val, int pos) {
  if (pos == 0) {
    insertFront(head, tail, val);
    return;
  }

  Node* curr = head;

  for (int i = 0; i < pos - 1 && curr; i++) {
    curr = curr->next;
  }

  if (!curr) return;
  
  if (!curr->next) {
    insertEnd(head, tail, val);
    return;
  }

  Node* newNode = new Node(val);
  newNode->next = curr->next;
  newNode->prev = curr;
  curr->next->prev = newNode;
  curr->next = newNode;
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

  insertAt(head, tail, 10, 0);
  insertAt(head, tail, 20, 1);
  insertAt(head, tail, 15, 1);

  display(head);
}