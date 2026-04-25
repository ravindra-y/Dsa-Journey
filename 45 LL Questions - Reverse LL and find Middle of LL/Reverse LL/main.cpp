#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

Node* buildList(vector<int> vals) {
  Node* dummy = new Node(0);
  Node* curr = dummy;
  for (int v : vals) {
    curr->next = new Node(v); // link new node to chain
    curr = curr->next;        // advance curr to new node
  }
  return dummy->next;
}

// Iterative reversal
Node* reverseIterative(Node* head) {
  Node* prev = nullptr;
  Node* curr = head;

  while (curr) {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

// Recursive reversal
Node* reverseRecursive(Node* head) {
  if (!head || !head->next) return head;
  
  Node* newHead = reverseRecursive(head->next);
  head->next->next = head;
  head->next = nullptr;
  return newHead;
}

void printList(Node* head) {
  while (head) {
    cout << head->data;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << "\n";
}

int main() {
  Node* head = buildList({1, 2, 3, 4});

  cout << "Original:             ";
  printList(head);

  head = reverseIterative(head);
  cout << "Iterative Reversed:   ";
  printList(head);

  head = reverseRecursive(head);
  cout << "Recursive Reversed:   ";
  printList(head);

  return 0;
}