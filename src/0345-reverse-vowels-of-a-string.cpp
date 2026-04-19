// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

class Solution {
 private:
  bool isVowel(char ch) {
    char c = tolower(ch);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:
  string reverseVowels(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (l < r && !isVowel(s[l])) { ++l; }
      while (l < r && !isVowel(s[r])) { --r; }
      if (l >= r) { break; }
      swap(s[l], s[r]);
      ++l;
      --r;
    }
    return s;
  }
};
