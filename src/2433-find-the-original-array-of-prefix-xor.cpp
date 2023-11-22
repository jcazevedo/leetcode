// 2433. Find The Original Array of Prefix Xor
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findArray(vector<int>& pref) {
    int N = pref.size();
    vector<int> ans = vector<int>(N, 0);
    ans[0] = pref[0];
    for (int i = 1; i < N; ++i)
      ans[i] = pref[i] ^ pref[i - 1];
    return ans;
  }
};
