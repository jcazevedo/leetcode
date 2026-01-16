// 2943. Maximize Area of Square Hole in Grid
// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/

#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    unordered_set<int> canRemoveH, canRemoveV, anchorsH, anchorsV;
    for (int bar : hBars) {
      canRemoveH.insert(bar);
      anchorsH.insert(bar - 1);
      anchorsH.insert(bar);
      anchorsH.insert(bar + 1);
    }
    for (int bar : vBars) {
      canRemoveV.insert(bar);
      anchorsV.insert(bar - 1);
      anchorsV.insert(bar);
      anchorsV.insert(bar + 1);
    }
    int ans = 1;
    for (int h : anchorsH) {
      int hh = h + 2;
      while (canRemoveH.count(hh - 1)) {
        int l = hh - h;
        for (int v : anchorsV) {
          int vv = v + 2;
          while (canRemoveV.count(vv - 1)) {
            if (vv - v == l) { ans = max(ans, l * l); }
            vv += 1;
          }
        }
        hh += 1;
      }
    }
    return ans;
  }
};
