#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node*& tail, int val) {
  Node* newNode = new Node(val);
  if (!tail) {
    newNode->next = newNode;
    tail = newNode;
    return;
  }
  newNode->next = tail->next; // new node's next = head
  tail->next = newNode;       // old tail links to new node
  tail = newNode;             // advance tail
}

void display(Node* tail) {
  if (!tail) {
    cout << "List is empty.\n";
    return;
  }
  Node* curr = tail->next; // start from head
  do {
    cout << curr->data << " -> ";
    curr = curr->next;
  } while (curr != tail->next);
  cout << "(head)\n";
}

int search(Node* tail, int val) {
  if (!tail) return -1;
  Node* curr = tail->next; // start at head
  int pos = 0;
  do {
    if (curr->data == val) return pos;
    curr = curr->next;
    pos++;
  } while (curr != tail->next); // stop when we reach head again
  return -1;
}

int main() {
  Node* tail = nullptr;

  insertEnd(tail, 30);
  insertEnd(tail, 20);
  insertEnd(tail, 10);
  insertEnd(tail, 5);

  display(tail);

  int key = 10;
  int result = search(tail, key);

  if (result != -1)
    cout << "Element " << key << " found at position: " << result << endl;
  else cout << "Element not found\n";

  return 0;
}