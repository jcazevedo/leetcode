#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
private:
  map<pair<int, int>, set<vector<int>>> cache;

  void go(int target, int maxC, const vector<int>& candidates) {
    if (target <= 0)
      return;
    if (cache.count({target, maxC}) == 0) {
      set<vector<int>> curr;
      for (int i = maxC; i >= 0; --i) {
        int n = candidates[i];
        int next = target - n;
        go(next, i, candidates);
        for (vector<int> v : cache[{next, i}]) {
          vector<int> vv = v;
          vv.push_back(n);
          curr.insert(vv);
        }
        if (next == 0)
          curr.insert({n});
      }
      cache[{target, maxC}] = curr;
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    cache.clear();
    go(target, candidates.size() - 1, candidates);
    vector<vector<int>> res;
    for (vector<int> v : cache[{target, candidates.size() - 1}])
      res.push_back(v);
    return res;
  }
};
