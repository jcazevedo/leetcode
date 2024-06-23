// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> right(n, 0);
    vector<int> left(n, 0);
    stack<int> s;
    s.push(n);
    for (int i = n - 1; i >= 0; --i) {
      while (s.top() != n && heights[s.top()] >= heights[i]) { s.pop(); }
      right[i] = s.top();
      s.push(i);
    }
    while (!s.empty()) { s.pop(); }
    s.push(-1);
    for (int i = 0; i < n; ++i) {
      while (s.top() != -1 && heights[s.top()] >= heights[i]) { s.pop(); }
      left[i] = s.top();
      s.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) { ans = max(ans, heights[i] * (right[i] - left[i] - 1)); }
    return ans;
  }
};
