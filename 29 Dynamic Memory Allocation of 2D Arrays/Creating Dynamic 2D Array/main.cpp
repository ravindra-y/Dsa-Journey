#include <iostream>
using namespace std;

int main() {
  int rows, cols;

  cout << "Enter number of rows: ";
  cin >> rows;

  cout << "Enter number of columns: ";
  cin >> cols;

  // Create array of row pointers
  int **arr = new int *[rows];

  // Allocate memory for each row with 'cols' size
  for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
  }

  // Take input
  cout << "Enter matrix elements:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> arr[i][j];
    }
  }

  // Print matrix
  cout << "\nMatrix is:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  // Free memory
  for (int i = 0; i < rows; i++) {
    delete[] arr[i];
  }
  delete[] arr;

  return 0;
}
