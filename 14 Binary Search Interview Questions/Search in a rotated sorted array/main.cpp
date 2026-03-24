// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[start] <= nums[mid]) {
            if (target >= nums[start] && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {12, 15, 18, 2, 4};
    cout << search(arr, 2);

    return 0;
}
