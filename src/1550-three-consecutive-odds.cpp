// 1550. Three Consecutive Odds
// https://leetcode.com/problems/three-consecutive-odds/

#include <vector>

using namespace std;

class Solution {
 public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    int nOdds = 0;
    for (int v : arr) {
      if (v % 2) {
        ++nOdds;
      } else {
        nOdds = 0;
      }
      if (nOdds == 3) { return true; }
    }
    return false;
  }
};
