#include <iostream>
#include <algorithm>
using namespace std;

void reverseArr(int arr[], int size) {
    // int start = 0, end = size - 1;

    // while(start < end) {
    //     swap(arr[start], arr[end]);
    //     start++; end--;
    // }

    reverse(arr, arr + size);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  reverseArr(arr, size);

  for(int i = 0; i < size; i++) {
    cout << arr[i] << ", ";
  }
  return 0;
}