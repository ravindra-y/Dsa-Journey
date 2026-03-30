#include <iostream>
#include <array>
using namespace std;

int main() {

  // ===== Static Array (Fixed Size, Stack Allocation) =====
  // Time Complexity: O(1) initialization (constant size)
  int basic[3] = {1, 2, 3};


  // ===== STL std::array (Fixed Size Container) =====
  // Time Complexity: O(1) initialization (constant size)
  array<int, 4> a = {1, 2, 3, 4};


  // ===== Size Operation =====
  // Time Complexity: O(1)
  int size = a.size();


  // ===== Traversal =====
  // Time Complexity: O(n)
  // Where n = number of elements in array
  for(int i = 0; i < size; i++) {
    cout << a[i] << endl;  // O(1) per access
  }


  // ===== Element Access (Bounds Checked) =====
  // Time Complexity: O(1)
  cout << "Element at 2nd Index: " << a.at(2) << endl;


  // ===== Check if Empty =====
  // Time Complexity: O(1)
  cout << "Empty or not: " << a.empty() << endl;


  // ===== Access First Element =====
  // Time Complexity: O(1)
  cout << "First Element: " << a.front() << endl;


  // ===== Access Last Element =====
  // Time Complexity: O(1)
  cout << "Last Element: " << a.back() << endl;

  return 0;
}
