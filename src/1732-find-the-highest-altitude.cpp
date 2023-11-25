// 1732. Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestAltitude(vector<int>& gain) {
    int ans = 0, curr = 0;
    for (int v : gain) {
      curr += v;
      ans = max(ans, curr);
    }
    return ans;
  }
};
