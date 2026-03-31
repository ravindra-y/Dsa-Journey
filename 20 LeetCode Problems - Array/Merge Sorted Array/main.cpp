//? https://leetcode.com/problems/merge-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

// TODO: Solve using two-pointer approach

//! Time Complexity: O(m + n)
void merge(vector<int> &A, int m, vector<int> &B, int n) {
  int i = m - 1;
  int j = n - 1;
  int idx = m + n - 1;

  while (i >= 0 && j >= 0) {
    if (A[i] >= B[j]) {
      A[idx--] = A[i--];
    } else {
      A[idx--] = B[j--];
    }
  }

  // If any elements remain in B, copy them over
  while (j >= 0) {
    A[idx--] = B[j--];
  }
}

int main() {
  vector<int> A = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> B = {2, 5, 6};
  int n = 3;

  merge(A, m, B, n);

  for (int i : A) {
    cout << i << " ";
  }
  return 0;
}