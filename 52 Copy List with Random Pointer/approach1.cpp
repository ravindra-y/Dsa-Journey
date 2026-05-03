// https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node* random;

  Node(int x) : val(x), next(NULL), random(NULL) {}
};

// Function to copy list
Node* copyRandomList(Node* head) {
  if (!head) return NULL;

  unordered_map<Node*, Node*> mp;
  Node* curr = head;

  // Step 1: create all nodes
  while (curr) {
    mp[curr] = new Node(curr->val);
    curr = curr->next;
  }

  // Step 2: connect next & random
  curr = head;
  while (curr) {
    mp[curr]->next = mp[curr->next];
    mp[curr]->random = mp[curr->random];
    curr = curr->next;
  }

  return mp[head];
}

// Helper to print list
void display(Node* head) {
  while (head) {
    cout << "Val: " << head->val;

    if (head->random) cout << ", Random: " << head->random->val;
    else cout << ", Random: NULL";

    cout << endl;
    head = head->next;
  }
}

int main() {
  // Creating example list
  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);

  n1->next = n2;
  n2->next = n3;

  // Setting random pointers
  n1->random = n3; // 1 -> 3
  n2->random = n1; // 2 -> 1
  n3->random = n2; // 3 -> 2

  cout << "Original List:\n";
  display(n1);

  Node* copied = copyRandomList(n1);

  cout << "\nCopied List:\n";
  display(copied);

  return 0;
}