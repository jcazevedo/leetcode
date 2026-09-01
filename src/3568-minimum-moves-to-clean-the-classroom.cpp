// 3568. Minimum Moves to Clean the Classroom
// https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/

#include <functional>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int minMoves(vector<string>& classroom, int energy) {
    int h = classroom.size(), w = classroom[0].size();
    tuple<int, int, int, int> start = make_tuple(-1, -1, -1, -1);
    int litter = 0;
    vector<vector<int>> litterIdx(h, vector<int>(w, -1));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (classroom[i][j] == 'S') { start = make_tuple(i, j, energy, 0); }
        if (classroom[i][j] == 'L') { litterIdx[i][j] = litter++; }
      }
    }
    if (litter == 0) { return 0; }
    get<3>(start) = (1 << litter) - 1;
    int masks = 1 << litter;
    int energyStates = energy + 1;
    vector<bool> visited = vector<bool>(h * w * energyStates * masks, false);
    function<int(int, int, int, int)> stateId = [&](int i, int j, int e, int mask) {
      return (((i * w + j) * energyStates + e) * masks + mask);
    };
    visited[stateId(get<0>(start), get<1>(start), get<2>(start), get<3>(start))] = true;
    queue<pair<int, tuple<int, int, int, int>>> q;
    q.push(make_pair(0, start));
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
      pair<int, tuple<int, int, int, int>> curr = q.front();
      q.pop();
      int dist = curr.first;
      int i = get<0>(curr.second);
      int j = get<1>(curr.second);
      int e = get<2>(curr.second);
      int l = get<3>(curr.second);
      for (const vector<int>& d : dirs) {
        int ni = i + d[0];
        int nj = j + d[1];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w || classroom[ni][nj] == 'X') { continue; }
        int ne = e - 1;
        if (classroom[ni][nj] == 'R') { ne = energy; }
        int nl = l;
        if (classroom[ni][nj] == 'L') { nl &= ~(1 << litterIdx[ni][nj]); }
        if (nl == 0) { return dist + 1; }
        tuple<int, int, int, int> nt = make_tuple(ni, nj, ne, nl);
        int ntId = stateId(ni, nj, ne, nl);
        if (visited[ntId]) { continue; }
        visited[ntId] = true;
        if (ne == 0) { continue; }
        q.push(make_pair(dist + 1, nt));
      }
    }
    return -1;
  }
};
