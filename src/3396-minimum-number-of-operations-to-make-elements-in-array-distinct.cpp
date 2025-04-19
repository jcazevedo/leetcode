// 3396. Minimum Number of Operations to Make Elements in Array Distinct
// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    unordered_set<int> unique;
    for (int i = 0; i < n; ++i) {
      ++cnt[nums[i]];
      unique.insert(nums[i]);
    }
    int removed = 0, ops = 0;
    while ((int)unique.size() != n - removed) {
      ++ops;
      int current_removed = 0;
      for (int i = removed; i < min(removed + 3, n); ++i) {
        --cnt[nums[i]];
        current_removed++;
        if (cnt[nums[i]] == 0) { unique.erase(nums[i]); }
      }
      removed += current_removed;
    }
    return ops;
  }
};
