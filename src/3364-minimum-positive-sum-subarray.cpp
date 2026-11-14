// 3364. Minimum Positive Sum Subarray
// https://leetcode.com/problems/minimum-positive-sum-subarray/

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int n = nums.size();
    vector<int> prefix(n + 1);
    for (int i = 0; i < n; ++i) { prefix[i + 1] = prefix[i] + nums[i]; }
    int ans = -1;
    multiset<int> window;
    for (int j = l; j <= n; ++j) {
      window.insert(prefix[j - l]);
      if (j > r) { window.erase(window.find(prefix[j - r - 1])); }
      multiset<int>::iterator it = window.lower_bound(prefix[j]);
      if (it != window.begin()) {
        --it;
        if (ans == -1) {
          ans = prefix[j] - *it;
        } else {
          ans = min(ans, prefix[j] - *it);
        }
      }
    }
    return ans;
  }
};
