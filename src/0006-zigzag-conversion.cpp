// 6. Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int N = s.size(), row = 0, rowDiff = 1;
    vector<string> rows = vector<string>(numRows, "");
    for (int i = 0; i < N; ++i) {
      rows[row] += s[i];
      row += rowDiff;
      if (row == numRows) {
        row = numRows - 2;
        rowDiff = -1;
      } else if (row < 0) {
        row = 1;
        rowDiff = +1;
      }
    }
    string ans = "";
    for (int i = 0; i < numRows; ++i) ans += rows[i];
    return ans;
  }
};
