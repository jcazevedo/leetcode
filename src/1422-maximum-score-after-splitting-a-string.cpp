// 1422. Maximum Score After Splitting a String
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxScore(string s) {
    int N = s.size();
    vector<int> one_count(N, 0);
    one_count[0] = s[0] == '1';
    for (int i = 1; i < N; ++i) {
      one_count[i] = one_count[i - 1];
      if (s[i] == '1') { ++one_count[i]; }
    }
    int best = INT_MIN;
    for (int i = 0; i < N - 1; ++i) {
      int left = (i + 1) - one_count[i];
      int right = one_count[N - 1] - one_count[i];
      best = max(best, left + right);
    }
    return best;
  }
};
