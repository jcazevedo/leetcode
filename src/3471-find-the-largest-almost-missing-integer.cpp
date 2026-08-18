// 3471. Find the Largest Almost Missing Integer
// https://leetcode.com/problems/find-the-largest-almost-missing-integer/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestInteger(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for (int num : nums) { ++cnt[num]; }
    int ans = -1;
    if (k == 1) {
      for (int num : nums) {
        if (cnt[num] == 1) { ans = max(ans, num); }
      }
    } else if (k == (int)nums.size()) {
      for (int num : nums) { ans = max(ans, num); }
    } else {
      if (cnt[nums[0]] == 1) { ans = max(ans, nums[0]); }
      if (cnt[nums.back()] == 1) { ans = max(ans, nums.back()); }
    }
    return ans;
  }
};
