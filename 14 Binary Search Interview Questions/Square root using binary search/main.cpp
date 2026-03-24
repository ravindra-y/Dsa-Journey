// https://leetcode.com/problems/sqrtx/description/

#include <iostream>
using namespace std;

int mySqrt(int x) {
    int start = 0, end = x;
    int ans = 0;

    while(start <= end) {
      int mid = start + (end - start) / 2;
      long long int square = mid * mid;
      
      if(square == x) {
        return mid;
      }

      if(square > x) {
        end = mid - 1;
      } else {
        ans = mid;
        start = mid + 1;
      }
    }

    return ans;
}

int main() {
  int n;
  cout << "Enter num: ";
  cin >> n;

  cout << "Square root: " << mySqrt(n) << endl;
  return 0;
}