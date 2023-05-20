// 740. Delete and Earn
// https://leetcode.com/problems/delete-and-earn/

#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
private:
  int score[10001];
  int dp[10001];
  int go(int n) {
    if (n < 0)
      return 0;
    if (dp[n] == -1)
      dp[n] = max(score[n] + go(n - 2), go(n - 1));
    return dp[n];
  }

public:
  int deleteAndEarn(vector<int>& nums) {
    memset(score, 0, sizeof(score));
    memset(dp, -1, sizeof(dp));
    int largest = nums[0];
    for (int num : nums) {
      score[num] += num;
      largest = max(largest, num);
    }
    return go(largest);
  }
};
