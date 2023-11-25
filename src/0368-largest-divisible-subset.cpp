// 368. Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return {};
    sort(nums.begin(), nums.end());
    vector<int> cnt(N, 1);
    vector<int> prev(N, -1);
    int max_idx = 0;
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && cnt[i] < cnt[j] + 1) {
          cnt[i] = cnt[j] + 1;
          prev[i] = j;
        }
      }
      if (cnt[max_idx] < cnt[i]) max_idx = i;
    }
    vector<int> res;
    while (max_idx >= 0) {
      res.push_back(nums[max_idx]);
      max_idx = prev[max_idx];
    }
    return res;
  }
};
