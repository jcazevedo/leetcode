#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int H = height.size();
    int left = 0, right = H - 1;
    int best_area = 0;
    while (left < right) {
      best_area = max(best_area, min(height[left], height[right]) * (right - left));
      if (height[left] < height[right])
        left++;
      else
        right--;
    }
    return best_area;
  }
};
