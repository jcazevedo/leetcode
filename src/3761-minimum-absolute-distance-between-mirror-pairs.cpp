// 3761. Minimum Absolute Distance Between Mirror Pairs
// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/

#include <algorithm>
#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  int reverse(int num) {
    int ans = 0;
    while (num) {
      ans = ans * 10 + num % 10;
      num /= 10;
    }
    return ans;
  }

 public:
  int minMirrorPairDistance(vector<int>& nums) {
    int n = nums.size(), ans = numeric_limits<int>::max();
    unordered_map<int, int> lastIdx;
    for (int i = 0; i < n; ++i) {
      unordered_map<int, int>::iterator it = lastIdx.find(nums[i]);
      if (it != lastIdx.end()) { ans = min(ans, i - it->second); }
      lastIdx[reverse(nums[i])] = i;
    }
    return ans == numeric_limits<int>::max() ? -1 : ans;
  }
};
