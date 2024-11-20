// 2516. Take K of Each Character From Left and Right
// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int takeCharacters(string s, int k) {
    int N = s.size();
    unordered_map<char, vector<int>> sumL;
    unordered_map<char, vector<int>> sumR;
    for (char ch = 'a'; ch <= 'c'; ++ch) {
      sumL[ch] = vector<int>(N, 0);
      for (int i = 0; i < N; ++i) {
        if (i > 0) { sumL[ch][i] = sumL[ch][i - 1]; }
        if (s[i] == ch) { ++sumL[ch][i]; }
      }
      sumR[ch] = vector<int>(N, 0);
      for (int i = N - 1; i >= 0; --i) {
        if (i + 1 < N) { sumR[ch][i] = sumR[ch][i + 1]; }
        if (s[i] == ch) { ++sumR[ch][i]; }
      }
    }
    for (char ch = 'a'; ch <= 'c'; ++ch) {
      if (sumL[ch][N - 1] < k) { return -1; }
    }
    int ans = N;
    int r = 0;
    for (int l = N; l >= 0; --l) {
      unordered_map<char, int> curr;
      for (char ch = 'a'; ch <= 'c'; ++ch) {
        if (r > 0) { curr[ch] = sumR[ch][N - r]; }
      }
      bool good = true;
      for (char ch = 'a'; ch <= 'c'; ++ch) {
        if (l > 0) { curr[ch] += sumL[ch][l - 1]; }
        if (curr[ch] < k) { good = false; }
      }
      while (l + r < N && !good) {
        ++r;
        good = true;
        for (char ch = 'a'; ch <= 'c'; ++ch) {
          if (s[N - r] == ch) { ++curr[ch]; }
          if (curr[ch] < k) { good = false; }
        }
      }
      ans = min(ans, l + r);
    }
    return ans;
  }
};
