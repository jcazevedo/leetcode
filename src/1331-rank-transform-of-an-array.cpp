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
    vector<int> toSort = arr;
    sort(begin(toSort), end(toSort));
    unordered_map<int, int> rank;
    rank.reserve(N);
    int curr = 1;
    for (int i = 0; i < N; ++i) {
      if (i == 0 || toSort[i] != toSort[i - 1]) { rank.emplace(toSort[i], curr++); }
    }
    vector<int> ans(N);
    for (int i = 0; i < N; ++i) { ans[i] = rank.find(arr[i])->second; }
    return ans;
  }
};
