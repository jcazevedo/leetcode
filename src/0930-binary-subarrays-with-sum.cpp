// 930. Binary Subarrays With Sum
// https://leetcode.com/problems/binary-subarrays-with-sum/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    int ans = 0, curr = 0, N = nums.size();
    unordered_map<int, int> cnt;
    for (int i = 0; i < N; ++i) {
      curr += nums[i];
      if (curr == goal) ++ans;
      ans += cnt[curr - goal];
      cnt[curr]++;
    }
    return ans;
  }
};
