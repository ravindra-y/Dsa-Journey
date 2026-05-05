#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;
  Node* child;

  Node(int val) {
    data = val;
    prev = next = child = NULL;
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
      child->prev = curr;
      curr->child = NULL;

      // find tail
      Node* tail = child;
      while (tail->next)
        tail = tail->next;

      // attach next
      tail->next = nextNode;
      if (nextNode) nextNode->prev = tail;
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
  head->next->prev = head;

  head->next->next = new Node(3);
  head->next->next->prev = head->next;

  head->next->next->next = new Node(4);
  head->next->next->next->prev = head->next->next;

  head->next->next->next->next = new Node(5);
  head->next->next->next->next->prev = head->next->next->next;

  // Child for node 2: 7-8
  Node* child1 = new Node(7);
  child1->next = new Node(8);
  child1->next->prev = child1;
  head->next->child = child1;

  // Child for node 3: 9
  Node* child2 = new Node(9);
  head->next->next->child = child2;

  head = flatten(head);

  cout << "Flattened Doubly List:\n";
  printList(head);

  return 0;
}