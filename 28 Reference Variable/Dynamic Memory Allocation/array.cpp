#include <iostream>
using namespace std;

int getSum(int *arr, int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int *arr = new int[n];   // dynamic array

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "Answer: " << ans << endl;

    delete[] arr;   // Always free allocated memory

    return 0;
}