#include <iostream>
#include <algorithm>
using namespace std;

void swapAlter(int arr[], int size) {
    int a = 0, b = 1;

    while(b < size) {
        swap(arr[a], arr[b]);
        a += 2;
        b += 2;
    }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};
  int size = sizeof(arr) / sizeof(arr[0]);

  swapAlter(arr, size);

  for(int i = 0; i < size; i++) {
    cout << arr[i] << ", ";
  }
  return 0;
}