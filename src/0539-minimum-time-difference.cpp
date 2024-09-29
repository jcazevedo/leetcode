// 539. Minimum Time Difference
// https://leetcode.com/problems/minimum-time-difference/

#include <algorithm>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    vector<int> tts;
    for (const string& timePoint : timePoints) {
      int hour = (timePoint[0] - '0') * 10 + (timePoint[1] - '0');
      int minutes = (timePoint[3] - '0') * 10 + (timePoint[4] - '0');
      tts.push_back(hour * 60 + minutes);
      tts.push_back(hour * 60 + minutes + 1440);
    }
    sort(tts.begin(), tts.end());
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < (int)tts.size() - 1; ++i) { ans = min(ans, tts[i + 1] - tts[i]); }
    return ans;
  }
};
