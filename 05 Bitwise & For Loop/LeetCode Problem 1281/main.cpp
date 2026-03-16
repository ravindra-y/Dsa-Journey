// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/

#include <iostream>
using namespace std;

int subtractProductAndSum(int n) {
    int Prod = 1, Sum = 0;

    while(n != 0) {
        int lastDig = n % 10;
        Prod *= lastDig;
        Sum += lastDig;
        n /= 10;
    }

    return (Prod - Sum);
}

int main() {
    int n;
    cout << "Enter num: ";
    cin >> n;

    cout << "Answer = " << subtractProductAndSum(n) << endl;

    return 0;
}