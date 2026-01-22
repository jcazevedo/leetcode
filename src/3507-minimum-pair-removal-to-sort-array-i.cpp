// 3507. Minimum Pair Removal to Sort Array I
// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/

#include <vector>

using namespace std;

class Solution {
 private:
  bool isSorted(const vector<int>& nums) {
    for (int i = 1; i < (int)nums.size(); ++i) {
      if (nums[i] < nums[i - 1]) { return false; }
    }
    return true;
  }

 public:
  int minimumPairRemoval(vector<int>& nums) {
    int ans = 0;
    while (!isSorted(nums)) {
      int minSum = nums[0] + nums[1];
      int minIdx = 0;
      for (int i = 1; i < (int)nums.size() - 1; ++i) {
        if (nums[i] + nums[i + 1] < minSum) {
          minSum = nums[i] + nums[i + 1];
          minIdx = i;
        }
      }
      nums[minIdx] = minSum;
      nums.erase(nums.begin() + minIdx + 1);
      ++ans;
    }
    return ans;
  }
};
