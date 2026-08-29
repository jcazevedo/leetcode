// 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
// https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/

#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string lexPalindromicPermutation(string s, string target) {
    if (target.size() == 1) {
      if (s > target) { return s; }
      return "";
    }
    unordered_map<char, int> cnt;
    for (char c : s) { ++cnt[c]; }
    string middle = "";
    for (char c = 'a'; c <= 'z'; ++c) {
      if (cnt[c] % 2 == 1) { middle += c; }
      cnt[c] /= 2;
    }
    if (middle.size() > 1) { return ""; }
    int mid = target.size() / 2;
    string left = "", right, ans;
    unordered_map<char, int> midCnt(cnt);
    bool equalPossible = true;
    for (int i = 0; i < mid; ++i) {
      if (midCnt[target[i]] == 0) {
        equalPossible = false;
        break;
      }
      --midCnt[target[i]];
      left += target[i];
    }
    if (equalPossible) {
      right = left;
      reverse(right.begin(), right.end());
      ans = left + middle + right;
      if (ans > target) { return ans; }
    }
    left = "";
    for (int i = mid - 1; i >= 0; --i) {
      midCnt = cnt;
      bool possible = true;
      for (int j = 0; j < i; ++j) {
        if (midCnt[target[j]] == 0) {
          possible = false;
          break;
        }
        --midCnt[target[j]];
      }
      if (!possible) { continue; }
      char next = target[i] + 1;
      while (next <= 'z' && midCnt[next] == 0) { ++next; }
      if (next > 'z') { continue; }
      left = target.substr(0, i);
      left += next;
      --midCnt[next];
      for (char ch = 'a'; ch <= 'z'; ++ch) { left += string(midCnt[ch], ch); }
      break;
    }
    if (left == "") { return ""; }
    right = left;
    reverse(right.begin(), right.end());
    ans = left + middle + right;
    if (ans > target) { return ans; }
    return "";
  }
};
