// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    int N = s.size();
    vector<int> ways(N + 1, 0);
    ways[N] = 1;
    for (int i = N - 1; i >= 0; --i) {
      if (s[i] == '0')
        continue;
      if (s[i] == '1' && i + 2 <= N)
        ways[i] += ways[i + 2];
      if (s[i] == '2' && i + 2 <= N && s[i + 1] <= '6')
        ways[i] += ways[i + 2];
      ways[i] += ways[i + 1];
    }
    return ways[0];
  }
};
