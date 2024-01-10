// 446. Arithmetic Slices II - Subsequence
// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int N = nums.size();
    vector<unordered_map<long long, int>> dp(N);
    int ans = 0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < i; ++j) {
        long long diff = (long long)nums[j] - nums[i];
        dp[i][diff] += 1;
        if (dp[j].find(diff) != dp[j].end()) {
          dp[i][diff] += dp[j][diff];
          ans += dp[j][diff];
        }
      }
    return ans;
  }
};
