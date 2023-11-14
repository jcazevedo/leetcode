// 1930. Unique Length-3 Palindromic Subsequences
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    int N = s.size();

    int ans = 0;
    for (char edge = 'a'; edge <= 'z'; ++edge) {
      int l = 0;
      while (l < N && s[l] != edge)
        l++;

      int r = N - 1;
      while (r >= 0 && s[r] != edge)
        r--;

      if (l < r) {
        unordered_set<char> visited;
        for (int i = l + 1; i <= r - 1; ++i)
          if (visited.count(s[i]) == 0) {
            ans++;
            visited.insert(s[i]);
          }
      }
    }

    return ans;
  }
};
