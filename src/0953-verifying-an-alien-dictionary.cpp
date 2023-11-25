// 953. Verifying an Alien Dictionary
// https://leetcode.com/problems/verifying-an-alien-dictionary/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  bool lessThanOrEqual(string word1, string word2,
                       unordered_map<char, int>& idx) {
    int N1 = word1.size(), N2 = word2.size(), i = 0;
    while (i < N1 && i < N2) {
      if (idx[word1[i]] < idx[word2[i]])
        return true;
      if (idx[word1[i]] > idx[word2[i]])
        return false;
      ++i;
    }
    return N1 <= N2;
  }

public:
  bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> idx;
    int N = order.size(), W = words.size();
    for (int i = 0; i < N; ++i)
      idx[order[i]] = i;
    for (int i = 0; i < (W - 1); ++i)
      if (!lessThanOrEqual(words[i], words[i + 1], idx))
        return false;
    return true;
  }
};
