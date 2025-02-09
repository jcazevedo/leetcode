// 2364. Count Number of Bad Pairs
// https://leetcode.com/problems/count-number-of-bad-pairs/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countBadPairs(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    long long ans = 0L;
    for (int i = 0; i < n; ++i) {
      int diff = i - nums[i];
      ans += i - cnt[diff];
      ++cnt[diff];
    }
    return ans;
  }
};
