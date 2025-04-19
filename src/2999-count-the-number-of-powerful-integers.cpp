// 2999. Count the Number of Powerful Integers
// https://leetcode.com/problems/count-the-number-of-powerful-integers/

#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

class Solution {
 private:
  long long count(string x, string s, int limit) {
    if (x.length() < s.length()) { return 0; }
    if (x.length() == s.length()) {
      if (x >= s) { return 1; }
      return 0;
    }
    long long ans = 0L;
    int len_prefix = x.length() - s.length();
    for (int i = 0; i < len_prefix; ++i) {
      if (limit < (x[i] - '0')) {
        ans += (long long)pow(limit + 1, len_prefix - i);
        return ans;
      }
      ans += (long long)(x[i] - '0') * (long long)pow(limit + 1, len_prefix - i - 1);
    }
    string suffix = x.substr(x.length() - s.length(), s.length());
    if (suffix >= s) { ++ans; }
    return ans;
  }

 public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    return count(to_string(finish), s, limit) - count(to_string(start - 1), s, limit);
  }
};
