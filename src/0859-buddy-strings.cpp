// 859. Buddy Strings
// https://leetcode.com/problems/buddy-strings/

#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool buddyStrings(string A, string B) {
    if (A.size() != B.size())
      return false;
    int N = A.size();
    if (N < 2)
      return false;
    string a_sorted = A, b_sorted = B;
    sort(a_sorted.begin(), a_sorted.end());
    sort(b_sorted.begin(), b_sorted.end());
    if (a_sorted != b_sorted)
      return false;
    int match_count = 0;
    unordered_map<char, int> char_cnt;
    bool has_rep = false;
    for (int i = 0; i < N; ++i) {
      if (A[i] == B[i])
        match_count++;
      char_cnt[A[i]]++;
      if (char_cnt[A[i]] >= 2)
        has_rep = true;
    }
    return match_count == N - 2 || (match_count == N && has_rep);
  }
};
