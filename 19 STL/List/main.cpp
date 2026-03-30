#include <iostream>
#include <list>
using namespace std;

int main() {

  // ===== List Declaration (Empty List) =====
  // Time: O(1)
  // Space: O(1)
  list<int> l;

  // ===== List Initialization (Size + Default Value) =====
  // Creates 5 nodes with value 100
  // Time: O(n)
  // Space: O(n)
  list<int> n(5, 100);

  // ===== Traversal =====
  // Time: O(n)
  for(int i : n) {
    cout << i << " ";
  }
  cout << endl;

  // ===== Insertion (if used) =====
  // l.push_back(1);   -> O(1)
  // l.push_front(2);  -> O(1)

  // ===== Erase (if used) =====
  // l.erase(l.begin()); -> O(1)
  // (If iterator already points to position)

  // ===== Size (if used) =====
  // l.size(); -> O(1) in modern C++ (C++11+)

  return 0;
}
