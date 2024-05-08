// 506. Relative Ranks
// https://leetcode.com/problems/relative-ranks/

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& score) {
    vector<pair<int, int>> scoreWithIdx;
    int N = score.size();
    for (int i = 0; i < N; ++i) scoreWithIdx.push_back(make_pair(score[i], i));
    sort(scoreWithIdx.begin(), scoreWithIdx.end());
    reverse(scoreWithIdx.begin(), scoreWithIdx.end());
    vector<string> ans(N);
    for (int i = 0; i < N; ++i)
      if (i + 1 == 1)
        ans[scoreWithIdx[i].second] = "Gold Medal";
      else if (i + 1 == 2)
        ans[scoreWithIdx[i].second] = "Silver Medal";
      else if (i + 1 == 3)
        ans[scoreWithIdx[i].second] = "Bronze Medal";
      else {
        ostringstream ss;
        ss << i + 1;
        ans[scoreWithIdx[i].second] = ss.str();
      }
    return ans;
  }
};
