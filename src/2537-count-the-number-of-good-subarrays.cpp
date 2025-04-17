// 2537. Count the Number of Good Subarrays
// https://leetcode.com/problems/count-the-number-of-good-subarrays/

#include <functional>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    long long ans = 0;
    int n = nums.size(), l = 0;
    unordered_map<int, int> cnt;
    function<long long(int)> pairs = [&cnt, &nums](int i) {
      long long c = cnt[nums[i]];
      return c * (c - 1) / 2;
    };
    long long c = 0;
    ++cnt[nums[0]];
    for (int r = 1; r < n; ++r) {
      c -= pairs(r);
      ++cnt[nums[r]];
      c += pairs(r);
      while (c >= k) {
        ans += n - r;
        c -= pairs(l);
        --cnt[nums[l]];
        c += pairs(l);
        ++l;
      }
    }
    return ans;
  }
};
