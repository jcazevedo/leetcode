// 1963. Minimum Number of Swaps to Make the String Balanced
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

#include <string>

using namespace std;

class Solution {
 public:
  int minSwaps(string s) {
    int ans = 0, curr = 0;
    for (char ch : s) {
      if (ch == '[') {
        ++curr;
      } else if (curr > 0) {
        --curr;
      } else {
        ++ans;
      }
    }
    return (ans + 1) / 2;
  }
};
