#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter num: ";
  cin >> n;

  for(int i = 2; i < n; i++) {
    if(n % i == 0) {
        cout << "Not Prime Number" << endl;
        break;
    } else {
        cout << "Prime Number" << endl;
        break;
    }
  }
  return 0;
}