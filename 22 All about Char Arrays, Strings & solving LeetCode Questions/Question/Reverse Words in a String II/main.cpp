#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

void reverseWords(vector<char> &s) {
  reverse(s.begin(), s.end());

  int start = 0;

  for (int end = 0; end < s.size(); end++) {
    if (s[end] == ' ') {
      reverse(s.begin() + start, s.begin() + end);
      start = end + 1;
    }
  }

  reverse(s.begin() + start, s.end());
}

int main() {
  string str = "the sky is blue";
  vector<char> s(str.begin(), str.end());

  reverseWords(s);

  for (char c : s)
    cout << c;

  return 0;
}
