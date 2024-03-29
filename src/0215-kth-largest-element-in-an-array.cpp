// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (auto v : nums) { pq.push(v); }
    while (k > 1) {
      pq.pop();
      k--;
    }
    return pq.top();
  }
};
