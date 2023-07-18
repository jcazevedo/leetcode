// 2272. Substring With Largest Variance
// https://leetcode.com/problems/substring-with-largest-variance/

#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int largestVariance(string s) {
    int ans = 0;
    unordered_map<char, int> cnts;
    for (char ch : s)
      cnts[ch]++;
    for (char i = 'a'; i <= 'z'; ++i) {
      for (char j = 'a'; j <= 'z'; ++j) {
        if (i == j)
          continue;
        int cntI = 0, cntJ = 0, remJ = cnts[j];
        for (char ch : s) {
          if (ch == i)
            ++cntI;
          if (ch == j) {
            ++cntJ;
            --remJ;
          }
          if (cntJ > 0)
            ans = max(ans, cntI - cntJ);
          if (cntI < cntJ && remJ > 0)
            cntI = cntJ = 0;
        }
      }
    }
    return ans;
  }
};
