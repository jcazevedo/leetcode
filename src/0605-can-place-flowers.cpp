// 605. Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/

#include <vector>

using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int L = flowerbed.size();
    for (int i = 0; i < L && n > 0; ++i) {
      if (flowerbed[i] == 0) {
        if (i > 0 && flowerbed[i - 1] != 0)
          continue;
        if (i < L - 1 && flowerbed[i + 1] != 0)
          continue;
        flowerbed[i] = 1;
        n--;
      }
    }
    return n == 0;
  }
};
