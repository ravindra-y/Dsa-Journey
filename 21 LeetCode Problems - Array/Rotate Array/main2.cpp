//? https://leetcode.com/problems/rotate-array/description/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// TODO: use % to totate index
// TODO: we know [n % 10] always gives [0...9] range

//! Time complexity: O(n), Space complexity: O(n)
void rotate(vector<int> &nums, int k) {
  int n = nums.size();
  vector<int> temp(n);

  for (int i = 0; i < n; i++) {
    temp[(i + k) % n] = nums[i];
  }

  nums = temp;
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