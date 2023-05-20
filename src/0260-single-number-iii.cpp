// 260. Single Number III
// https://leetcode.com/problems/single-number-iii/

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int v = 0, L = nums.size();
    for (int i = 0; i < L; i++)
      v ^= nums[i];
    int d = v & -v, l = 0, r = 0;
    for (int i = 0; i < L; i++) {
      if ((nums[i] & d) > 0)
        l ^= nums[i];
      else
        r ^= nums[i];
    }
    vector<int> res;
    res.push_back(v ^ l);
    res.push_back(v ^ r);
    return res;
  }
};
