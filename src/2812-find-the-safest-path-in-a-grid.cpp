// 2812. Find the Safest Path in a Grid
// https://leetcode.com/problems/find-the-safest-path-in-a-grid/

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class UnionFind {
 private:
  vector<int> p, rank;

 public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) { p[i] = i; }
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

  bool connectedSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!connectedSet(i, j)) {
      int x = findSet(i);
      int y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) { ++rank[y]; }
      }
    }
  }
};

class Solution {
 private:
  static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

 public:
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();
    int totalCells = n * n;
    vector<int> distance(totalCells, -1);
    queue<int> q;
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        if (grid[row][col] == 1) {
          int cell = row * n + col;
          distance[cell] = 0;
          q.push(cell);
        }
      }
    }
    int maxDistance = 0;
    while (!q.empty()) {
      int cell = q.front();
      q.pop();
      int row = cell / n;
      int col = cell % n;
      for (const int(&dir)[2] : dirs) {
        int nextRow = row + dir[0];
        int nextCol = col + dir[1];
        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n) { continue; }
        int nextCell = nextRow * n + nextCol;
        if (distance[nextCell] != -1) { continue; }
        distance[nextCell] = distance[cell] + 1;
        maxDistance = max(maxDistance, distance[nextCell]);
        q.push(nextCell);
      }
    }
    vector<vector<int>> cellsAtDistance(maxDistance + 1);
    for (int cell = 0; cell < totalCells; ++cell) { cellsAtDistance[distance[cell]].push_back(cell); }
    UnionFind components(totalCells);
    vector<char> active(totalCells, false);
    for (int safety = maxDistance; safety >= 0; --safety) {
      for (int cell : cellsAtDistance[safety]) {
        active[cell] = true;
        int row = cell / n;
        int col = cell % n;
        for (const int(&dir)[2] : dirs) {
          int nextRow = row + dir[0];
          int nextCol = col + dir[1];
          if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n) { continue; }
          int nextCell = nextRow * n + nextCol;
          if (active[nextCell]) { components.unionSet(cell, nextCell); }
        }
      }
      if (active[0] && active[totalCells - 1] && components.connectedSet(0, totalCells - 1)) { return safety; }
    }
    return 0;
  }
};
