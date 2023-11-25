// 2024. Maximize the Confusion of an Exam
// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int ans = k, ts = 0, fs = 0, l = 0;
    for (int i = 0; i < k; ++i) {
      if (answerKey[i] == 'T') ++ts;
      if (answerKey[i] == 'F') ++fs;
    }
    for (int r = k; r < (int)answerKey.size(); ++r) {
      if (answerKey[r] == 'T') ++ts;
      if (answerKey[r] == 'F') ++fs;
      while (l <= r && min(ts, fs) > k) {
        if (answerKey[l] == 'T') --ts;
        if (answerKey[l] == 'F') --fs;
        ++l;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
