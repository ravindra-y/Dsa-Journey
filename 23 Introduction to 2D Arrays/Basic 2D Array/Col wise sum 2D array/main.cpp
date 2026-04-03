#include <iostream>
using namespace std;

void printColSum(int arr[][3], int row, int col) {
  for(int i = 0; i < col; i++) {
    int sum = 0;

    for(int j = 0; j < row; j++) {
      sum += arr[j][i];
    }
    cout << i+1 << " colSum: " << sum << endl;
  }
}

int main() {
  int arr[3][3];

  cout << "Enter element: ";
  for(int col = 0; col < 3; col++) {
    for(int row = 0; row < 3; row++) {
      cin >> arr[row][col];
    }
  }
  cout << endl;

  //printing 2D array
  for(int row = 0; row < 3; row++) {
    for(int col = 0; col < 3; col++) {
      cout << arr[row][col] << " ";
    }
    cout << endl;
  }
  cout << endl;

  printColSum(arr, 3, 3);

  return 0;
}
