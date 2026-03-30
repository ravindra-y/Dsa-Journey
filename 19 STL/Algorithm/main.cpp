#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;

  v.push_back(1);
  v.push_back(3);
  v.push_back(6);
  v.push_back(7);

  // cout << "Finding 6: " << binary_search(v.begin(), v.end(), 6) << endl;

  // cout << "Finding 6: " << lower_bound(v.begin(), v.end(), 6) - v.begin() <<
  // endl; cout << "Finding 6: " << upper_bound(v.begin(), v.end(), 6) -
  // v.begin() << endl;

  // int a = 3;
  // int b = 5;

  // cout << "Max: " << max(a, b) << endl;
  // cout << "Min: " << min(a, b) << endl;

  // swap(a, b);
  // cout << "a -> " << a << endl;
  // cout << "b -> " << b << endl;

  // string s = "abcd";
  // reverse(s.begin(), s.end());
  // cout << s << endl;

  // rotate(v.begin(), v.begin()+1, v.end());
  // cout <<"After rotate: " << endl;
  // for(auto i : v) {
  //   cout << i << " ";
  // }
  // cout << endl;

  // Based on Intro Sort -> Quick + Insertion + Heap
  sort(v.begin(), v.end());
  for (auto i : v) {
    cout << i << " ";
  }

  return 0;
}