// 1456. Maximum Number of Vowels in a Substring of Given Length
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <string>

using namespace std;

class Solution {
 private:
  bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }

 public:
  int maxVowels(string s, int k) {
    int N = s.size(), curr = 0, ans = 0;
    for (int i = 0; i < k; ++i)
      if (isVowel(s[i])) ++curr;
    ans = curr;
    for (int i = k; i < N; ++i) {
      if (isVowel(s[i - k])) --curr;
      if (isVowel(s[i])) ++curr;
      ans = max(ans, curr);
    }
    return ans;
  }
};
