// Given an array/list 'arr' of integers ans postion 'm'. You have to reverse the array after that posion.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void reverseArr(vector<int> &arr, int m) {
  int s = m + 1, e = arr.size() - 1;

  while (s <= e) {
    swap(arr[s], arr[e]);
    s++;
    e--;
  }
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  int m = 3;
  reverseArr(arr, m);

  for (int val : arr) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}