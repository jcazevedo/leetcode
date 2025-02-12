// 2342. Max Sum of a Pair With Equal Sum of Digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  int digitSum(int num) {
    int ans = 0;
    while (num) {
      ans += num % 10;
      num /= 10;
    }
    return ans;
  }

 public:
  int maximumSum(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, priority_queue<int>> sums;
    for (int i = 0; i < n; ++i) {
      int s = digitSum(nums[i]);
      sums[s].push(nums[i]);
    }
    int ans = -1;
    for (auto& [_, pq] : sums) {
      if (pq.size() >= 2) {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        ans = max(ans, n1 + n2);
      }
    }
    return ans;
  }
};
