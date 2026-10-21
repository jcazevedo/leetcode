// 3863. Minimum Operations to Sort a String
// https://leetcode.com/problems/minimum-operations-to-sort-a-string/

#include <string>

using namespace std;

class Solution {
 public:
  int minOperations(string s) {
    int n = s.size();
    bool sorted = true;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] > s[i + 1]) {
        sorted = false;
        break;
      }
    }
    if (sorted) { return 0; }
    if (n == 2) { return -1; }
    bool left = true;
    for (int i = 1; i < n; ++i) {
      if (s[i] < s[0]) {
        left = false;
        break;
      }
    }
    if (left) { return 1; }
    bool right = true;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] > s[n - 1]) {
        right = false;
        break;
      }
    }
    if (right) { return 1; }
    bool needsThree = s[0] > s[n - 1];
    for (int i = 1; i < n - 1; ++i) {
      if (s[i] >= s[0] || s[i] <= s[n - 1]) {
        needsThree = false;
        break;
      }
    }
    return needsThree ? 3 : 2;
  }
};
