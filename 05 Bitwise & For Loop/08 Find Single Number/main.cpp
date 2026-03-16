#include <iostream>
using namespace std;

int main() {
  int arr[] = {2, 3, 2, 4, 4};
  int n = 5;
  int ans = 0;

  for (int i = 0; i < n; i++)
    ans ^= arr[i];

  cout << ans;

  return 0;
}