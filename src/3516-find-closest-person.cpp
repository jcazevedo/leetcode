// 3516. Find Closest Person
// https://leetcode.com/problems/find-closest-person/

#include <cmath>

using namespace std;

class Solution {
 public:
  int findClosest(int x, int y, int z) {
    if (abs(z - y) > abs(z - x)) { return 1; }
    if (abs(z - x) > abs(z - y)) { return 2; }
    return 0;
  }
};
