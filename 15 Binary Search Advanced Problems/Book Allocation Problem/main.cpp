#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &books, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {

        if (pageSum + books[i] <= mid) {
            pageSum += books[i];
        } 
        else {
            studentCount++;
            
            if (studentCount > m || books[i] > mid) {
                return false;
            }

            pageSum = books[i];
        }
    }

    return true;
}

int allocateBooks(vector<int> &books, int n, int m) {

    if (m > n) {
        return -1;
    }

    int start = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += books[i];
    }

    int end = sum;
    int ans = -1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (isPossible(books, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } 
        else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {

    vector<int> books = {10, 20, 30, 40};
    int n = books.size();
    int m = 2;

    cout << "Minimum pages = " << allocateBooks(books, n, m);

    return 0;
}