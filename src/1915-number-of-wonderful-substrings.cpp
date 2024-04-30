// 1915. Number of Wonderful Substrings
// https://leetcode.com/problems/number-of-wonderful-substrings/

#include <cstring>
#include <string>

using namespace std;

class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    int N = word.size(), curr = 0, len = 'j' - 'a' + 1;
    long long ans = 0, prev[1 << len];
    memset(prev, 0, sizeof(prev));
    prev[0] = 1L;
    for (int i = 0; i < N; ++i) {
      curr ^= (1 << (word[i] - 'a'));
      ans += prev[curr];
      for (int d = 0; d < len; ++d) ans += prev[curr ^ (1 << d)];
      ++prev[curr];
    }
    return ans;
  }
};
