// 2206. Divide Array Into Equal Pairs
// https://leetcode.com/problems/divide-array-into-equal-pairs/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool divideArray(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (int num : nums) { ++cnt[num]; }
    for (unordered_map<int, int>::iterator itr = cnt.begin(); itr != cnt.end(); ++itr) {
      if (itr->second % 2) { return false; }
    }
    return true;
  }
};
