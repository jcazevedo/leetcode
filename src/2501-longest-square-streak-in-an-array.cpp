// 2501. Longest Square Streak in an Array
// https://leetcode.com/problems/longest-square-streak-in-an-array/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    int N = nums.size();
    sort(begin(nums), end(nums));
    unordered_map<long long, int> len;
    int ans = -1;
    for (int i = N - 1; i >= 0; --i) {
      long long sq = ((long long)nums[i]) * nums[i];
      int l = len[sq] + 1;
      len[nums[i]] = l;
      ans = max(ans, l);
    }
    return ans > 1 ? ans : -1;
  }
};
