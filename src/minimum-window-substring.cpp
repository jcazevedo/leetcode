#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> target;
    for (char ch : t)
      target[ch]++;
    unordered_map<char, int> cnt;
    int N = s.size();
    string best = "";
    int left = 0, good = 0, len = INT_MAX;
    for (int i = 0; i < N; ++i) {
      if (target[s[i]] == 0)
        continue;
      if (cnt[s[i]] < target[s[i]])
        good++;
      cnt[s[i]]++;
      if (good == t.size()) {
        while (target[s[left]] == 0 || cnt[s[left]] > target[s[left]]) {
          cnt[s[left]]--;
          left++;
        }
        if (len > i - left + 1) {
          len = i - left + 1;
          best = s.substr(left, len);
        }
      }
    }
    return best;
  }
};
