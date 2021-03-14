#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define A 256
#define P 2147483647

class Solution {
private:
  pair<int, int> has_dup_substring(string S, int n) {
    unordered_map<long long, vector<int>> visited;
    long long h = 1;
    for (int i = 0; i < n - 1; ++i)
      h = (h * A) % P;
    long long t = 0;
    for (int i = 0; i < n; ++i)
      t = (A * t + (S[i] - '0')) % P;
    visited[t].push_back(0);
    int N = S.size();
    for (int i = n; i < N; ++i) {
      t = (A * (t - (S[i - n] - '0') * h) + (S[i] - '0')) % P;
      if (t < 0)
        t += P;
      vector<int> candidates = visited[t];
      for (int c : candidates) {
        bool good = true;
        for (int j = 0; j < n && good; ++j) {
          if (S[c + j] != S[i - n + 1 + j])
            good = false;
        }
        if (good)
          return make_pair(c, n);
      }
      visited[t].push_back(i - n + 1);
    }
    return {-1, n};
  }

public:
  string longestDupSubstring(string S) {
    int N = S.size();
    int lo = 0, hi = N - 1;
    string best = "";
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      pair<int, int> dup = has_dup_substring(S, mid);
      if (dup.first != -1) {
        best = S.substr(dup.first, mid);
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    return best;
  }
};
