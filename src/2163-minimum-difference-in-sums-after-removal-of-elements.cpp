// 2163. Minimum Difference in Sums After Removal of Elements
// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/

#include <limits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minimumDifference(vector<int>& nums) {
    int l = nums.size(), n = l / 3;
    priority_queue<int> prePQ;
    vector<long long> pre(l);
    pre[0] = nums[0];
    prePQ.push(nums[0]);
    for (int i = 1; i < l; ++i) {
      pre[i] = pre[i - 1] + nums[i];
      prePQ.push(nums[i]);
      if ((int)prePQ.size() > n) {
        pre[i] -= prePQ.top();
        prePQ.pop();
      }
    }
    priority_queue<int, vector<int>, greater<int>> sufPQ;
    vector<long long> suf(l);
    suf[l - 1] = nums[l - 1];
    sufPQ.push(nums[l - 1]);
    for (int i = l - 2; i >= 0; --i) {
      suf[i] = suf[i + 1] + nums[i];
      sufPQ.push(nums[i]);
      if ((int)sufPQ.size() > n) {
        suf[i] -= sufPQ.top();
        sufPQ.pop();
      }
    }
    long long ans = numeric_limits<long long>::max();
    for (int i = n - 1; i < 2 * n; ++i) { ans = min(ans, pre[i] - suf[i + 1]); }
    return ans;
  }
};
