// 1497. Check If Array Pairs Are Divisible by k
// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> cnt;
    int N = arr.size();
    for (int i = 0; i < N; ++i) { ++cnt[(arr[i] % k + k) % k]; }
    for (unordered_map<int, int>::iterator itr = cnt.begin(); itr != cnt.end(); ++itr) {
      if (k == 2 * itr->first && itr->second % 2 != 0) {
        return false;
      } else if (cnt[(k - itr->first) % k] != itr->second) {
        return false;
      }
    }
    return true;
  }
};
