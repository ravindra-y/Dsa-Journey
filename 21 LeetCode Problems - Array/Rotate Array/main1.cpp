//? https://leetcode.com/problems/rotate-array/description/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// TODO: Solve useing "reverse function"

//! Time complexity: O(n)
void rotate(vector<int> &nums, int k) {
  int n = nums.size();
  k = k % n;

  reverse(nums.begin(), nums.end());       // Step 1 -- O(n)
  reverse(nums.begin(), nums.begin() + k); // Step 2 -- O(k)
  reverse(nums.begin() + k, nums.end());   // Step 3 -- O(n - k)
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;

  rotate(nums, k);

  for (auto i : nums) {
    cout << i << " ";
  }
  return 0;
}