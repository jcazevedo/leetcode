// 3433. Count Mentions Per User
// https://leetcode.com/problems/count-mentions-per-user/

#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

#define ONLINE 0
#define OFFLINE 1
#define MESSAGE 2

class Solution {
 private:
  int toInt(const string& s) {
    istringstream ss(s);
    int ans;
    ss >> ans;
    return ans;
  }

 public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    vector<bool> online(numberOfUsers, true);
    vector<int> mentions(numberOfUsers, 0);
    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, greater<tuple<int, int, string>>> pq;
    for (vector<string>& event : events) {
      pq.push({toInt(event[1]), event[0] == "MESSAGE" ? MESSAGE : OFFLINE, event[2]});
    }
    while (!pq.empty()) {
      auto [ts, eventType, eventDescription] = pq.top();
      pq.pop();
      switch (eventType) {
        case ONLINE:
          online[toInt(eventDescription)] = true;
          break;
        case OFFLINE:
          online[toInt(eventDescription)] = false;
          pq.push({ts + 60, ONLINE, eventDescription});
          break;
        case MESSAGE:
          if (eventDescription == "ALL") {
            for (int i = 0; i < numberOfUsers; ++i) { ++mentions[i]; }
          } else if (eventDescription == "HERE") {
            for (int i = 0; i < numberOfUsers; ++i) {
              if (!online[i]) { continue; }
              ++mentions[i];
            }
          } else {
            int idx = 0;
            int N = eventDescription.size();
            while (idx < N) {
              string curr = "";
              idx += 2;
              while (idx < N && eventDescription[idx] != ' ') {
                curr += eventDescription[idx];
                ++idx;
              }
              ++mentions[toInt(curr)];
              ++idx;
            }
          }
          break;
      }
    }
    return mentions;
  }
};
