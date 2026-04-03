//? https://www.naukri.com/code360/problems/print-like-a-wave_893268

#include <iostream>
#include <vector>
using namespace std;

//! Time complexity -> O(m * n)
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {

  vector<int> ans;

  for (int col = 0; col < mCols; col++) {

    if (col & 1) {
      // odd Index -> Bottom to top
      for (int row = nRows - 1; row >= 0; row--) {
        ans.push_back(arr[row][col]);
      }
    } else {
      // even index -> top to bottom
      for (int row = 0; row < nRows; row++) {
        ans.push_back(arr[row][col]);
      }
    }
  }

  return ans;
}

int main() {

  int nRows = 3;
  int mCols = 4;

  // Initialize 2D vector
  vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  vector<int> result = wavePrint(arr, nRows, mCols);

  cout << "Wave Print Output: ";
  for (int num : result) {
    cout << num << " ";
  }

  return 0;
}