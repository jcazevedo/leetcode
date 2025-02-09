// 3160. Find the Number of Distinct Colors Among the Balls
// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    int q = queries.size();
    int tot = 0;
    vector<int> ans(q);
    unordered_map<int, int> colors;
    unordered_map<int, int> colorCnt;
    for (int i = 0; i < q; ++i) {
      if (colorCnt[colors[queries[i][0]]] == 1) { --tot; }
      --colorCnt[colors[queries[i][0]]];
      colors[queries[i][0]] = queries[i][1];
      if (colorCnt[queries[i][1]] == 0) { ++tot; }
      colorCnt[queries[i][1]]++;
      ans[i] = tot;
    }
    return ans;
  }
};
