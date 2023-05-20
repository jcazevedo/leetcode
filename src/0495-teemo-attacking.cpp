// 495. Teemo Attacking
// https://leetcode.com/problems/teemo-attacking/

#include <vector>

using namespace std;

class Solution {
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int ans = 0;
    int start = -1, end = -1;
    for (int time : timeSeries) {
      if (time > end) {
        ans += (end - start);
        start = time;
      }
      end = time + duration;
    }
    ans += (end - start);
    return ans;
  }
};
