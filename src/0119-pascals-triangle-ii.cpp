// 119. Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> prev = {1};
    vector<int> next;
    for (int i = 1; i <= rowIndex; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (j == 0 || j == i)
          next.push_back(1);
        else
          next.push_back(prev[j - 1] + prev[j]);
      }
      prev = next;
      next.clear();
    }
    return prev;
  }
};
