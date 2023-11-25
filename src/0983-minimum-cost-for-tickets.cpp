// 983. Minimum Cost For Tickets
// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <vector>

using namespace std;

class Solution {
 private:
  int minCost(int dayIdx,
              const vector<int>& days,
              const vector<int>& costs,
              vector<int>& cache) {
    if (dayIdx >= (int)days.size()) return 0;
    if (cache[dayIdx] == -1) {
      int day1 = costs[0] + minCost(dayIdx + 1, days, costs, cache);
      int day7 = costs[1];
      int i7 = dayIdx;
      while (i7 < (int)days.size() && days[i7] - days[dayIdx] < 7) i7++;
      day7 += minCost(i7, days, costs, cache);
      int day30 = costs[2];
      int i30 = dayIdx;
      while (i30 < (int)days.size() && days[i30] - days[dayIdx] < 30) i30++;
      day30 += minCost(i30, days, costs, cache);
      cache[dayIdx] = min(day1, min(day7, day30));
    }
    return cache[dayIdx];
  }

 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int N = days.size();
    vector<int> cache = vector<int>(N, -1);
    return minCost(0, days, costs, cache);
  }
};
