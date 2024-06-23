// 2294. Partition Array Such That Maximum Difference Is K
// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int partitionArray(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : nums) { pq.push(num); }
    int ans = 0;
    while (!pq.empty()) {
      ++ans;
      int minV = pq.top();
      pq.pop();
      while (!pq.empty() && pq.top() - minV <= k) { pq.pop(); }
    }
    return ans;
  }
};
