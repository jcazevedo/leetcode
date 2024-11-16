// 3254. Find the Power of K-Size Subarrays I
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

#include <deque>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> resultsArray(vector<int>& nums, int k) {
    int N = nums.size() - k + 1;
    vector<int> ans(N, -1);
    deque<vector<int>> curr;
    for (int i = 0; i < k; ++i) {
      if (curr.size() == 0 || nums[i] != nums[i - 1] + 1) {
        curr.push_back({i, i});
      } else {
        (*curr.rbegin())[1] = i;
      }
    }
    if (curr.size() == 1) { ans[0] = nums[(*curr.begin())[1]]; }
    for (int i = 1; i < N; ++i) {
      if (i - 1 == (*curr.begin())[1]) { curr.pop_front(); }
      if (curr.size() == 0 || nums[i + k - 1] != nums[i + k - 2] + 1) {
        curr.push_back({i + k - 1, i + k - 1});
      } else {
        (*curr.rbegin())[1] = i + k - 1;
      }
      if (curr.size() == 1) { ans[i] = nums[(*curr.begin())[1]]; }
    }
    return ans;
  }
};
