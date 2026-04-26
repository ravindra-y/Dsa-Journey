//? https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Helpers
ListNode* build(vector<int> v) {
  ListNode dummy(0);
  ListNode* cur = &dummy;
  for (int x : v) {
    cur->next = new ListNode(x);
    cur = cur->next;
  }
  return dummy.next;
}

ListNode* reverseKGroup(ListNode* head, int k) {
  // Count nodes to check if we have at least k
  ListNode* curr = head;
  int count = 0;
  while (curr && count < k) {
    curr = curr->next;
    count++;
  }

  // Base case: fewer than k nodes, return as-is
  if (count < k) return head;

  // Reverse first k nodes
  ListNode* prev = nullptr;
  curr = head;
  for (int i = 0; i < k; i++) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  // head is now the tail, connect to recursively processed rest
  head->next = reverseKGroup(curr, k);

  return prev;
}

void print(ListNode* h) {
  while (h) {
    cout << h->val << (h->next ? " -> " : "\n");
    h = h->next;
  }
}

int main() {
  ListNode* head = build({1, 2, 3, 4, 5, 6, 7});

  cout << "Before: ";
  print(head);

  head = reverseKGroup(head, 3);

  cout << "After:  ";
  print(head);
}