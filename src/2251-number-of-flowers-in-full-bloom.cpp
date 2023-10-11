// 2251. Number of Flowers in Full Bloom
// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

#include <queue>
#include <vector>

using namespace std;

#define FLOWER_IN 0
#define PEOPLE_IN 1
#define FLOWER_OUT 2

class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<int> ans(people.size());
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (const vector<int>& flower : flowers) {
      pq.push({flower[0], FLOWER_IN});
      pq.push({flower[1], FLOWER_OUT});
    }
    for (int i = 0; i < (int)people.size(); ++i)
      pq.push({people[i], PEOPLE_IN, i});
    int currFlowers = 0;
    while (!pq.empty()) {
      vector<int> curr = pq.top();
      pq.pop();
      if (curr[1] == FLOWER_IN)
        currFlowers++;
      if (curr[1] == FLOWER_OUT)
        currFlowers--;
      if (curr[1] == PEOPLE_IN)
        ans[curr[2]] = currFlowers;
    }
    return ans;
  }
};
