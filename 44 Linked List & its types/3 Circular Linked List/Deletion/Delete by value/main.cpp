#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node*& tail, int val) {
  Node* newNode = new Node(val);

  if (!tail) {
    newNode->next = newNode;
    tail = newNode;
    return;
  }

  newNode->next = tail->next;
  tail->next = newNode;
  tail = newNode;
}

void deleteFront(Node*& tail) {
  if (!tail) return;

  Node* head = tail->next;

  if (head == tail) {
    delete head;
    tail = nullptr;
    return;
  }

  tail->next = head->next;
  delete head;
}

void deleteByValue(Node*& tail, int val) {
  if (!tail) return;

  Node* head = tail->next;

  if (head->data == val) {
    deleteFront(tail);
    return;
  }
  
  Node* curr = head;
  while (curr->next != head && curr->next->data != val)
    curr = curr->next;
  if (curr->next == head) {
    cout << val << " not found.\n";
    return;
  }
  Node* toDelete = curr->next;
  curr->next = toDelete->next;
  if (toDelete == tail) tail = curr;
  delete toDelete;
}

void display(Node* tail) {
  if (!tail) {
    cout << "List is empty.\n";
    return;
  }
  Node* curr = tail->next; // start from head
  do {
    cout << curr->data << " -> ";
    curr = curr->next;
  } while (curr != tail->next);
  cout << "(head)\n";
}

int main() {
  Node* tail = nullptr;

  insertEnd(tail, 10);
  insertEnd(tail, 20);
  insertEnd(tail, 30);
  insertEnd(tail, 40);

  cout << "Initial:            ";
  display(tail); // 10 -> 20 -> 30 -> 40 -> (head)

  deleteByValue(tail, 20);
  cout << "Delete mid (20):    ";
  display(tail); // 10 -> 30 -> 40 -> (head)

  deleteByValue(tail, 10);
  cout << "Delete head (10):   ";
  display(tail); // 30 -> 40 -> (head)

  deleteByValue(tail, 40);
  cout << "Delete tail (40):   ";
  display(tail); // 30 -> (head)

  deleteByValue(tail, 99); // 99 not found.

  deleteByValue(tail, 30);
  cout << "Delete last (30):   ";
  display(tail); // List is empty.

  return 0;
}