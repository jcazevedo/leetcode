// 646. Maximum Length of Pair Chain
// https://leetcode.com/problems/maximum-length-of-pair-chain/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    int N = pairs.size();
    sort(pairs.begin(), pairs.end(), [](const vector<int>& v1, const vector<int>& v2) { return v1[1] < v2[1]; });
    vector<int> dp(N, 1);
    for (int i = 1; i < N; ++i)
      for (int j = 0; j < i; ++j)
        if (pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i], dp[j] + 1);
    int ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, dp[i]);
    return ans;
  }
};
