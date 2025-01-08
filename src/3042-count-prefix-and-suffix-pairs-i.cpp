// 3042. Count Prefix and Suffix Pairs I
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int N = words.size(), ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (words[j].size() >= words[i].size() && words[j].substr(0, words[i].size()) == words[i] &&
            words[j].substr(words[j].size() - words[i].size(), words[i].size()) == words[i]) {
          ++ans;
        }
      }
    }
    return ans;
  }
};
