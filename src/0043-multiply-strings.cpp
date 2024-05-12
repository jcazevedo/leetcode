// 43. Multiply Strings
// https://leetcode.com/problems/multiply-strings/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 private:
  string add(string& num1, string& num2) {
    int N = max(num1.size(), num2.size());
    string ans = "";
    int carry = 0;
    for (int i = 0; i < N; ++i) {
      int d1 = i < (int)num1.size() ? num1[num1.size() - i - 1] - '0' : 0;
      int d2 = i < (int)num2.size() ? num2[num2.size() - i - 1] - '0' : 0;
      int res = d1 + d2 + carry;
      ans += (char)((res % 10) + '0');
      carry = res / 10;
    }
    if (carry) ans += (char)(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
  }

  string mult(string& num, char mult) {
    int N = num.size();
    string ans = "";
    int carry = 0, mInt = mult - '0';
    for (int i = N - 1; i >= 0; --i) {
      int d = num[i] - '0';
      int res = d * mInt + carry;
      ans += (char)((res % 10) + '0');
      carry = res / 10;
    }
    if (carry) ans += (char)(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
  }

 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    string ans = "0";
    int N = num2.size();
    for (int i = 0; i < N; ++i) {
      string m = mult(num1, num2[N - i - 1]);
      for (int k = 0; k < i; ++k) m += '0';
      ans = add(ans, m);
    }
    return ans;
  }
};
