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
  // Copy values into an array
  vector<int> vals;
  ListNode* curr = head;
  while (curr != nullptr) {
    vals.push_back(curr->val);
    curr = curr->next;
  }

  // Two-pointer palindrome check
  int left = 0;
  int right = vals.size() - 1;
  while (left < right) {
    if (vals[left] != vals[right]) {
      return false;
    }
    left++;
    right--;
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