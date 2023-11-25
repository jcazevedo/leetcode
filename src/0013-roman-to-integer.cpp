// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  static unordered_map<string, int> char_1_strs;
  static unordered_map<string, int> char_2_strs;

  int romanToInt(string s) {
    int ans = 0;
    int N = s.size();

    for (int i = 0; i < N; ++i) {
      bool done = false;

      for (const auto& [key, value] : char_2_strs) {
        if (s.substr(i, 2) == key) {
          ans += value;
          ++i;
          done = true;
          break;
        }
      }

      if (done) continue;

      for (const auto& [key, value] : char_1_strs) {
        if (s.substr(i, 1) == key) {
          ans += value;
          done = true;
          break;
        }
      }
    }

    return ans;
  }
};

unordered_map<string, int> Solution::char_1_strs = {
    {"I", 1},   {"V", 5},   {"X", 10},  {"L", 50},
    {"C", 100}, {"D", 500}, {"M", 1000}};

unordered_map<string, int> Solution::char_2_strs = {
    {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
