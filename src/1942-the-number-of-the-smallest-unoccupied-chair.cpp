// 1942. The Number of the Smallest Unoccupied Chair
// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

#define ENTER (+1)
#define LEAVE (-1)

class Solution {
 public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n = times.size();
    set<int> unoccupied;
    for (int i = 0; i < n; ++i) { unoccupied.insert(i); }
    vector<vector<int>> events;
    for (int i = 0; i < n; ++i) {
      events.push_back({times[i][0], ENTER, i});
      events.push_back({times[i][1], LEAVE, i});
    }
    sort(begin(events), end(events));
    unordered_map<int, int> chairs;
    for (int i = 0; i < n * 2; ++i) {
      if (events[i][1] == ENTER) {
        int chair = *unoccupied.begin();
        if (targetFriend == events[i][2]) { return chair; }
        unoccupied.erase(chair);
        chairs[events[i][2]] = chair;
      } else {
        int chair = chairs[events[i][2]];
        unoccupied.insert(chair);
        chairs.erase(events[i][2]);
      }
    }
    return -1;
  }
};
