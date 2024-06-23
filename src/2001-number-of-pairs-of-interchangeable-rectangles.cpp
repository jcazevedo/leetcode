// 2001. Number of Pairs of Interchangeable Rectangles
// https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    unordered_map<double, long long> count;
    for (const vector<int>& rectangle : rectangles) ++count[((double)rectangle[0]) / rectangle[1]];
    long long ans = 0L;
    for (auto itr = count.begin(); itr != count.end(); ++itr) ans += (itr->second * (itr->second - 1)) / 2L;
    return ans;
  }
};
