//? https://leetcode.com/problems/spiral-matrix/description/

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
  vector<int> ans;
  if (matrix.empty())
    return ans;

  int m = matrix.size();
  int n = matrix[0].size();

  int srow = 0, scol = 0;
  int erow = m - 1, ecol = n - 1;

  while (srow <= erow && scol <= ecol) {

    // Top row
    for (int i = scol; i <= ecol; i++) {
      ans.push_back(matrix[srow][i]);
    }

    // Right column
    for (int i = srow + 1; i <= erow; i++) {
      ans.push_back(matrix[i][ecol]);
    }

    // Bottom row (check to avoid duplicate row)
    if (srow < erow) {
      for (int i = ecol - 1; i >= scol; i--) {
        ans.push_back(matrix[erow][i]);
      }
    }

    // Left column (check to avoid duplicate column)
    if (scol < ecol) {
      for (int i = erow - 1; i > srow; i--) {
        ans.push_back(matrix[i][scol]);
      }
    }

    srow++; erow--;
    scol++; ecol--;
  }

  return ans;
}

int main() {

  vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

  vector<int> result = spiralOrder(matrix);

  cout << "Spiral Order: ";
  for (int x : result) {
    cout << x << " ";
  }

  return 0;
}