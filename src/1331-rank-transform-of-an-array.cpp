// 1331. Rank Transform of an Array
// https://leetcode.com/problems/rank-transform-of-an-array/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    int N = arr.size();
    vector<int> toSort(N);
    for (int i = 0; i < N; ++i) { toSort[i] = arr[i]; }
    sort(begin(toSort), end(toSort));
    unordered_map<int, int> rank;
    int curr = 1;
    for (int i = 0; i < N; ++i) {
      if (rank.find(toSort[i]) == rank.end()) { rank[toSort[i]] = curr++; }
    }
    vector<int> ans(N);
    for (int i = 0; i < N; ++i) { ans[i] = rank[arr[i]]; }
    return ans;
  }
};
