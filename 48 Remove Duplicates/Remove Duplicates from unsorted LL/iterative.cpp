#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// insert at end
ListNode* build(ListNode* head, int val) {
  ListNode* node = new ListNode(val);
  if (!head) return node;

  ListNode* temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = node;
  return head;
}

// print list
void print(ListNode* head) {
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "null\n";
}

// brute force solution
ListNode* deleteDuplicatesUnsorted(ListNode* head) {
  ListNode* dummy = new ListNode(0);
  dummy->next = head;

  ListNode* prev = dummy;
  ListNode* curr = head;

  while (curr) {
    int count = 0;
    ListNode* temp = head;

    while (temp) {
      if (temp->val == curr->val) count++;
      temp = temp->next;
    }

    if (count > 1) {
      prev->next = curr->next;
    } else {
      prev = curr;
    }

    curr = curr->next;
  }

  return dummy->next;
}

int main() {
  ListNode* head = nullptr;

  head = build(head, 10);
  head = build(head, 20);
  head = build(head, 20);
  head = build(head, 30);
  head = build(head, 30);
  head = build(head, 40);

  cout << "Before: ";
  print(head);

  head = deleteDuplicatesUnsorted(head);

  cout << "After: ";
  print(head);
}