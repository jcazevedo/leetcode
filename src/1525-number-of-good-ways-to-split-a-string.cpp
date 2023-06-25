// 1525. Number of Good Ways to Split a String
// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int numSplits(string s) {
    unordered_map<char, int> left, right;
    int ans = 0, N = s.size();
    left[s[0]]++;
    for (int i = 1; i < N; ++i)
      right[s[i]]++;
    for (int i = 1; i < N; ++i) {
      if (left.size() == right.size())
        ++ans;
      right[s[i]]--;
      if (right[s[i]] == 0)
        right.erase(s[i]);
      left[s[i]]++;
    }
    return ans;
  }
};
