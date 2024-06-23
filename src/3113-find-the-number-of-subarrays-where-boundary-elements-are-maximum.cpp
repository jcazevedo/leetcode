// 3113. Find the Number of Subarrays Where Boundary Elements Are Maximum
// https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long numberOfSubarrays(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> minPQ;
    unordered_map<int, int> prev;
    int n = nums.size();
    long long ans = 0L;
    for (int i = 0; i < n; ++i) {
      minPQ.push(nums[i]);
      prev[nums[i]]++;
      ans += prev[nums[i]];
      while (minPQ.top() < nums[i]) {
        prev[minPQ.top()] = 0;
        minPQ.pop();
      }
    }
    return ans;
  }
};
