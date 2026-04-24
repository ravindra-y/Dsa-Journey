#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node*& head, int val) {
  Node* newNode = new Node(val);

  if (!head) {
    head = newNode;
    return;
  }

  Node* curr = head;

  while (curr->next) {
    curr = curr->next;
  }

  curr->next = newNode;
}

void deleteEnd(Node*& head) {
  // execute when list is empty
  if (!head) {
    return;
  }

  // execute when list have single node
  if (!head->next) {
    delete head;
    head = nullptr;
    return;
  }

  Node* curr = head;

  // second last find
  while (curr->next->next) {
    curr = curr->next;
  }

  delete curr->next;
  curr->next = nullptr;
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

  deleteEnd(head);

  printList(head);
}