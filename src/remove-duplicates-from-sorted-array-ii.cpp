#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int N = nums.size();
    if (N <= 2) return N;
    int j = 2;
    for (int i = 2; i < N; ++i) {
      if (nums[i] != nums[j - 2]) nums[j++] = nums[i];
    }
    return j;
  }
};
