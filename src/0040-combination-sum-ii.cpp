// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

#include <map>
#include <vector>

using namespace std;

class Solution {
private:
  void solve(int i, const vector<int>& uniqueCandidates, map<int, int>& count,
             int currSum, int target, vector<int>& curr,
             vector<vector<int>>& ans) {
    if (currSum == target) {
      ans.push_back(curr);
    } else {
      if (i >= (int)uniqueCandidates.size() || currSum > target) {
        return;
      }
      int nextSum = currSum;
      for (int j = 1; j <= count[uniqueCandidates[i]]; ++j) {
        curr.push_back(uniqueCandidates[i]);
        nextSum += uniqueCandidates[i];
        solve(i + 1, uniqueCandidates, count, nextSum, target, curr, ans);
      }
      for (int j = 1; j <= count[uniqueCandidates[i]]; ++j) {
        curr.pop_back();
      }
      solve(i + 1, uniqueCandidates, count, currSum, target, curr, ans);
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    map<int, int> count;
    vector<int> uniqueCandidates;
    for (int v : candidates) {
      count[v]++;
    }
    for (auto itr = count.begin(); itr != count.end(); ++itr) {
      uniqueCandidates.push_back(itr->first);
    }
    vector<vector<int>> ans;
    vector<int> curr;
    solve(0, uniqueCandidates, count, 0, target, curr, ans);
    return ans;
  }
};
