// 2965. Find Missing and Repeated Values
// https://leetcode.com/problems/find-missing-and-repeated-values/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<bool> visited(n * n + 1, false);
    int sum = 0;
    for (const vector<int>& line : grid) {
      for (int num : line) {
        visited[num] = true;
        sum += num;
      }
    }
    int missing = -1;
    for (int i = 1; i <= n * n; ++i) {
      if (!visited[i]) {
        missing = i;
        break;
      }
    }
    int expected = n * n * (n * n + 1) / 2;
    int repeated = sum + missing - expected;
    return {repeated, missing};
  }
};
