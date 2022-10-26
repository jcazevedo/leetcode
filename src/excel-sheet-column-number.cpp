#include <string>

using namespace std;

class Solution {
 public:
  int titleToNumber(string s) {
    long long ans = 0;
    for (char ch : s) {
      ans *= 26;
      ans += (ch - 'A' + 1);
    }
    return ans;
  }
};
