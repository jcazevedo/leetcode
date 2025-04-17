// 2176. Count Equal and Divisible Pairs in an Array
// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

#include <vector>

using namespace std;

class Solution {
 public:
  int countPairs(vector<int>& nums, int k) {
    int ans = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((i * j) % k != 0) { continue; }
        if (nums[i] != nums[j]) { continue; }
        ++ans;
      }
    }
    return ans;
  }
};
