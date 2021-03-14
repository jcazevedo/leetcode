#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  int maxPower(string s) {
    int curr = 1;
    char prev = s[0];
    int N = s.size();
    int ans = 1;
    for (int i = 1; i < N; ++i) {
      if (s[i] == prev)
        curr++;
      else {
        prev = s[i];
        curr = 1;
      }
      ans = max(ans, curr);
    }
    return ans;
  }
};
