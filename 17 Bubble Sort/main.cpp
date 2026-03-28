#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    bool isSwap = false; // --> Optimization

    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        isSwap = true;
      }
    }
    if (!isSwap) {
      return;
    }
  }
}

int main() {
  vector<int> arr = {6, 2, 8, 4, 10};

  bubbleSort(arr, arr.size());

  for (int val : arr) {
    cout << val << " ";
  }
  return 0;
}