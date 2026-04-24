// 2833. Furthest Point From Origin
// https://leetcode.com/problems/furthest-point-from-origin/

#include <cmath>
#include <string>

using namespace std;

class Solution {
 public:
  int furthestDistanceFromOrigin(string moves) {
    int l = 0, r = 0, u = 0;
    for (const char& ch : moves) {
      if (ch == 'L') { ++l; }
      if (ch == 'R') { ++r; }
      if (ch == '_') { ++u; }
    }
    return abs(l - r) + u;
  }
};
