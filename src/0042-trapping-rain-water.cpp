// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

#include <stack>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int N = height.size(), ans = 0;
    stack<tuple<int, int>> prev;
    for (int i = 0; i < N; ++i) {
      if (height[i] > 0) {
        int minHeight = 0;
        while (!prev.empty() && get<0>(prev.top()) <= height[i]) {
          int areaToAdd = (i - get<1>(prev.top()) - 1) * (get<0>(prev.top()) - minHeight);
          ans += areaToAdd;
          minHeight = get<0>(prev.top());
          prev.pop();
        }
        if (!prev.empty()) { ans += (i - get<1>(prev.top()) - 1) * (height[i] - minHeight); }
        prev.push({height[i], i});
      }
    }
    return ans;
  }
};
