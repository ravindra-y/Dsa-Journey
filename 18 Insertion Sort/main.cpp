#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n) {
  for (int i = 1; i < n; i++) {
    int curr = arr[i];
    int prev = i - 1;

    while (prev >= 0 && arr[prev] > curr) {
      arr[prev + 1] = arr[prev];
      prev--;
    }

    arr[prev + 1] = curr;
  }
}

int main() {
  vector<int> arr = {1, 10, 7, 4, 8, 2, 11};
  insertionSort(arr, arr.size());

  for (int val : arr) {
    cout << val << " ";
  }
  return 0;
}