// 2406. Divide Intervals Into Minimum Number of Groups
// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

#include <algorithm>
#include <vector>

using namespace std;

#define BEGIN (+1)
#define END (-1)

class Solution {
 public:
  int minGroups(vector<vector<int>>& intervals) {
    vector<vector<int>> events;
    for (const vector<int>& interval : intervals) {
      events.push_back({interval[0], BEGIN});
      events.push_back({interval[1] + 1, END});
    }
    sort(begin(events), end(events));
    int curr = 0, ans = 0;
    for (const vector<int>& event : events) {
      curr += event[1];
      ans = max(ans, curr);
    }
    return ans;
  }
};
