#include <vector>

using namespace std;

class Solution {
public:
  int minStartValue(vector<int>& nums) {
    int N = nums.size(), sum = 0, curr = 1;
    for (int i = 0; i < N; ++i) {
      sum += nums[i];
      curr = max(curr, (-sum) + 1);
    }
    return curr;
  }
};
