// 89. Gray Code
// https://leetcode.com/problems/gray-code/

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> ans(1 << n);
    ans[0] = 0;
    ans[1] = 1;
    for (int l = 2; l <= n; ++l) {
      int len = 1 << (l - 1);
      int j = len - 1;
      for (int i = len; i < len * 2; ++i, --j) {
        ans[i] = ans[j] | len;
      }
    }
    return ans;
  }
};
