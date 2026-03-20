#include <iostream>
using namespace std;

int duplicate(int arr[], int size) {
    int ans = 0;

    // XOR all array elements
    for (int i = 0; i < size; i++) {
        ans ^= arr[i];
    }

    // XOR numbers from 1 to size-1
    for (int i = 1; i < size; i++) {
        ans ^= i;
    }

    return ans;
}

int main() {
    int arr[] = {1, 3, 4, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Duplicate: " << duplicate(arr, size);
    return 0;
}
