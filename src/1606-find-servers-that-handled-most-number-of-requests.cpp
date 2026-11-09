// 1606. Find Servers That Handled Most Number of Requests
// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    set<int> available;
    for (int i = 0; i < k; ++i) { available.insert(i); }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
    vector<int> handled(k, 0);
    int r = arrival.size();
    for (int i = 0; i < r; ++i) {
      while (!busy.empty() && busy.top().first <= arrival[i]) {
        available.insert(busy.top().second);
        busy.pop();
      }
      if (available.empty()) { continue; }
      set<int>::iterator it = available.lower_bound(i % k);
      if (it == available.end()) { it = available.begin(); }
      int server = *it;
      available.erase(it);
      ++handled[server];
      busy.emplace(arrival[i] + load[i], server);
    }
    int most = handled[0];
    for (int i = 1; i < k; ++i) { most = max(most, handled[i]); }
    vector<int> ans;
    for (int server = 0; server < k; ++server) {
      if (handled[server] == most) { ans.push_back(server); }
    }
    return ans;
  }
};
