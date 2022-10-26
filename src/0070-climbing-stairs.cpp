// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <vector>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for (int i = 0; i < n; ++i) {
      if (i + 1 <= n) ways[i + 1] += ways[i];
      if (i + 2 <= n) ways[i + 2] += ways[i];
    }
    return ways[n];
  }
};
