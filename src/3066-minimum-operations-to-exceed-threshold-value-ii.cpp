// 3066. Minimum Operations to Exceed Threshold Value II
// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int num : nums) { pq.push(num); }
    int ans = 0;
    while (pq.size() >= 2) {
      long long n1 = pq.top();
      pq.pop();
      long long n2 = pq.top();
      pq.pop();
      if (n1 >= k && n2 >= k) { break; }
      pq.push(min(n1, n2) * 2 + max(n1, n2));
      ++ans;
    }
    return ans;
  }
};
