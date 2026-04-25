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
    curr->next = new Node(v);
    curr = curr->next;
  }
  return dummy->next;
}

// ─── Approach 1: Length-based ─────────────────────────────────────────────
// Pass 1: count length
// Pass 2: walk to (length/2)th node
Node* findMiddle_Length(Node* head) {
  if (!head) return nullptr;

  int len = 0;
  Node* curr = head;
  while (curr) {
    len++;
    curr = curr->next;
  } // pass 1: count

  curr = head;
  for (int i = 0; i < len / 2; i++) // pass 2: walk to mid
    curr = curr->next;

  return curr;
}


// ─── Approach 2: Fast-Slow (your code) ────────────────────────────────────
// One pass: slow moves 1 step, fast moves 2 steps
// When fast hits end, slow is at middle
Node* findMiddle_FastSlow(Node* head) {
  if (!head) return nullptr;

  Node* slow = head;
  Node* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

void printList(Node* head) {
  while (head) {
    cout << head->data << (head->next ? " -> " : "\n");
    head = head->next;
  }
}

int main() {
  // Odd length
  Node* odd = buildList({1, 2, 3, 4, 5});
  // Even length
  Node* even = buildList({1, 2, 3, 4});

  cout << "Odd  list: ";
  printList(odd);
  cout << "  Length approach : " << findMiddle_Length(odd)->data << "\n";
  cout << "  FastSlow approach: " << findMiddle_FastSlow(odd)->data << "\n\n";

  cout << "Even list: ";
  printList(even);
  cout << "  Length approach : " << findMiddle_Length(even)->data << "\n";
  cout << "  FastSlow approach: " << findMiddle_FastSlow(even)->data << "\n";
}