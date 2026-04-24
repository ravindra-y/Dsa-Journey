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

void display(Node* curr) {
  while (curr != nullptr) {
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

  insertFront(head, tail, 10);
  insertFront(head, tail, 20);
  insertFront(head, tail, 30);

  display(head);

  freeList(head);
}