#include <deque>
#include <iostream>

using namespace std;

int main() {

  // ===== Deque Declaration =====
  // Time: O(1)
  // Space: O(1)
  deque<int> d;

  // ===== Insertion at Back =====
  // Time: O(1)
  d.push_back(1);

  // ===== Insertion at Front =====
  // Time: O(1)
  d.push_front(2);

  // ===== Traversal =====
  // Time: O(n)
  for (int i : d) {
    cout << i << " ";
  }
  cout << endl;

  // ===== Element Access (Bounds Checked) =====
  // Time: O(1)
  cout << "Print First Index Element: " << d.at(1) << endl;

  // ===== Access Front =====
  // Time: O(1)
  cout << "Front: " << d.front() << endl;

  // ===== Access Back =====
  // Time: O(1)
  cout << "Back: " << d.back() << endl;

  // ===== Check if Empty =====
  // Time: O(1)
  cout << "Empty or not: " << d.empty() << endl;

  // ===== Erase Operation =====
  // Erasing a range shifts elements
  // Time: O(n)
  cout << "Before erase: " << d.size() << endl;
  d.erase(d.begin(), d.begin() + 1);
  cout << "After erase: " << d.size() << endl;

  return 0;
}