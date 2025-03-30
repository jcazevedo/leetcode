// 3394. Check if Grid can be Cut into Sections
// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<vector<int>> hEvents, vEvents;
    for (const vector<int>& rectangle : rectangles) {
      hEvents.push_back({rectangle[0], 1});
      hEvents.push_back({rectangle[2], 0});
      vEvents.push_back({rectangle[1], 1});
      vEvents.push_back({rectangle[3], 0});
    }
    sort(hEvents.begin(), hEvents.end());
    sort(vEvents.begin(), vEvents.end());
    int remaining = rectangles.size();
    int ev = hEvents.size();
    int curr = 0;
    int cuts = 0;
    for (int i = 0; i < ev; ++i) {
      if (hEvents[i][1] == 1) { ++curr; }
      if (hEvents[i][1] == 0) {
        --curr;
        --remaining;
        if (curr == 0 && remaining > 0) { ++cuts; }
      }
      if (cuts == 2) { return true; }
    }
    remaining = rectangles.size();
    curr = 0;
    cuts = 0;
    for (int i = 0; i < ev; ++i) {
      if (vEvents[i][1] == 1) { ++curr; }
      if (vEvents[i][1] == 0) {
        --curr;
        --remaining;
        if (curr == 0 && remaining > 0) { ++cuts; }
      }
      if (cuts == 2) { return true; }
    }
    return false;
  }
};
