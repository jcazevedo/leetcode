// 214. Shortest Palindrome
// https://leetcode.com/problems/shortest-palindrome/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> manacherOdd(string s) {
    int N = s.size();
    s = "$" + s + "^";
    vector<int> p(N + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= N; ++i) {
      p[i] = max(0, min(r - i, p[l + (r - i)]));
      while (s[i - p[i]] == s[i + p[i]]) { ++p[i]; }
      if (i + p[i] > r) {
        l = i - p[i];
        r = i + p[i];
      }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
  }

 public:
  string shortestPalindrome(string s) {
    string t = "";
    for (char ch : s) { t += string("#") + ch; }
    t += "#";
    vector<int> d = manacherOdd(t);
    int N = s.size(), best = 0;
    for (int i = 0; i < N; ++i) {
      if (i > 0) {
        int lenEven = (d[2 * i] - 1) / 2;
        if (i - lenEven == 0) { best = lenEven * 2; }
      }
      int lenOdd = d[2 * i + 1] / 2;
      if (i - (lenOdd - 1) == 0) { best = lenOdd * 2 - 1; }
    }
    if (best == N) { return s; }
    string prefix = s.substr(best);
    reverse(prefix.begin(), prefix.end());
    return prefix + s;
  }
};
