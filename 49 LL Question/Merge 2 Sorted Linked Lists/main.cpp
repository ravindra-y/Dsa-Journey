// https://leetcode.com/problems/merge-two-sorted-lists/

#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Merge function (recursive)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  // Base cases
  if (!list1) return list2;
  if (!list2) return list1;

  // Choose smaller node
  if (list1->val <= list2->val) {
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  } else {
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
  }
}

// Helper function to print list
void printList(ListNode* head) {
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

int main() {
  // Creating first list: 1 -> 3 -> 5
  ListNode* list1 = new ListNode(1);
  list1->next = new ListNode(3);
  list1->next->next = new ListNode(5);

  // Creating second list: 2 -> 4 -> 6
  ListNode* list2 = new ListNode(2);
  list2->next = new ListNode(4);
  list2->next->next = new ListNode(6);

  // Merge lists
  ListNode* merged = mergeTwoLists(list1, list2);

  // Print result
  printList(merged);

  return 0;
}