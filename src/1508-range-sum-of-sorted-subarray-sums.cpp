// 1508. Range Sum of Sorted Subarray Sums
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

#include <queue>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> sums(n, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        sums[j] += nums[i];
        pq.push(sums[j]);
      }
      sums[i] = nums[i];
      pq.push(sums[i]);
    }
    long long ans = 0;
    int idx = 1;
    while (idx <= right) {
      int curr = pq.top();
      pq.pop();
      if (idx >= left) { ans = (ans + curr) % MOD; }
      ++idx;
    }
    return ans;
  }
};
