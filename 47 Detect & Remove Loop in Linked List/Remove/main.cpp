// https://leetcode.com/problems/linked-list-cycle-ii/

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

Node* detectCycle(Node* head) {
  if (!head) return nullptr;

  Node* slow = head;
  Node* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      // Find start of cycle
      slow = head;

      Node* prevFast = fast;
      while (slow != fast) {
        slow = slow->next;
        prevFast = fast;
        fast = fast->next;
      }

      // Remove cycle safely
      prevFast->next = nullptr;

      return slow; // start of cycle
    }
  }

  return nullptr; // no cycle
}

int main() {
  // Example: 1 -> 2 -> 3 -> 4 -> 5 -> (back to 3)
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  // Creating cycle (5 -> 3)
  head->next->next->next->next->next = head->next->next;

  Node* cycleStart = detectCycle(head);

  if (cycleStart) {
    cout << "Cycle starts at node with value: " << cycleStart->data << endl;
  } else {
    cout << "No cycle detected" << endl;
  }

  return 0;
}