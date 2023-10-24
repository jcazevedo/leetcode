// 667. Beautiful Arrangement II
// https://leetcode.com/problems/beautiful-arrangement-ii/

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> constructArray(int n, int k) {
    vector<int> ans;
    for (int i = 1; i < n - k; ++i)
      ans.push_back(i);
    for (int i = 0; i <= k; ++i)
      ans.push_back((i % 2 == 0) ? (n - k + i / 2) : (n - i / 2));
    return ans;
  }
};
