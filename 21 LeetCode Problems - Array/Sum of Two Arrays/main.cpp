//? https://www.naukri.com/code360/problems/sum-of-two-arrays_893186

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m) {
  int i = n - 1;
  int j = m - 1;
  vector<int> ans;
  int carry = 0;

  while (i >= 0 && j >= 0) {
    int sum = a[i] + b[j] + carry;
    carry = sum / 10;
    ans.push_back(sum % 10);
    i--;
    j--;
  }

  // First case
  while (i >= 0) {
    int sum = a[i] + carry;
    carry = sum / 10;
    ans.push_back(sum % 10);
    i--;
  }

  // Second case
  while (j >= 0) {
    int sum = b[j] + carry;
    carry = sum / 10;
    ans.push_back(sum % 10);
    j--;
  }

  // Third case (remaining carry)
  while (carry != 0) {
    ans.push_back(carry % 10);
    carry /= 10;
  }

  // Reverse result because digits are added from last
  reverse(ans.begin(), ans.end());
  
  return ans;
}

int main() {
  vector<int> a = {1, 2, 3, 4}; // Represents 1234
  vector<int> b = {9, 9, 9};    // Represents 999

  vector<int> result = findArraySum(a, a.size(), b, b.size());

  cout << "Sum: ";
  for (int digit : result) {
    cout << digit;
  }

  return 0;
}