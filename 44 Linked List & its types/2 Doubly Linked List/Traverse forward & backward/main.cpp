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

void traverseForward(Node* head) {
  while (head) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "null\n";
}

void traverseBackward(Node* tail) {
  while (tail) {
    cout << tail->data << " -> ";
    tail = tail->prev;
  }
  cout << "null\n";
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  insertEnd(head, tail, 10);
  insertEnd(head, tail, 20);
  insertEnd(head, tail, 30);

  traverseForward(head);
  traverseBackward(tail);
}