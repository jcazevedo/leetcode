// 1653. Minimum Deletions to Make String Balanced
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDeletions(string s) {
    int N = s.size();
    vector<int> countB(N, 0);
    vector<int> countA(N, 0);
    for (int i = 0; i < N; ++i) {
      if (i > 0) { countB[i] = countB[i - 1]; }
      if (s[i] == 'b') { ++countB[i]; }
    }
    for (int i = N - 1; i >= 0; --i) {
      if (i < N - 1) { countA[i] = countA[i + 1]; }
      if (s[i] == 'a') { ++countA[i]; }
    }
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < N; ++i) { ans = min(ans, (i > 0 ? countB[i - 1] : 0) + countA[i]); }
    ans = min(ans, countB[N - 1]);
    return ans;
  }
};
