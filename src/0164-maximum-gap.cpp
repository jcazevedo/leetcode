// 164. Maximum Gap
// https://leetcode.com/problems/maximum-gap/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    int N = nums.size();
    if (N == 1) { return 0; }
    int mn = numeric_limits<int>::max(), mx = numeric_limits<int>::min();
    for (int i = 0; i < N; ++i) {
      mn = min(mn, nums[i]);
      mx = max(mx, nums[i]);
    }
    int gap = mx - mn > 0 ? max(1, (mx - mn) / (N - 1)) : 1;
    int B = (mx - mn) / gap + 1;
    vector<vector<int>> buckets(B, {numeric_limits<int>::max(), numeric_limits<int>::min()});
    for (int i = 0; i < N; ++i) {
      int b = (nums[i] - mn) / gap;
      buckets[b][0] = min(buckets[b][0], nums[i]);
      buckets[b][1] = max(buckets[b][1], nums[i]);
    }
    int ans = 0;
    int prev = numeric_limits<int>::max();
    for (int i = 0; i < B; ++i) {
      if (buckets[i][0] > buckets[i][1]) { continue; }
      ans = max(ans, buckets[i][0] - prev);
      prev = buckets[i][1];
    }
    return ans;
  }
};
