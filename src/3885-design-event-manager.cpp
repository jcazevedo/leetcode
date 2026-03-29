// 3885. Design Event Manager
// https://leetcode.com/problems/design-event-manager/

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class EventManager {
 private:
  priority_queue<vector<int>> pq;
  unordered_map<int, int> priorities;
  unordered_set<int> active;

 public:
  EventManager(vector<vector<int>>& events) {
    for (const vector<int>& event : events) {
      pq.push({event[1], -event[0]});
      priorities[event[0]] = event[1];
      active.insert(event[0]);
    }
  }

  void updatePriority(int eventId, int newPriority) {
    if (!active.count(eventId)) { return; }
    priorities[eventId] = newPriority;
    pq.push({newPriority, -eventId});
  }

  int pollHighest() {
    while (!pq.empty()) {
      vector<int> top = pq.top();
      pq.pop();
      if (!active.count(-top[1])) { continue; }
      if (priorities[-top[1]] == top[0]) {
        active.erase(-top[1]);
        return -top[1];
      }
    }
    return -1;
  }
};
