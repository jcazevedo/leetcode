// 3445. Maximum Difference Between Even and Odd Frequency II
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/

#include <algorithm>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDifference(string s, int k) {
    int n = s.size(), ans = numeric_limits<int>::min();
    for (char ch1 = '0'; ch1 <= '4'; ++ch1) {
      for (char ch2 = '0'; ch2 <= '4'; ++ch2) {
        if (ch1 == ch2) { continue; }
        vector<vector<int>> best(2, vector<int>(2, numeric_limits<int>::max()));
        int cnt_ch1 = 0, cnt_ch2 = 0, prev_ch1 = 0, prev_ch2 = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
          cnt_ch1 += (s[right] == ch1);
          cnt_ch2 += (s[right] == ch2);
          while (right - left + 1 >= k && cnt_ch2 - prev_ch2 >= 2) {
            best[prev_ch1 & 1][prev_ch2 & 1] = min(best[prev_ch1 & 1][prev_ch2 & 1], prev_ch1 - prev_ch2);
            prev_ch1 += (s[left] == ch1);
            prev_ch2 += (s[left] == ch2);
            ++left;
          }
          int curr_best = best[(cnt_ch1 & 1) ^ 1][(cnt_ch2 & 1) ^ 0];
          if (curr_best != numeric_limits<int>::max()) { ans = max(ans, cnt_ch1 - cnt_ch2 - curr_best); }
        }
      }
    }
    return ans;
  }
};
