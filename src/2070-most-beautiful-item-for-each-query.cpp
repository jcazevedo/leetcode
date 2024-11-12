// 2070. Most Beautiful Item for Each Query
// https://leetcode.com/problems/most-beautiful-item-for-each-query/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    sort(begin(items), end(items));
    int I = items.size();
    vector<int> maxBeauty(I);
    maxBeauty[0] = items[0][1];
    for (int i = 1; i < I; ++i) { maxBeauty[i] = max(items[i][1], maxBeauty[i - 1]); }
    int Q = queries.size();
    vector<int> ans(Q);
    for (int q = 0; q < Q; ++q) {
      vector<int> item = {queries[q], numeric_limits<int>::max()};
      int idx = upper_bound(begin(items), end(items), item) - begin(items);
      ans[q] = idx == 0 ? 0 : maxBeauty[idx - 1];
    }
    return ans;
  }
};
