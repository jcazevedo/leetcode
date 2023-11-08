// 2849. Determine if a Cell Is Reachable at a Given Time
// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

#include <algorithm>

using namespace std;

class Solution {
public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    if (fx == sx && fy == sy)
      return t == 0 || t > 1;
    return t >= max(abs(fx - sx), abs(fy - sy));
  }
};
