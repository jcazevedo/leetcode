// 940. Distinct Subsequences II
// https://leetcode.com/problems/distinct-subsequences-ii/

#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int distinctSubseqII(string s) {
    int n = s.size();
    vector<long long> distinct(n + 1, 0);
    vector<int> visited('z' - 'a' + 1, -1);
    distinct[0] = 1;
    for (int i = 1; i <= n; ++i) {
      int prev = visited[s[i - 1] - 'a'];
      if (prev != -1) {
        distinct[i] = (2L * distinct[i - 1] - distinct[prev]) % MOD;
      } else {
        distinct[i] = (2L * distinct[i - 1]) % MOD;
      }
      visited[s[i - 1] - 'a'] = i - 1;
    }
    return (distinct[n] + MOD - 1) % MOD;
  }
};
