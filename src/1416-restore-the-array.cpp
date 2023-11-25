// 1416. Restore The Array
// https://leetcode.com/problems/restore-the-array/

#include <string>

using namespace std;

#define MOD 1000000007
#define MAXN 100010

class Solution {
 private:
  long long ways[MAXN];

 public:
  int numberOfArrays(string s, int k) {
    int N = s.size();
    for (int i = 0; i < N; ++i) ways[i] = -1;
    ways[N] = 1;

    for (int i = N - 1; i >= 0; --i) {
      ways[i] = 0;
      if (s[i] == '0') continue;
      long long curr = 0;
      for (int j = i; j < N; ++j) {
        curr = curr * 10 + s[j] - '0';
        if (curr >= 1 && curr <= k) ways[i] = (ways[i] + ways[j + 1]) % MOD;
        if (curr > k) break;
      }
    }

    return ways[0];
  }
};
