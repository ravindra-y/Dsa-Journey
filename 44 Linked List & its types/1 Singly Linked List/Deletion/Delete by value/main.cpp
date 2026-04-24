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

void deleteFront(Node*& head) {
  if (!head) return;

  Node* temp = head;
  head = head->next;
  delete temp;
}

void deleteByValue(Node*& head, int val) {
  if (!head) return;

  // execute when only single or first node is == val
  if (head->data == val) {
    deleteFront(head);
    return;
  }

  Node* curr = head;

  while (curr->next && curr->next->data != val) {
    curr = curr->next;
  }

  if (!curr->next) return; // not found

  Node* temp = curr->next;
  curr->next = temp->next;
  delete temp;
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

  deleteByValue(head, 30);

  printList(head);
}