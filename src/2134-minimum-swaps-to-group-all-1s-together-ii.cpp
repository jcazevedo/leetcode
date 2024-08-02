// 2134. Minimum Swaps to Group All 1's Together II
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    int N = nums.size();
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (nums[i] == 0) { ++cnt; }
      nums.push_back(nums[i]);
    }
    int range = N - cnt;
    if (range == 0) { return 0; }
    vector<int> ps(2 * N, 0);
    ps[0] = nums[0] == 0;
    for (int i = 1; i < 2 * N; ++i) {
      ps[i] += ps[i - 1];
      if (nums[i] == 0) { ++ps[i]; }
    }
    int ans = numeric_limits<int>::max();
    for (int i = range - 1; i < 2 * N; ++i) {
      int curr = ps[i];
      if (i - range >= 0) { curr -= ps[i - range]; }
      ans = min(ans, curr);
    }
    return ans;
  }
};
