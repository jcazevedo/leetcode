// 87. Scramble String
// https://leetcode.com/problems/scramble-string/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  bool isScrambleAux(
      const string& s1, const string& s2, int fs, int fe, int ts, int te, vector<vector<vector<vector<int>>>>& cache) {
    int len = fe - fs;
    if (len == 1) { return s1[fs] == s2[ts]; }
    if (cache[fs][fe][ts][te] != -1) { return cache[fs][fe][ts][te] == 1; }
    for (int s = fs + 1; s < fe; ++s) {
      int lenSplit = s - fs;
      bool withoutSwap = isScrambleAux(s1, s2, fs, fs + lenSplit, ts, ts + lenSplit, cache) &&
                         isScrambleAux(s1, s2, fs + lenSplit, fe, ts + lenSplit, te, cache);
      if (withoutSwap) {
        cache[fs][fe][ts][te] = 1;
        return true;
      }
      bool withSwap = isScrambleAux(s1, s2, fs, fs + lenSplit, te - lenSplit, te, cache) &&
                      isScrambleAux(s1, s2, fs + lenSplit, fe, ts, te - lenSplit, cache);
      if (withSwap) {
        cache[fs][fe][ts][te] = 1;
        return true;
      }
    }
    cache[fs][fe][ts][te] = 0;
    return false;
  }

 public:
  bool isScramble(string s1, string s2) {
    int N = s1.size();
    vector<vector<vector<vector<int>>>> cache(
        N, vector<vector<vector<int>>>(N + 1, vector<vector<int>>(N, vector<int>(N + 1, -1))));
    return isScrambleAux(s1, s2, 0, N, 0, N, cache);
  }
};
