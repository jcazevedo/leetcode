// 1400. Construct K Palindrome Strings
// https://leetcode.com/problems/construct-k-palindrome-strings/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool canConstruct(string s, int k) {
    if ((int)s.size() < k) { return false; }
    unordered_map<char, int> cnt;
    for (char ch : s) { ++cnt[ch]; }
    int odd = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      if (cnt[ch] % 2) { ++odd; }
    }
    return odd <= k;
  }
};
