#include <iostream>
using namespace std;

void printRowSum(int arr[][3], int row, int col) {
  int maxSum = 0;
  int atIndex = -1;

  for (int i = 0; i < row; i++) {
    int sum = 0;

    for (int j = 0; j < col; j++) {
      sum += arr[i][j];
    }
    cout << i + 1 << " rowSum: " << sum << endl;
    if(maxSum < max(maxSum, sum)) {
      maxSum = max(maxSum, sum);
      atIndex = i;
    }
  }
  cout << endl;

  cout << "Largest Sum at " << atIndex << " index: " << maxSum;
}

int main() {
  int arr[3][3];

  cout << "Enter element: ";
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      cin >> arr[row][col];
    }
  }
  cout << endl;

  // printing 2D array
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      cout << arr[row][col] << " ";
    }
    cout << endl;
  }
  cout << endl;

  printRowSum(arr, 3, 3);

  return 0;
}