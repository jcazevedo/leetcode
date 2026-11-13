// 3420. Count Non-Decreasing Subarrays After K Operations
// https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/

#include <deque>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    long long cost = 0;
    long long ans = 0;
    deque<pair<int, int>> blocks;
    int right = n - 1;
    for (int left = n - 1; left >= 0; --left) {
      int count = 1;
      while (!blocks.empty() && blocks.front().first <= nums[left]) {
        int height = blocks.front().first;
        int size = blocks.front().second;
        blocks.pop_front();
        cost += 1LL * (nums[left] - height) * size;
        count += size;
      }
      blocks.emplace_front(nums[left], count);
      while (cost > k) {
        cost -= blocks.back().first - nums[right];
        if (--blocks.back().second == 0) { blocks.pop_back(); }
        --right;
      }
      ans += right - left + 1;
    }
    return ans;
  }
};
