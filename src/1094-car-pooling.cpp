// 1094. Car Pooling
// https://leetcode.com/problems/car-pooling/

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    map<int, int> diffs;
    for (vector<int> trip : trips) {
      diffs[trip[1]] += trip[0];
      diffs[trip[2]] -= trip[0];
    }
    int curr = 0;
    for (auto itr = diffs.begin(); itr != diffs.end(); ++itr) {
      curr += itr->second;
      if (curr > capacity) return false;
    }
    return true;
  }
};
