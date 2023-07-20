// 1125. Smallest Sufficient Team
// https://leetcode.com/problems/smallest-sufficient-team/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    unordered_map<string, int> idxs;
    int idx = 0;
    int P = people.size();
    int S = req_skills.size();
    for (const string& skill : req_skills) {
      idxs[skill] = idx++;
    }
    vector<int> peopleBitmasks(P, 0);
    for (int i = 0; i < P; ++i) {
      for (const string& skill : people[i]) {
        peopleBitmasks[i] |= 1 << idxs[skill];
      }
    }
    vector<long long> dp(1 << S, (1LL << (P + 1)) - 1);
    dp[0] = 0LL;
    for (int i = 0; i < P; ++i) {
      int mask = peopleBitmasks[i];
      for (int m = 0; m < 1 << S; ++m) {
        long long next = dp[m] | (1LL << i);
        if (__builtin_popcountll(next) < __builtin_popcountll(dp[m | mask])) {
          dp[m | mask] = next;
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i < P; ++i) {
      if (dp[(1 << S) - 1] & (1LL << i)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
