// 3442. Maximum Difference Between Even and Odd Frequency I
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/

#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int maxDifference(string s) {
    unordered_map<char, int> cnt;
    for (char ch : s) { ++cnt[ch]; }
    int max_odd = 0, min_even = s.size() + 1;
    for (unordered_map<char, int>::iterator itr = cnt.begin(); itr != cnt.end(); ++itr) {
      if (itr->second % 2) {
        max_odd = max(max_odd, itr->second);
      } else {
        min_even = min(min_even, itr->second);
      }
    }
    return max_odd - min_even;
  }
};
