#include <vector>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int N = nums.size();
    int sum = 0;
    for (int n : nums)
      sum += n;
    if (sum % 2 != 0)
      return false;
    vector<vector<bool>> dp = vector<vector<bool>>(sum + 1,
                                                   vector<bool>(N + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; ++i) {
      for (int s = 0; s < sum; ++s) {
        if (dp[s][i]) {
          dp[s][i + 1] = true;
          dp[s + nums[i]][i + 1] = true;
        }
      }
    }
    return dp[sum / 2][N];
  }
};
