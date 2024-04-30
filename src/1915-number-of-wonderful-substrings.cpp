// 1915. Number of Wonderful Substrings
// https://leetcode.com/problems/number-of-wonderful-substrings/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    unordered_map<int, long long> prev;
    int N = word.size(), curr = 0;
    long long ans = 0;
    prev[0] = 1L;
    for (int i = 0; i < N; ++i) {
      curr ^= (1 << (word[i] - 'a'));
      ans += prev[curr];
      for (char ch = 'a'; ch <= 'j'; ++ch)
        ans += prev[curr ^ (1 << (ch - 'a'))];
      ++prev[curr];
    }
    return ans;
  }
};
