//? https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1?utm_source=chatgpt.com

#include <iostream>
#include <stack>
using namespace std;

stack<int> insertAtBottom(stack<int> st, int x) {

  // Base case
  if (st.empty()) {
    st.push(x);
    return st;
  }

  int topElement = st.top();
  st.pop();

  // Recursive call
  st = insertAtBottom(st, x);

  // Push back top element
  st.push(topElement);

  return st;
}

void printStack(stack<int> st) {
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}

int main() {
  stack<int> st;

  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);

  cout << "Original Stack (top to bottom): ";
  printStack(st);

  st = insertAtBottom(st, 10);

  cout << "After inserting at bottom: ";
  printStack(st);

  return 0;
}