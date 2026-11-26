// 1189. Maximum Number of Balloons
// https://leetcode.com/problems/maximum-number-of-balloons/

#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> cnt;
    for (char ch : text) { ++cnt[ch]; }
    int ans = text.size();
    ans = min(ans, cnt['b']);
    ans = min(ans, cnt['a']);
    ans = min(ans, cnt['l'] / 2);
    ans = min(ans, cnt['o'] / 2);
    ans = min(ans, cnt['n']);
    return ans;
  }
};
