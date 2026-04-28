#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

// ─── Merge Sort Helpers
// ───────────────────────────────────────────────────────

Node* merge(Node* a, Node* b) {
  if (!a) return b;
  if (!b) return a;
  if (a->data <= b->data) {
    a->next = merge(a->next, b);
    return a;
  } else {
    b->next = merge(a, b->next);
    return b;
  }
}

void splitList(Node* head, Node*& left, Node*& right) {
  Node* slow = head;
  Node* fast = head->next;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  left = head;
  right = slow->next;
  slow->next = nullptr;
}

Node* mergeSort(Node* head) {
  if (!head || !head->next) return head;
  Node *left, *right;
  splitList(head, left, right);
  left = mergeSort(left);
  right = mergeSort(right);
  return merge(left, right);
}

// ─── Remove Adjacent Duplicates After Sorting ────────────────────────────────

Node* removeDuplicates(Node* head) {
  Node* curr = head;
  while (curr && curr->next) {
    if (curr->data == curr->next->data) {
      Node* dup = curr->next;
      curr->next = dup->next;
      delete dup;
    } else {
      curr = curr->next;
    }
  }
  return head;
}

// ─── Utility
// ──────────────────────────────────────────────────────────────────

Node* buildList(int arr[], int n) {
  Node* head = nullptr;
  Node* tail = nullptr;
  for (int i = 0; i < n; i++) {
    Node* node = new Node(arr[i]);
    if (!head) head = tail = node;
    else {
      tail->next = node;
      tail = node;
    }
  }
  return head;
}

void printList(Node* head) {
  while (head) {
    cout << head->data;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << "\n";
}

int main() {
  int arr[] = {5, 3, 1, 3, 7, 5, 9, 1, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  Node* head = buildList(arr, n);

  cout << "Original : ";
  printList(head);

  head = mergeSort(head);
  cout << "Sorted   : ";
  printList(head);

  head = removeDuplicates(head);
  cout << "No Dupes : ";
  printList(head);

  return 0;
}