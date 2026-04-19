// 680. Valid Palindrome II
// https://leetcode.com/problems/valid-palindrome-ii/

#include <string>

using namespace std;

class Solution {
 private:
  bool isPalindrome(const string& s, int left, int right, int allowedRemovals) {
    while (left < right) {
      if (s[left] != s[right]) {
        if (allowedRemovals == 0) { return false; }
        return isPalindrome(s, left + 1, right, allowedRemovals - 1) ||
               isPalindrome(s, left, right - 1, allowedRemovals - 1);
      }
      left++;
      right--;
    }
    return true;
  }

 public:
  bool validPalindrome(string s) { return isPalindrome(s, 0, s.size() - 1, 1); }
};
