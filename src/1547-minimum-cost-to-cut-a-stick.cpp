// 1547. Minimum Cost to Cut a Stick
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <limits>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
private:
  int bestAux(int from, int to, vector<int>& cuts,
              map<tuple<int, int>, int>& cache) {
    if (cache.find({from, to}) == cache.end()) {
      int length = to - from;
      int best = numeric_limits<int>::max();
      bool hasCutToDo = false;
      for (int cut : cuts) {
        if (cut <= from || cut >= to)
          continue;
        hasCutToDo = true;
        best = min(best, length + bestAux(from, cut, cuts, cache) +
                             bestAux(cut, to, cuts, cache));
      }
      if (!hasCutToDo)
        cache[{from, to}] = 0;
      else
        cache[{from, to}] = best;
    }
    return cache[{from, to}];
  }

  int best(int size, vector<int>& cuts) {
    map<tuple<int, int>, int> cache;
    return bestAux(0, size, cuts, cache);
  }

public:
  int minCost(int n, vector<int>& cuts) { return best(n, cuts); }
};
