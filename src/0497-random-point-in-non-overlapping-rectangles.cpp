// 497. Random Point in Non-overlapping Rectangles
// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> rects;

public:
  Solution(vector<vector<int>>& rects) : rects(rects) {}

  vector<int> pick() {
    int totArea = 0;
    vector<int> selectedRectangle;
    for (const vector<int>& rect : rects) {
      int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
      totArea += area;
      if (rand() % totArea < area)
        selectedRectangle = rect;
    }
    int x = rand() % (selectedRectangle[2] - selectedRectangle[0] + 1) +
            selectedRectangle[0];
    int y = rand() % (selectedRectangle[3] - selectedRectangle[1] + 1) +
            selectedRectangle[1];
    return {x, y};
  }
};
