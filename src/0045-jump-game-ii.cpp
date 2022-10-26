// 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 private:
  int go(vector<int>& nums, vector<int>& cache, int i) {
    if (i >= (int)nums.size()) return nums.size() + 1;
    if (cache[i] == -1) {
      if (i == (int)nums.size() - 1)
        cache[i] = 0;
      else {
        int ans = nums.size() + 1;
        for (int j = 1; j <= nums[i]; ++j) ans = min(ans, 1 + go(nums, cache, i + j));
        cache[i] = ans;
      }
    }
    return cache[i];
  }

 public:
  int jump(vector<int>& nums) {
    vector<int> cache = vector<int>(nums.size(), -1);
    return go(nums, cache, 0);
  }
};
