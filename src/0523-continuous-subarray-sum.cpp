// 523. Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sum;
    int n = nums.size();
    int curr = 0;
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
      curr = (curr + nums[i]) % k;
      if (sum.find(curr) != sum.end()) {
        if (i + 1 - sum[curr] >= 2) { return true; }
      } else {
        sum[curr] = i + 1;
      }
    }
    return false;
  }
};
