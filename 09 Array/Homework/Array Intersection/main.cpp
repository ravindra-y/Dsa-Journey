#include <iostream>
using namespace std;

void arrIntersection(int arrA[], int n, int arrB[], int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arrA[i] == arrB[j]) {
                cout << arrA[i] << ", ";
            }
        }
    }
}

int main() {
  int arrA[] = {1, 2, 3, 4};
  int n = sizeof(arrA) / sizeof(arrA[0]);
  int arrB[] = {2, 4, 6, 8};
  int m = sizeof(arrB) / sizeof(arrB[0]);

  arrIntersection(arrA, n, arrB, m);
  return 0;
}