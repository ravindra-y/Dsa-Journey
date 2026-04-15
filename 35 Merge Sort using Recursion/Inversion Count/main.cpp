#include <iostream>
#include <vector>
using namespace std;

long merge(vector<long> &arr, long s, long e) {
  long ans = 0;

  long mid = (s + e) / 2;

  int l1 = mid - s + 1;
  int l2 = e - mid;

  vector<long> a1(l1);
  vector<long> a2(l2);

  long idx = s;

  // copy elements
  for (int i = 0; i < l1; i++) {
    a1[i] = arr[idx++];
  }

  for (int i = 0; i < l2; i++) {
    a2[i] = arr[idx++];
  }

  int idx1 = 0;
  int idx2 = 0;
  idx = s;

  while (idx1 < l1 && idx2 < l2) {

    if (a1[idx1] > a2[idx2]) {
      ans += (l1 - idx1);
      arr[idx++] = a2[idx2++];
    } else {
      arr[idx++] = a1[idx1++];
    }
  }

  while (idx1 < l1) {
    arr[idx++] = a1[idx1++];
  }

  while (idx2 < l2) {
    arr[idx++] = a2[idx2++];
  }

  return ans;
}

long countInv(vector<long> &arr, long s, long e) {
  if (s >= e)
    return 0;

  long mid = (s + e) / 2;

  long inv = countInv(arr, s, mid);
  inv += countInv(arr, mid + 1, e);
  inv += merge(arr, s, e);

  return inv;
}

long inversionCount(vector<long> &arr, long N) {
  return countInv(arr, 0, N - 1);
}

int main() {
  long N;

  cout << "Enter number of elements: ";
  cin >> N;

  vector<long> arr(N);

  cout << "Enter array elements:\n";
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  long result = inversionCount(arr, N);

  cout << "Number of inversions: " << result << endl;

  return 0;
}