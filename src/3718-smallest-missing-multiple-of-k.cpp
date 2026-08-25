// 3718. Smallest Missing Multiple of K
// https://leetcode.com/problems/smallest-missing-multiple-of-k/

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingMultiple(vector<int>& nums, int k) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int ans = k;
    while (numSet.count(ans)) { ans += k; }
    return ans;
  }
};
