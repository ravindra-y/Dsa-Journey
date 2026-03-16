// https://leetcode.com/problems/number-of-1-bits/description/

#include <iostream>
#include <cstdint>
using namespace std;

int hammingWeight(uint32_t n) {
  int countBit = 0;

  while (n != 0) {
    if (n & 1) {
      // checking last bit
      countBit++;
    }
    n = n >> 1;
  }

  return countBit;
}

int main() {
  int n;
  cout << "Enter num: ";
  cin >> n;

  cout << "Number is one bits in " << n << " is: " << hammingWeight(n) << endl;
  return 0;
}