// 815. Bus Routes
// https://leetcode.com/problems/bus-routes/

#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    if (source == target)
      return 0;

    int R = routes.size();
    unordered_map<int, vector<int>> routesInStop;
    for (int i = 0; i < R; ++i) {
      int NR = routes[i].size();
      for (int j = 0; j < NR; ++j)
        routesInStop[routes[i][j]].push_back(i);
    }

    unordered_set<int> visitedRoutes;
    unordered_map<int, int> distances;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    for (int i = 0; i < R; ++i) {
      bool inStop = false;
      for (int route : routesInStop[source])
        if (route == i) {
          inStop = true;
          break;
        }

      if (inStop) {
        visitedRoutes.insert(i);
        for (int stop : routes[i]) {
          distances[stop] = 0;
          pq.push({0, stop, i});
        }
      }
    }

    while (!pq.empty()) {
      int distance, stop, route;
      tie(distance, stop, route) = pq.top();
      pq.pop();

      if (stop == target)
        return distance + 1;

      if (visitedRoutes.count(route) == 0) {
        visitedRoutes.insert(route);
        for (int next : routes[route])
          if (distances.count(next) == 0 || distance < distances[next]) {
            distances[next] = distance;
            pq.push({distance, next, route});
          }
      }

      for (int nextRoute : routesInStop[stop]) {
        if (visitedRoutes.count(nextRoute) == 1)
          continue;

        visitedRoutes.insert(nextRoute);
        for (int next : routes[nextRoute])
          if (distances.count(next) == 0 || distance + 1 < distances[next]) {
            distances[next] = distance + 1;
            pq.push({distance + 1, next, nextRoute});
          }
      }
    }

    return -1;
  }
};
