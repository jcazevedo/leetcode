#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char, vector<int> > pos;
    int N = s.size();
    for (int i = 0; i < N; i++) {
      pos[s[i]].push_back(i);
    }
    map<char, int> curr;
    map<char, int> idx;
    int best = 0, start = 0;
    for (int i = 0; i < N; i++) {
      int prev = curr.find(s[i]) == curr.end() ? -1 : curr[s[i]];
      if (prev != -1) {
        start = max(start, pos[s[i]][idx[s[i]]] + 1);
        idx[s[i]]++;
      }
      curr[s[i]] = i;
      best = max(best, i - start + 1);
    }
    return best;
  }
};
