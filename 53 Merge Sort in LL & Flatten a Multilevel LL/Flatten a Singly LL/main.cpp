#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* child;

  Node(int val) {
    data = val;
    next = child = NULL;
  }
};

// Flatten function
Node* flatten(Node* head) {
  Node* curr = head;

  while (curr) {
    if (curr->child) {
      Node* child = curr->child;
      Node* nextNode = curr->next;

      // attach child
      curr->next = child;
      curr->child = NULL;

      // find tail
      Node* tail = child;
      while (tail->next)
        tail = tail->next;

      // attach next
      tail->next = nextNode;
    }
    curr = curr->next;
  }
  return head;
}

// Print
void printList(Node* head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // Main list: 1-2-3-4-5
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  // Child for node 2: 7-8
  Node* child1 = new Node(7);
  child1->next = new Node(8);
  head->next->child = child1;

  // Child for node 3: 9
  Node* child2 = new Node(9);
  head->next->next->child = child2;

  head = flatten(head);

  cout << "Flattened Singly List:\n";
  printList(head);

  return 0;
}