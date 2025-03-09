// 3208. Alternating Groups II
// https://leetcode.com/problems/alternating-groups-ii/

#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size();
    vector<int> dp(n * 2);
    dp[0] = 1;
    for (int i = 1; i < n * 2; ++i) {
      if (colors[i % n] == colors[(i - 1) % n]) {
        dp[i] = 1;
      } else {
        dp[i] = dp[i - 1] + 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (dp[i + k - 1] >= k) { ++ans; }
    }
    return ans;
  }
};
