#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int start2 = mid + 1;

  // If already sorted
  if (arr[mid] <= arr[start2])
    return;

  while (left <= mid && start2 <= right) {

    if (arr[left] <= arr[start2]) {
      left++;
    } else {
      int value = arr[start2];
      int index = start2;

      // Shift elements
      while (index != left) {
        arr[index] = arr[index - 1];
        index--;
      }

      arr[left] = value;

      left++;
      mid++;
      start2++;
    }
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = 6;

  mergeSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  for(auto i : arr) {
    cout << i << " ";
  }

  return 0;
}