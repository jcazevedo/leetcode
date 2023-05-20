// 218. The Skyline Problem
// https://leetcode.com/problems/the-skyline-problem/

#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // {false, height} means a building exits with height 'height'.
    // {true, height} means a building enters with height 'height'.
    map<int, vector<pair<bool, int>>> events;
    for (const vector<int>& building : buildings) {
      events[building[0]].push_back({true, building[2]});
      events[building[1]].push_back({false, building[2]});
    }
    int curr_height = 0;
    vector<vector<int>> ans;
    multiset<int> heights;
    for (auto itr = events.begin(); itr != events.end(); ++itr) {
      int x = itr->first;
      const vector<pair<bool, int>>& x_events = itr->second;
      for (const pair<bool, int>& event : x_events) {
        if (event.first)
          heights.insert(event.second);
        else
          heights.erase(heights.find(event.second));
      }
      int next_height = heights.empty() ? 0 : *heights.rbegin();
      if (next_height != curr_height)
        ans.push_back({x, next_height});
      curr_height = next_height;
    }
    return ans;
  }
};
