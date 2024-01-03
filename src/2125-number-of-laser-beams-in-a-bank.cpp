// 2125. Number of Laser Beams in a Bank
// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfBeams(vector<string>& bank) {
    int ans = 0;

    int prev = 0;
    for (const string& s : bank) {
      int cnt = 0;
      for (const char& ch : s)
        if (ch == '1') ++cnt;
      ans += prev * cnt;
      if (cnt != 0) prev = cnt;
    }

    return ans;
  }
};
