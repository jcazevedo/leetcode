// 673. Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int N = nums.size();
    vector<int> count(N, 1);
    vector<int> length(N, 1);
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i]) {
          if (length[j] + 1 > length[i]) {
            length[i] = length[j] + 1;
            count[i] = count[j];
          } else if (length[j] + 1 == length[i])
            count[i] += count[j];
        }
    int maxLength = 0;
    for (int i = 0; i < N; ++i)
      maxLength = max(length[i], maxLength);
    int ans = 0;
    for (int i = 0; i < N; ++i)
      if (length[i] == maxLength)
        ans += count[i];
    return ans;
  }
};
