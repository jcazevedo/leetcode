// 1526. Minimum Number of Increments on Subarrays to Form a Target Array
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int minNumberOperations(vector<int>& target) {
    target.push_back(0);
    int ans = 0, N = target.size();
    stack<int> heights;
    heights.push(0);
    for (int i = 0; i < N; ++i) {
      if (target[i] > heights.top()) {
        heights.push(target[i]);
      } else {
        while (heights.top() > target[i]) {
          int height = heights.top();
          heights.pop();
          int nextHeight = target[i];
          if (!heights.empty() && heights.top() > target[i])
            nextHeight = heights.top();
          ans += height - nextHeight;
          if (!heights.empty() && target[i] > heights.top())
            heights.push(target[i]);
        }
      }
    }
    return ans;
  }
};
