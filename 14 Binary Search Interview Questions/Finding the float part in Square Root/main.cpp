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

double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;

    for(int i = 0; i < precision; i++) {
      factor = factor / 10;

      for(double j = ans; j*j < n; j += factor) {
        ans = j;
      }
    }

    return ans;
}

int main() {
  int n;
  cout << "Enter num: ";
  cin >> n;

  cout << "Square root: " << mySqrt(n) << endl;
  cout << "Square root with decimal: " << morePrecision(n, 3, mySqrt(n)) << endl;
  return 0;
}