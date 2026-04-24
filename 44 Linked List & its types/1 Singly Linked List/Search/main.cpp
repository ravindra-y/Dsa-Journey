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

int search(Node* head, int val) {
  int pos = 0;
  while (head) {
    if (head->data == val) return pos;
    head = head->next;
    pos++;
  }
  return -1; // not found
}

int main() {
  Node* head = NULL;

  insertEnd(head, 10);
  insertEnd(head, 20);
  insertEnd(head, 30);

  display(head);
  cout << "Prsent at node Index: " << search(head, 30) << endl;
}