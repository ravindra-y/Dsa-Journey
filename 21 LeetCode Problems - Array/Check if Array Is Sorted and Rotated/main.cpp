//? https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums) {
  int n = nums.size();
  int count = 0;

  for (int i = 1; i < n; i++) {
    if (nums[i - 1] > nums[i]) { //! isRotated
      count++;
    }
  }

  if (nums[n - 1] > nums[0]) { //! isSorted
    count++;
  }

  return count <= 1;
}

int main() {
  vector<int> nums = {3, 4, 5, 1, 2};

  bool ans = check(nums);

  if (ans) {
    cout << "Ture" << endl;
  } else {
    cout << "False" << endl;
  }
  
  return 0;
}