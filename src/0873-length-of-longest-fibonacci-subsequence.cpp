// 873. Length of Longest Fibonacci Subsequence
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size(), ans = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    unordered_map<int, int> indexOf;
    for (int i = 0; i < n; ++i) {
      indexOf[arr[i]] = i;
      for (int j = 0; j < i; ++j) {
        int diff = arr[i] - arr[j];
        if (indexOf.count(diff) && diff < arr[j]) {
          dp[j][i] = dp[indexOf[diff]][j] + 1;
        } else {
          dp[j][i] = 2;
        }
        ans = max(ans, dp[j][i]);
      }
    }
    return ans > 2 ? ans : 0;
  }
};
