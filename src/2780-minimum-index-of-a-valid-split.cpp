// 2780. Minimum Index of a Valid Split
// https://leetcode.com/problems/minimum-index-of-a-valid-split/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumIndex(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    int best = -1;
    int bestCnt = 0;
    for (int i = 0; i < n; ++i) {
      ++cnt[nums[i]];
      if (cnt[nums[i]] > bestCnt) {
        bestCnt = cnt[nums[i]];
        best = nums[i];
      }
    }
    int l = 0, r = bestCnt;
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] == best) {
        ++l;
        --r;
      }
      if (l > (i + 1) / 2 && r > (n - i - 1) / 2) { return i; }
    }
    return -1;
  }
};
