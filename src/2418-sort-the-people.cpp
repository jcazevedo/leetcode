// 2418. Sort the People
// https://leetcode.com/problems/sort-the-people/

#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int N = names.size();
    priority_queue<pair<int, string>> pq;
    for (int i = 0; i < N; ++i) { pq.push(make_pair(heights[i], names[i])); }
    vector<string> ans;
    while (!pq.empty()) {
      pair<int, string> curr = pq.top();
      pq.pop();
      ans.push_back(curr.second);
    }
    return ans;
  }
};
