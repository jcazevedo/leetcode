// 3375. Minimum Operations to Make Array Values Equal to K
// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_set<int> unique;
    for (int i = 0; i < n; ++i) {
      if (nums[i] < k) { return -1; }
      if (nums[i] != k) { unique.insert(nums[i]); }
    }
    return unique.size();
  }
};
