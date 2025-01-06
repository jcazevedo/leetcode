// 1769. Minimum Number of Operations to Move All Balls to Each Box
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int N = boxes.size();
    vector<int> l(N, 0), r(N, 0), bl(N, 0), br(N, 0), ans(N);
    br[N - 1] = boxes[N - 1] == '1' ? 1 : 0;
    for (int i = N - 2; i >= 0; --i) {
      br[i] = br[i + 1];
      r[i] = r[i + 1] + br[i + 1];
      if (boxes[i] == '1') { ++br[i]; }
    }
    bl[0] = boxes[0] == '1' ? 1 : 0;
    for (int i = 1; i < N; ++i) {
      bl[i] = bl[i - 1];
      l[i] = l[i - 1] + bl[i - 1];
      if (boxes[i] == '1') { ++bl[i]; }
    }
    for (int i = 0; i < N; ++i) { ans[i] = l[i] + r[i]; }
    return ans;
  }
};
