// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while(start < end) {
        int mid = start + (end - start) / 2;

        if(arr[mid] < arr[mid + 1]) {
            // ascending part
            start = mid + 1;
        } else {
            // descending part
            end = mid;
        }
    }

    return start;
}

int main() {
    vector<int> vec = {0, 10, 5, 2};
    cout << "Index: " << peakIndexInMountainArray(vec) << endl;
    return 0;
}
