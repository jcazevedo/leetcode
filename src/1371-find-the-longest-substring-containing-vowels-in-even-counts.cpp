// 1371. Find the Longest Substring Containing Vowels in Even Counts
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findTheLongestSubstring(string s) {
    int N = s.size(), ans = 0, curr = 0;
    vector<int> prev(1 << 5, -1);
    prev[curr] = 0;
    for (int i = 1; i <= N; ++i) {
      char ch = s[i - 1];
      if (ch == 'a') {
        curr = curr ^ (1 << 0);
      } else if (ch == 'e') {
        curr = curr ^ (1 << 1);
      } else if (ch == 'i') {
        curr = curr ^ (1 << 2);
      } else if (ch == 'o') {
        curr = curr ^ (1 << 3);
      } else if (ch == 'u') {
        curr = curr ^ (1 << 4);
      }
      if (prev[curr] != -1) {
        ans = max(ans, i - prev[curr]);
      } else {
        prev[curr] = i;
      }
    }
    return ans;
  }
};
