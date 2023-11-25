// 1. Two Sum
// https://leetcode.com/problems/two-sum/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
      if (seen.count(target - nums[i]) > 0) return {seen[target - nums[i]], i};
      seen[nums[i]] = i;
    }
    return {-1, -1};
  }
};
