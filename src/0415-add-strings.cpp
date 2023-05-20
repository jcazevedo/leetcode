// 415. Add Strings
// https://leetcode.com/problems/add-strings/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    if (num1 == "0")
      return num2;
    if (num2 == "0")
      return num1;
    string ans = "";
    int i1 = num1.size() - 1;
    int i2 = num2.size() - 1;
    int carry = 0;
    while (i1 >= 0 || i2 >= 0) {
      int sum = carry;
      if (i1 >= 0)
        sum += (num1[i1] - '0');
      if (i2 >= 0)
        sum += (num2[i2] - '0');
      i1--;
      i2--;
      ans += sum % 10 + '0';
      carry = sum / 10;
    }
    if (carry > 0)
      ans += carry + '0';
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
