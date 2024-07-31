// 1105. Filling Bookcase Shelves
// https://leetcode.com/problems/filling-bookcase-shelves/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 private:
  int getBest(int nextBook,
              int currentWidth,
              int currentHeight,
              vector<vector<int>>& cache,
              const vector<vector<int>>& books,
              int shelfWidth) {
    if (nextBook == (int)books.size() - 1) {
      if (currentWidth + books[nextBook][0] <= shelfWidth) { return max(currentHeight, books[nextBook][1]); }
      return currentHeight + books[nextBook][1];
    }
    if (cache[nextBook][currentWidth] != 0) { return cache[nextBook][currentWidth]; }
    int ans = currentHeight + getBest(nextBook + 1, books[nextBook][0], books[nextBook][1], cache, books, shelfWidth);
    if (currentWidth + books[nextBook][0] <= shelfWidth) {
      ans = min(ans, getBest(nextBook + 1, currentWidth + books[nextBook][0], max(currentHeight, books[nextBook][1]),
                             cache, books, shelfWidth));
    }
    cache[nextBook][currentWidth] = ans;
    return ans;
  }

 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int N = books.size();
    vector<vector<int>> cache(N, vector<int>(shelfWidth + 1, 0));
    return getBest(0, 0, 0, cache, books, shelfWidth);
  }
};
