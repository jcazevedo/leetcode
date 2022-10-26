#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<string> dfs(vector<string>& curr, unordered_map<string, vector<int>>& graph, vector<bool>& used,
                     vector<vector<string>>& tickets) {
    if (curr.size() == tickets.size() + 1) return curr;
    vector<pair<string, int>> next_tickets;
    for (int ticket : graph[curr.back()]) {
      if (used[ticket]) continue;
      next_tickets.emplace_back(tickets[ticket][1], ticket);
    }
    sort(next_tickets.begin(), next_tickets.end());
    for (const pair<string, int>& next_ticket : next_tickets) {
      used[next_ticket.second] = true;
      curr.push_back(next_ticket.first);
      vector<string> res = dfs(curr, graph, used, tickets);
      if (res.size() > 0) return res;
      curr.pop_back();
      used[next_ticket.second] = false;
    }
    return {};
  }

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, vector<int>> graph;
    int T = tickets.size();
    for (int t = 0; t < T; ++t) graph[tickets[t][0]].push_back(t);
    vector<bool> used(T, false);
    vector<string> res = {"JFK"};
    return dfs(res, graph, used, tickets);
  }
};
