//? https://www.naukri.com/code360/problems/replace-spaces_1172172

#include <iostream>
using namespace std;

void replaceSpaces(string &str) {
  int n = str.length();
  int cnt = 0;

  // count spaces
  for (int i = 0; i < n; i++) {
    if (str[i] == ' ')
      cnt++;
  }

  // resize
  str.resize(n + 2 * cnt);

  int i = n - 1;          // old end
  int j = str.length() - 1; // new end

  while (i >= 0) {
    if (str[i] == ' ') {
      str[j--] = '0';
      str[j--] = '4';
      str[j--] = '@';
    } else {
      str[j--] = str[i];
    }
    i--;
  }
}

int main() {
  string str = "Hello World";
  replaceSpaces(str);
  cout << str << endl;
  return 0;
}
