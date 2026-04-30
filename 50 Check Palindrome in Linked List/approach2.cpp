#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int data) : val(data), next(nullptr) {}
};

void insertEnd(ListNode*& head, int data) {
  ListNode* newNode = new ListNode(data); // create new node

  // If list is empty, new node becomes head
  if (!head) {
    head = newNode;
    return;
  }

  // Traverse to last node
  ListNode* curr = head;
  while (curr->next) {
    curr = curr->next;
  }

  curr->next = newNode; // attach new node at end
}

bool isPalindrome(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return true;
  }

  // Step 1: Find the middle using slow/fast pointers
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Step 2: Reverse the second half
  ListNode* prev = nullptr;
  ListNode* curr = slow;
  while (curr != nullptr) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  // Step 3: Compare both halves
  ListNode* left = head;
  ListNode* right = prev;
  while (right != nullptr) {
    if (left->val != right->val) {
      return false;
    }
    left = left->next;
    right = right->next;
  }
  return true;
}

void display(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

int main() {
  ListNode* head = NULL;

  insertEnd(head, 1);
  insertEnd(head, 2);
  insertEnd(head, 1);

  display(head);

  if (isPalindrome(head)) {
    cout << "This is Palindrome" << endl;
  } else {
    cout << "This is not Palindrome" << endl;
  }
}