#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int unique = 0, L = nums.size();
    for (int i = 0; i < L; i++)
      unique ^= nums[i];
    return unique;
  }
};
