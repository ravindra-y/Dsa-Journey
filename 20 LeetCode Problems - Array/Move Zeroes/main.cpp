//? https://leetcode.com/problems/move-zeroes/description/

#include <iostream>
#include <vector>
using namespace std;

// TODO: Solve using two-pointer approach
// TODO: shift all non-zero element to the left

//! Time Complexity: O(n)
void moveZeroes(vector<int>& nums) {
  int idx = 0;

  for(int i = 0; i < nums.size(); i++) {
    if(nums[i] != 0) {
      swap(nums[idx++], nums[i]);
    }
  }
}

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};

  moveZeroes(nums);

  for(auto i : nums) {
    cout << i << " ";
  }
  return 0;
}