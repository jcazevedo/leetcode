// 334. Increasing Triplet Subsequence
// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <vector>

using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() == 0) return false;
    int N = nums.size();
    bool h2 = false, h3 = false;
    int n1 = nums[0], n2, n3;
    for (int i = 1; i < N; i++) {
      if (h2 && nums[i] > n2) return true;

      if (!h2 && nums[i] < n1) {
        n1 = nums[i];
      } else if (h2 && nums[i] > n1 && nums[i] < n2) {
        n2 = nums[i];
      } else if (!h2 && nums[i] > n1) {
        h2 = true;
        n2 = nums[i];
      } else if (h2 && ((!h3 && nums[i] < n1) || (h3 && nums[i] < n3))) {
        h3 = true;
        n3 = nums[i];
      } else if (h2 && h3 && nums[i] < n2 && nums[i] > n3) {
        n1 = n3;
        n2 = nums[i];
        h3 = false;
      }
    }
    return false;
  }
};
