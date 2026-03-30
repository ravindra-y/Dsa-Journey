#include <iostream>
#include <vector>
using namespace std;

int main() {

  // ===== Vector Declaration (Empty Vector) =====
  // Time: O(1)
  // Space: O(1)
  vector<int> v;

  // ===== Vector Initialization (Size + Default Value) =====
  // Creates 5 elements initialized to 1
  // Time: O(n)
  // Space: O(n)
  vector<int> a(5, 1);

  // ===== Copy Constructor =====
  // Copies all elements from 'a'
  // Time: O(n)
  // Space: O(n)
  vector<int> last(a);

  // ===== Size Operation =====
  // Time: O(1)
  cout << "Size: " << v.size() << endl;

  // ===== Push Back Operation =====
  // Time: Amortized O(1)
  // Worst Case: O(n) (when reallocation happens)
  v.push_back(1);
  cout << "Capacity: " << v.capacity() << endl;

  v.push_back(2);
  cout << "Capacity: " << v.capacity() << endl;

  v.push_back(3);
  cout << "Capacity: " << v.capacity() << endl;
  cout << "Size: " << v.size() << endl;

  // ===== Element Access (Bounds Checked) =====
  // Time: O(1)
  cout << "Element at 2nd Index: " << v.at(2) << endl;

  // ===== Front & Back Access =====
  // Time: O(1)
  cout << "Front: " << v.front() << endl;
  cout << "Back: " << v.back() << endl;

  // ===== Traversal (Range-based loop) =====
  // Time: O(n)
  cout << "Before pop" << endl;
  for(int i : v) {
    cout << i << " ";
  } cout << endl;

  // ===== Pop Back =====
  // Time: O(1)
  v.pop_back();

  // ===== Traversal Again =====
  // Time: O(n)
  cout << "After pop" << endl;
  for(int i : v) {
    cout << i << " ";
  } cout << endl;

  // ===== Clear Vector =====
  // Time: O(n) (destroys all elements)
  // Capacity remains unchanged
  cout << "Before clear size: " << v.size() << endl;
  v.clear();
  cout << "After clear size: " << v.size() << endl;

  return 0;
}
