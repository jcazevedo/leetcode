// 3434. Maximum Frequency After Subarray Operation
// https://leetcode.com/problems/maximum-frequency-after-subarray-operation/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    int N = nums.size();
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (nums[i] == k) { ++cnt; }
    }
    int chg = 0;
    for (int t = 1; t <= 50; ++t) {
      if (t == k) { continue; }
      int curr = 0;
      int best = 0;
      for (int i = 0; i < N; ++i) {
        if (nums[i] == t) { ++curr; }
        if (nums[i] == k) { --curr; }
        curr = max(curr, 0);
        best = max(best, curr);
      }
      chg = max(chg, best);
    }
    return cnt + chg;
  }
};
