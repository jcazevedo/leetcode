// 2678. Number of Senior Citizens
// https://leetcode.com/problems/number-of-senior-citizens/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countSeniors(vector<string>& details) {
    int ans = 0;
    for (const string& s : details) {
      int age = (s[11] - '0') * 10 + s[12] - '0';
      if (age > 60) { ++ans; }
    }
    return ans;
  }
};
