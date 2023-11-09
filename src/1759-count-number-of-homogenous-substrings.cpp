// 1759. Count Number of Homogenous Substrings
// https://leetcode.com/problems/count-number-of-homogenous-substrings/

#include <string>

using namespace std;

#define MOD 1000000007

class Solution {
private:
  int modAdd(long long a, long long b) { return (a + b) % MOD; }

public:
  int countHomogenous(string s) {
    int N = s.size();

    int ans = 0;
    int currentLength = 0;
    for (int i = 0; i < N; ++i) {
      if (i == 0 || s[i] == s[i - 1])
        currentLength++;
      else
        currentLength = 1;

      ans = modAdd(ans, currentLength);
    }

    return ans;
  }
};
