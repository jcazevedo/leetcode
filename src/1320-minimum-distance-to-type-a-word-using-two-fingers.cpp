// 1320. Minimum Distance to Type a Word Using Two Fingers
// https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/

#include <algorithm>
#include <functional>
#include <limits>
#include <string>
#include <vector>

using namespace std;

#define UNPLACED 26

class Solution {
 public:
  int minimumDistance(string word) {
    int n = word.size();
    function<int(int, int)> cost = [](int a, int b) -> int {
      if (a == UNPLACED) { return 0; }
      return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    };
    vector<int> dp(27, numeric_limits<int>::max());
    dp[UNPLACED] = 0;
    for (int i = 1; i < n; i++) {
      int c = word[i] - 'A';
      int prev = word[i - 1] - 'A';
      vector<int> ndp(27, numeric_limits<int>::max());
      for (int j = 0; j <= 26; j++) {
        if (dp[j] == numeric_limits<int>::max()) { continue; }
        ndp[j] = min(ndp[j], dp[j] + cost(prev, c));
        ndp[prev] = min(ndp[prev], dp[j] + cost(j, c));
      }
      dp = ndp;
    }
    return *min_element(dp.begin(), dp.end());
  }
};
