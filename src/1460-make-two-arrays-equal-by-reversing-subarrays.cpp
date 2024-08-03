// 1460. Make Two Arrays Equal by Reversing Subarrays
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    int N = arr.size();
    unordered_map<int, int> cnt;
    for (int i = 0; i < N; ++i) { ++cnt[arr[i]]; }
    for (int i = 0; i < N; ++i) { --cnt[target[i]]; }
    for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
      if (itr->second != 0) { return false; }
    }
    return true;
  }
};
