// 378. Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int H = matrix.size();
    int W = matrix[0].size();
    set<pair<int, int>> included;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   std::greater<pair<int, pair<int, int>>>>
        pq;
    included.insert(make_pair(0, 0));
    pq.push(make_pair(matrix[0][0], make_pair(0, 0)));
    while (k > 1) {
      pair<int, pair<int, int>> current = pq.top();
      pq.pop();
      int i = current.second.first;
      int j = current.second.second;
      auto b = make_pair(i + 1, j);
      auto r = make_pair(i, j + 1);
      if (b.first < H && b.second < W && included.find(b) == included.end()) {
        included.insert(b);
        pq.push(make_pair(matrix[b.first][b.second], b));
      }
      if (r.first < H && r.second < W && included.find(r) == included.end()) {
        included.insert(r);
        pq.push(make_pair(matrix[r.first][r.second], r));
      }
      k--;
    }
    return pq.top().first;
  }
};
