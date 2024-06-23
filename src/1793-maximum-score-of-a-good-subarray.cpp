// 1793. Maximum Score of a Good Subarray
// https://leetcode.com/problems/maximum-score-of-a-good-subarray/

#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> right(n, 0);
    vector<int> left(n, 0);
    stack<int> s;
    s.push(n);
    for (int i = n - 1; i >= 0; i--) {
      while (s.top() != n && nums[s.top()] >= nums[i]) { s.pop(); }
      right[i] = s.top();
      s.push(i);
    }
    while (!s.empty()) { s.pop(); }
    s.push(-1);
    for (int i = 0; i < n; ++i) {
      while (s.top() != -1 && nums[s.top()] >= nums[i]) { s.pop(); }
      left[i] = s.top();
      s.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (k < right[i] && k > left[i]) { ans = max(ans, nums[i] * (right[i] - left[i] - 1)); }
    }
    return ans;
  }
};
