// 1218. Longest Arithmetic Subsequence of Given Difference
// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int>& arr, int difference) {
    int N = arr.size();
    unordered_map<int, int> dp;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      dp[arr[i]] = max(dp[arr[i]], dp[arr[i] - difference] + 1);
      ans = max(ans, dp[arr[i]]);
    }
    return ans;
  }
};
