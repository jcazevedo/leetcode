#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    for (vector<int> interval : intervals) {
      if (interval[1] < newInterval[0]) {
        result.push_back(interval);
      } else if (interval[0] > newInterval[1]) {
        result.push_back(newInterval);
        newInterval = interval;
      } else if (interval[1] >= newInterval[0] || interval[0] <= newInterval[1]) {
        newInterval = {min(interval[0], newInterval[0]), max(interval[1], newInterval[1])};
      }
    }
    result.push_back(newInterval);
    return result;
  }
};
