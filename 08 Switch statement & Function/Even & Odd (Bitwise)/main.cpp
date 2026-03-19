// Even number → last bit = 0

// Odd number → last bit = 1

#include <iostream>
using namespace std;

bool isEven(int n) {
  if(n & 1) { // even
    return false;
  } else { // odd
    return true;
  }
}

int main() {
  if(isEven(44)) {
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }
  return 0;
}