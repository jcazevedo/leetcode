// 2462. Total Cost to Hire K Workers
// https://leetcode.com/problems/total-cost-to-hire-k-workers/

#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    set<pair<int, int>> totCandidates;
    for (int i = 0; i < candidates; ++i) totCandidates.insert(make_pair(costs[i], i));
    for (int i = costs.size() - 1; i >= (int)costs.size() - candidates; --i)
      totCandidates.insert(make_pair(costs[i], i));
    int il = candidates, ir = costs.size() - candidates - 1;
    long long ans = 0;
    while (k-- > 0) {
      pair<int, int> choice = *totCandidates.begin();
      ans += costs[choice.second];
      totCandidates.erase(make_pair(choice.first, choice.second));
      if (il <= ir) {
        if (choice.second < il) {
          totCandidates.insert(make_pair(costs[il], il));
          il++;
        } else {
          totCandidates.insert(make_pair(costs[ir], ir));
          ir--;
        }
      }
    }
    return ans;
  }
};
