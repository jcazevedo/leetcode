// 1968. Array With Elements Not Equal to Average of Neighbors
// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> ans(n);
    int i = 0;
    for (int j = 0; j < n; j += 2) { ans[j] = nums[i++]; }
    for (int j = 1; j < n; j += 2) { ans[j] = nums[i++]; }
    return ans;
  }
};
