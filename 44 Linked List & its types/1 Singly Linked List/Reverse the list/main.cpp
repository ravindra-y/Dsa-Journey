#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

// Function to insert at the end
void insertEnd(Node*& head, int val) {
  Node* newNode = new Node(val); // create new node

  // If list is empty, new node becomes head
  if (!head) {
    head = newNode;
    return;
  }

  // Traverse to last node
  Node* curr = head;
  while (curr->next) {
    curr = curr->next;
  }

  curr->next = newNode; // attach new node at end
}

// Display function
void display(Node* head) {
  while (head != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

void reverse(Node*& head) {
  Node* prev = nullptr;
  Node* curr = head;
  while (curr) {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

int main() {
  Node* head = NULL;

  insertEnd(head, 10);
  insertEnd(head, 20);
  insertEnd(head, 30);

  display(head);
  reverse(head);
  display(head);
}