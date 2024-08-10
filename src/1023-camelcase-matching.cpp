// 1023. Camelcase Matching
// https://leetcode.com/problems/camelcase-matching/

#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    unordered_map<char, int> cnt;
    for (const char& ch : pattern) { ++cnt[ch]; }
    int N = queries.size();
    int P = pattern.size();
    vector<bool> ans(N, true);
    for (int i = 0; i < N; ++i) {
      const string& query = queries[i];
      int Q = query.size();
      vector<bool> used(Q, false);
      int p = 0;
      int q = 0;
      while (p < P && q < Q) {
        while (q < Q && query[q] != pattern[p]) { ++q; }
        if (q < Q) {
          used[q] = true;
          ++q;
          ++p;
        } else {
          break;
        }
      }
      if (p != P) { ans[i] = false; }
      for (q = 0; q < Q; ++q) {
        if (used[q]) { continue; }
        if (isupper(query[q])) {
          ans[i] = false;
          break;
        }
      }
    }
    return ans;
  }
};
