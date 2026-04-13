// Find sum of all element

#include <iostream>
using namespace std;

int allSum(int *arr, int n) {
  if (n == 0) {
    return 0;
  }

  return arr[0] + allSum(arr + 1, n - 1);
}

int main() {
  int arr[5] = {3, 2, 5, 1, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Sum = " << allSum(arr, n) << endl;

  return 0;
}

/*

allSum([a1,a2,a3,a4],4)
│
├── a1 + allSum([a2,a3,a4],3)
│        │
│        ├── a2 + allSum([a3,a4],2)
│        │        │
│        │        ├── a3 + allSum([a4],1)
│        │        │        │
│        │        │        ├── a4 + allSum([],0)
│        │        │        │        │
│        │        │        │        └── 0   (base case)

*/