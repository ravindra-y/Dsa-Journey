#include <iostream>
using namespace std;

// Function to find the unique element
int uniqueElement(int arr[], int size) {
  int unique = 0;
  for (int i = 0; i < size; i++) {
    unique ^= arr[i];
  }
  return unique;
}

int main() {
  int arr[] = {1, 2, 1, 3, 4, 3, 2};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Unique Element in the Array [";
  for (int i = 0; i < size; i++) {
    cout << arr[i];
    if (i < size - 1)
      cout << ", ";
  }
  cout << "] is: " << uniqueElement(arr, size) << endl;

  return 0;
}