#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> vec) {
    int start = 0, end = vec.size() - 1;
    
    while(start < end) {
        int mid = start + (end - start)/2;

        if(vec[mid] >= vec[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return start;
}

int main() {
  vector <int> vec = {8, 10, 17, 1, 3};

  cout << "Pivot: " << getPivot(vec) << endl;
  return 0;
}