// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* buildNode(ListNode* head, int val) {
  ListNode* newNode = new ListNode(val);

  if (!head) return newNode;

  ListNode* curr = head;
  while (curr->next) {
    curr = curr->next;
  }

  curr->next = newNode;
  return head;
}

ListNode* deleteDuplicates(ListNode* head) {
  // empty list
  if (!head) return head;

  // non-empty list
  ListNode* curr = head;

  while (curr && curr->next) {
    if (curr->val != curr->next->val) {
      curr = curr->next;
    } else {
      ListNode* nodeToDelete = curr->next;
      curr->next = curr->next->next;
      delete (nodeToDelete);
    }
  }

  return head;
}

void print(ListNode* head) {
  while(head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "null\n" << endl;
}

int main() {
  ListNode* head = nullptr;

  head = buildNode(head, 10);
  head = buildNode(head, 20);
  head = buildNode(head, 20);
  head = buildNode(head, 30);
  head = buildNode(head, 30);
  head = buildNode(head, 40);

  cout << "Before: ";
  print(head);

  head = deleteDuplicates(head);

  cout << "After: ";
  print(head);

}