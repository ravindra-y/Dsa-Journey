#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int d) : data(d), next(nullptr) {}
};

void insertNode(Node*& tail, int element, int d) {
  // empty list
  if (tail == NULL) {
    Node* newNode = new Node(d);
    tail = newNode;
    newNode->next = newNode;
  } else {
    // non-empty list
    // assuming that the element is present in the list
    Node* curr = tail;
    while (curr->data != element) {
      curr = curr->next;
    }

    // element found -> curr is representing element wala node
    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
  }
}

void display(Node* tail) {
  if (tail == NULL) {
    cout << "List is empty\n";
    return;
  }

  Node* curr = tail->next; // start from head
  do {
    cout << curr->data << " -> ";
    curr = curr->next;
  } while (curr != tail->next);

  cout << "(back to head)\n";
}

int main() {
  Node* tail = NULL;

  // Insert into empty list (element ignored, first node)
  insertNode(tail, -1, 10); // List: 10
  display(tail);

  // Insert after 10
  insertNode(tail, 10, 20); // List: 10 -> 20
  display(tail);

  // Insert after 20
  insertNode(tail, 20, 30); // List: 10 -> 20 -> 30
  display(tail);

  // Insert after 10 (middle insertion)
  insertNode(tail, 10, 15); // List: 10 -> 15 -> 20 -> 30
  display(tail);

  // Insert after tail (30) -> becomes new sequence before head
  insertNode(tail, 30, 99); // List: 10 -> 15 -> 20 -> 30 -> 99
  display(tail);

  return 0;
}