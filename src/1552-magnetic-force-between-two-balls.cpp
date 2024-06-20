// 1552. Magnetic Force Between Two Balls
// https://leetcode.com/problems/magnetic-force-between-two-balls/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& position, int m) {
    int n = position.size();
    sort(position.begin(), position.end());
    int lo = 1;
    int hi = position[n - 1] - position[0];
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      int curr = 1;
      int prev = position[0];
      for (int i = 1; i < n && curr < m; ++i) {
        if (position[i] - prev >= mid) {
          ++curr;
          prev = position[i];
        }
      }
      if (curr < m)
        hi = mid - 1;
      else
        lo = mid;
    }
    return lo;
  }
};
