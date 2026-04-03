//? https://leetcode.com/problems/search-a-2d-matrix/description/

#include <iostream>
#include <vector>
using namespace std;

//! complexity -> O(long (row * col))
bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int row = matrix.size();
  int col = matrix[0].size();

  int start = 0;
  int end = row * col - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    int element = matrix[mid / col][mid % col];

    if (element == target) {
      return 1;
    }

    if (element < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return 0;
}

int main() {

  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  cout << searchMatrix(matrix, 9) << endl;
  return 0;
}