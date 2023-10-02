// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

#include <string>

using namespace std;

class Solution {
public:
  bool winnerOfGame(string colors) {
    int aCnt = 0, bCnt = 0, N = colors.size();
    char last = colors[0];
    int currentCnt = 1;
    for (int i = 1; i < N; ++i)
      if (colors[i] == last)
        currentCnt++;
      else {
        if (last == 'A' && currentCnt > 2)
          aCnt += currentCnt - 2;
        if (last == 'B' && currentCnt > 2)
          bCnt += currentCnt - 2;
        last = colors[i];
        currentCnt = 1;
      }
    if (last == 'A' && currentCnt > 2)
      aCnt += currentCnt - 2;
    if (last == 'B' && currentCnt > 2)
      bCnt += currentCnt - 2;
    return aCnt > bCnt;
  }
};
