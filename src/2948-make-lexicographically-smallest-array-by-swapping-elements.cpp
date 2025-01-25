// 2948. Make Lexicographically Smallest Array by Swapping Elements
// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int N = nums.size();
    vector<int> sorted(nums);
    sort(begin(sorted), end(sorted));
    int curr = 0;
    unordered_map<int, int> g;
    unordered_map<int, vector<int>> l;
    g[sorted[0]] = 0;
    l[0] = {sorted[0]};
    for (int i = 1; i < N; ++i) {
      if (abs(sorted[i] - sorted[i - 1]) > limit) { ++curr; }
      g[sorted[i]] = curr;
      l[curr].push_back(sorted[i]);
    }
    for (int i = 0; i < N; ++i) {
      int group = g[nums[i]];
      nums[i] = *l[group].begin();
      l[group].erase(l[group].begin());
    }
    return nums;
  }
};
