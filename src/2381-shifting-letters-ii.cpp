// 2381. Shifting Letters II
// https://leetcode.com/problems/shifting-letters-ii/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int N = s.size(), S = shifts.size();
    vector<int> d(N, 0);
    for (int i = 0; i < S; ++i) {
      if (shifts[i][2] == 1) {
        ++d[shifts[i][0]];
        if (shifts[i][1] + 1 < N) { --d[shifts[i][1] + 1]; }
      } else {
        --d[shifts[i][0]];
        if (shifts[i][1] + 1 < N) { ++d[shifts[i][1] + 1]; }
      }
    }
    string ans(N, ' ');
    int tot = 0;
    for (int i = 0; i < N; ++i) {
      tot = (tot + d[i]);
      ans[i] = 'a' + ((s[i] - 'a' + tot) % 26 + 26) % 26;
    }
    return ans;
  }
};
