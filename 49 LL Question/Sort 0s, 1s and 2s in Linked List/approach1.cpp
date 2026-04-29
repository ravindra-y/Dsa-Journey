// https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int x) : data(x), next(NULL) {}
};

Node* sortList(Node* head) {
  if (!head || !head->next) return head;

  int zeroCount = 0;
  int oneCount = 0;
  int twoCount = 0;

  Node* temp = head;
  while(temp) {
    if(temp->data == 0) {
      zeroCount++;
    } else if(temp->data == 1) {
      oneCount++;
    } else {
      twoCount++;
    }

    temp = temp->next;
  }

  temp = head;
  while(temp != nullptr) {
    if(zeroCount) {
      temp->data = 0;
      zeroCount--;
    } else if(oneCount) {
      temp->data = 1;
      oneCount--;
    } else {
      temp->data = 2;
      twoCount--;
    }

    temp = temp->next;
  }

  return head;
}

// Helper to print list
void printList(Node* head) {
  while (head) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

int main() {
  // Example: 1 -> 2 -> 0 -> 1 -> 2 -> 0
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(0);
  head->next->next->next = new Node(1);
  head->next->next->next->next = new Node(2);
  head->next->next->next->next->next = new Node(0);

  cout << "Before: ";
  printList(head);

  head = sortList(head);

  cout << "After: ";
  printList(head);

  return 0;
}