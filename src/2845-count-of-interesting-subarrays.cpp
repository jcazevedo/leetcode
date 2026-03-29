// 2845. Count of Interesting Subarrays
// https://leetcode.com/problems/count-of-interesting-subarrays/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    long long ans = 0;
    unordered_map<int, long long> cnt;
    cnt[0] = 1;
    int prefix = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] % modulo == k) { prefix++; }
      int rem = prefix % modulo;
      int need = (rem - k % modulo + modulo) % modulo;
      if (cnt.count(need)) { ans += cnt[need]; }
      ++cnt[rem];
    }
    return ans;
  }
};
