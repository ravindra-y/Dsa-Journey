#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {

  if (n == 0)
    return -1;

  if (arr[0] == key)
    return 0;

  int index = linearSearch(arr + 1, n - 1, key);

  if (index == -1)
    return -1;
  else
    return index + 1;
}

int main() {

  int arr[] = {10, 20, 30, 40, 50};
  int n = 5;
  int key = 30;

  int result = linearSearch(arr, n, key);

  if (result == -1)
    cout << "Element not found";
  else
    cout << "Element found at index " << result;

  return 0;
}