#include <iostream>
using namespace std;

void reverse(string &str, int i) {
  int n = str.length();
  
  // base case
  if(i > n-i-1) return;

  swap(str[i], str[n-i-1]);
  i++;

  reverse(str, i);

}

int main() {
  string name = "abcdefg";

  reverse(name, 0);

  for(char st : name) {
    cout << st << " ";
  }
  return 0;
}