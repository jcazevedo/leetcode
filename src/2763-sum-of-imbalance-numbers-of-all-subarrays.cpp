// 2763. Sum of Imbalance Numbers of All Subarrays
// https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumImbalanceNumbers(vector<int>& nums) {
    int ans = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      int curr = 0, minV = nums[i], maxV = nums[i];
      unordered_set<int> visited;
      visited.insert(nums[i]);
      for (int j = i + 1; j < n; ++j) {
        if (!visited.count(nums[j])) {
          if (nums[j] < minV) {
            if (nums[j] < minV - 1) { ++curr; }
          } else if (nums[j] > maxV) {
            if (nums[j] > maxV + 1) { ++curr; }
          } else {
            if (visited.count(nums[j] - 1) && visited.count(nums[j] + 1)) {
              --curr;
            } else if (!visited.count(nums[j] + 1) && !visited.count(nums[j] - 1)) {
              ++curr;
            }
          }
        }
        visited.insert(nums[j]);
        minV = min(minV, nums[j]);
        maxV = max(maxV, nums[j]);
        ans += curr;
      }
    }
    return ans;
  }
};
