//? https://leetcode.com/problems/rotate-image/description/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();

  // Step 1: Flip (transpose) across the diagonal
  for (int row = 0; row < n; row++) {
    for (int col = row; col < n; col++) {
      swap(matrix[row][col], matrix[col][row]);
    }
  }

  // Step 2: Reverse each row
  for (int row = 0; row < n; row++) {
    reverse(matrix[row].begin(), matrix[row].end());
  }
}

int main() {

  vector<vector<int>> matrix = {
      {1, 2, 3}, 
      {4, 5, 6}, 
      {7, 8, 9}
  };

  cout << "Original Matrix:\n";
  for (auto row : matrix) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  // Rotate the matrix
  rotate(matrix);

  cout << "\nRotated Matrix (90 degrees clockwise):\n";
  for (auto row : matrix) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}