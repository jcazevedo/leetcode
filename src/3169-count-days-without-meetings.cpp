// 3169. Count Days Without Meetings
// https://leetcode.com/problems/count-days-without-meetings/

#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (const vector<int>& meeting : meetings) {
      pq.push({meeting[0], 0});
      pq.push({meeting[1], 1});
    }
    int ans = days, currMeetings = 0, start = -1;
    while (!pq.empty()) {
      pair<int, int> curr = pq.top();
      pq.pop();
      int prevMeetings = currMeetings;
      if (curr.second == 0) {
        ++currMeetings;
      } else {
        --currMeetings;
      }
      if (currMeetings > 0 && prevMeetings == 0) { start = curr.first; }
      if (currMeetings == 0 && prevMeetings > 0) { ans -= (curr.first - start + 1); }
    }
    return ans;
  }
};
