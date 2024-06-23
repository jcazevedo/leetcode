// 733. Flood Fill
// https://leetcode.com/problems/flood-fill/

#include <map>
#include <vector>

using namespace std;

class Solution {
 private:
  const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  void flood_fill(
      vector<vector<int>>& image, int sr, int sc, int H, int W, int newColor, vector<vector<bool>>& visited) {
    visited[sr][sc] = true;
    for (pair<int, int> new_dir : dirs) {
      int new_sr = sr + new_dir.first;
      int new_sc = sc + new_dir.second;
      if (new_sr >= 0 && new_sr < H && new_sc >= 0 && new_sc < W && image[new_sr][new_sc] == image[sr][sc] &&
          !visited[new_sr][new_sc]) {
        flood_fill(image, new_sr, new_sc, H, W, newColor, visited);
      }
    }
    image[sr][sc] = newColor;
  }

 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int H = image.size();
    int W = image[0].size();
    vector<vector<bool>> visited(H, vector<bool>(W));
    flood_fill(image, sr, sc, H, W, newColor, visited);
    return image;
  }
};
