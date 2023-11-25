// 168. Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/

#include <string>

using namespace std;

class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string ans = "";
    while (columnNumber) {
      columnNumber--;
      ans = ((char)((columnNumber % 26) + 'A')) + ans;
      columnNumber /= 26;
    }
    return ans;
  }
};
