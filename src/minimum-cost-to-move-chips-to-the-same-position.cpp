#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostToMoveChips(vector<int> &position) {
    int to_even = 0, to_odd = 0;
    for (int pos : position) {
      if (pos % 2 == 0)
        to_odd++;
      else
        to_even++;
    }
    return min(to_even, to_odd);
  }
};
