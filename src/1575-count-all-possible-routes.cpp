// 1575. Count All Possible Routes
// https://leetcode.com/problems/count-all-possible-routes/

#include <cmath>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
private:
  int getRoutes(int curr, int finish, int fuel, const vector<int>& locations,
                vector<vector<int>>& cache) {
    if (fuel < 0)
      return 0;
    if (cache[curr][fuel] == -1) {
      long long ans = curr == finish ? 1L : 0L;
      for (int i = 0; i < (int)locations.size(); ++i) {
        if (i == curr)
          continue;
        int requiredFuel = abs(locations[i] - locations[curr]);
        if (fuel - requiredFuel >= 0)
          ans = (ans +
                 getRoutes(i, finish, fuel - requiredFuel, locations, cache)) %
                MOD;
      }
      cache[curr][fuel] = ans;
    }
    return cache[curr][fuel];
  }

public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    vector<vector<int>> cache =
        vector<vector<int>>(locations.size(), vector<int>(fuel + 1, -1));
    return getRoutes(start, finish, fuel, locations, cache);
  }
};
