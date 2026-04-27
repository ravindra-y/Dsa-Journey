// https://leetcode.com/problems/linked-list-cycle/description/

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

// Floyd's Cycle Detection Algorithm
bool hasCycle(Node* head) {
  Node* slow = head;
  Node* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) return true;
  }

  return false;
}

int main() {
  // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  cout << "Without cycle: " << (hasCycle(head) ? "Circular" : "Not Circular")
       << endl;

  // Create a cycle: 5 -> 3
  head->next->next->next->next->next = head->next->next;

  cout << "With cycle:    " << (hasCycle(head) ? "Circular" : "Not Circular")
       << endl;

  return 0;
}