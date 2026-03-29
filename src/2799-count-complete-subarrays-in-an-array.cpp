// 2799. Count Complete Subarrays in an Array
// https://leetcode.com/problems/count-complete-subarrays-in-an-array/

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    unordered_set<int> seen;
    for (int n : nums) { seen.insert(n); }
    int distinct = seen.size();
    unordered_map<int, int> freq;
    int n = nums.size(), l = 0, ans = 0;
    for (int r = 0; r < n; ++r) {
      ++freq[nums[r]];
      while ((int)freq.size() == distinct) {
        ans += (n - r);
        --freq[nums[l]];
        if (freq[nums[l]] == 0) { freq.erase(nums[l]); }
        ++l;
      }
    }
    return ans;
  }
};
