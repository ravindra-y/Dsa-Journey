#include <iostream>
using namespace std;

// Node structure
struct Node {
  int data;
  Node* next;
  
  Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the beginning
void insertFront(Node*& head, int val) {
  Node* newNode = new Node(val); // create new node

  newNode->next = head; // new node points to current head
  head = newNode;       // update head to new node
}


// Function to display linked list
void display(Node* head) {
  while (head != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

int main() {
  Node* head = NULL; // initially list is empty

  insertFront(head, 10);
  insertFront(head, 20);
  insertFront(head, 30);

  display(head);
}