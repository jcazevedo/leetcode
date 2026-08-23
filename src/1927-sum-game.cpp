// 1927. Sum Game
// https://leetcode.com/problems/sum-game/

#include <string>

using namespace std;

class Solution {
 public:
  bool sumGame(string num) {
    int n = num.size();
    int leftSum = 0, rightSum = 0, leftQuestions = 0, rightQuestions = 0;
    for (int i = 0; i < n; ++i) {
      if (num[i] == '?') {
        if (i < n / 2) {
          ++leftQuestions;
        } else {
          ++rightQuestions;
        }
      } else {
        if (i < n / 2) {
          leftSum += num[i] - '0';
        } else {
          rightSum += num[i] - '0';
        }
      }
    }
    return 2 * (leftSum - rightSum) != 9 * (rightQuestions - leftQuestions);
  }
};
