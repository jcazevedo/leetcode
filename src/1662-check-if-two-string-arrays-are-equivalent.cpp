// 1662. Check If Two String Arrays are Equivalent
// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int w1 = 0, w2 = 0, i1 = 0, i2 = 0;
    while (w1 < (int)word1.size() && w2 < (int)word2.size()) {
      if (i1 >= (int)word1[w1].size()) {
        w1++;
        i1 = 0;
      }
      if (i2 >= (int)word2[w2].size()) {
        w2++;
        i2 = 0;
      }
      if (w1 < (int)word1.size() && w2 < (int)word2.size() &&
          word1[w1][i1] != word2[w2][i2]) {
        return false;
      } else {
        i1++;
        i2++;
      }
    }
    return w1 >= (int)word1.size() && w2 >= (int)word2.size();
  }
};
