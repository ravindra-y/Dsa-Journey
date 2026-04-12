//? https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650

#include <iostream>
using namespace std;

int countDistinctWays(int nStairs) {
  // base case
  if(nStairs < 0) return 0;
  if(nStairs == 0) return 1;

  //recursive call
  int ans = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);

  return ans;
}

int main() {
  int nStairs;
  cout << "Enter Stairs: ";
  cin >> nStairs;

  cout << "Ways: " << countDistinctWays(nStairs) << endl;
  return 0;
}