// 962. Maximum Width Ramp
// https://leetcode.com/problems/maximum-width-ramp/

#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxWidthRamp(vector<int>& nums) {
    vector<pair<int, int>> ni;
    set<pair<int, int>> in;
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
      ni.push_back(make_pair(nums[i], i));
      in.insert(make_pair(i, nums[i]));
    }
    sort(begin(ni), end(ni));
    int ans = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (in.begin()->first < ni[i].second) { ans = max(ans, ni[i].second - in.begin()->first); }
      in.erase(make_pair(ni[i].second, ni[i].first));
    }
    return ans;
  }
};
