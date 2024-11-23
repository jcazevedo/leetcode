// 3362. Zero Array Transformation III
// https://leetcode.com/problems/zero-array-transformation-iii/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    int N = nums.size(), Q = queries.size();
    priority_queue<int> good;
    vector<vector<int>> queryStart(N, vector<int>());
    vector<int> intervalEnd(N, 0);
    for (int q = 0; q < Q; ++q) { queryStart[queries[q][0]].push_back(q); }
    int used = 0, inUse = 0;
    for (int i = 0; i < N; ++i) {
      for (int q : queryStart[i]) { good.push(queries[q][1]); }
      while (nums[i] - inUse > 0) {
        while (!good.empty() && good.top() < i) { good.pop(); }
        if (good.empty()) { return -1; }
        ++inUse;
        ++used;
        ++intervalEnd[good.top()];
        good.pop();
      }
      inUse -= intervalEnd[i];
    }
    return queries.size() - used;
  }
};
