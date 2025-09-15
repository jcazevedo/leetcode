// 1935. Maximum Number of Words You Can Type
// https://leetcode.com/problems/maximum-number-of-words-you-can-type/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    unordered_set<char> brokenChars;
    for (char ch : brokenLetters) { brokenChars.insert(ch); }
    int ans = 0;
    bool broken = false;
    for (char ch : text) {
      if (ch == ' ') {
        if (!broken) { ++ans; }
        broken = false;
      } else {
        if (brokenChars.count(ch)) { broken = true; }
      }
    }
    if (!broken) { ++ans; }
    return ans;
  }
};
