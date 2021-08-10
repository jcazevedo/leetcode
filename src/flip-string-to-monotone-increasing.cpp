#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int N = s.size();
    vector<int> cnt(N + 1, 0);
    cnt[0] = 0;
    for (int i = 1; i <= N; ++i) {
      cnt[i] = cnt[i - 1];
      if (s[i  - 1] == '1')
        cnt[i]++;
    }
    int ans = N;
    for (int i = 0; i <= N; ++i) {
      int cnt_left = cnt[i];
      int cnt_right = cnt[N] - cnt[i];
      int tot_flips = cnt_left + N - i - cnt_right;
      ans = min(ans, tot_flips);
    }
    return ans;
  }
};
