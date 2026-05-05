#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) {
    val = x;
    next = NULL;
  }
};

// Find middle
ListNode* findMid(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head->next;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// Merge two sorted lists
ListNode* merge(ListNode* left, ListNode* right) {
  if (!left) return right;
  if (!right) return left;

  ListNode* dummy = new ListNode(-1);
  ListNode* temp = dummy;

  while (left && right) {
    if (left->val < right->val) {
      temp->next = left;
      left = left->next;
    } else {
      temp->next = right;
      right = right->next;
    }
    temp = temp->next;
  }

  if (left) temp->next = left;
  if (right) temp->next = right;

  return dummy->next;
}

// Merge Sort
ListNode* sortList(ListNode* head) {
  if (!head || !head->next) return head;

  ListNode* mid = findMid(head);
  ListNode* left = head;
  ListNode* right = mid->next;
  mid->next = NULL;

  left = sortList(left);
  right = sortList(right);

  return merge(left, right);
}

// Print list
void printList(ListNode* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // Hardcoded list: 4 -> 2 -> 1 -> 3 -> 5
  ListNode* head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(5);

  cout << "Original List:\n";
  printList(head);

  head = sortList(head);

  cout << "Sorted List:\n";
  printList(head);

  return 0;
}