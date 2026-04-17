// 3761. Minimum Absolute Distance Between Mirror Pairs
// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/

#include <algorithm>
#include <limits>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  int reverse(int num) {
    int ans = 0;
    while (num) {
      ans *= 10;
      ans += num % 10;
      num /= 10;
    }
    return ans;
  }

 public:
  int minMirrorPairDistance(vector<int>& nums) {
    int n = nums.size(), ans = numeric_limits<int>::max();
    unordered_map<int, stack<int>> idxs;
    for (int i = n - 1; i >= 0; --i) { idxs[nums[i]].push(i); }
    for (int i = 0; i < n; ++i) {
      idxs[nums[i]].pop();
      int rev = reverse(nums[i]);
      if (!idxs[rev].empty()) { ans = min(ans, idxs[rev].top() - i); }
    }
    return ans == numeric_limits<int>::max() ? -1 : ans;
  }
};
