// 956. Tallest Billboard
// https://leetcode.com/problems/tallest-billboard/description/

#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

#define MAXSUM 5000

class Solution {
 private:
  map<int, int> getDiffs(vector<int>& rods, int from, int to) {
    set<pair<int, int>> states;
    states.insert(make_pair(0, 0));
    for (int i = from; i < to; ++i) {
      int rod = rods[i];
      set<pair<int, int>> next;
      for (const pair<int, int>& state : states) {
        next.insert(make_pair(state.first + rod, state.second));
        next.insert(make_pair(state.first, state.second + rod));
      }
      for (const pair<int, int>& nextState : next) states.insert(nextState);
    }
    map<int, int> ans;
    for (const pair<int, int>& state : states) {
      int diff = state.first - state.second;
      ans[diff] = max(ans[diff], state.first);
    }
    return ans;
  }

 public:
  int tallestBillboard(vector<int>& rods) {
    int N = rods.size();
    map<int, int> diffsLeft = getDiffs(rods, 0, N / 2);
    map<int, int> diffsRight = getDiffs(rods, N / 2, N);
    int ans = 0;
    for (auto itr = diffsLeft.begin(); itr != diffsLeft.end(); ++itr) {
      int diff = itr->first;
      int height = itr->second;
      if (diffsRight.count(-diff)) ans = max(ans, height + diffsRight[-diff]);
    }
    return ans;
  }
};
