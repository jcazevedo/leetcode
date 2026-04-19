// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <algorithm>
#include <string>
#include <string_view>

using namespace std;

class Solution {
 private:
  static bool isVowel(char c) { return string_view("aeiouAEIOU").find(c) != string_view::npos; }

 public:
  string reverseVowels(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (l < r && !isVowel(s[l])) { ++l; }
      while (l < r && !isVowel(s[r])) { --r; }
      swap(s[l], s[r]);
      ++l;
      --r;
    }
    return s;
  }
};
