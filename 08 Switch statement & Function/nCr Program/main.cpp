#include <iostream>
using namespace std;

int factorial(int a) {
    int fact = 1;

    for(int i = 1; i < a; i++) {
        fact = fact * i;
    }

    return fact;
}

int nCr(int n, int r) {
    int factN = factorial(n);
    int factR = factorial(r);
    int factNmR = factorial(n - r);

    return factN / (factR * factNmR);
}

int main() {
  cout << nCr(13, 0) << endl;
  return 0;
}

// nCr = n! / r! * (n-r)!