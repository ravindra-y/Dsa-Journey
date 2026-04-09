#include <iostream>
using namespace std;

int main() {
  int rows = 3;

  // Step 1: Create array of row pointers
  int **arr = new int *[rows];

  // Step 2: Allocate different column sizes
  arr[0] = new int[2]; // Row 0 → 2 columns
  arr[1] = new int[4]; // Row 1 → 4 columns
  arr[2] = new int[3]; // Row 2 → 3 columns

  // Assign values
  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[1][0] = 3;
  arr[1][1] = 4;
  arr[1][2] = 5;
  arr[1][3] = 6;
  arr[2][0] = 7;
  arr[2][1] = 8;
  arr[2][2] = 9;

  // Print
  for (int i = 0; i < rows; i++) {
    int cols;
    if (i == 0)
      cols = 2;
    else if (i == 1)
      cols = 4;
    else
      cols = 3;

    for (int j = 0; j < cols; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  // Step 3: Free memory
  delete[] arr[0];
  delete[] arr[1];
  delete[] arr[2];
  delete[] arr;

  return 0;
}