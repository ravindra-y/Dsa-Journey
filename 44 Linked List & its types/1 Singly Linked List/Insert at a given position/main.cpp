#include <iostream>
using namespace std;

// Node creation
struct Node {
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

void insertFront(Node*& head, int val) {
  Node* newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}

void insertEnd(Node*& head, int val) {
  Node* newNode = new Node(val);

  if(!head) {
    head = newNode;
    return;
  }

  Node* curr = head;

  while(curr->next) {
    curr = curr->next;
  }

  curr->next = newNode;
}

void insertAt(Node*& head, int val, int pos) {
  // if postion is zero
  if (pos == 0) {
    insertFront(head, val);
    return;
  }

  Node* newNode = new Node(val);
  Node* curr = head;

  for (int i = 0; i < pos - 1 && curr; i++) {
    curr = curr->next;
  }

  if (head == nullptr && pos > 0) {
    cout << "Invalid position\n";
    return;
  }

  newNode->next = curr->next;
  curr->next = newNode;
}

void printList(Node* head) {
  while (head) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "null\n";
}

int main() {
  Node* head = nullptr;

  insertEnd(head, 10);
  insertEnd(head, 20);
  insertEnd(head, 30);

  insertAt(head, 60, 1);
  printList(head);
}