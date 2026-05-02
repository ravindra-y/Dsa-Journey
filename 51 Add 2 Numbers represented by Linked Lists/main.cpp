// https://leetcode.com/problems/add-two-numbers/description/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {}
};

void insertEnd(ListNode*& head, int val) {
  ListNode* newNode = new ListNode(val);

  if (!head) {
    head = newNode;
    return;
  }

  ListNode* curr = head;
  while (curr->next) {
    curr = curr->next;
  }

  curr->next = newNode;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode dummy(0);
  ListNode* current = &dummy;
  int carry = 0;

  while (l1 || l2 || carry) {
    int val1 = l1 ? l1->val : 0;
    int val2 = l2 ? l2->val : 0;
    int sum = val1 + val2 + carry;

    carry = sum / 10;
    current->next = new ListNode(sum % 10);
    current = current->next;

    if (l1) l1 = l1->next;
    if (l2) l2 = l2->next;
  }

  return dummy.next;
}

void display(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

int main() {
  ListNode* l1 = NULL;
  ListNode* l2 = NULL;

  // Example: 342 (stored as 2 -> 4 -> 3)
  insertEnd(l1, 2);
  insertEnd(l1, 4);
  insertEnd(l1, 3);

  // Example: 465 (stored as 5 -> 6 -> 4)
  insertEnd(l2, 5);
  insertEnd(l2, 6);
  insertEnd(l2, 4);

  cout << "List 1: ";
  display(l1);

  cout << "List 2: ";
  display(l2);

  ListNode* result = addTwoNumbers(l1, l2);

  cout << "Result: ";
  display(result);

  return 0;
}