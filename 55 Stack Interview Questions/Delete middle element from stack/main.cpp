// https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246

#include <iostream>
#include <stack>
using namespace std;

// Recursive helper function
void solve(stack<int>& st, int count, int size) {
  // base case
  if (count == size / 2) {
    st.pop();
    return;
  }

  int num = st.top();
  st.pop();

  // RECURSIVE CALL
  solve(st, count + 1, size);

  st.push(num);
}

// Function to delete middle element
void deleteMiddle(stack<int>& st) {
  int n = st.size();

  int count = 0;
  solve(st, count, n);
}

// Function to print stack (top to bottom)
void printStack(stack<int> st) {
  cout << "Stack (top to bottom): ";
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}

int main() {
  stack<int> st;

  // Sample input
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);

  cout << "Original ";
  printStack(st);

  deleteMiddle(st);

  cout << "After deleting middle ";
  printStack(st);

  return 0;
}