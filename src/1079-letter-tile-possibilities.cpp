// 1079. Letter Tile Possibilities
// https://leetcode.com/problems/letter-tile-possibilities/

#include <algorithm>
#include <set>
#include <string>

using namespace std;

class Solution {
 public:
  int numTilePossibilities(string tiles) {
    int n = tiles.size();
    set<string> possible;
    for (int i = 1; i < (1 << n); ++i) {
      string s = "";
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) { s += tiles[j]; }
      }
      sort(s.begin(), s.end());
      do { possible.insert(s); } while (next_permutation(s.begin(), s.end()));
    }
    return possible.size();
  }
};
