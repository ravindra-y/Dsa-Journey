#include <iostream>
using namespace std;

void print(int arr[], int s, int e) {
  for (int i = s; i <= e; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int binarySearch(int *arr, int s, int e, int k) {

  print(arr, s, e);

  //! base case
  // element not found
  if (s > e)
    return -1;

  int mid = s + (e - s) / 2;

  // element found
  if (arr[mid] == k)
    return mid;

  if (arr[mid] < k) {
    return binarySearch(arr, mid + 1, e, k);
  } else {
    return binarySearch(arr, s, mid - 1, k);
  }
}

int main() {

  int arr[6] = {2, 4, 6, 10, 14, 15};
  int size = 6;
  int key = 15;

  int index = binarySearch(arr, 0, size - 1, key);
  cout << endl;

  if (index != -1) {
    cout << "Element Present at index: " << index << endl;
  } else {
    cout << "Element not Present" << endl;
  }

  return 0;
}