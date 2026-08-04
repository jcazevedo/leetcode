// 3731. Find Missing Elements
// https://leetcode.com/problems/find-missing-elements/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMissingElements(vector<int>& nums) {
    vector<int> ans;
    sort(nums.begin(), nums.end());
    int curr = nums[0];
    int N = nums.size();
    for (int i = 1; i < N; ++i) {
      ++curr;
      while (curr != nums[i]) {
        ans.push_back(curr);
        ++curr;
      }
    }
    return ans;
  }
};
