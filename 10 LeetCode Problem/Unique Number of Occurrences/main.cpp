// https://leetcode.com/problems/unique-number-of-occurrences/description/

#include <iostream>
#include <vector>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    // Step 1: frequency array
    int freq[2001] = {0};  // index = value + 1000
        
    for (int num : arr) {
        freq[num + 1000]++;
    }
        
    // Step 2: check if frequencies are unique
    bool used[1001] = {false};  // max possible frequency
        
    for (int i = 0; i < 2001; i++) {
        if (freq[i] > 0) {
            if (used[freq[i]]) {
                 return false;  // duplicate frequency found
            }
            used[freq[i]] = true;
        }
    }
        
    return true;
}

int main() {
  vector<int> arr = {1, 2, 2, 1, 1, 3};
  return 0;
}

// https://www.youtube.com/watch?v=oVa8DfUDKTw&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=10