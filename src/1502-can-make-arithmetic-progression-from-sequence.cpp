// 1502. Can Make Arithmetic Progression From Sequence
// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

#include <limits>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    int minV = numeric_limits<int>::max(), maxV = numeric_limits<int>::min(), N = arr.size();
    for (int i = 0; i < N; ++i) {
      minV = min(minV, arr[i]);
      maxV = max(maxV, arr[i]);
    }
    if (maxV - minV == 0) return true;
    if ((maxV - minV) % (N - 1) != 0) return false;
    int diff = (maxV - minV) / (N - 1);
    unordered_set<int> visited;
    for (int i = 0; i < N; ++i) {
      if (visited.count(arr[i])) return false;
      visited.insert(arr[i]);
      if ((arr[i] - minV) % diff != 0) return false;
    }
    return true;
  }
};
