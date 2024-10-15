// 2938. Separate Black and White Balls
// https://leetcode.com/problems/separate-black-and-white-balls/

#include <string>

using namespace std;

class Solution {
 public:
  long long minimumSteps(string s) {
    long long ans = 0;
    int N = s.size(), next0 = N;
    for (int i = N - 1; i >= 0; --i) {
      if (s[i] == '1') {
        if (next0 != N) {
          ans += next0 - i;
          --next0;
        }
      } else if (next0 == N) {
        next0 = i;
      }
    }
    return ans;
  }
};
