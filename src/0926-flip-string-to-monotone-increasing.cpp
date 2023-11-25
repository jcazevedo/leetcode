// 926. Flip String to Monotone Increasing
// https://leetcode.com/problems/flip-string-to-monotone-increasing/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    int N = s.size();
    int tot_cnt = 0;
    for (int i = 0; i < N; ++i)
      if (s[i] == '1') ++tot_cnt;
    int ans = N;
    int cnt = 0;
    for (int i = 0; i <= N; ++i) {
      int cnt_left = cnt;
      int cnt_right = tot_cnt - cnt;
      int tot_flips = cnt_left + N - i - cnt_right;
      ans = min(ans, tot_flips);
      if (i < N && s[i] == '1') ++cnt;
    }
    return ans;
  }
};
