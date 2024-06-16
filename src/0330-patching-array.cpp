// 330. Patching Array
// https://leetcode.com/problems/patching-array/

#include <vector>

using namespace std;

class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    int patches = 0;
    long long missing = 1L;
    int idx = 0;
    int N = nums.size();
    while (missing <= n) {
      if (idx < N && nums[idx] <= missing) {
        missing += nums[idx];
        ++idx;
      } else {
        missing += missing;
        ++patches;
      }
    }
    return patches;
  }
};
