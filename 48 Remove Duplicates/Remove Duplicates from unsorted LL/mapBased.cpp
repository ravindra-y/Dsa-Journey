#include <iostream>
#include <unordered_map>
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

ListNode* deleteDuplicatesUnsorted(ListNode* head) {
  unordered_map<int, int> count;

  ListNode* curr = head;
  while (curr) {
    count[curr->val]++;
    curr = curr->next;
  }

  ListNode* dummy = new ListNode(0); // FIXED
  dummy->next = head;

  ListNode* prev = dummy;
  curr = head;

  while (curr) {
    if (count[curr->val] > 1) {
      prev->next = curr->next;
    } else {
      prev = curr;
    }
    curr = curr->next;
  }

  return dummy->next;
}

void print(ListNode* head) {
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "null\n" << endl;
}

int main() {
  ListNode* head = nullptr;

  head = buildNode(head, 4);
  head = buildNode(head, 2);
  head = buildNode(head, 5);
  head = buildNode(head, 4);
  head = buildNode(head, 2);
  head = buildNode(head, 2);

  cout << "Before: ";
  print(head);

  deleteDuplicatesUnsorted(head); // FIXED

  cout << "After: ";
  print(head);
}