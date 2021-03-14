#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int N = nums.size();
    vector<int> prefix_mult = vector<int>(N, 0);
    vector<int> suffix_mult = vector<int>(N, 0);
    vector<int> output = vector<int>(N, 0);
    prefix_mult[0] = nums[0];
    suffix_mult[N - 1] = nums[N - 1];
    for (int i = 1; i < N; ++i)
      prefix_mult[i] = prefix_mult[i - 1] * nums[i];
    for (int i = N - 2; i >= 0; --i)
      suffix_mult[i] = suffix_mult[i + 1] * nums[i];

    for (int i = 0; i < N; ++i) {
      int pref = i > 0 ? prefix_mult[i - 1] : 1;
      int suff = i < N - 1 ? suffix_mult[i + 1] : 1;
      output[i] = pref * suff;
    }

    return output;
  }
};
