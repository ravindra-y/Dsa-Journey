#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key) {
    int s = 0, e = n - 1;
    int ans = -1;

    while(s <= e) {
        int mid = s + (e - s) / 2;

        if(arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int n, int key) {
    int s = 0, e = n - 1;
    int ans = -1;

    while(s <= e) {
        int mid = s + (e - s) / 2;

        if(arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int countOcc(int l, int f) {
    int count = (l - f) + 1;
    return count;
}

int main() {
    int even[] = {1, 2, 3, 3, 3, 3, 5};
    int size = sizeof(even) / sizeof(even[0]);

    cout << "First occ: " << firstOcc(even, size, 3) << endl;
    cout << "Last occ: " << lastOcc(even, size, 3) << endl;

    cout << "Total occ: " << countOcc(lastOcc(even, size, 3), firstOcc(even, size, 3)) << endl;

    return 0;
}
