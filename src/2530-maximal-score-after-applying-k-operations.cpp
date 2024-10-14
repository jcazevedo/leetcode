// 2530. Maximal Score After Applying K Operations
// https://leetcode.com/problems/maximal-score-after-applying-k-operations/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int num : nums) { pq.push(num); }
    long long ans = 0L;
    while (k--) {
      int curr = pq.top();
      pq.pop();
      ans += curr;
      pq.push((curr + 2) / 3);
    }
    return ans;
  }
};
