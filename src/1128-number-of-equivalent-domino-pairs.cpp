// 1128. Number of Equivalent Domino Pairs
// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    map<vector<int>, int> cnt;
    for (const vector<int>& domino : dominoes) { ++cnt[{min(domino[0], domino[1]), max(domino[0], domino[1])}]; }
    int ans = 0;
    for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
      int c = itr->second;
      ans += (c * (c - 1)) / 2;
    }
    return ans;
  }
};
