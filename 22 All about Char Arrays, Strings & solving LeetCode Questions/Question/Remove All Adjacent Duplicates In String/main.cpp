//? https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <iostream>
using namespace std;

string removeDuplicates(string s) {
  string result;

  for(char c : s) {
    if(!result.empty() && result.back() == c) {
      result.pop_back(); // remove duplicate pair
    } else {
      result.push_back(c);
    }
  }

  return result;
}

int main() {
  string s = "abbaca";

  removeDuplicates(s);

  cout << s << endl;
  
  return 0;
}