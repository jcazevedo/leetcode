// 395. Longest Substring with At Least K Repeating Characters
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int longestSubstring(string s, int k) {
    int L = s.size();
    if (k > L) return 0;
    unordered_map<char, int> cnt;
    for (int i = 0; i < L; ++i) cnt[s[i]]++;
    for (int i = 0; i < L; ++i) {
      if (cnt[s[i]] < k)
        return max(longestSubstring(s.substr(0, i), k),
                   longestSubstring(s.substr(i + 1), k));
    }
    return L;
  }
};
